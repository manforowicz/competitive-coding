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

    let tmp = next_arr::<u64>();
    let _n = tmp[0];
    let m = tmp[1];
    let mut arr = next_arr::<u64>();
    arr.sort();
    let mut best_sum = 0;
    let mut sum = 0;

    let mut prev = arr[0];

    for _ in 0..2 {
        for i in 0..arr.len() {
            if arr[i] != prev && (prev + 1) % m != arr[i] {
                sum = 0;
            }
            sum += arr[i];
            best_sum = max(best_sum, sum);
            prev = arr[i];
        }
    }

    let result = arr.iter().sum::<u64>().saturating_sub(best_sum);

    writeln!(out, "{}", result).unwrap();
}
