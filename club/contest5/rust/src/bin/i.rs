use std::cmp::max;
use std::io::{stdin, BufRead};
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
    let mut read = Read::new(stdin.lock());

    let (n, _k) = scan!(read, usize, usize);
    let actions = read.next_arr::<usize>();

    // Maximum number of stones person who moves first
    // can gain if the pile starts with i stones,
    let mut dp = vec![0; n+1];

    for i in 1..=n {
        let mut max_gain = 0;
        for action in &actions {
            if *action <= i {
                let gain = i - dp[i - action];
                max_gain = max(max_gain, gain);
            }
        }
        dp[i] = max_gain;
    }
    println!("{}", dp[n]); 
}
