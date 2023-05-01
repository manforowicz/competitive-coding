#![allow(unused_imports, dead_code)]
use std::cmp::{max, min};
use std::collections::*;
use std::fs::File;
use std::io::{stdin, stdout, BufRead, BufReader, BufWriter, Write};
use std::iter::FromIterator;
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

fn get_pow2_above(num: u32) -> u32 {
    let mut pow = 1;
    while pow <= num {
        pow *= 2;
    }
    pow
}

fn main() {
    let stdin = stdin();
    let mut read = Read::new(stdin.lock()); // or file

    let _n = scan!(read, usize);
    let mut balls = read.next_arr::<u32>();
    balls.sort_unstable();
    balls.reverse();

    // freq[num written on ball] = frequency
    let mut freq = HashMap::<u32, u32>::new();

    for ball in &balls {
        if let Some(freq) = freq.get_mut(ball) {
            *freq += 1;
        } else {
            freq.insert(*ball, 1);
        }
    }
    balls.dedup();

    let mut pairs = 0;
    for ball in balls {
        let other = get_pow2_above(ball) - ball;

        if freq.contains_key(&other) {
            if ball == other {
                pairs += freq[&ball] / 2;
            } else {
                let new_pairs = min(freq[&ball], freq[&other]);
                pairs += new_pairs;
                *freq.get_mut(&other).unwrap() -= new_pairs;
            }
        }
    }
    println!("{}", pairs);
}
