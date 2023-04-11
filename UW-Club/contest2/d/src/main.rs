#[allow(unused_imports)]
use std::collections::HashSet;
use std::io::{stdin, stdout, BufWriter, Write};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>,
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        if self.buffer.is_empty() {
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
        self.buffer
            .pop()
            .expect("No input left")
            .parse()
            .ok()
            .expect("Failed parse")
    }
}

fn explore(links: &Vec<Vec<usize>>, visited: &mut Vec<bool>, curr: usize) {
    if !visited[curr] {
        visited[curr] = true;
        for other in &links[curr] {
            explore(links, visited, *other);
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let n: usize = scan.next();
    let m: usize = scan.next();

    let mut links: Vec<Vec<usize>> = vec![vec![]; n];
    let mut visited = vec![false; n];

    for _ in 0..m {
        let a = scan.next::<usize>() - 1;
        scan.next::<char>();
        let b = scan.next::<usize>() - 1;
        scan.next::<char>();

        links[a].push(b);
        links[b].push(a);
    }

    let mut components = 0;

    for i in 0..n {
        if !visited[i] {
            components += 1;
            explore(&links, &mut visited, i);
        }
    }

    write!(out, "{} {}", components + m - n, n - m).unwrap();
}
