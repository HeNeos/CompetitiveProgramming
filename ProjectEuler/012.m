x = Flatten@
    Position[Table[Length@Divisors[(i*(i + 1))/2], {i, 1, 13000}],  
     x_ /; x > 500] // First;
Print[x*(x + 1)/2]