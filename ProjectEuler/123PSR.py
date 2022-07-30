import math
prim = [1]*1000000
rprim = []
def fastexp(n,m,fij):
    if m==0:
        return 1
    if m==1:
        return n
    if m%2==0:
        aux = int(int(fastexp(n,int(m/2),fij))%fij)
        aux = int(int((aux * aux))%fij)
        return aux
    else:
        aux = int(int(fastexp(n,int((m-1)/2),fij))%fij)
        aux = int(int((aux*aux))%fij)
        aux = int(int((aux*n))%fij)
        return aux
def sieve():
    for i in range(2,int(math.sqrt(1000000))):
        if prim[i] == 1 :
            for j in range(i*i,1000000,i):
                prim[j] = 0
    for i in range(2,1000000):
        if prim[i] == 1:
            rprim.append(i)
sieve()
for i in range(7000,100000):
    aux = (fastexp(rprim[i]-1,i+1,rprim[i]*rprim[i]) + fastexp(rprim[i]+1,i+1,rprim[i]*rprim[i]))%(rprim[i]*rprim[i])
    #aux = (((rprim[i]-1)**(i+1))%(rprim[i]*rprim[i]) + ((rprim[i]+1)**(i+1))%(rprim[i]*rprim[i]))%(rprim[i]*rprim[i])
    if aux>10000000000:
        #print(fastexp(rprim[i]-1,i+1,rprim[i]*rprim[i]))
        print(i+1)
        #print(rprim[i])
        break
