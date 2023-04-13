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

    let t: usize = next_line();

    for _ in 0..t {
        let _n: usize = next_line();
        let s = raw_line();
        let mut seen = HashSet::with_capacity(s.len() * 2);

        let mut possible = false;

        for i in 0..s.len() - 1 {
            let curr = &s[i..i + 2];
            if (i > 1 && *curr == s[i - 2..i])
                || (i > 0 && *curr != s[i - 1..i + 1] && seen.contains(curr))
            {
                possible = true;
                break;
            }

            seen.insert(curr);
        }

        if possible {
            writeln!(out, "YES").unwrap();
        } else {
            writeln!(out, "NO").unwrap();
        }
    }
}
