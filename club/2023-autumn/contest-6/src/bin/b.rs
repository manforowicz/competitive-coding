#![allow(dead_code)]

use std::collections::HashSet;
use std::io::{stdin, stdout, BufRead, BufWriter, Write};
use std::str::{FromStr, SplitAsciiWhitespace};


struct Read<T: BufRead> {
    buf: T,
    line: String,
}

impl<T: BufRead> Read<T> {
    fn new(buf: T) -> Self {
        Read {
            buf,
            line: String::new(),
        }
    }

    fn line(&mut self) -> SplitAsciiWhitespace {
        self.line.clear();
        self.buf.read_line(&mut self.line).expect("Failed read");
        self.line.split_ascii_whitespace()
    }

    fn next_arr<U: FromStr>(&mut self) -> Vec<U> {
        self.line()
            .map(|s| s.parse().ok().expect("Failed parse"))
            .collect()
    }
}

macro_rules! scan {
    ( $read:expr, $( $type:ty ),* ) => {{
        let mut iter = $read.line();
        ($(
            iter.next()
                .expect("No next")
                .parse::<$type>()
                .expect("Couldn't parse")
        ),*)
    }}
}

fn color_component(visited: &mut [bool], adj: &Vec<Vec<usize>>, curr_set: &mut HashSet<usize>, next_set: &mut HashSet<usize>, node: usize) -> bool {
    if next_set.contains(&node) {
        visited[node] = true;
        return false;
    }

    if visited[node] {
        return true;
    }

    visited[node] = true;

    curr_set.insert(node);

    for &friend in &adj[node] {
        if !color_component(visited, adj, next_set, curr_set, friend) {
            return false;
        }
    }

    true
}

fn main() {
    let mut read = Read::new(stdin().lock());

    let (n, m) = scan!(read, usize, usize);

    let mut adj = vec![vec![]; n];

    for _ in 0..m {
        let (u, v) = scan!(read, usize, usize);
        adj[u - 1].push(v - 1);
        adj[v - 1].push(u - 1);
    }



    let mut set_lens = Vec::new();

    let mut visited = vec![false; n];

    for node in 0..n {
        if !visited[node] {
            let mut a = HashSet::new();
            let mut b = HashSet::new();
            if !color_component(&mut visited, &adj, &mut a, &mut b, node) {
                println!("0");
                return;
            }

            if !a.is_empty() {
                set_lens.push(a.len());
            }
            if !b.is_empty() {
                set_lens.push(b.len());
            }
        }
    }

    let mut answer = 0;

    for set_len in set_lens {
        answer += set_len * (n - set_len);
    }

    println!("{}", answer / 2 - m);

}