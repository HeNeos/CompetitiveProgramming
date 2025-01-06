l = {2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 18, 20, 21, 24, 
   27, 28, 30, 32, 35, 36, 39, 40, 42, 45, 48, 52, 54, 56, 60, 63, 64,
    65, 70, 72, 80};

l2 = 1/(l*l);

ans = FindInstance[
   1/2 == l2 . v && 0 <= v \[VectorLessEqual] 1,
   v \[Element] Vectors[Length@l2, Integers],
   400
];

Length@ans