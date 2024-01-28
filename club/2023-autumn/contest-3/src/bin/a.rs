
use std::collections::{HashMap, BTreeSet};
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
    let mut read = Read::new(stdin().lock());
    let mut out = BufWriter::new(stdout().lock());

    let t = scan!(read, u32);

    for _ in 0..t {
        let n = scan!(read, usize);
        let arr: Vec<i64> = read.next_arr();

        let mut chunks = vec![0];

        let mut positivity = arr[0].is_positive();
        for elem in arr {
            if elem == 0 {
                continue;
            }
            if elem.is_positive() != positivity {
                chunks.push(0);
                positivity = elem.is_positive();
            }
            *chunks.last_mut().unwrap() += elem;
        }

        let mut lookup: HashMap<i64, Vec<usize>> = HashMap::new();

        for (i, elem) in chunks.iter().enumerate() {
            if !lookup.contains_key(elem) {
                lookup.insert(*elem, Vec::new());
            }
            lookup.get_mut(elem).unwrap().push(i);
        }

        let tree = BTreeSet::from_iter(chunks.iter().copied());

        let offset = 0;

        while let Some(lowest) = tree.first() {
            
        }
    }
}