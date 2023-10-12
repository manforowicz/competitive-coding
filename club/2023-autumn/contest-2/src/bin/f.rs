use std::cmp::max;
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

fn main() {
    let mut read = Read::new(stdin().lock());
    let mut out = BufWriter::new(stdout().lock());
    let t = scan!(read, u32);

    for _ in 0..t {
        let (n, k) = scan!(read, usize, u32);

        let fruits: Vec<u32> = read.next_arr();
        let height: Vec<u32> = read.next_arr();

        let mut l = 0;
        let mut r = 0;

        let mut best_len = 0;

        let mut sum = 0;

        loop {
            sum += fruits[r];

            // advance left pointer
            while sum > k {
                sum -= fruits[l];
                l += 1;
            }

            best_len = max(best_len, r + 1 - l);

            r += 1;

            if r == n {
                break;
            }

            if height[r - 1] % height[r] != 0 {
                l = r;
                sum = 0;
            }
        }

        writeln!(out, "{best_len}").unwrap();
    }
}
