#![allow(dead_code)]

use std::io::{stdin, BufRead};
use std::str::{FromStr, SplitAsciiWhitespace};

struct Read<T: BufRead> {
    buf: T,
    line: String,
}

impl<T: BufRead> Read<T> {
    fn new(buf: T) -> Self {
        Read {
            buf,
            line: String::new(),
        }
    }

    fn line(&mut self) -> SplitAsciiWhitespace {
        self.line.clear();
        self.buf.read_line(&mut self.line).expect("Failed read");
        self.line.split_ascii_whitespace()
    }

    fn next_arr<U: FromStr>(&mut self) -> Vec<U> {
        self.line()
            .map(|s| s.parse().ok().expect("Failed parse"))
            .collect()
    }
}

macro_rules! scan {
    ( $read:expr, $( $type:ty ),* ) => {{
        let mut iter = $read.line();
        ($(
            iter.next()
                .expect("No next")
                .parse::<$type>()
                .expect("Couldn't parse")
        ),*)
    }}
}

//////// IO BOILERPLATE ABOVE ////////

//////// SOLUTION BELOW ////////

fn is_possible(items: &[u32], scouts: u32, max_carry: u32) -> bool {
    let mut l = 0;
    let mut r = items.len() - 1;

    let mut pairs = 0;

    while l < r {
        if items[l] + items[r] <= max_carry {
            pairs += 1;
            l += 1;
            r -= 1;
        } else {
            r -= 1;
        }
    }

    items.len() as u32 <= scouts + pairs
}

fn main() {
    let mut read = Read::new(stdin().lock());

    let (_n, m) = scan!(read, usize, u32);

    let mut items: Vec<u32> = read.next_arr();
    items.sort_unstable();

    let largest_item = items[items.len() - 1];

    let mut min_answer = largest_item;
    let mut max_answer = largest_item * 2;

    while min_answer != max_answer {
        let mid = (min_answer + max_answer) / 2;
        if is_possible(&items, m, mid) {
            max_answer = mid;
        } else {
            min_answer = mid + 1;
        }
    }

    println!("{max_answer}");
}
