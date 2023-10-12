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
    // Setup
    // let file = BufReader::new(File::open("in.txt").unwrap());
    let stdin = stdin();
    let mut read = Read::new(stdin.lock()); // or file

    let _n = scan!(read, u32);

    let s = scan!(read, String);

    let mut length = 0;
    let mut best_length = 0;
    let mut has_dash = false;
    let mut has_o = false;
    
    for c in s.bytes() {
        if c == b'-' {
            best_length = max(length, best_length);
            length = 0;
            has_dash = true;
        } else {
            length += 1;
            has_o = true;
        }
    }
    best_length = max(best_length, length);

    if has_dash && has_o {
        println!("{}", best_length);
    } else {
        println!("-1");
    }
}
