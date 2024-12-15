n = 12000;

phi[n_, l_, r_] :=  Length@Select[Range[l, r], CoprimeQ[n, #] &];

ans = 0;
For[i = n, i >= 2, i--,
    left = Ceiling[i/3 + 0.0000001];
    right = Floor[i/2 - 0.0000001];
    aux = 0;
    aux += phi[i, left, right];
    ans += aux;
  ];
Print[ans];