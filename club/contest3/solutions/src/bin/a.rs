#[allow(unused_imports)]
use std::cmp::{max, min};
use std::collections::HashSet;
use std::io::{stdin, stdout, BufWriter, Write};

fn raw_line() -> String {
    let mut s = String::new();
    stdin().read_line(&mut s).expect("Failed read");
    s
}

fn next_line<T: std::str::FromStr>() -> T {
    raw_line().parse().ok().expect("Failed parse")
}

fn next_arr<T: std::str::FromStr>() -> Vec<T> {
    raw_line()
        .split_whitespace()
        .map(|s| s.parse().ok().expect("Failed parse"))
        .collect()
}

fn main() {
    let mut out = BufWriter::new(stdout());

    let t: usize = next_line();

    for _ in 0..t {
        let _n: usize = next_line();
        let arr = next_arr::<u32>();
        let even = arr.iter().filter(|&&x| x % 2 == 0).count();
        writeln!(out, "{}", min(even, arr.len() - even)).unwrap();
    }
}
