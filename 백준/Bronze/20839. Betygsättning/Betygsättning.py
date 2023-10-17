x,y,z=map(int,input().split())
a,b,c=map(int,input().split())
if x<=a and y<=b and z<=c:
    print("A")
elif x/2<=a and y<=b and z<=c:
    print("B")
elif y<=b and z<=c:
    print("C")
elif y/2<=b and z<=c:
    print("D")
elif z<=c:
    print("E")