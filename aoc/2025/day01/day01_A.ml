let rec solve current_position ans =
  match read_line () with
  | exception End_of_file -> ans
  | line ->
      let dir, pos = Scanf.sscanf line "%s %d" (fun d p -> d, p) in
      let new_pos =
        let p =
          match dir with
            | "R" -> current_position + pos
            | "L" -> current_position - pos
            | _ -> current_position
        in
        let p = p mod 100 in
        if p < 0 then p + 100 else p
      in
      match new_pos with
        | 0 -> solve new_pos (ans+1)
        | _ -> solve new_pos ans

let () =
  let result = solve 50 0 in
  Printf.printf "%d\n" result
