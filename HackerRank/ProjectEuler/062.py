from collections import defaultdict
d=defaultdict(lambda:[])

n,k=map(int,input().split(' '))

l=[]
for i in range(1,n):
    temp=i*i*i
    s="".join(sorted(str(temp)))
    d[s].append(i)

for item in d.items():
    if len(item[1]) == k:
        l.append(pow(min(item[1]), 3))

new=sorted(l)
for v in new:
    print(v)
