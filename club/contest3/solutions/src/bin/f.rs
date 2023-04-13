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

        let out_degree: Vec<usize> = adj.iter()
            .map(HashSet::len).collect();

        let mut leafs: HashSet<usize> = out_degree.iter()
            .enumerate()
            .filter(|(_, sub)| **sub == 1)
            .map(|(i, _)| i)
            .collect();

        /* 

        for _ in 0..k {
            for leaf in leafs.iter() {
                for neighbor in adj[*leaf].iter() {
                    adj[*neighbor].remove(leaf);
                    if adj[*neighbor].len() == 1 {
                        leafs.insert(*neighbor);
                    }
                    leafs.remove(leaf);
                }

            }

        }
        */
    }
}
