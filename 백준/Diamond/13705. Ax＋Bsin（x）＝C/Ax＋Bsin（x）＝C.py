from decimal import *
getcontext().prec = 50
getcontext().rounding = ROUND_HALF_UP

a,b,c = map(Decimal,map(int,input().split()))
pi = Decimal('3.14159265358979323846264338327950288419716939937510')

def sin(x) :
	
	#print(divmod(x,pi)[1])
	a=Decimal(divmod(x,2*pi)[1])

	#print(a)
	sum=Decimal('0.0')

	k=0;
	facto=1
	while(k<30) :
		#print(sum)
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
while(i<300) :
	i=i+1
	m=Decimal((s+e)/2)
	if(c>f(m)):
		s=m
	else:
		e=m
	#print(m)

print(round(m,6))


'''
def sin(x):
    if -pi <= x <= pi:
        getcontext().prec += 2
        i, lasts, s, fact, num, sign = 1, 0, x, 1, x, 1
        while s != lasts:
            lasts = s
            i += 2
            fact *= i * (i-1)
            num *= x * x
            sign *= -1
            s += num / fact * sign
        getcontext().prec -= 2
        return +s
    elif x > pi:
        while x > pi:
            x-=2*pi
        return sin(x)
    elif x < -pi:
        while x < -pi:
            x+=2*pi
        return sin(x)

def f(x):
    return a*x+b*Decimal(sin(x))-c

left = c / a - Decimal('1')
right = c / a + Decimal('1')
while right - left > Decimal(1e-20):
    mid = (left + right) / 2
    if f(mid) > 0:
        right = mid
    elif f(mid) < 0:
        left = mid
    else:
        break
print(round((left + right)/2,6))
'''