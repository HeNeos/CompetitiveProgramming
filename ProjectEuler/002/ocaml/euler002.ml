let even_fibonacci (n : int) : int list =
  let rec even_fibonacci_generator a b =
    if a > n then [] else a :: even_fibonacci_generator (a + (2 * b)) ((2 * a) + (3 * b))
  in
  even_fibonacci_generator 2 3
;;

let limit : int = 4_000_000
let ans : int = List.fold_left (fun acc x -> acc + x) 0 (even_fibonacci limit)
let () = Printf.printf "%d\n" ans
