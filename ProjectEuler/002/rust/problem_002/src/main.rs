fn main() {
    let mut a: u32 = 1;
    let mut b: u32 = 1;
    let n: u32 = 4_000_000;
    let mut sum: u64 = 0;
    while (a + b) <= n {
        sum += (a + b) as u64;
        a += 2 * b;
        b += 2 * (a - b);
    }
    println!("{sum}");
}
