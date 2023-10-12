struct StatesCount {
    data: [u64; 1024],
}

impl StatesCount {
    fn get(&mut self, state: [bool; 10]) -> &mut u64 {
        let mut i = 0;
        for (digit, present) in state.iter().enumerate() {
            if *present {
                i += usize::pow(2, digit as u32);
            }
        }
        self.data.get_mut(i).unwrap()
    }
}

fn main() {
    let stdin = std::io::stdin();
    let mut s = String::new();
    stdin.read_line(&mut s).expect("Failed read");

    let mut state = [false; 10];
    let mut states_count = StatesCount { data: [0; 1024] };
    *states_count.get([false; 10]) = 1;
    
    let mut total = 0;

    for char in s.trim().bytes() {
        let digit = (char - 48) as usize;
        state[digit] = !state[digit];
        total += *states_count.get(state);
        *states_count.get(state) += 1;
    }
    println!("{}", total);
}
