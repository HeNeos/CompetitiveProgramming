Part[DeleteDuplicates@Sort@Flatten@
    Map[
        #*(# + Divisors[#^2 + 1])*(# + (#^2 + 1)/Divisors[#^2 + 1]) &, 
        Range[1, 77790]
    ],
    150000
]