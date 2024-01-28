use std::io::stdin;

const MOD: u64 = 998244353;

fn exp(mut base: u64, mut pow: u64) -> u64 {
    base %= MOD;
    let mut result = 1;

    while pow != 0 {
        if pow % 2 == 1 {
            result = result * base % MOD;
        }
        base = base * base % MOD;

        pow /= 2;
    }
    result
}

fn inverse(value: u64) -> u64 {
    exp(value, MOD - 2)
}

fn factorial(value: u64) -> u64 {
    let mut result = 1;
    for i in 1..=value {
        result = result * i % MOD;
    }
    result
}

fn total_ordered_subsets(len: u64) -> u64 {
    if len == 1 {
        1
    } else {
        len * (1 + total_ordered_subsets(len - 1))
    }
    
}

fn main() {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    let s = s.trim().as_bytes();

    println!("{}", total_ordered_subsets(5));

    let mut result = total_ordered_subsets(s.len() as u64);

    println!("{result}");

    let mut letter_count = [0; 26];

    for c in s {
        letter_count[(c - b'a') as usize] += 1;
    }

    for count in letter_count {
        if count != 0 {
            println!("{}", factorial(count));
            result = result * inverse(factorial(count)) % MOD;
        }
    }

    println!("{result}");

    
}