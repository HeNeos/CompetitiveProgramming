fn isqrt(n: u64) -> u32 {
    let x: f64 = (n as f64).sqrt();
    x as u32
}

fn sieve(n: u32) -> (Vec<u32>, Vec<u64>) {
    let mut is_prime: Vec<bool> = vec![true; n as usize + 1];
    let mut primes: Vec<u32> = Vec::new();
    let mut primes_sum: Vec<u64> = vec![0; n as usize + 1];
    for number in 2..=n {
        if is_prime[number as usize] {
            let mut multiple: u64 = number as u64 * number as u64;
            primes.push(number as u32);
            primes_sum[number as usize] = primes_sum[(number - 1) as usize] + number as u64;
            while multiple <= n as u64 {
                is_prime[multiple as usize] = false;
                multiple += number as u64;
            }
        } else {
            primes_sum[number as usize] = primes_sum[(number - 1) as usize];
        }
    }
    (primes, primes_sum)
}

fn lucy(n: u64, prime_index: i32, primes: &Vec<u32>, primes_sum: &Vec<u64>) -> u128 {
    if prime_index == -1 {
        return n as u128 * (n as u128 + 1) / 2 - 1;
    }
    let prime: u128 = primes[prime_index as usize] as u128;
    if prime * prime >= n as u128 {
        if n < primes_sum.len() as u64 {
            return primes_sum[n as usize] as u128;
        }
        return lucy(n, prime_index - 1, primes, primes_sum);
    }
    lucy(n, prime_index - 1, primes, primes_sum)
        - prime
            * (lucy(n / prime as u64, prime_index - 1, primes, primes_sum)
                - lucy(prime as u64 - 1, prime_index - 1, primes, primes_sum))
}

fn pi(n: u32, primes: &Vec<u32>) -> u32 {
    let mut left: usize = 0;
    let mut right: usize = primes.len() - 1;
    while left < right {
        let mid = left + (right - left + 1) / 2;
        if primes[mid] <= n {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    left as u32
}

fn main() {
    let n: u64 = 2_000_000;
    let n_sqrt: u32 = isqrt(n);
    let (primes, primes_sum) = sieve(n_sqrt);
    let ans: u128 = lucy(n, pi(n_sqrt, &primes) as i32, &primes, &primes_sum);
    println!("{ans}");
}
