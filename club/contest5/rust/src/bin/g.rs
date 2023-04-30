#![allow(unused_imports, dead_code)]
use std::iter::FromIterator;
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

fn get_pow2_above(num: u32) -> u32 {
    let mut pow = 1;
    while pow <= num {
        pow *= 2;
    }
    pow
}

fn main() {
    let stdin = stdin();
    let stdout = stdout();
    let mut read = Read::new(stdin.lock()); // or file
    let mut out = BufWriter::new(stdout.lock());

    let n = scan!(read, usize);
    let arr = read.next_arr::<u32>();

    let mut arr_set = HashMap::<u32, u32>::new();
    for elem in &arr {
        if let Some(count) = arr_set.get_mut(elem) {
            *count += 1;
        } else {
            arr_set.insert(*elem, 1);
        }
    }

    let max_int = *arr.iter().max().unwrap();

    for i in 0..n {
        let mut target = get_pow2_above(arr[i]);
        while target - arr[i] <= max_int {
            //if arr_set.contains(&(target - arr[i])) {
            //    peers[i] += 1;
            //}
            target *= 2;
        }
        
    }


}
