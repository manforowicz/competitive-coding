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

    let tmp = next_arr::<i64>();
    let _n = tmp[0];
    let k = tmp[1];
    let d = tmp[2];
    let a = next_arr::<i64>();

    // greatest sum for [# of terms][sum % d]
    let mut dp = vec![vec![-1; d as usize]; (k + 1) as usize];
    dp[0][0] = 0;

    for ai in a {
        for terms in (1..=k as usize).rev() {
            for rem in 0..d {
                if dp[terms - 1][rem as usize] != -1 {
                    let new_rem = ((rem + ai) % d) as usize;

                    dp[terms][new_rem] = max(dp[terms][new_rem], dp[terms - 1][rem as usize] + ai);
                }
            }
        }
    }
    writeln!(out, "{}", dp[k as usize][0]).unwrap();
}
