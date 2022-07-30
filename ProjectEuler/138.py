import math
answ = 0
b = 1
answ2 = 0
while(b < 10000000000000000):
    if(answ==12):
        break
    aux1 = 5*b*b+1-4*b
    aux2 = 5*b*b+1+4*b
    sqaux1 = int(math.floor(math.sqrt(aux1)))
    sqaux2 = int(math.floor(math.sqrt(aux2)))
    flag1 = False
    if(sqaux1*sqaux1 == aux1 or (sqaux1+1)*(sqaux1+1) == aux1):
        answ = answ+1
        aux = int(math.sqrt(b*b+(2*b-1)*(2*b-1)))
        print(answ,2*b,2*b-1,aux)
        flag1 = True
        answ2 = answ2+aux
    if(sqaux2*sqaux2 == aux2 or (sqaux2+1)*(sqaux2+1) == aux2):
        answ = answ+1
        aux = int(math.sqrt(b*b+(2*b+1)*(2*b+1)))
        print(answ,2*b,2*b+1,aux)
        answ2 = answ2+aux
        flag1 = True
    if(flag1):
        if(answ < 11):
            b = int(math.floor(b*17.9442575))
        if(answ >= 11):
            b = int(math.floor(b*17.944271))
        b = (b//8)*8
    else:
        b=(b//8)*8
        b = b+8
print(answ2)
