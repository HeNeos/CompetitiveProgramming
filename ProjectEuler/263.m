PracticalQ[n_] := Module[
    {f, p, e, prod = 1, ok = True},
    If[n < 1 || (n > 1 && OddQ[n]), False, 
        If[n == 1, 
            True, 
            f = FactorInteger[n]; 
            {p, e} = Transpose[f]; 
            Do[
                If[p[[i]] > 1 + DivisorSigma[1, prod], 
                    ok = False; 
                    Break[]
                ]; 
                prod = prod*p[[i]]^e[[i]], {i, Length[p]}
            ]; 
            ok
        ]
    ]
];

Test[n_] := Module[
    {},
    AllTrue[{n - 8, n - 4, n, n + 4, n + 8}, PracticalQ]
]

l1 = Select[
    Prime[Range[60000000] ], 
    Or[Mod[#, 60] == 11, Mod[#, 60] == 31] &
];

n = Select[
    l1, 
    AllTrue[{#, # + 6, # + 12, # + 18}, PrimeQ] &
];

n = Select[
    n,
    PrimePi[{#, # + 6, # + 12, # + 18}] - PrimePi[#] == Range[4] - 1 &
];

possAns = Map[# + 9 &, n];

ans = Select[possAns, Test];

Print[Total@ans];