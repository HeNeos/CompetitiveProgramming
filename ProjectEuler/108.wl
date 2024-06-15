Position[
 Table[Length@Select[Divisors[i^2], # > i &] >= 1000, {i, 1, 
   181000}], True]