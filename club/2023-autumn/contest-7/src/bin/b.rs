fn main() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    let n: u64 = buf.trim().parse().unwrap();

    let mut answer: u64 = 0;

    let mut a = 1;

    while a * a * a <= n {
        let mut b = a;
        while b * b * a <= n {
            let max_c = n / (a * b);
            answer += max_c - b + 1;
            b += 1;
        }
        a += 1;
    }
    println!("{answer}");
}
