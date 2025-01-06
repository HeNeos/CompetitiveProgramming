fn main() {
    let mut a: i32 = 1;
    let mut b: i32 = 1;
    let n: i32 = 4_000_000;
    let mut sum: i64 = 0;
    let mut counter: i8 = 0;
    while b <= n {
        if counter == 1 {
            counter -= 3;
            sum += b as i64;
        }
        b = a + b;
        a = b - a;
        counter += 1;
    }
    println!("{sum}");
}
