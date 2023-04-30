#![allow(unused_imports, dead_code, unused_macros)]
use std::cmp::{max, min};
use std::collections::*;
use std::fs::File;
use std::io::{stdin, stdout, BufRead, BufReader, BufWriter, Write};
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

fn get_prime_factors(mut num: usize, primes: &mut Vec<usize>, sieve: &Vec<usize>) {
    primes.clear();
    while sieve[num] != 0 {
        let prime_factor = sieve[num];
        primes.push(prime_factor);
        while num % prime_factor == 0 {
            num /= prime_factor;
        }
    }
}

fn generate_sieve(max: usize) -> Vec<usize> {
    let mut sieve = vec![0; max + 1];

    for i in 2..sieve.len() {
        if sieve[i] == 0 {
            for multiple in 1..sieve.len() / i {
                sieve[i * multiple] = i;
            }
        }
    }
    sieve
}

fn main() {
    let stdin = stdin();
    let stdout = stdout();
    let mut read = Read::new(stdin.lock()); // or file
    let mut out = BufWriter::new(stdout.lock());

    let _n = scan!(read, usize);
    let spiders = read.next_arr::<usize>();
    let max_legs = *spiders.iter().max().unwrap();

    let sieve = generate_sieve(max_legs);

    let mut links = vec![Vec::<usize>::new(); max_legs + 1];

    let mut prime_factors = Vec::new();

    for legs in &spiders {
        get_prime_factors(*legs, &mut prime_factors, &sieve);
        for i in 0..prime_factors.len() {
            for j in i + 1..prime_factors.len() {
                links[i].push(j);
                links[j].push(i);
            }
        }
    }

    let (s, t) = scan!(read, usize, usize);
    let mut s_primes = Vec::new();
    get_prime_factors(spiders[s + 1], &mut s_primes, &sieve);
    let mut t_primes = Vec::new();
    get_prime_factors(spiders[t + 1], &mut t_primes, &sieve);

    let mut visited = vec![false; max_legs + 1];
    let mut came_from = vec![0; max_legs + 1];

    let mut curr = VecDeque::from(t_primes);

    let mut success = false;

    while !curr.is_empty() {
        let node = curr.pop_front().unwrap();

        if s_primes.contains(&node) {
            success = true;
            let mut path = Vec::new();
            let mut backtrack = node;
            while came_from[backtrack] != 0 {
                path.push(backtrack);
                backtrack = came_from[backtrack];
            }
        }

        for link in &links[node] {
            if !visited[*link] {
                visited[*link] = true;
                came_from[*link] = node;
                curr.push_back(*link);
            }
        }
    }

    if success {

    }
}
