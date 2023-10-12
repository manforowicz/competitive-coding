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
    let stdout = stdout();
    let mut read = Read::new(stdin.lock()); // or file
    let mut out = BufWriter::new(stdout.lock());

    let t = scan!(read, u32);
    for _ in 0..t {
        let n = scan!(read, usize);
        let arr = read.next_arr::<u32>();

        writeln!(out, "{}", n - 1).unwrap();

        if n - 1 == 0 {
            continue;
        };

        writeln!(out, "{} {}", 1, n).unwrap();
        let target = if (arr[0] + arr[n - 1]) % 2 == 0 {
            arr[n - 1]
        } else {
            arr[0]
        };

        for i in 1..n - 1 {
            if (target + arr[i]) % 2 == 0 {
                writeln!(out, "{} {}", i + 1, n).unwrap();
            } else {
                writeln!(out, "{} {}", 1, i + 1).unwrap();
            }
        }
    }
}
