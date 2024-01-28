use std::io::{BufWriter, stdout, stdin};
use std::io::Write;

const YES: &str = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes";

fn main() {
    let mut out = BufWriter::new(stdout().lock());
    let mut t = String::new();
    stdin().read_line(&mut t).unwrap();
    let t: u32 = t.trim().parse().unwrap();
    let mut s = String::new();

    for _ in 0..t {
        s.clear();
        stdin().read_line(&mut s).unwrap();
        if YES.contains(s.trim()) {
            writeln!(out, "YES").unwrap();
        } else {
            writeln!(out, "NO").unwrap();
        }
    }
}