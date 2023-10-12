#![allow(dead_code, unused_imports, unused_macros)]
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


fn expected_steps(prev_expected: f64, back_beauty: u32, fwd_beauty: u32) -> f64 {
    (1.0 + prev_expected) * (fwd_beauty + back_beauty) as f64 / fwd_beauty as f64 + 1.0
}


fn main() {
    //let mut read = Read::new(stdin().lock());
    //let mut out = BufWriter::new(stdout().lock());

    //let (n, m) = scan!(read, usize, usize);

    //let mut dp = vec![vec![0; m + 1]; n];

    //for city in 1..n {
    //    for beauty_sum in 0..m + 1 {
    //        
    //    }
    //}


}
