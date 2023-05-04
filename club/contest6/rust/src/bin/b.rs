use std::io::{stdin, stdout, BufRead, BufWriter, Write};
use std::str::{FromStr, SplitAsciiWhitespace};
use std::iter::once;

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

struct Car {
    i: u32,
    time: f64,
}

impl Car {
    fn get_time_to(next_i: usize, flags: &Vec<u32>) {
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
        let flags = once(0)
            .chain(read.line().map(|s| s.parse().ok().unwrap()))
            .chain(once(l))
            .collect::<Vec<u32>>();
        
        let left = Car { i: 0, time: 0.0 };
        let right = Car { i: l, time: 0.0 };

        while left.i - right.i > 1 {

        }
    }
}
