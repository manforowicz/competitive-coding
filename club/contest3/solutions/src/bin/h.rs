#![allow(unused_imports)]
#![allow(dead_code)]
#![allow(unused)]
use std::cmp::{max, min};
use std::collections::{BTreeSet, HashSet};
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

macro_rules! test {
    () => {{
        let s = raw_line().split_whitespace();
        while let Some(thing) = s.next() {
            return thing.parse().ok().expect("Failed parse");
        }
    }};
}

fn main() {
    let mut out = BufWriter::new(stdout());

    let tmp = next_arr::<usize>();
    let n = tmp[0];
    let m = tmp[1];
    let k = tmp[2];
    let a = next_arr::<u64>();

    let (x, y, z) = test!();

    let mut window = BTreeSet::<u64>::from_iter(a[0..m].iter().cloned());

    let mut sum: u64 = window.iter().take(k).sum();

    for i in 0..n - m {
        sum -= a[i];

        window.remove(&a[i]);
    }

    writeln!(out, "{}", 5).unwrap();
}
