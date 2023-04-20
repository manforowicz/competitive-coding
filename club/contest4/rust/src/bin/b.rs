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
    let stdin = stdin().lock();
    let mut read = Read::new(stdin);

    let (_n, k) = scan!(read, usize, u64);

    let dates = read.next_arr::<u64>();

    let mut cost: u64 = k + 1;
    for pair in dates.windows(2) {
        let gap = pair[1] - pair[0];
        cost += min(gap, k + 1);
    }

    writeln!(stdout(), "{}", cost).unwrap();
}
