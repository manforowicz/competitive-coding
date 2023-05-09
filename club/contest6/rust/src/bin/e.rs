//#![allow(unused_imports, dead_code)]
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

// returns number of elements which must be incremented
fn num_to_increment(arr: &[usize], i: usize, mex: usize) -> usize {
    if arr[i] == mex - 1 {
        return 0;
    }

    let mut left = 0;
    let mut right = i - 1;
    loop {
        let mid = (left + right) / 2;
        if mex - 1 - arr[mid] > i - mid {
            right = mid - 1;
        } else if mex - 1 - arr[mid] < i - mid {
            left = mid + 1;
        } else if mex - 1 - arr[mid] == i - mid {
            return i - mid;
        }
    }
}

// counts number of val starting at index start
fn count_from(arr: &[usize], start: usize, val: usize) -> usize {
    let mut end = start;
    while end < arr.len() && arr[end] == val {
        end += 1;
    }
    end - start
}

fn main() {
    let stdin = stdin();
    let stdout = stdout();
    let mut read = Read::new(stdin.lock());
    let mut out = BufWriter::new(stdout.lock());

    let t = scan!(read, u32);
    for _ in 0..t {
        let n = scan!(read, usize);
        let mut arr = read.next_arr::<usize>();
        arr.sort_unstable();

        write!(out, "{} ", count_from(&arr, 0, 0)).unwrap();

        let mut added = 0;

        let mut i = 0;
        let mut impossible = false;
        for mex in 1..=n {
            while i + 1 < n && arr[i + 1] < mex {
                i += 1;
            }
            if i < mex - 1 {
                impossible = true;
            }
            if impossible {
                write!(out, "-1 ").unwrap();
                continue;
            }

            added += num_to_increment(&arr, i, mex);

            write!(out, "{} ", added + count_from(&arr, i + 1, mex)).unwrap();
        }
        writeln!(out).unwrap();
    }
}
