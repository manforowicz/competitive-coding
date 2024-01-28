#![allow(dead_code)]

use std::collections::{HashMap, HashSet};
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

// returns: (distinct_count, elements, in the order in which they first appear)
fn distinct_element_lookup(arr: &Vec<u32>) -> (Vec<usize>, Vec<u32>) {
    let mut set = HashSet::new();
    let mut unique_elems = Vec::new();

    // number of distinct elements in arr[0..=i]
    let mut distinct_count = vec![0; arr.len()];

    for (elem, count) in arr.iter().zip(distinct_count.iter_mut()) {
        if set.insert(elem) {
            unique_elems.push(*elem);
        }
        *count = set.len();
    }

    (distinct_count, unique_elems)
}

fn main() {
    let mut read = Read::new(stdin().lock());
    let mut out = BufWriter::new(stdout().lock());

    let _n = scan!(read, usize);

    let (a_distinct_count, a_unique_elems) = distinct_element_lookup(&read.next_arr());
    let (b_distinct_count, b_unique_elems) = distinct_element_lookup(&read.next_arr());

    let mut first_same = 0;

    while first_same < a_unique_elems.len()
        && first_same < b_unique_elems.len()
        && a_unique_elems[first_same] == b_unique_elems[first_same]
    {
        first_same += 1;
    }

    let q = scan!(read, usize);

    for _ in 0..q {
        let (x, y) = scan!(read, usize, usize);

        writeln!(out, "{} {} {}", a_distinct_count[x-1], b_distinct_count[y-1], first_same).unwrap();
        if a_distinct_count[x - 1] == b_distinct_count[y - 1] && a_distinct_count[x - 1] <= first_same {
            writeln!(out, "Yes").unwrap();
        } else {
            writeln!(out, "No").unwrap();
        }
    }
}
