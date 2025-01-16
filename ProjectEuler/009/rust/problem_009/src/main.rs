fn isqrt(x: u32) -> u32 {
    let y: f64 = (x as f64).sqrt();
    y as u32
}

fn main() {
    for sum in 501u32..=666u32 {
        let sum_squares: u32 = sum * sum;
        let product: u32 = 2000 * sum - 1_000_000;
        let difference_square: u32 = sum_squares - 4 * product;
        let difference: u32 = isqrt(difference_square);
        if difference * difference == difference_square {
            let mut b: u32 = difference + sum;
            let mut a: u32 = b - 2 * difference;
            if b % 2 == 0 && a % 2 == 0 {
                b /= 2;
                a /= 2;
                let c: u32 = 1000 - a - b;
                println!("{a}*{b}*{c}={product}");
            }
        }
    }
}
