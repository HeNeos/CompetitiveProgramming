package main

import (
	"fmt"
	"math"
	"math/big"
)

const sieveLimit int32 = 10000000

var testMillerRabin = [...]int32{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}
var isPrimeSieve []bool

func iSqrt(n int64) int32 {
	if n <= 1 {
		return int32(n)
	}

	var z int64 = n >> 2
	var r2 int32 = 2 * iSqrt(z)
	var r3 int32 = r2 + 1

	if n < int64(r3)*int64(r3) {
		return r2
	} else {
		return r3
	}
}

func multiplierMod(a int64, b int64, mod int64) int64 {
	return (a % mod * b % mod) % mod
}

func fastPow(x int64, y int64, mod int64) int64 {
	var ans int64 = 1
	for y > 0 {
		if y&1 == 1 {
			ans = multiplierMod(ans, x, mod)
		}
		y >>= 1
		x = multiplierMod(x, x, mod)
	}
	return ans % mod
}

func checkComposite(n int64, a int64, d int64, s int32) bool {
	var x int64 = fastPow(a, d, n)
	if x == 1 || x == n-1 {
		return false
	}
	for r := int32(1); r < s; r++ {
		var bigX = big.NewInt(x)
		var xSquare = new(big.Int)
		xSquare = xSquare.Mul(bigX, bigX)
		var xMod = new(big.Int)
		xMod = xMod.Mod(xSquare, big.NewInt(n))
		x = xMod.Int64()
		if x == n-1 {
			return false
		}
	}
	return true
}

func primeSieve(n int32) (primes []int32) {
	isPrimeSieve = make([]bool, n, n)
	for i := range isPrimeSieve {
		isPrimeSieve[i] = true
	}
	isPrimeSieve[0], isPrimeSieve[1] = false, false

	primes = make([]int32, 0, 0)
	for i := int32(2); i < n; i++ {
		if isPrimeSieve[i] {
			primes = append(primes, i)
			for j := int64(i) * int64(i); j < int64(n); j += int64(i) {
				isPrimeSieve[j] = false
			}
		}
	}
	return
}

func isPrime(p int64) bool {
	if p < int64(sieveLimit) {
		return isPrimeSieve[p]
	}
	var r int32 = 0
	var d int64 = p - 1
	for d&1 == 0 {
		d >>= 1
		r++
	}
	for i := 0; i < len(testMillerRabin); i++ {
		if p == int64(testMillerRabin[i]) {
			return true
		}
		if checkComposite(p, int64(testMillerRabin[i]), d, r) {
			return false
		}
	}
	return true
}

func primePi(n int32, primes []int32) int32 {
	var left int32 = 0
	var right int32 = int32(len(primes)) - 1
	for left < right {
		var middle int32 = left + (right-left+1)/2
		if primes[middle] <= n {
			left = middle
		} else {
			right = middle - 1
		}
	}
	if primes[left] > n {
		left--
	}
	return left + 1
}

func generateNextProduct(factors []int32, limit int64, primes []int32) (int64, bool) {
	var size = len(factors)
	var currentProduct int64 = 1
	var indexLimits []int32 = make([]int32, size, size)
	for i, factorIndex := range factors {
		indexLimits[i] = primePi(int32(math.Pow(float64(limit)/float64(currentProduct), 1.0/(float64(size+1-i)))), primes)
		currentProduct *= int64(primes[factorIndex])
	}
	if factors[0] >= indexLimits[0] {
		return 0, false
	}
	var newProduct int64 = currentProduct / int64(primes[factors[size-1]])
	factors[size-1]++
	var passedLimit bool = factors[size-1] > indexLimits[size-1]
	if !passedLimit {
		newProduct *= int64(primes[factors[size-1]])
	} else {
		newProduct = currentProduct
		factors[size-1]--
	}
	var previousPos = size - 1
	for passedLimit || newProduct > limit {
		for ; previousPos >= 1 && (newProduct > limit || factors[previousPos] > indexLimits[previousPos] || passedLimit); previousPos-- {
			passedLimit = false
			newProduct /= int64(primes[factors[previousPos-1]])
			factors[previousPos-1]++
			newProduct *= int64(primes[factors[previousPos-1]])

			newProduct /= int64(primes[factors[previousPos]])
			factors[previousPos] = factors[previousPos-1] + 1
			newProduct *= int64(primes[factors[previousPos]])
		}
		if newProduct <= limit {
			return newProduct, true
		}
		return 0, false
	}
	return newProduct, newProduct <= limit
}

func solve(n int32, limit int64, primes []int32) int64 {
	var factors []int32 = make([]int32, n-1, n-1)
	var currentProduct int64 = 1
	for i := 0; i < len(factors)-1; i++ {
		factors[i] = int32(i) + 1
		currentProduct *= int64(primes[factors[i]])
	}
	factors[n-2] = n - 2
	currentProduct *= int64(primes[factors[n-2]])

	var ans int64 = 0
	for {
		newProduct, shouldContinue := generateNextProduct(factors, limit, primes)
		if !shouldContinue {
			break
		}
		var lastPosition = factors[n-2]
		if newProduct*int64(primes[lastPosition]) > limit {
			continue
		}
		var newPhi int64 = newProduct
		for i := 0; i < len(factors); i++ {
			newPhi /= int64(primes[factors[i]])
			newPhi *= int64(primes[factors[i]] - 1)
		}
		var k int32 = primes[factors[0]]/(n+1) + 1
		if k%2 == 1 {
			k++
		}
		for ; k < primes[factors[0]]; k += 2 {
			var numerator int64 = int64(k)*newPhi + 1
			var denominator int64 = int64(k)*newPhi - newProduct*int64(k) + newProduct

			var p int64 = numerator / denominator
			if newProduct*p > limit {
				break
			}
			if p <= int64(primes[factors[n-2]]) {
				continue
			}
			if numerator%denominator != 0 {
				continue
			}
			var isValid bool = isPrime(p)
			if isValid {
				ans += newProduct * p
			}
		}
	}
	return ans
}

func main() {
	var primes = primeSieve(sieveLimit)
	var n int64
	fmt.Scanf("%d", &n)

	// n = p1 * p2 * ...
	// k = (n-1)/(n-phi(n))
	// (k-1)*n = k*phi(n)-1
	// (k-1)*n/p*p = k*phi(n/p)*phi(p) - 1
	// (k-1)*x*p = k*phi(x)*(p-1) - 1
	// p*(xk-x) = p*(k*phi(x)) - k*phi(x) - 1
	// p = (k*phi(x) - xk + x) / (k*phi(x) + 1)
	// p = (k*(p1-1) - p1*k + p1) / (k*(p1-1) + 1) = (p1-k)/(kp1-k+1)
	// 1 = k*phi(n) mod n
	// 1 = n mod k

	var ans int64 = 0
	for elements := int32(2); elements < int32(11); elements++ {
		ans += solve(elements, n, primes)
	}
	fmt.Println(ans)
}
