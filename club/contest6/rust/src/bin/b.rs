#![allow(unused_imports, dead_code)]
use std::io::{stdin, stdout, BufRead, BufWriter, Write};
use std::iter::once;
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

struct Car<'a> {
    i: usize,
    time: f64,
    left: bool,
    flags: &'a Vec<u32>,
}

impl<'a> Car<'a> {
    fn speed(&self) -> usize {
        if self.left {
            self.i + 1
        } else {
            self.flags.len() - self.i
        }
    }

    fn dist_to_next(&self) -> u32 {
        if self.left {
            self.flags[self.i + 1] - self.flags[self.i]
        } else {
            self.flags[self.i] - self.flags[self.i - 1]
        }
    }

    fn time_to_next(&self) -> f64 {
        self.dist_to_next() as f64 / self.speed() as f64
    }

    fn go_to_next(&mut self) {
        self.time += self.time_to_next();
        if self.left {
            self.i += 1;
        } else {
            self.i -= 1;
        }
    }
}

fn main() {
    let stdin = stdin();
    let stdout = stdout();
    let mut read = Read::new(stdin.lock());
    let mut out = BufWriter::new(stdout.lock());

    let t = scan!(read, u32);

    for _ in 0..t {
        let (n, l) = scan!(read, usize, u32);

        let flags: Vec<u32> = once(0)
            .chain(read.line().map(|s| s.parse().expect("Failed parse")))
            .chain(once(l))
            .collect();

        let mut left = Car {
            i: 0,
            time: 0.0,
            left: true,
            flags: &flags,
        };
        let mut right = Car {
            i: n + 1,
            time: 0.0,
            left: false,
            flags: &flags,
        };

        while right.i - left.i > 1 {
            if left.time + left.time_to_next() < right.time + right.time_to_next() {
                left.go_to_next();
            } else {
                right.go_to_next();
            }
        }

        let dist_remaining = left.dist_to_next() as f64
            - if left.time < right.time {
                left.speed() as f64 * (right.time - left.time)
            } else {
                right.speed() as f64 * (left.time - right.time)
            };

        let remaining_time = dist_remaining / (left.speed() + right.speed()) as f64;

        let time = f64::max(left.time, right.time) + remaining_time;

        writeln!(out, "{}", time).unwrap();
    }
}
