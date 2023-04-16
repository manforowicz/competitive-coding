#![allow(unused_imports, dead_code)]
use std::cmp::{max, min};
use std::collections::*;
use std::fs::File;
use std::io::*;

struct Scan<T: BufRead>(T);

impl<T: BufRead> Scan<T> {
    fn raw_line(&mut self) -> String {
        let mut s = String::new();
        self.0.read_line(&mut s).expect("Failed read");
        s
    }

    fn next_line<U: std::str::FromStr>(&mut self) -> U {
        self.raw_line().trim().parse().ok().expect("Failed parse")
    }

    fn next_arr<U: std::str::FromStr>(&mut self) -> Vec<U> {
        self.raw_line()
            .split_ascii_whitespace()
            .map(|s| s.parse().ok().expect("Failed parse"))
            .collect()
    }
}

impl Scan<std::io::StdinLock<'static>> {
    fn stdin() -> Self {
        Self(stdin().lock())
    }
}

impl Scan<BufReader<File>> {
    fn file(filename: &str) -> Self {
        Self(BufReader::new(
            File::open(filename).expect("Couldn't open file"),
        ))
    }
}

fn main() {
    let mut out = BufWriter::new(stdout());
    let mut scan = Scan::stdin();
    let t: u32 = scan.next_line();

    for _ in 0..t {
        let n = scan.next_line::<usize>();
        let b = scan.next_arr::<i64>();

        // answer on subarray 0..i
        let mut dp: Vec<i64> = vec![1; n];

        // (sum from a[0]..a[i]), (greatest index where it ends)
        let mut sums = HashMap::<i64, usize>::new();
        sums.insert(0, 0);
        let mut sum = b[0];
        for i in 1..n {
            dp[i] = dp[i - 1] * 2;

            if let Some(index) = sums.get(&sum) {
                dp[i] -= dp[*index];
            }
            dp[i] += 1000000007;
            dp[i] %= 1000000007;
            sums.insert(sum, i - 1);
            sum += b[i];
        }
        writeln!(out, "{}", dp[n - 1]).unwrap();
    }
}
