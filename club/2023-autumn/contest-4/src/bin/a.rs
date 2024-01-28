#![allow(clippy::if_same_then_else)]
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


fn furthest_greater_than(mut min_i: usize, value: i64, lookup: &[i64]) -> usize {

    let mut max_i = lookup.len() - 1;

    while min_i != max_i {
        let mid = (min_i + max_i + 1) / 2;
        if lookup[mid] > value {
            min_i = mid;
        } else {
            max_i = mid - 1;
        }

    }
    min_i
}

fn main() {
    let mut read = Read::new(stdin().lock());
    let mut out = BufWriter::new(stdout().lock());


    let t = scan!(read, u32);

    for _ in 0..t {
        let n = scan!(read, usize);
        let arr: Vec<i64> = read.next_arr();
        
        // prefix sum of array
        let mut prefix = vec![0];
        let mut prev = 0;
        for elem in &arr {
            prev += elem;
            prefix.push(prev);
        }


        // greatest[i] = greatest element in prefix[i..]
        let mut greatest = vec![0; prefix.len()];
        let mut max = prefix[prefix.len() - 1];
        for i in (0..prefix.len()).rev() {
            if prefix[i] > max {
                max = prefix[i];
            }
            greatest[i] = max;
        }


        let mut i = 0;
        let mut skips = 0;
        while i < prefix.len() {
            write!(out, "({i}, ");
            i = furthest_greater_than(i, prefix[i], &greatest);
            writeln!(out, "{i})");

            if i < arr.len() {
                if arr[i] < 0 {
                    skips += 2;
                } else if arr[i] == 0 {
                    skips += 1;
                }
            }

            i += 1;
        }

        let answer = n as i32 - skips;
        writeln!(out, "{}", answer).unwrap();
    }
}