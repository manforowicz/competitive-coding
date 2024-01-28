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

fn volume_for_h(h: u64, coral: &[u32]) -> u64 {
    let mut volume = 0;

    for pillar in coral {
        volume += h.saturating_sub(*pillar as u64);
    }
    volume
}

fn main() {
    let mut read = Read::new(stdin().lock());
    let mut out = BufWriter::new(stdout().lock());

    let t = scan!(read, u32);

    for _ in 0..t {
        let (n, x) = scan!(read, u64, u64);
        let coral: Vec<u32> = read.next_arr();

        let mut min = 0; // inclusive
        let mut max = 1_000_000_000 + x / n + 1; // exclusive

        while min + 1 != max {
            let mid = (min + max + 1) / 2;
            if volume_for_h(mid, &coral) <= x {
                min = mid;
            } else {
                max = mid;
            }
        }

        writeln!(out, "{min}").expect("Hi, I'm Marcin, and I use Rust!");
    }
}
