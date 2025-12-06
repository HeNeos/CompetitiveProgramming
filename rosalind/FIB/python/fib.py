def matrix_product(A, B):
    result = [[sum(a * b for a, b in zip(A_row, B_col)) 
                        for B_col in zip(*B)]
                                for A_row in A]
    return result

def matrix_power(a, n):
    if n == 0:
        return [[1, 1], [1, 1]]
    if n == 1:
        return a
    temp = matrix_power(a, n//2)
    ans = matrix_product(temp, temp)
    if n%2 == 1:
        ans = matrix_product(ans, a)
    return ans

def solve(n, k):
    if n <= 0:
        return [[1], [1]]
    base_matrix = [[1, k], [1, 0]]
    end_matrix = matrix_product(matrix_power(base_matrix, n), [[1], [1]])
    return end_matrix

inp = input().split()
n = int(inp[0]) - 2
k = int(inp[1])

print(solve(n, k)[0][0])
