use std::cmp::min;
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

// plan_id = a*p^0 + b*p^1 + c*p^2 + d*p^3 ... k

fn add_plans(k: usize, p: usize, mut a: usize, mut b: usize) -> usize {
    let mut sum = 0;

    for i in 1..=k {
        let place_value = (p + 1).pow(i as u32);
        let new = a % place_value + b % place_value;
        a -= a % place_value;
        b -= b % place_value;
        sum += min(new, place_value - (p + 1).pow(i as u32 - 1))
    }
    sum
}

struct Plan {
    cost: i64,
    id: usize,
}

fn main() {
    let mut read = Read::new(stdin().lock());

    let (n, k, p) = scan!(read, usize, usize, usize);

    let mut plans: Vec<Plan> = Vec::new();

    for _ in 0..n {
        let arr: Vec<usize> = read.next_arr();
        let mut id = 0;
        for (i, val) in arr.iter().skip(1).enumerate() {
            id += val * (p + 1).pow(i as u32);
        }
        plans.push(Plan {
            cost: arr[0] as i64,
            id,
        });
    }

    let mut dp = vec![-1; (p + 1).pow(k as u32)];

    dp[0] = 0;

    for plan in &plans {
        for base_id in (0..dp.len()).rev() {
            let base_cost = dp[base_id];
            if base_cost == -1 {
                continue;
            }

            let dest_id = add_plans(k, p, base_id, plan.id);
            if dp[dest_id] == -1 || dp[dest_id] > base_cost + plan.cost {
                dp[dest_id] = base_cost + plan.cost;
            }
        }
    }

    println!("{:?}", dp.last().unwrap());
}
