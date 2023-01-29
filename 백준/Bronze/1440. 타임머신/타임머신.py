from itertools import permutations
perms = list(permutations(map(int, input().split(":"))))
cnt = 0
for perm in perms:
    if 1 <= perm[0] <= 12 and 0 <= perm[1] <= 59 and 0 <= perm[2] <= 59:
        cnt += 1
print(cnt)
