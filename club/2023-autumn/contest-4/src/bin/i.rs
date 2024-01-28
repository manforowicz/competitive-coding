use std::io::stdin;

fn character(character: u8) -> usize {
    (character - b'a') as usize
}

fn main() {
    let mut s = String::new();
    let mut t = String::new();
    stdin().read_line(&mut s).unwrap();
    stdin().read_line(&mut t).unwrap();

    let s = s.trim().as_bytes();
    let t = t.trim().as_bytes();

    let mut lookup = [(); 26].map(|_| Vec::new());

    for (i, byte) in s.iter().enumerate() {
        lookup[character(*byte)].push(i);
    }

    let mut spot = 0;
    let mut cycles = 0;
    for c in t {
        if lookup[character(*c)].is_empty() {
            println!("-1");
            return;
        }
        let i = lookup[character(*c)].partition_point(|&elem| elem < spot);
        spot = if i == lookup[character(*c)].len() {
            cycles += 1;
            lookup[character(*c)][0]
        } else {
            lookup[character(*c)][i]
        } + 1;
    }

    println!("{}", cycles * s.len() as u64 + spot as u64);
}