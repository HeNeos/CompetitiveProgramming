Total[
  Select[
    Range[1, 10000], 
    # + (DivisorSigma[1, #] - #) == DivisorSigma[1, DivisorSigma[1, #] - #] 
    && DivisorSigma[1, #] != 2*# &
  ]
]