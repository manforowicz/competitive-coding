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

fn continuous(arr: &[i64]) -> bool {
    for pair in arr.windows(2) {
        if pair[0] != pair[1] {
            return false;
        }
    }
    return true;
}

fn main() {
    let stdin = stdin();
    let stdout = stdout();
    let mut read = Read::new(stdin.lock()); // or file
    let mut out = BufWriter::new(stdout.lock());

    let (n, k) = scan!(read, usize, usize);
    let arr = read.next_arr::<i64>();


    let mut left_end = vec![0; k];
    for i in 0..k {
        left_end[i] = arr[i];
        for j in k..k+i {
            left_end[i] -= arr[j];
        }
    }

    let mut right_end = vec![0; k];
    for i in 0..k {
        right_end[i] = arr[i];
        for j in i+1..k {
            right_end[i] -= arr[j + n - k];
        }
    }


    let q = scan!(read, u32);
    for _ in 0..q {
        let (mut l, mut r) = scan!(read, usize, usize);
        l -= 1;
        r -= 1;
        let mut possible = true;
        if l < k && n - k < r {
            if !(continuous(&left_end[l..min(k, r)]) || continuous(&right_end[0..r + k - n])) {
                possible = false;
            }
        }
        if possible {
            writeln!(out, "Yes").unwrap();
        } else {
            writeln!(out, "No").unwrap();
        }

    }
}
