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

// searches for characters of small, in big.
fn max_substr_len<'a>(
    small: impl Iterator<Item = &'a u8>,
    big: impl Iterator<Item = &'a u8>,
) -> usize {
    let mut small = small.peekable();
    let mut len = 0;
    for c in big {
        if let Some(&next) = small.peek() {
            if c == next {
                len += 1;
                small.next();
            }
        } else {
            break;
        }
    }
    len
}

fn main() {
    let mut read = Read::new(stdin().lock());

    let (n, t) = scan!(read, usize, String);

    let t = t.trim().as_bytes();

    let mut strings = vec![vec![]; n];

    let mut info = vec![(0, 0); n];
    for (string, tup) in &mut strings.iter_mut().zip(info.iter_mut()) {
        read.buf.read_until(b'\n', string).unwrap();
        string.pop();

        tup.0 = max_substr_len(t.iter(), string.iter());
        tup.1 = max_substr_len(t.iter().rev(), string.iter().rev())
    }

    info.sort();

    let mut answer: u64 = 0;
    for (_, b) in &info {
        let mismatches = info.partition_point(|(a, _)| a + b < t.len()) as u64;
        answer += info.len() as u64 - mismatches;
    }

    println!("{}", answer);
}
