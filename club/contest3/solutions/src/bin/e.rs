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


    let tmp = next_arr::<u64>();
    let _n = tmp[0];
    let k = tmp[1];
    let d = tmp[2];
    let a = next_arr::<u64>();


    // greatest sum so far where (sum % d = index)
    let mut dp = vec![0, d];

    // number of terms
    let mut quantity = vec![0, d];

    for elem in a {
        for i in 0..d {
            let new_i = ((i + elem) % d) as usize;
            dp[new_i] = max(dp[new_i], dp[i as usize] + elem);
        }
    }



    writeln!(out, "{}", 5).unwrap();
}
