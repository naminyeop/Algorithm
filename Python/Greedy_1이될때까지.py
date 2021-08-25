
N,K = list(map(int,input().split()))

print(N) # 17
print(K) # 4

num = N
count = 0

while num != 1:
#    print(num)
    if num % K == 0:
        num = num / K
        count = count + 1
    else:
        num = num -1
        count = count + 1

print(count)