#![allow(unused)]
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
        let _ = raw_line();
        let line = next_arr::<usize>();
        let n = line[0];
        let k = line[1];

        let mut adj = vec![HashSet::new(); n + 1];
        for _ in 1..n {
            let edge = next_arr::<usize>();
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        let mut next_leafs = HashSet::new();
        for i in 1..adj.len() {
            if adj[i].len() <= 1 {
                next_leafs.insert(i);
            }
        }

        let mut remain = n as i32;

        for _ in 0..k {
            let leafs = next_leafs.clone();
            next_leafs = HashSet::new();
            if leafs.is_empty() {
                break;
            }
            for leaf in leafs {
                remain -= 1;
                for other in (adj[leaf]).clone() {
                    adj[leaf].remove(&other);
                    adj[other].remove(&leaf);
                    if adj[other].len() == 1 {
                        next_leafs.insert(other);
                    }
                }
            }
        }
        writeln!(out, "{}", remain).unwrap();
    }
}
