# https://www.acmicpc.net/problem/11047

# 동전과 가치 입력
N,K = map(int,input().split())
#print(N)
#print(K)

# 동전 종류 입력
coin = []
for i in range(N):
    coin.append(int(input()))

# 동전 갯수 변수 초기화
result = 0

# 동전 내림차순 정렬
coin.sort(reverse=True)

# print(coin)
for i in coin:
#    print(i)
    if i > K:
        continue
    result = result + (K // i)
    K = K % i

print(result)


