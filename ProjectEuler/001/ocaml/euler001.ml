let limit : int = 1000 - 1
let divisor_1 : int = 3
let divisor_2 : int = 5
let triangular_sum (n : int) : int = n * (n + 1) / 2
let sum divisor = divisor * triangular_sum (limit / abs divisor)

let rec fold_left (f : int -> int) (acc : int) (lst : int list) =
  match lst with
  | [] -> acc
  | head :: tail -> fold_left f (acc + f head) tail
;;

let divisors = [ divisor_1; divisor_2; -divisor_1 * divisor_2 ]
let ans : int = fold_left sum 0 divisors
let () = Printf.printf "%d\n" ans
