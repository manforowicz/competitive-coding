#![allow(unused_imports, dead_code)]
use std::cmp::{max, min};
use std::collections::*;
use std::fs::File;
use std::io::{stdin, stdout, BufRead, BufReader, BufWriter, Write};
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
    let stdin = stdin();
    let mut read = Read::new(stdin.lock()); // or file

    let (n, m) = scan!(read, u64, u64);

    let highest_a = min(n, (m as f64).sqrt() as u64 + 1);
    let lowest_a = (m + n - 1) / n;

    if lowest_a > highest_a {
        println!("-1");
    } else {
        let mut best = std::u64::MAX;

        for a in lowest_a..=highest_a {
            let b = (m + a - 1) / a;
            best = min(best, a * b);
        }
        println!("{}", best);
    }
}
