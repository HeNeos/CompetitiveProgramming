ans = NMinimize[{2^p2*3^p3*5^p5*7^
       p7*(11^p11)*(13^p13)*(17^p17)*(19^p19)*(23^p23)*(29^p29)*(31^
        p31)*(37^p37)*(41^p41)*43^p43*47^p47*53^p53*59^
       p59, (2*p2 + 1)*(2*p3 + 1)*(2*p5 + 1)*(2*p7 + 1) (2*p11 + 
          1)*(2*p13 + 1)*(2*p17 + 1)*(2*p19 + 1)*(2*p23 + 1)*(2*p29 + 
          1)*(2*p31 + 1)*(2*p37 + 1)*(2*p41 + 1)*(2*p43 + 1)*(2*p47 + 
          1)*(2*p53 + 1)*(2*p59 + 1) >= 8000000 && 
      p2 \[Element] NonNegativeIntegers && 
      p3 \[Element] NonNegativeIntegers && 
      p5 \[Element] NonNegativeIntegers && 
      p7 \[Element] NonNegativeIntegers && 
      p11 \[Element] NonNegativeIntegers && 
      p13 \[Element] NonNegativeIntegers && 
      p17 \[Element] NonNegativeIntegers && 
      p19 \[Element] NonNegativeIntegers && 
      p23 \[Element] NonNegativeIntegers && 
      p29 \[Element] NonNegativeIntegers && 
      p31 \[Element] NonNegativeIntegers && 
      p37 \[Element] NonNegativeIntegers && 
      p41 \[Element] NonNegativeIntegers && 
      p43 \[Element] NonNegativeIntegers && 
      p47 \[Element] NonNegativeIntegers && 
      p53 \[Element] NonNegativeIntegers && 
      p59 \[Element] NonNegativeIntegers}, {p2, p3, p5, p7, p11, p13, 
     p17, p19, p23, p29, p31, p37, p41, p43, p47, p53, p59}, 
    MaxIterations -> 400][[1]];

InputForm[ans];

Position[
 Table[Length@Divisors[i^2] >= 8000000, {i, 9350130049860000, 
   9350130049861000}], True]