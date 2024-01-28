use std::io::{stdin, BufRead};
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

fn get_digit_count(mut num: u64, n: u32) -> [u32; 10] {
    let mut out = [0; 10];

    for _ in 0..n {
        out[(num % 10) as usize] += 1;
        num /= 10;
    }
    out
}

fn a_goes_into_b(a: [u32; 10], b: [u32; 10]) -> bool {
    for (count_a, count_b) in a.iter().zip(b) {
        if *count_a != count_b {
            return false;
        }
    }
    true
}

fn main() {
    let mut read = Read::new(stdin().lock());

    let n = scan!(read, u32);
    let s = scan!(read, u64);

    let lookup = get_digit_count(s, n);

    let mut result = 0;
    let mut a = 0;
    while a * a < 10_u64.pow(n) {
        if a_goes_into_b(get_digit_count(a * a, n), lookup) {
            result += 1;
        }
        a += 1;
    }
    println!("{result}");
}
