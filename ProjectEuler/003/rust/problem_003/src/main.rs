use std::cmp;
fn main() {
    let mut n: i64 = 600_851_475_143;
    let mut prime_factor: i64 = 2;
    let mut largest_prime_factor: i64 = 1;
    while prime_factor * prime_factor <= n {
        if n % prime_factor == 0 {
            largest_prime_factor = cmp::max(largest_prime_factor, prime_factor);
            while n % prime_factor == 0 {
                n /= prime_factor;
            }
        }
        prime_factor += 1;
    }
    if n != 1 {
        largest_prime_factor = cmp::max(largest_prime_factor, n);
    }
    println!("{largest_prime_factor}");
}
