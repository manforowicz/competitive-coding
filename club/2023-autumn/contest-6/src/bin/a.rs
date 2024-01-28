#![allow(dead_code)]

use std::collections::HashSet;
use std::io::{stdin, stdout, BufRead, BufWriter, Write};
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
    let mut out = BufWriter::new(stdout().lock());

    let t = scan!(read, u32);

    for _ in 0..t {
        let (_m, s) = scan!(read, u32, usize);
        let arr: Vec<usize> = read.next_arr();
        let mut seen = [false; 51];

        for &elem in &arr {
            seen[elem] = true;
        }

        let max_elem = *arr.iter().max().unwrap();

        let mut sum = 0;
        for i in 1..max_elem {
            if !seen[i] {
                sum += i;
            }
        }

        let mut i = max_elem;

        while sum < s {
            if i >= seen.len() || !seen[i] {
                sum += i;
            }
            i += 1;
        }

        if sum == s {
            writeln!(out, "YES").unwrap();
        } else {
            writeln!(out, "NO").unwrap();
        }
    }
}