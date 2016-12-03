prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]


def dfs(cur, num, deep, pre):
    if deep>12:
        return
    global ans
    global div_num
    global n
    if num > div_num:
        ans = cur
        div_num = num
    elif num == div_num and cur < ans:
        ans = cur
    for i in range(1, pre+1):
        cur *= prime[deep]
        if cur <= n:
            dfs(cur, num*(i+1), deep + 1, i)
        else:
            break


T = int(input())
for i in range(T):
    n = int(input())
    ans = n
    div_num = 0
    dfs(1, 1, 0, 30)
    print(ans,div_num)