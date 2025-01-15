use std::cmp;
use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where
    P: AsRef<Path>,
{
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}

fn main() {
    let mut line_number: Vec<String> = Vec::new();
    if let Ok(lines) = read_lines("./input.txt") {
        for line in lines.map_while(Result::ok) {
            line_number.push(line);
        }
    }
    let number: String = line_number.concat();
    let number_length: usize = 13;
    let mut current_product: u64 = 1;
    let mut current_zeros: u32 = 0;
    for pos in 0..number_length {
        let current_digit: u32 = number.chars().nth(pos).unwrap().to_digit(10).unwrap();
        if current_digit == 0 {
            current_zeros += 1;
        } else {
            current_product *= current_digit as u64;
        }
    }
    let mut maximal_product: u64 = 0;
    if current_zeros == 0 {
        maximal_product = current_product;
    }
    for end_position in (number_length + 1)..=number.len() {
        let start_position: usize = end_position - number_length - 1;
        let current_digit: u32 = number
            .chars()
            .nth(end_position - 1)
            .unwrap()
            .to_digit(10)
            .unwrap();
        let past_digit: u32 = number
            .chars()
            .nth(start_position)
            .unwrap()
            .to_digit(10)
            .unwrap();
        if past_digit == 0 {
            current_zeros -= 1;
        } else {
            current_product /= past_digit as u64;
        }
        if current_digit == 0 {
            current_zeros += 1;
        } else {
            current_product *= current_digit as u64;
        }
        if current_zeros == 0 {
            maximal_product = cmp::max(maximal_product, current_product);
        }
    }
    println!("{maximal_product}");
}
