test = int(input())
asd = 1
while asd <= test:
    # asd += 1
    s=input()
    p=input()
    st = list(s)
    pat = list(p)
    for x in pat:
        st.remove(x)
    st = sorted(st)
    temp = [x for x in st]
    temp.append(pat[0])
    temp.sort()
    temp = temp[::-1]
    ans = ""
    if p[0] not in st:
        fir = ''.join(st[0:len(temp)-temp.index(pat[0])-1])
        sec = ''.join(pat)
        third  = ''.join(st[len(temp)-temp.index(pat[0])-1:])
        ans = fir + sec + third
    else:
        x1 =  ''.join(st[0:st.index(pat[0])])
        x2 = ''.join(pat)
        x3 = ''.join(st[st.index(pat[0]):])
        ch1 = x1 + x2 + x3
        fir = ''.join(st[0:len(temp)-temp.index(pat[0])-1])
        sec = ''.join(pat)
        third  = ''.join(st[len(temp)-temp.index(pat[0])-1:])
        ch2 = fir + sec + third
        ans = min(ch1, ch2)
    print(ans)
    asd += 1