fn squares_sum(n: u64) -> u128 {
    (n as u128) * (n as u128 + 1) * (2 * n as u128 + 1) / 6
}

fn integers_sum(n: u64) -> u128 {
    n as u128 * (n as u128 + 1) / 2
}

fn main() {
    let n = 100u64;
    let difference: u128 = integers_sum(n) * integers_sum(n) - squares_sum(n);
    println!("{difference}");
}
