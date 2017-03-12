import random

def power_mod(a,n,m):
    r=1
    while n>0:
        if n%2==1:
            r=r*a%m
        a=a*a%m
        n=n//2
    return r

def witness(a,p):
    k=0
    q=p-1
    while q%2==0:
        k+=1
        q=q//2
    v=power_mod(a,q,p)
    if v==1 or v==p-1:
        return False
    while k>0:
        k-=1
        v=v*v%p
        if v==p-1:
            return False
    return True

def miller_rabin(p):
    if p==2:
        return True
    if p%2==0:
        return False
    for i in range(50):
        a=random.randint(1,p-1)
        if witness(a,p):
            return False
    return True

n=int(input())
if miller_rabin(n):
    print('Yes')
else:
    print('No')