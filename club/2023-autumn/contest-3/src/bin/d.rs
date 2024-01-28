fn main() {
    let mut s = String::with_capacity(3);
    std::io::stdin().read_line(&mut s).unwrap();
    let s = s.trim();
    for c in s.chars() {
        let count = s.chars().filter(|&x| x == c).count();
        if count == 1 {
            println!("{}", c);
            return;
        }
    }
    println!("-1");
}