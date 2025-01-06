m[n_] := Module[
   {d, valid, inverse, k, a},
   d = Divisors[n];
   valid = Select[d, 1 == GCD[#, n/#] &];
   inverse = Map[n/#*ModularInverse[n/#, #] &, valid];
   k = Map[Ceiling[(n + # - 1)/ n] - 1 &, inverse];
   a = MapThread[n*#2 + 1 - #1 &, {inverse, k}];
   Max[a]
];

t = Table[m[i], {i, 1, 10000000}];

Total[t]