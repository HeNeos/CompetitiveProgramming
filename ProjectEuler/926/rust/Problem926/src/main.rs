const MAX_N: u32 = 10_000_005;
const MOD: u64 = 1_000_000_007;

fn sieve() -> Vec<u32> {
    let mut is_prime = vec![true; (MAX_N + 1) as usize];
    let mut primes = Vec::new();
    for number in 2..=MAX_N {
        if is_prime[number as usize] {
            primes.push(number);
            let mut multiple: u64 = number as u64 * number as u64;
            while multiple <= MAX_N as u64 {
                is_prime[multiple as usize] = false;
                multiple += number as u64;
            }
        }
    }
    primes
}

fn factorize_factorial(n: u32, primes: &Vec<u32>) -> Vec<(u32, u32)> {
    let mut factorization: Vec<(u32, u32)> = Vec::new();
    for prime in primes {
        if *prime > n {
            break;
        }
        let mut power: u32 = 0;
        let mut n_copy: u32 = n;
        while n_copy > 0 {
            n_copy /= *prime;
            power += n_copy;
        }
        factorization.push((*prime, power));
    }
    factorization
}

fn main() {
    let n: u32 = 10_000_000;
    let mut ans: u64 = 0;
    let primes: Vec<u32> = sieve();
    let factorial_factorization: Vec<(u32, u32)> = factorize_factorial(n, &primes);
    let max_possible_roundness: u32 = factorial_factorization[0].1;
    for roundness in 1..=max_possible_roundness {
        let mut x: u64 = 1;
        for factor in &factorial_factorization {
            if factor.1 < roundness {
                break;
            }
            x *= factor.1 as u64 / roundness as u64 + 1;
            x %= MOD;
        }
        ans += x - 1;
        ans %= MOD;
    }
    println!("{ans}");
}
