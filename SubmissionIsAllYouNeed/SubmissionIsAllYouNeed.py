t = int(input().strip())
for i in range(t):
    n = int(input().strip())
    arr = list(map(int, input().split()))
    total_sum = sum(arr)
    count_zeros = arr.count(0)
    ans = total_sum + count_zeros
    print(ans)