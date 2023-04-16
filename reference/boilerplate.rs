----- Base ----------

#![allow(unused_imports, dead_code)]
use std::cmp::{max, min};
use std::collections::*;
use std::fs::File;
use std::io::*;

struct Scan<T: BufRead>(T);

impl<T: BufRead> Scan<T> {
    fn raw_line(&mut self) -> String {
        let mut s = String::new();
        self.0.read_line(&mut s).expect("Failed read");
        s
    }

    fn next_line<U: std::str::FromStr>(&mut self) -> U {
        self.raw_line().trim().parse().ok().expect("Failed parse")
    }

    fn next_arr<U: std::str::FromStr>(&mut self) -> Vec<U> {
        self.raw_line()
            .split_ascii_whitespace()
            .map(|s| s.parse().ok().expect("Failed parse"))
            .collect()
    }
}

impl Scan<std::io::StdinLock<'static>> {
    fn stdin() -> Self {
        Self(stdin().lock())
    }
}

impl Scan<BufReader<File>> {
    fn file(filename: &str) -> Self {
        Self(BufReader::new(
            File::open(filename).expect("Couldn't open file"),
        ))
    }
}

fn main() {
    let mut out = BufWriter::new(stdout());
    let mut scan = Scan::stdin();
    let n = scan.next_line::<i64>();
    writeln!(out, "{}", n).unwrap();
}

------ Line Scan --------

struct Scan<'a>(std::str::SplitAsciiWhitespace<'a>);

impl<'a> Scan<'a> {
    fn new(line: &'a str) -> Self {
        Self(line.split_ascii_whitespace())
    }

    fn next<T: std::str::FromStr>(&mut self) -> T {
        self.0
            .next()
            .expect("Nothing left on line")
            .parse()
            .ok()
            .expect("Failed parse")
    }
}
