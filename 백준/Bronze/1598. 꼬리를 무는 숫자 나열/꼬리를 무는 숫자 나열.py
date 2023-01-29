a, b = map(int, input().split())
x1 = (a-1)//4 + 1 
y1 = (a-1)%4
x2 = (b-1)//4 + 1 
y2 = (b-1)%4
print(abs(x2-x1) + abs(y2-y1))