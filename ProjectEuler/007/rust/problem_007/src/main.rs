fn calculate_upper_bound(n: u32) -> u32 {
    let mut right: u64 = n as u64 * n as u64;
    let mut left: u64 = 2 * n as u64 - 1;
    while left < right {
        let mid = left + (right - left + 1) / 2;
        if (mid as f64 / (mid as f64).ln()) as u64 <= n as u64 {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    left as u32 * 2
}

fn sieve(n: u32) -> Vec<u32> {
    let mut is_prime: Vec<bool> = vec![true; n as usize + 1];
    let mut primes: Vec<u32> = Vec::new();
    for number in 2..=n {
        if is_prime[number as usize] {
            primes.push(number);
            let mut multiplier: u64 = number as u64 * number as u64;
            while multiplier <= n as u64 {
                is_prime[multiplier as usize] = false;
                multiplier += number as u64;
            }
        }
    }
    primes
}

fn main() {
    let n = 10_001u32;
    let max_n = calculate_upper_bound(n);
    let primes: Vec<u32> = sieve(max_n);
    let prime = primes[n as usize - 1];
    println!("{prime}");
}
