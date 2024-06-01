getColumn[x_, r_] := x - (r-1)*r/2;
boundaries[r_] := {(r-1)*r/2 + 1, r*(r+1)/2};
getValue[r_, c_] := (r-1)*r/2 + c;

check[r_, c_] := Module[
   {l, v, rawV, test, testValid, testValues, testSubsets},
   l = {{r - 2, c - 1}, {r - 2, c + 1}, {r - 1, c - 2}, {r - 1, c},
      {r - 1, c + 2}, {r, c - 2}, {r, c + 2}, {r + 1, c - 1}, 
      {r + 1, c + 1}, {r + 2, c - 1}, {r + 2, c + 1}
   };
   rawV = getValue[Sequence @@ #] & /@ l;
   v = PrimeQ[rawV];
   test = {{1, 3, 4, 6}, {1, 2}, {2, 4, 5, 7}, {3, 4, 6, 8},
      {4, 5, 7, 9}, {6, 10}, {8, 9, 10, 11}, {7, 11}
   };
   testValid = Select[#, v[[#]] &] & /@ test;
   testValid = Select[testValid, Length[#] >= 2 &];
   testSubsets = Flatten[Subsets[#, {2}] & /@ testValid, 1];
   testSubsets = ContainsAny[
      testSubsets,
      {{1, 4}, {2, 4}, {4, 8}, {6, 8}, {7, 9}, {4, 9}, {8, 10}, {8, 9}, {9, 11}}
   ];
   testSubsets
];

(* Optimized for odd rows *)
solve[r_] := Module[
   {l, columns, sol},
   l = Prime[Range[Sequence @@ PrimePi[boundaries[r]]]];
   l = If[l[[1]] >= boundaries[r][[1]], l, l[[2 ;;]]];
   columns = getColumn[#, r] & /@ l;
   sol = Position[check[r, #] & /@ columns, True];
   Total[getValue[r, columns[[Flatten@sol]]]]
];

r1 = 5678027;
r2 = 7208785;

Print[solve[r1] + solve[r2]];