#![allow(unused_imports)]
#![allow(dead_code)]
use std::io::{stdin, stdout, BufWriter, Write};
use std::cmp::{max, min};
use std::collections::HashSet;


fn raw_line() -> String {
    let mut s = String::new();
    stdin().read_line(&mut s).expect("Failed read");
    s
}

fn next_line<T: std::str::FromStr>() -> T {
    raw_line().trim().parse().ok().expect("Failed parse")
}

fn next_arr<T: std::str::FromStr>() -> Vec<T> {
    raw_line()
        .split_whitespace()
        .map(|s| s.parse().ok().expect("Failed parse"))
        .collect()
}

fn main() {
    let mut out = BufWriter::new(stdout());
    writeln!(out, "{}", 5).unwrap();
}
