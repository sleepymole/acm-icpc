from queue import Queue

limit = 10 ** 18
Hash = {}
q = Queue()
q.put([1, 1, 3, 3, 4])

while not q.empty():
    a = q.get()
    a.sort()
    if a[0] <= 0 or a[4] > limit:
        continue
    if a[4] in Hash:
        continue
    Hash[a[4]] = a
    s = 1
    for i in a:
        s *= i
    q.put([s // a[0] - a[0], a[1], a[2], a[3], a[4]])
    q.put([s // a[1] - a[1], a[0], a[2], a[3], a[4]])
    q.put([s // a[2] - a[2], a[1], a[0], a[3], a[4]])
    q.put([s // a[3] - a[3], a[1], a[2], a[0], a[4]])
    q.put([s // a[4] - a[4], a[1], a[2], a[3], a[0]])

N = int(input())
count = 0
sol = []
for i in Hash:
    a = Hash[i]
    if a[0] == a[1] or a[1] == a[2] or a[2] == a[3] or a[3] == a[4]:
        continue
    if a[4] <= N:
        sol.append(a)
        count += 1
sol.sort()
if count==0:
    print('No Solution')
else:
    print(count)
    for i in sol:
        print(i[0], i[1], i[2], i[3], i[4])
