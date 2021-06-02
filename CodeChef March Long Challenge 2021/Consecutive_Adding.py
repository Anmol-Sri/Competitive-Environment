def solve():
    l = input()
    l = l.split()
    r = int(l[0])
    c = int(l[1])
    x = int(l[2])
    a = []
    for i in range(r):
        row = list(map(int, input().split()))
        a.append(row)
    b = []
    for i in range(r):
        row = list(map(int, input().split()))
        b.append(row)
    for i in range(r):
        for j in range(c - x + 1):
            v = a[i][j] - b[i][j]
            for k in range(j, j + x):
                a[i][k] -= v
    for i in range(c):
        for j in range(r - x + 1):
            v = a[j][i] - b[j][i]
            for k in range(j, j + x):
                a[k][i] -= v
    ok = True
    for i in range(r):
        for j in range(c):
            if a[i][j] != b[i][j]:
                ok = False
                break
    if ok:
        print("Yes")
    else:
        print("No")
t = int(input())
for i in range(t):
    solve()
