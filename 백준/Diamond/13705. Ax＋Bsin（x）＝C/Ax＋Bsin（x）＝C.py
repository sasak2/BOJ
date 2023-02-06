from decimal import *
getcontext().prec = 50
getcontext().rounding = ROUND_HALF_UP

a,b,c = map(Decimal,map(int,input().split()))
pi = Decimal('3.14159265358979323846264338327950288419716939937510')
def sin(x) :
	a=Decimal(divmod(x,2*pi)[1])
	sum=Decimal('0.0')
	k=0;
	facto=1
	while(k<20) :
		if k>=1 :
			facto=facto*(2*k+1)*(2*k)
		sum=sum+((((k+1)%2)*2-1)*(a**(2*k+1))/facto)
		k=k+1
	return sum;
def f(x):
	return Decimal(a*x+b*Decimal(sin(x)))
s=Decimal('0.0')
e=Decimal('100000.0')
i=0
while(i<100) :
	i=i+1
	m=Decimal((s+e)/2)
	if(c>f(m)):
		s=m
	else:
		e=m
print(round(m,6))