a,b = map(int, input().split())
a = int(a)
b = int(b)
ans = [[i for i in range(a*2+b*2, a*2+b, -1)],[i for i in range(a*2+b, a+b, -1)]]

for i in range(a):
    lis1 = list(map(int, input().split()))
    last1 = -1
    first1 = -1
    for j in range(b):
        if(lis1[j] == 1):
            if(last1 == -1):
                first1 = ans[1][i]
                ans[1][i] = ans[0][j]
                last1 = j
            else:
                ans[0][last1] = ans[0][j]
                last1 = j
    if(first1 != -1):
        ans[0][last1] = first1

ans = (ans[1] + ans[0]) * 2
for i in range(a+b):
    ans[ans[i]-1] = i+1

for i in ans:
    print(i, end = ' ')
