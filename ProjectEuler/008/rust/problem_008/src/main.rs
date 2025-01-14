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

fn get_product(number: &String, start_position: usize, end_position: usize) -> u32 {
    let number_slice: &str = &number[start_position..end_position];
    let mut product: u32 = 1;
    for digit in number_slice.chars() {
        product *= digit as u32;
    }
    return product;
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
    let mut maximal_product: u32 = 0;
    for end_position in (number_length + 1)..=number.len() {
        let start_position: usize = end_position - number_length - 1;
        let product: u32 = get_product(&number, start_position, end_position);
        maximal_product = cmp::max(maximal_product, product);
    }
    println!("{maximal_product}");
}
