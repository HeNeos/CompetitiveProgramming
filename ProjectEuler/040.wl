s = StringJoin[ToString /@ Table[i, {i, 1, 200000}]];
Times @@ 
 Map[ToExpression@StringTake[s, {#}] &, Table[10^i, {i, 0, 6}]]