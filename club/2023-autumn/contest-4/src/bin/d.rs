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

#[derive(Clone)]
struct Link {
    dest: usize,
    beauty: u32,
    cost: u32,
}

// returns optimal (beauty, cost) if this path leads to destination
fn dfs(nodes: &[Vec<Link>], visited: &mut [bool], curr: usize, goal: usize) -> Option<(u32, u32)> {
    if visited[curr] {
        return None;
    } else if curr == goal {
        return Some((0, 0));
    }
    visited[curr] = true;

    let mut best = None;

    for link in &nodes[curr] {
        if let Some((b, c)) = dfs(nodes, visited, link.dest, goal) {
            let (b, c) = (b + link.beauty, c + link.cost);
            if let Some((best_b, best_c)) = best {
                if b as f64 / c as f64 > best_b as f64 / best_c as f64 {
                    best = Some((b, c));
                }
            } else {
                best = Some((b, c));
            }
        }
    }
    visited[curr] = false;
    best
}

fn main() {
    let mut read = Read::new(stdin().lock());

    let (n, m) = scan!(read, usize, u32);

    let mut nodes = vec![vec![]; n];

    for _ in 0..m {
        let (u, v, beauty, cost) = scan!(read, usize, usize, u32, u32);
        println!("{u}, {v}, {beauty}, {cost}");
        nodes[u - 1].push(Link {
            dest: v - 1,
            beauty,
            cost,
        });
    }

    let mut visited = vec![false; n];

    let Some((beauty, cost)) = dfs(&nodes, &mut visited, 0, n - 1) else {
        panic!("Hi, I'm Marcin, and now is a time to PANIC!")
    };

    println!("{}", beauty as f64 / cost as f64);
}
