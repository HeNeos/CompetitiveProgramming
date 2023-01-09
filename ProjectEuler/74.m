chain[n_] := Module[
   {halt = False, ans = 1, current, c = {}},
   current = n;
   c = Append[c, current];
   While[halt === False,
      current = Total@Factorial@IntegerDigits[current];
      If[MemberQ[c, current],
         halt = True,
         ans += 1; c = Append[c, current]
      ];
   ];
   ans
];

t = Table[chain[i], {i, 1, 1000000}];
Length@Flatten@Position[t, 60]