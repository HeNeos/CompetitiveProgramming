n = 10^12;

list = Prime[Range[PrimePi@Ceiling@Sqrt[n/2] + 1]];

ans1 = 0;
For[i = 1, i <= Length@list, i++,
    If[list[[i]]*list[[i]] > n, Break[]]; 
    For[j = i + 1, j <= Length@list, j++,
        If[n < list[[j]]*list[[i]]*list[[j]], Break[]];
        aux = PrimePi[n/(list[[i]]*list[[j]])];
        aux -= j;
        If[aux <= 0, Break[]];
        ans1 += aux;
    ]
];

ans2 = 0;
For[i = 1, i <= Length@list, i++,
    aux = PrimePi[n/(list[[i]]^3)];
    If[aux >= i, aux -= 1];
    If[aux <= 0, Break[]];
    ans2 += aux;
];

ans3 = PrimePi[(n)^(1/7)];

ans = ans1+ans2+ans3;