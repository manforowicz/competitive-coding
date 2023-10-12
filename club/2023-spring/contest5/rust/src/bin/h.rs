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
        let (n, k) = scan!(read, i32, i32);
        let street = read.next_arr::<usize>();

        let max_c = *street.iter().max().unwrap() + 1;
        let mut days_for_c = vec![0; max_c];
        let mut last_pos_of_c = vec![-1; max_c];

        for pos in 0..n {
            let c = street[pos as usize];
            if pos > last_pos_of_c[c] {
                let days = (pos - last_pos_of_c[c]+ k - 2) / k;
                days_for_c[c] += days;
                last_pos_of_c[c] = max(pos, last_pos_of_c[c] + k * days);
            }
        }

        let pos = n;
        for c in 0..max_c {
            if pos > last_pos_of_c[c] {
                let days = (pos - last_pos_of_c[c]+ k - 2) / k;
                days_for_c[c] += days;
                last_pos_of_c[c] = max(pos, last_pos_of_c[c] + k * days);
            }
        }
        writeln!(out, "{}", days_for_c.iter().min().unwrap()).unwrap();
    }
}
