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

    fn next<U: FromStr>(&mut self) -> U {
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
        let str = from_utf8(&self.buf).unwrap();
        str.parse().ok().expect("Couldn't parse token.")
    }
}

fn main() {
    let mut read = Reader::new(stdin().lock());
    let mut out = BufWriter::new(stdout().lock());

    let n: usize = read.next();
    let q: u32 = read.next();

    let mut prefix1 = Vec::with_capacity(n + 1);
    let mut prefix2 = Vec::with_capacity(n + 1);
    let mut prefix3 = Vec::with_capacity(n + 1);

    prefix1.push(0);
    prefix2.push(0);
    prefix3.push(0);

    for i in 0..n {
        prefix1.push(prefix1[i]);
        prefix2.push(prefix2[i]);
        prefix3.push(prefix3[i]);
        match read.next() {
            1 => prefix1[i + 1] += 1,
            2 => prefix2[i + 1] += 1,
            3 => prefix3[i + 1] += 1,
            _ => panic!(),
        }
    }

    for _ in 0..q {
        let l: usize = read.next();
        let r: usize = read.next();

        let count1 = prefix1[r] - prefix1[l - 1];
        let count2 = prefix2[r] - prefix2[l - 1];
        let count3 = prefix3[r] - prefix3[l - 1];

        writeln!(out, "{count1} {count2} {count3}").unwrap();
    }
}
