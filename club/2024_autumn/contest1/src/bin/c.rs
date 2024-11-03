use std::io::{stdin, stdout, BufRead, BufWriter, Write};
use std::str::{from_utf8, FromStr};

struct Reader<T: BufRead> {
    inner: T,
    buf: Vec<u8>,
}

impl<T: BufRead> Reader<T> {
    fn new(inner: T) -> Self {
        Self {
            inner,
            buf: Vec::new(),
        }
    }

    fn next_slice(&mut self) -> &[u8] {
        self.buf.clear();
        loop {
            let byte = self.inner.fill_buf().unwrap();
            if byte.is_empty() || byte[0] == b' ' || byte[0] == b'\n' {
                self.inner.consume(1);
                break;
            }
            self.buf.push(byte[0]);
            self.inner.consume(1);
        }
        &self.buf
    }

    fn next<U: FromStr>(&mut self) -> U {
        from_utf8(self.next_slice())
            .unwrap()
            .parse()
            .ok()
            .expect("Couldn't parse token.")
    }
}

fn main() {
    let mut read = Reader::new(stdin().lock());
    let mut out = BufWriter::new(stdout().lock());

    let n: u32 = read.next();

    for _ in 0..n {
        let len: usize = read.next();
        let binary = read.next_slice();
        let ones = binary.iter().filter(|x| **x == b'1').count();

        if ones >= len - ones {
            writeln!(out, "YES").unwrap();
        } else {
            writeln!(out, "NO").unwrap();
        }
    }
}
