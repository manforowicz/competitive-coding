#[allow(unused_imports)]
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

    fn line<T: std::str::FromStr>(&self) -> Vec<T> {
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

fn main() {
    let mut out = BufWriter::new(stdout());
    let mut scan = Scanner::default();

    let n = scan.token::<usize>();
    let arr = scan.line::<u32>();
    write!(out, "{}", n).ok();
}



----- OR ----------

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
    writeln!(out, "{}", 5).unwrap();
}
