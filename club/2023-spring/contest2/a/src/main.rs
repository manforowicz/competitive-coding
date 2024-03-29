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

    let mut s = scan.next::<String>().into_bytes();

    for i in (1..s.len()).step_by(2) {
        let tmp = s[i];
        s[i] = s[i-1];
        s[i-1] = tmp;
    }

    write!(out, "{}", std::str::from_utf8(&s).unwrap()).unwrap();
}
