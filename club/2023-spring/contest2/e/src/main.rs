use std::io::{stdin, stdout, Write};

fn main() {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    let mut vals = s.split_whitespace();

    let mut a = vals.next().unwrap().parse::<u64>().unwrap();
    let mut x = vals.next().unwrap().parse::<u64>().unwrap();
    let m = vals.next().unwrap().parse::<u64>().unwrap();

    // a^0
    // + all_above * (a^1)
    // + all_above * (a^2)
    // + all_above * (a^4)
    // + all_above * (a^8)
    // + ...
    // begins at a^0
    let mut sum = 1;

    // a^0 + a^1 + a^2 + a^3 + ... + a^(x-1)
    // begins at no terms
    let mut result = 0;

    // a^(# of terms already in sequence "result")
    let mut multiplier = 1;

    while x > 0 {
        if x % 2 == 1 {
            result += sum * multiplier;
            multiplier *= a;

            result %= m;
            multiplier %= m;
        }
        sum += a * sum;
        sum %= m;

        a = a * a;
        a %= m;

        x /= 2;
    }

    stdout().write(result.to_string().as_bytes()).unwrap();
}
