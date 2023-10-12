#![allow(unused_imports)]
#![allow(dead_code)]
use std::cmp::{max, min};
use std::collections::HashSet;
use std::io::{stdin, stdout, BufWriter, Write};

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

    let mut t: i64 = next_arr()[1];

    let list: Vec<i64> = next_arr();

    t %= list.iter().sum::<i64>();

    let mut i = 0;

    while t - list[i] > 0 {
        t -= list[i];
        i += 1;
    }

    writeln!(out, "{} {}", i+1, t).unwrap();
}
