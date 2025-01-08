use std::collections::HashMap;

struct Solver {
    a_cache: HashMap<i64, i128>,
    s_cache: HashMap<i64, i128>,
}

impl Solver {
    fn new() -> Self {
        let mut a_cache = HashMap::new();
        a_cache.insert(1, 1);

        let mut s_cache = HashMap::new();
        s_cache.insert(1, 1);

        Solver { a_cache, s_cache }
    }

    fn a(&mut self, n: i64) -> i128 {
        if let Some(&value) = self.a_cache.get(&n) {
            return value;
        }
        let result = if n % 2 == 0 {
            2i128 * self.a(n / 2)
        } else {
            self.a((n - 1) / 2) - 3i128 * self.a((n + 1) / 2)
        };
        self.a_cache.insert(n, result);
        result
    }

    fn s(&mut self, n: i64) -> i128 {
        if let Some(&value) = self.s_cache.get(&n) {
            return value;
        }
        let result = if n % 2 == 0 {
            -self.a(n / 2)
        } else {
            -3i128 * self.a(n / 2 + 1)
        } + 4i128 * self.a(1);
        self.s_cache.insert(n, result);
        result
    }
}

fn main() {
    let mut solver = Solver::new();
    let value = solver.s(10i64.pow(12));

    println!("{value}");
}
