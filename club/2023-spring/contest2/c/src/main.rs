#[allow(unused_imports)]
use std::collections::HashSet;
use std::io::{stdin, stdout, BufWriter, Write};

fn line<T: std::str::FromStr>() -> Vec<T> {
    let mut input = String::new();
    stdin().read_line(&mut input).expect("Failed read");
    input
        .split_whitespace()
        .rev()
        .map(|s| s.parse().ok().expect("Failed parse"))
        .collect()
}

fn search(world: &Vec<Vec<u32>>, visited: &mut HashSet<u32>, pos: (usize, usize)) -> usize {
    if pos.0 >= world.len() || pos.1 >= world[0].len() || visited.contains(&world[pos.0][pos.1]) {
        0
    } else if pos.0 == world.len() - 1 && pos.1 == world[0].len() - 1 {
        1
    } else {
        visited.insert(world[pos.0][pos.1]);
        let ways =
            search(world, visited, (pos.0 + 1, pos.1)) + search(world, visited, (pos.0, pos.1 + 1));
        visited.remove(&world[pos.0][pos.1]);
        ways
    }
}

fn main() {
    let mut out = BufWriter::new(stdout());

    let [w, h] = line::<usize>()[..2] else {panic!()};

    let mut world: Vec<Vec<u32>> = vec![vec![0; w]; h];

    for row in &mut world {
        *row = line::<u32>();
    }

    let mut visited = HashSet::<u32>::new();
    write!(out, "{}", search(&world, &mut visited, (0, 0))).unwrap();
}
