n! = p1^a1 * p2^a2 ... pk^ak
base = p1 -> a1
base = p2 -> a2
base = p1*p2 -> min(a1, a2)

if n = 3 
3! = 6 = 2^1 * 3^1
base = p1^b1 * p2^b2
where b1 <= a1 && b2 <= a2 && ...
otherwise -> 0

b2 = 0
b1 != 0 -> a1/1 + a1/2 + ... + a1/a1 -> ~a1log(a1)

b2 = 1
b1 != 0 -> min(a1/1, a2) + min(a1/2, a2) + ... 

b2 = 2 
b1 != 0 -> min(a1/1, a2/2) + ...

prefix sum: O(a1 + a2)

============================================

r1 = Roundness(n!, p1)
r2 = Roundness(n!, p2)

=> r12 = min(r1, r2) = Roundness(n!, p1*p2)
=> r1^x = r1 / x = Roundness(n!, p1^x)

Roundness is a multiplicative function for a fixed n!

Sum(Roundness(1..n!)) ?
Lucy ? it's only over primes X
Hyperbola dirichlet method ?
Min_25 ? Too overkill (don't wanna code it in Rust)
Fenwick Tree ? Optimization but it's not clear how to apply it
