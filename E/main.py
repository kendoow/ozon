def find_cards(n, m, friends):
    answ = []
    curr_num = -1
    for i in range(len(friends)):
        while (curr_num in answ or curr_num < friends[i] + 1) and curr_num < m:
            curr_num += 1
        if curr_num in answ:
            return [-1]
        answ.append(curr_num)
        curr_num = -1
    return answ

n, m = map(int, input().split())
friends = list(map(int, input().split()))

max_ai = max(friends)
if max_ai >= m:
    print(-1)
else:
    result = find_cards(n, m, friends)
    print(" ".join(map(str, result)))
