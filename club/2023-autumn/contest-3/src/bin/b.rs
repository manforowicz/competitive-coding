use std::collections::HashSet;
use std::io::{stdin, BufRead};
use std::str::SplitAsciiWhitespace;

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
    let mut read = Read::new(stdin().lock());

    let (s, t, m) = scan!(read, usize, usize, usize);

    let mut adj_to_v = vec![HashSet::new(); t];

    for _ in 0..m {
        let (a, b) = scan!(read, usize, usize);
        adj_to_v[b - s - 1].insert(a);
    }

    let mut shared = Vec::new();

    for i in 0..t {
        for j in i + 1..t {
            shared.clear();
            let a = &adj_to_v[i];
            let b = &adj_to_v[j];
            if a.len() < b.len() {
                for elem in a {
                    if b.contains(elem) {
                        shared.push(elem);
                    }
                }
            } else {
                for elem in b {
                    if a.contains(elem) {
                        shared.push(elem);
                    }
                }
            }
            if shared.len() >= 2 {
                println!("{} {} {} {}", i + s + 1, j + s + 1, shared[0], shared[1]);
                return;
            }
        }
    }
    println!("-1");
}
