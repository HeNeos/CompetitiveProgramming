use std::cmp;
use std::collections::HashMap;

const MAX_N: u32 = 10_000_005;

fn sieve() -> Vec<u32> {
    let mut least_prime_factor = vec![0; (MAX_N + 1) as usize];
    least_prime_factor[1] = 1;
    for number in 2..=MAX_N {
        if least_prime_factor[number as usize] == 0 {
            least_prime_factor[number as usize] = number;
            let mut multiple: u64 = number as u64 * number as u64;
            while multiple <= MAX_N as u64 {
                if least_prime_factor[multiple as usize] == 0 {
                    least_prime_factor[multiple as usize] = number;
                }
                multiple += number as u64;
            }
        }
    }
    least_prime_factor
}

fn factorize(mut n: u32, least_prime_factor: &Vec<u32>) -> Vec<(u32, u32)> {
    let mut prime_factors: Vec<(u32, u32)> = Vec::new();
    while n > 1 {
        let divisor = least_prime_factor[n as usize];
        let mut counter = 0;
        while n % divisor == 0 {
            n /= divisor;
            counter += 1;
        }
        prime_factors.push((divisor, counter));
    }
    prime_factors
}

fn factorize_factorial(n: u32, least_prime_factor: &Vec<u32>) -> HashMap<u32, u32> {
    let mut factorization: HashMap<u32, u32> = HashMap::new();
    for number in 2..=n {
        let number_factors: Vec<(u32, u32)> = factorize(number, least_prime_factor);
        for factor in number_factors {
            let current_exponent = factorization.get(&factor.0).unwrap_or(&0);
            factorization.insert(factor.0, *current_exponent + factor.1);
        }
    }
    factorization
}

fn roundness(factorization: HashMap<u32, u32>, base_factors: Vec<(u32, u32)>) -> u32 {
    let mut roundness: u32 = u32::MAX;
    for factor in base_factors {
        let factor_base = factor.0;
        let factor_exponent = factor.1;
        let factorization_exponent = factorization.get(&factor_base).unwrap_or(&0);
        roundness = cmp::min(roundness, *factorization_exponent / factor_exponent);
    }
    roundness
}

fn main() {
    let least_prime_factor: Vec<u32> = sieve();
    let factorial_factorization: HashMap<u32, u32> = factorize_factorial(10, &least_prime_factor);
    let base: u32 = 12;
    let base_factors: Vec<(u32, u32)> = factorize(base, &least_prime_factor);

    let round: u32 = roundness(factorial_factorization, base_factors);
    println!("{round}");
}
