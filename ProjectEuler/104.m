isPandigital[n_] :=
Module[
    {s},
    s = Sort[RealDigits[Fibonacci[n, 1`15]][[1]][[1 ;; 9]]];
    s == {1, 2, 3, 4, 5, 6, 7, 8, 9}
]

t = Position[Table[isPandigital[i], {i, 2, 400000}], True];
t = Flatten@t;
t = t + 1;

t[[
    Flatten@
        Position[
            Map[
                Sort@IntegerDigits[Mod[Fibonacci[#], 10^10] ][[-9 ;;]] == {1, 2, 3, 4, 5, 6, 7, 8, 9} &
                , t
            ]
        , True]
]]