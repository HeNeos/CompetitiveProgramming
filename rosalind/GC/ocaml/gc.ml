let process_fasta =
  match read_line () with
  | exception End_of_file -> -1
  | line ->
      let label = String.sub line 1 (String.length line - 1) in
      count label


