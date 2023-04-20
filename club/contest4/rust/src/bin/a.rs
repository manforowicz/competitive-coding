#![allow(unused_imports, dead_code)]
use std::cmp::{max, min};
use std::collections::*;
use std::fs::File;
use std::io::{stdin, stdout, BufRead, BufReader, BufWriter, Write};
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

fn main() {
    let file = BufReader::new(File::open("in.txt").unwrap());
    //let stdin = stdin().lock();
    let mut read = Read::new(file); // or file
    let mut out = BufWriter::new(stdout().lock());

    let t = scan!(read, u32);

    for _ in 0..t {
        let n = scan!(read, u32);
        let a: Vec<u32> = read.next_arr();
        let mut frequency = HashMap::new();
        for elem in a {
            if let Some(count) = frequency.get_mut(&elem) {
                *count += 1;
            } else {
                frequency.insert(elem, 1);
            }
        }
    }
}
