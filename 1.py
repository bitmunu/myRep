print("Введите 3 числа")
lis = list(map(int, input().split(' ')))
count = 0

for (ind, j) in enumerate(lis):
    if lis[0] == lis[ind] and ind != 0:
        count = count + 1

if count == 1:
    print(f"{2}")
elif count == 2:
    print(3)
elif count == 0:
    print(0)

