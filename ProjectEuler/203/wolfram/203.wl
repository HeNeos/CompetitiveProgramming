pascalValue[i_, j_] := Binomial[i, j];
pascal = Flatten@Table[pascalValue[i, j], {i, 0, 50}, {j, 0, i}];
pascal = DeleteDuplicates[pascal];
Total@Select[pascal, MoebiusMu[#] != 0 &];