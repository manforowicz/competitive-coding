#![allow(dead_code)]

use std::collections::HashSet;
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

fn main() {
    let mut read = Read::new(stdin().lock());

    let n = scan!(read, usize);

    let a: Vec<u32> = read.next_arr();
    let b: Vec<u32> = read.next_arr();


    // lower_i and upper_i (exclusive)
    // that's compatible with the given i
    let mut equal = vec![(0, 0); n];

    let mut set_a = HashSet::new();
    let mut set_b = HashSet::new();

    let mut a_i = 0;
    let mut b_i = 0;

    let mut difference_count = 0;

    while a_i < a.len() && b_i < b.len() {
        if set_a.len() < set_b.len() {
            a_i += 1;
        } else if set_a.len() > set_b.len() {
            b_i += 1;
        } else if set_a.contains(&a[a_i + 1]) {
            a_i += 1;
        } else {
            b_i += 1;
        }
        if set_a.insert(a[a_i]) {
            if set_b.contains(&a[a_i]) {
                difference_count -= 1;
            } else {
                difference_count += 1;
            }
        }

        if set_b.insert(b[b_i]) {
            if set_a.contains(&b[b_i]) {
                difference_count -= 1;
            } else {
                difference_count += 1;
            }
        }
    }

    let q = scan!(read, u32);
    for _ in 0..q {
        let (x, y) = scan!(read, u32, u32);
    }


}