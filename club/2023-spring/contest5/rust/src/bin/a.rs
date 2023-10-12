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

fn get_mex(arr: &mut [i64]) -> i64 {
    arr.sort_unstable();

    let mut curr = -1;
    for elem in arr {
        if *elem > curr + 1 {
            return curr + 1;
        }
        curr = *elem;
    }
    return curr + 1;
}

fn main() {
    let stdin = stdin();
    let stdout = stdout();
    let mut read = Read::new(stdin.lock());
    let mut out = BufWriter::new(stdout.lock());

    let (n, m) = scan!(read, i64, usize);
    let arr = read.next_arr::<i64>();

    let mut elems_at_j = vec![Vec::<i64>::new(); m];

    for i in 0..n {
        let start = arr[i as usize];
        let increment = i + 1;
        let upper_j = (n - start) / increment + 1;
        let lower_j = (0 - start) / increment;

        for j in max(1, lower_j)..=min(upper_j, m as i64) {
            let elem = start + increment * j;
            if elem >= 0 {
                elems_at_j[j as usize - 1].push(elem);
            }
        }
    }

    for j in 0..m {
        writeln!(out, "{}", get_mex(&mut elems_at_j[j])).unwrap();
    }
}
