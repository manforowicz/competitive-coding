def func(a, x, m):
    sum = 0
    for i in range(x):
        sum += a**i % m
        sum %= m
        print(a**i % m, ", sum:", sum)
    print("result: ", sum)

func(5, 12, 8)