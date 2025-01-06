use std::cmp;

fn is_palindrome(mut n: i32) -> bool {
    let mut digits: Vec<i8> = Vec::new();
    while n > (0 as i32) {
        digits.push((n % 10) as i8);
        n /= 10;
    }
    let size = digits.len();
    let mut left_pointer = 0 as usize;
    let mut right_pointer = size - 1;
    while left_pointer < right_pointer {
        if digits[left_pointer] != digits[right_pointer] {
            return false;
        }
        left_pointer += 1;
        right_pointer -= 1;
    }
    true
}

fn main() {
    let mut ans = 1;
    for a in 100..=999 {
        let mut step = 1;
        let mut b_start = a;
        if a % 11 != 0 {
            step = 11;
            b_start = 11 * ((a + 10) / 11);
        }
        for b in (b_start..1000).step_by(step) {
            let product: i32 = a * b;
            if is_palindrome(product) {
                ans = cmp::max(ans, product);
            }
        }
    }
    println!("{ans}");
}
