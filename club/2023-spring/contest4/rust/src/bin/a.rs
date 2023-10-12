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
    let mut read = Read::new(stdin().lock());
    let mut out = BufWriter::new(stdout().lock());

    let t = scan!(read, u32);

    for _ in 0..t {
        let n = scan!(read, usize);
        let a: Vec<u32> = read.next_arr();
        let zeros = a.iter().filter(|&&x| x == 0).count();
        let ones = a.iter().filter(|&&x| x == 1).count();

        // Can we squeeze a different number between every single 0?
        if zeros <= (n + 1) / 2 {
            writeln!(out, "0").unwrap();

        // Can we group all 0s and all 1s, seperating them with another number?
        } else if ones == 0 || zeros + ones + 1 <= n {
            writeln!(out, "1").unwrap();

        // We know there are only 1s and 0s at this point
        // Can we squeeze a 0 between every single 1?
        } else if ones <= (n + 1) / 2 {
            writeln!(out, "2").unwrap();

        // Sum of 3 is always impossible with only 1s and 0s
        } else {
            writeln!(out, "3").unwrap();
        }
    }
}
