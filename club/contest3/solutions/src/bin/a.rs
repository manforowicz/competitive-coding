#[allow(unused_imports)]
use std::cmp::{max, min};
use std::collections::HashSet;
use std::io::{stdin, stdout, BufWriter, Write};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>,
}
impl Scanner {
    fn token<T: std::str::FromStr>(&mut self) -> T {
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

    fn next_array<T: std::str::FromStr>(&self) -> Vec<T> {
        if !self.buffer.is_empty() {
            panic!("Unread tokens!")
        }
        let mut input = String::new();
        stdin().read_line(&mut input).expect("Failed read");
        input
            .split_whitespace()
            .map(|s| s.parse().ok().expect("Failed parse"))
            .collect()
    }
}

fn next_line() -> String {
    let mut s = String::new();
    stdin().read_line(&mut s).expect("Failed read");
    s
}

fn main() {
    let mut out = BufWriter::new(stdout());
    let mut scan = Scanner::default();

    let t = next_line().parse().unwrap();

    for _ in 0..t {
        let n = next_line().parse().unwrap();
        let arr = scan.next_array::<u32>();
        let even = arr.iter().filter(|&&x| x % 2 == 0).count();
        writeln!(out, "{}", min(even, arr.len() - even)).ok();
    }
}
