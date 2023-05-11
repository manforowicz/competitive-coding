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

fn longest_sequence(s: &str) -> usize {
    let bytes = s.as_bytes();
    let mut longest = 0;
    let mut current = 0;

    let mut sub_count = || {
        for letter in bytes {
            if *letter == b'0' {
                current = 0;
            } else {
                current += 1;
            }
            longest = max(longest, current);
        }
    };
    sub_count();
    sub_count();

    min(longest, bytes.len())
}

fn main() {
    let stdin = stdin();
    let stdout = stdout();
    let mut read = Read::new(stdin.lock());
    let mut out = BufWriter::new(stdout.lock());

    let t = scan!(read, u32);

    for _ in 0..t {
        let s = scan!(read, String);
        let longest = longest_sequence(&s);
        let width = (longest + 1) / 2;
        let height = (longest + 2) / 2;
        writeln!(out, "{}", width * height).unwrap();
    }
}
