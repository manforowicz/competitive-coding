#![allow(unused_imports, dead_code, unused_macros)]
use std::collections::*;
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

fn get_prime_factors(mut num: usize, primes: &mut Vec<usize>, sieve: &Vec<usize>) {
    primes.clear();
    while num != 1 {
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
            for multiple in 1..=(sieve.len() - 1) / i {
                sieve[i * multiple] = i;
            }
        }
    }
    sieve
}

#[derive(Clone, Default, Debug)]
struct Link {
    spider_i: usize,
    dest: usize,
}

fn main() {
    let stdin = stdin();
    let stdout = stdout();
    let mut read = Read::new(stdin.lock());
    let mut out = BufWriter::new(stdout.lock());

    let _n = scan!(read, usize);
    let spiders = read.next_arr::<usize>();
    let max_legs = *spiders.iter().max().unwrap();
    let sieve = generate_sieve(max_legs);

    let mut links = vec![Vec::<Link>::new(); max_legs + 1];
    let mut primes = Vec::new();
    for spider_i in 0..spiders.len() {
        get_prime_factors(spiders[spider_i], &mut primes, &sieve);
        for (i, first) in primes.iter().enumerate() {
            for second in primes[i + 1..].iter() {
                links[*first].push(Link {
                    spider_i,
                    dest: *second,
                });
                links[*second].push(Link {
                    spider_i,
                    dest: *first,
                });
            }
        }
    }

    let (s, t) = scan!(read, usize, usize);
    let mut s_primes = Vec::new();
    get_prime_factors(spiders[s - 1], &mut s_primes, &sieve);
    let mut t_primes = Vec::new();
    get_prime_factors(spiders[t - 1], &mut t_primes, &sieve);

    let mut visited = vec![false; max_legs + 1];
    let mut came_from = vec![Link::default(); max_legs + 1];
    let mut curr = VecDeque::from(t_primes.clone());
    let mut ending = None;

    while !curr.is_empty() {
        let node = curr.pop_front().unwrap();

        if s_primes.contains(&node) {
            ending = Some(node);
            break;
        }
        for link in &links[node] {
            if !visited[link.dest] {
                visited[link.dest] = true;
                came_from[link.dest] = Link {
                    spider_i: link.spider_i,
                    dest: node,
                };
                curr.push_back(link.dest);
            }
        }
    }

    if s == t {
        writeln!(out, "1\n{}", s).unwrap();
    } else if let Some(mut node) = ending {
        let mut path = Vec::new();
        while !t_primes.contains(&node) {
            path.push(came_from[node].spider_i + 1);
            node = came_from[node].dest;
        }

        writeln!(out, "{}", path.len() + 2).unwrap();
        write!(out, "{} ", s).unwrap();
        for spider in path {
            write!(out, "{} ", spider).unwrap();
        }
        writeln!(out, "{} ", t).unwrap();
    } else {
        writeln!(out, "-1").unwrap();
    }
}
