#![allow(unused_imports)]
#![allow(dead_code)]
use std::cmp::{max, min};
use std::collections::HashSet;
use std::io::{stdin, stdout, BufWriter, Write};

fn raw_line() -> String {
    let mut s = String::new();
    stdin().read_line(&mut s).expect("Failed read");
    s
}

fn next_line<T: std::str::FromStr>() -> T {
    raw_line().trim().parse().ok().expect("Failed parse")
}

fn next_arr<T: std::str::FromStr>() -> Vec<T> {
    raw_line()
        .split_whitespace()
        .map(|s| s.parse().ok().expect("Failed parse"))
        .collect()
}

#[derive(Copy, Clone)]
struct Pos {
    pos: usize,
    id: usize,
}

fn main() {
    let mut out = BufWriter::new(stdout());

    // PART 1

    let n: usize = next_line();
    let mut segments_left = vec![vec![]; n + 1];
    let mut segments_right = vec![vec![]; n + 1];
    let mut m = 0;

    for left in 1..=n {
        let mut length = 1;
        while left + length - 1 <= n {
            let right = left + length - 1;
            segments_left[left].push(Pos { pos: right, id: m });
            segments_right[right].push(Pos { pos: left, id: m });
            m += 1;
            length *= 2;
        }
    }

    writeln!(out, "{}", m).unwrap();
    for left in 1..=n {
        for right in &segments_left[left] {
            writeln!(out, "{} {}", left, right.pos).unwrap();
        }
    }
    out.flush().unwrap();

    // PART 2

    let q: usize = next_line();

    for _ in 0..q {
        let tmp = next_arr::<usize>();
        let l = tmp[0];
        let r = tmp[1];
        let id1 = segments_left[l][segments_left[l]
            .binary_search_by(|x| x.pos.cmp(&r))
            .unwrap_or_else(|x| x - 1)]
        .id;
        let id2 = segments_right[r][segments_right[r]
            .binary_search_by(|x| x.pos.cmp(&l))
            .unwrap_or_else(|x| x)]
        .id;
        writeln!(out, "{} {}", id1 + 1, id2 + 1).unwrap();
        out.flush().unwrap();
    }
}
