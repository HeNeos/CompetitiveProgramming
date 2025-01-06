fn triangular_sum(n: i64) -> i128 {
    (n as i128) * ((n + 1) as i128) / 2
}

fn main() {
    let n: i64 = 1000 - 1;
    let ans: i128 =
        3 * triangular_sum(n / 3) + 5 * triangular_sum(n / 5) - 15 * triangular_sum(n / 15);
    println!("{ans}");
}
