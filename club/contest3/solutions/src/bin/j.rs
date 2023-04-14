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
    let t: u32 = next_line();


    for _ in 0..t {
        let _n = next_line::<usize>();
        let arr = next_arr::<i64>();
        let mut sum = 0;
        let mut ways = 1;
        for b in arr {
            sum += b;
            if sum != b {
                ways *= 2;
                ways %= 1000000007;
            }
        }
        writeln!(out, "{}", ways).unwrap();
    }
}