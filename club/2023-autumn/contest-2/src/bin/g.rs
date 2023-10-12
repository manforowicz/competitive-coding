use std::io::{stdin, stdout, BufRead, BufWriter, Write};
use std::str::SplitAsciiWhitespace;

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

// euclidean algorithm
fn gcd(a: u64, b: u64) -> u64 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn main() {
    let mut read = Read::new(stdin().lock());
    let mut out = BufWriter::new(stdout().lock());
    let t = scan!(read, u32);

    for _ in 0..t {
        let (n, m) = scan!(read, u64, u64);


        // each person gets (a / b) of an apple
        let gcd = gcd(n, m);
        let mut a = n / gcd;
        let b = m / gcd;

        // not possible if b isn't a power of 2
        if !b.is_power_of_two() {
            writeln!(out, "-1").unwrap();
            continue;
        }

        // all whole apples require no cuts. ignore them.
        a %= b;

        let mut place_value = b / 2;
        let mut cuts = 0;

        while place_value != 0 {
            // cuts per piece = (1 - place_value / b)
            // cost += m * (1 - place_value / b)
            if place_value <= a {
                cuts += m - m * place_value / b;
                a -= place_value;
            }
            place_value /= 2;
        }
        writeln!(out, "{cuts}").unwrap();
    }
}