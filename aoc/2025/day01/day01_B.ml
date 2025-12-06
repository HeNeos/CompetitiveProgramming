let rec solve current_position ans =
  match read_line () with
  | exception End_of_file -> ans
  | line ->
      let dir, pos = Scanf.sscanf line "%s %d" (fun d p -> d, p) in
      let new_pos, addition =
        let p =
          match dir, current_position with
            | "R", _ -> current_position + pos
            | "L", 0 -> 100 - pos
            | "L", _ -> current_position - pos
            | _, _ -> current_position
        in
        let addition =
          match dir with
            | "R" -> p / 100
            | "L" -> if p < 0 then ((abs p) + 100 - 1)/100 else 0
            | _ -> 0
        in
        let p = p mod 100 in
        match dir, p with
          | "R", _ -> (p, addition)
          | "L", 0 -> (p, addition + 1)
          | "L", _ -> ((p + 100) mod 100, addition)
          | _, _ ->  (p, addition)
      in
      solve new_pos (ans + addition)

let () =
  let result = solve 50 0 in
  Printf.printf "%d\n" result
