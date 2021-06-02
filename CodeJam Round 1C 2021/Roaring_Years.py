def build(k, s):
    p = []
    for _ in range(k):
        # starting from s just add s + 1 to next and so on for k times...
        p.append(str(s))
        s += 1
    return int("".join(p))
def fun(k, n):
    # applying binary search on the single starting segment for a good year
    l = 1
    r = 10**10
    while l < r:
        m = (l + r)//2
        # building the cur year for starting value of mid and increasing it further
        v = build(k, m)
        if v <= n:
            l = m + 1
        else:
            r = m
    return build(k, l)
T = int(input())
for t in range(1, T + 1):
    n = int(input())
    # building initial ans for pair of 2...
    ans = fun(2, n)
    # processing  ans for range of length of 3...20
    for k in range(3, 20):
        ans = min(ans, fun(k, n))
    print("Case #", t, ": ", ans, sep = "")