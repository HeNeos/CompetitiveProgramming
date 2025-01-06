f[n_, m_] := f[n, m] =
  Module[{},
    If[n < -1,
      Return[0]
    ];
    If[-1 <= n < m,
      Return[1]
    ];
    If[n == m,
      Return[2]
    ];
    f[n - 1, m] + f[n - m, m] + Sum[f[n - m - i, m], {i, 2, m}]
  ]

l = f[#, 50]& /@ Range[1, 200];

FirstPosition[# > 10^6& /@ l, True]
