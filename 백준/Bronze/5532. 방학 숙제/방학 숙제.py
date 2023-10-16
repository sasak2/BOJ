l = int(input())
a = int(input())
b = int(input())
c = int(input())
d = int(input())

if a % c == 0 :
  value = a // c
else :
  value = (a // c) + 1

if b % d == 0 :
  value2 = b // d
else :
  value2 = (b // d) + 1

print(l - max(value, value2))#######################fdjfa;iejioejioewa