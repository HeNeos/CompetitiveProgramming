sol = FindInstance[
   a + b + c == 1000 && a^2 + b^2 == c^2 && 0 < a < b < c, 
   {a \[Element] Integers, b \[Element] Integers, c \[Element] Integers}
];

Times @@ sol[[1, All, 2]]