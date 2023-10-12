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

    let (n, k) = scan!(read, usize, usize);
    let arr = read.next_arr::<i64>();

    let mut good_r = vec![false; n];
    let mut arr_sim = arr.clone();
    for i in 0..n + 1 - k {
        let c = arr_sim[i];
        let mut zeros = true;
        for j in 0..k {
            arr_sim[i + j] -= c;
            if arr_sim[i + j] != 0 {
                zeros = false;
            }
        }
        good_r[i + k - 1] = zeros;
    }
    println!("{arr_sim:?}");

    let mut good_l = vec![false; n];
    arr_sim = arr.clone();
    for i in (k - 1..n).rev() {
        let c = arr_sim[i];
        let mut zeros = true;
        for j in 0..k {
            arr_sim[i - j] -= c;
            if arr_sim[i - j] != 0 {
                zeros = false;
            }
        }
        good_l[i + 1 - k] = zeros;
    }
    println!("{arr_sim:?}");

    let q = scan!(read, u32);
    for _ in 0..q {
        let (l, r) = scan!(read, usize, usize);

        if good_l[l - 1] || good_r[r - 1] {
            writeln!(out, "Yes").unwrap();
        } else {
            writeln!(out, "No").unwrap();
        }
    }
}
