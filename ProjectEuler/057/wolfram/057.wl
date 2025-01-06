list = Drop[Convergents[Sqrt@2, 1001], 1];
list = Map[
    IntegerLength[Numerator[#]] > IntegerLength[Denominator[#]] &, 
    list
];
Count[list, True]