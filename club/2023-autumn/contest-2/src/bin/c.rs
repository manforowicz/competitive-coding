#![allow(dead_code)]
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

fn dist_between(adj: &Vec<Vec<usize>>, target: usize, start: usize) -> usize {
    let mut visited = vec![false; adj.len()];
    let mut currents = Vec::<usize>::new();
    let mut futures = vec![start];
    let mut dist = 0;

    loop {
        std::mem::swap(&mut currents, &mut futures);
        futures.clear();
        for &curr in &currents {
            visited[curr] = true;
            if curr == target {
                return dist;
            }
            for &adjacent in &adj[curr] {
                if !visited[adjacent] {
                    futures.push(adjacent);
                }
            }
        }
        dist += 1;
    }
}

fn nearest_loop(
    adj: &Vec<Vec<usize>>,
    visited: &mut Vec<bool>,
    prev: usize,
    pos: usize,
) -> Option<usize> {
    if visited[pos] {
        return Some(pos);
    }
    visited[pos] = true;

    for &next in &adj[pos] {
        if next != prev {
            if let Some(point) = nearest_loop(adj, visited, pos, next) {
                return Some(point);
            }
        }
    }
    None
}

fn main() {
    let mut read = Read::new(stdin().lock());
    let mut out = BufWriter::new(stdout().lock());

    let t = scan!(read, u32);

    for _ in 0..t {
        let (n, a, b) = scan!(read, usize, usize, usize);
        let mut adj = vec![vec![]; n + 1];
        for _ in 0..n {
            let (u, v) = scan!(read, usize, usize);
            adj[u].push(v);
            adj[v].push(u);
        }

        let mut visited = vec![false; n + 1];

        let safety = nearest_loop(&adj, &mut visited, b, b).unwrap();
        let a_dist = dist_between(&adj, a, safety);
        let b_dist = dist_between(&adj, b, safety);

        //writeln!(out, "point: {point}, a_dist: {a_dist}, b_dist: {b_dist}").unwrap();

        if a_dist > b_dist {
            writeln!(out, "YES").unwrap();
        } else {
            writeln!(out, "NO").unwrap();
        }
    }
    out.flush().unwrap();
}
