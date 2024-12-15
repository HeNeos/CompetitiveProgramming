u = Plus @@ Table[(-1) ^ i * n^i, {i, 0, 10}];

l = Table[u /. n -> i, {i, 1, 10}];

polynomials = InterpolatingPolynomial[l[[1 ;; #]], n]& /@ Range[10];

Print[Total[MapIndexed[#1 /. n -> (First[#2] + 1)&, polynomials]]]
