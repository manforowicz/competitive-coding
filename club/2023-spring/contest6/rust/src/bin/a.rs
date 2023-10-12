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
    let stdin = stdin();
    let stdout = stdout();
    let mut read = Read::new(stdin.lock());
    let mut out = BufWriter::new(stdout.lock());

    let t = scan!(read, u32);
    'outer: for _ in 0..t {
        let _n = scan!(read, u32);
        let arr = read.next_arr::<u32>();
        let mut increasing = true;

        for window in arr.windows(2) {
            if increasing && window[0] > window[1] {
                increasing = false;
            } else if !increasing && window[0] < window[1] {
                writeln!(out, "NO").unwrap();
                continue 'outer;
            }
        }
        writeln!(out, "YES").unwrap();
    }
}
