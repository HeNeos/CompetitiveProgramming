use cached::proc_macro::cached;
use cached::UnboundCache;

fn sieve(n: u8) -> (Vec<u32>, Vec<u32>) {
    let mut is_prime: Vec<bool> = vec![true; n as usize + 1];
    let mut primes: Vec<u32> = Vec::new();
    let mut pi: Vec<u32> = vec![0; n as usize + 1];
    for number in 2..=n {
        if is_prime[number as usize] {
            let mut multiple: u32 = number as u32 * number as u32;
            primes.push(number as u32);
            pi[number as usize] = pi[(number - 1) as usize] + 1;
            while multiple as u8 <= n {
                is_prime[multiple as usize] = false;
                multiple += number as u32;
            }
        } else {
            pi[number as usize] = pi[(number - 1) as usize];
        }
    }
    (primes, pi)
}

fn max_power_in_factorial(mut n: u8, prime: u8) -> u128 {
    let mut power: u128 = 1 as u128;
    let prime_square: u8 = prime * prime;
    while n >= prime_square {
        n /= prime_square;
        power *= prime_square as u128;
    }
    if n >= prime {
        power *= prime as u128;
    }
    power
}

fn build_factorials(n: u8) -> Vec<u128> {
    let mut f: Vec<u128> = vec![1; n as usize + 1];
    f[0] = 1;
    for i in 1..=n {
        f[i as usize] = f[(i - 1) as usize] * i as u128;
    }
    f
}

#[cached(
    type = "UnboundCache<(u8, i32), u8>",
    create = "{ UnboundCache::new() }",
    convert = r#"{ (n, prime_index) }"#
)]
fn lucy_pi(n: u8, prime_index: i32, primes: &Vec<u32>) -> u8 {
    if prime_index == -1 {
        return n - 1;
    }
    let prime: u32 = primes[prime_index as usize];
    if prime * prime > n as u32 {
        return lucy_pi(n, prime_index - 1, primes);
    }
    lucy_pi(n, prime_index - 1, primes)
        - (lucy_pi(n / prime as u8, prime_index - 1, primes)
            - lucy_pi(prime as u8 - 1, prime_index - 1, primes))
}

fn pi(n: u8, pi_sqrt: &Vec<u32>, primes: &Vec<u32>) -> u8 {
    if primes[primes.len() as usize - 1] < n as u32 {
        return lucy_pi(
            n,
            pi((n as f32).sqrt() as u8, pi_sqrt, primes) as i32 - 1,
            primes,
        );
    }
    if primes[0] > n as u32 {
        return 0;
    }
    pi_sqrt[n as usize] as u8
}

#[cached(
    type = "UnboundCache<(u8, i32), u128>",
    create = "{ UnboundCache::new() }",
    convert = r#"{ (n, prime_index) }"#
)]
fn lucy_primorial(
    n: u8,
    prime_index: i32,
    primes: &Vec<u32>,
    pi_sqrt: &Vec<u32>,
    factorials: &Vec<u128>,
) -> u128 {
    if prime_index == -1 {
        return factorials[n as usize];
    }
    let current_prime: u32 = primes[prime_index as usize];
    let numerator: u128 = lucy_primorial(n, prime_index - 1, primes, pi_sqrt, factorials);
    if current_prime * current_prime > n as u32 {
        return numerator;
    }
    let mut denominator: u128 = lucy_primorial(
        n / current_prime as u8,
        prime_index - 1,
        primes,
        pi_sqrt,
        factorials,
    ) / lucy_primorial(
        current_prime as u8 - 1,
        prime_index - 1,
        primes,
        pi_sqrt,
        factorials,
    );
    denominator *= (current_prime as u128).pow(
        lucy_pi(n / current_prime as u8, prime_index - 1, primes) as u32
            - lucy_pi(current_prime as u8 - 1, prime_index - 1, primes) as u32,
    );
    numerator / denominator
}

fn main() {
    let n: u8 = 20;
    let n_sqrt: u8 = (n as f64).sqrt() as u8;
    let (primes, pi_sqrt) = sieve(n_sqrt);
    let factorials: Vec<u128> = build_factorials(n);
    let mut ans: u128 = lucy_primorial(
        n,
        pi(n_sqrt, &pi_sqrt, &primes) as i32 - 1,
        &primes,
        &pi_sqrt,
        &factorials,
    );
    for prime in &primes {
        ans /= *prime as u128;
        ans *= max_power_in_factorial(n, *prime as u8);
    }
    println!("{0}", ans);
}
