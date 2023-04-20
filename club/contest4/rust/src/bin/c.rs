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
    // let file = BufReader::new(File::open("in.txt").unwrap());
    let stdin = stdin();
    let stdout = stdout();
    let mut read = Read::new(stdin.lock()); // or file
    let mut out = BufWriter::new(stdout.lock());

    let t = scan!(read, u32);

    for _ in 0..t {
        let (a, b, c) = scan!(read, u32, u32, u32);
        if (a + b + c) % 3 != 0 {
            writeln!(out, "-1").unwrap();
            continue;
        }
        let avg = (a + b + c) / 3;
        let diff1 = max(a, avg) - min(a, avg);
        let diff2 = max(b, avg) - min(b, avg);
        let diff3 = max(c, avg) - min(c, avg);

        if diff1 % 2 != 0 || diff2 % 2 != 0 || diff3 % 2 != 0 {
            writeln!(out, "-1").unwrap();
            continue;
        }
        writeln!(out, "{}", max(max(diff1, diff2), diff3) / 2).unwrap();
    }
}
