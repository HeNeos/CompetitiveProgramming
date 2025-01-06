Count[
 Map[
  Mod[Length[ContinuedFraction[Sqrt[#]][[2]]], 2] == 1 &, 
  Complement[Range[2, 10000], Table[i*i, {i, 1, 100}]]
  ], True
 ]