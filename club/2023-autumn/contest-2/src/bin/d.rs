#![allow(dead_code)]
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

fn main() {
    let mut read = Read::new(stdin().lock());
    let mut out = BufWriter::new(stdout().lock());

    let (_n, _m) = scan!(read, u32, u32);

    let s = scan!(read, String);
    let t = scan!(read, String);

    let prefix = t.starts_with(&s);
    let suffix = t.ends_with(&s);

    if prefix && suffix {
        write!(out, "0").unwrap();
    } else if prefix {
        write!(out, "1").unwrap();
    } else if suffix {
        write!(out, "2").unwrap();
    } else {
        write!(out, "3").unwrap();
    }
    out.flush().unwrap();
}
