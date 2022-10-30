def is_pal(n):
    a=str(n)
    b=a[::-1]
    if(a==b):
        return 1
    else:
        return 0

def op(n):
    a=str(n)
    b=a[::-1]
    m=int(b)
    return (n+m)

def is_lychel(n):
    count=0
    while(is_pal(n)!=1 and count<61):
        n=op(n)
        count=count+1
    if(count>=60):
        return -1
    else:
        return n


n=int(input())
a = {}
for i in range (1,n):
    index=is_lychel(i)
    if index in a.keys():
        a[index] += 1
    else:
        a[index]= 1
value=0
c_value=0

for item in a.items():
    if item[1] > value and item[0] != -1:
        value = item[1]
        c_value = item[0]

print(c_value,value)
