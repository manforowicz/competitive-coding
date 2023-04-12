#[allow(unused_imports)]
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
        self.buffer.pop().expect("No input left").parse().ok().expect("Failed parse")
    }
}

fn main() {
    let mut scan = Scanner::default();
    let mut out = BufWriter::new(stdout());

    let n = scan.next::<usize>();

    let mut called = vec![false; n];
    let mut uncalled_count = n;

    for i in 0..n {
        let calling = scan.next::<usize>() - 1;
        if !called[i] {
            if !called[calling] {
                called[calling] = true;
                uncalled_count -= 1;
            }
        }
    }
    writeln!(out, "{}", uncalled_count).unwrap();

    for i in 0..n {
        if !called[i] {
            write!(out, "{} ", i+1).unwrap();
        }
    }
    
}
