#[allow(unused_imports)]
use std::cmp::{max, min};
use std::collections::HashSet;
use std::io::{stdin, stdout, BufWriter, Write};

fn next_array<T: std::str::FromStr>() -> Vec<T> {
    next_line()
        .split_whitespace()
        .map(|s| s.parse().ok().expect("Failed parse"))
        .collect()
}

fn next_line() -> String {
    let mut s = String::new();
    stdin().read_line(&mut s).expect("Failed read");
    s
}

fn main() {
    let mut out = BufWriter::new(stdout());

    let t = next_line().parse().unwrap();

    for _ in 0..t {
        let _n = next_line();
        let arr = next_array::<u32>();
        let even = arr.iter().filter(|&&x| x % 2 == 0).count();
        writeln!(out, "{}", min(even, arr.len() - even)).ok();
    }
}
