import math
arr = []
for i in range(2,20):
    for j in range(2,200):
        if int(pow(j,i)) < 10:
            continue
        aux = int(pow(j,i))
        cont = 0
        while aux>=10:
            cont += int(aux%10)
            aux = int(aux/10)
        cont += aux
        if j==cont:
            arr.append(int(pow(j,i)))
arr.sort()
print(arr[29])
