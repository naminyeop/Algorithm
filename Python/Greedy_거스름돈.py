# https://www.acmicpc.net/problem/5585

n = 1000 - int(input())

count = 0

array = [500,100,50,10,5,1]

for x in array:
    count = count + (n // x)
    n = n % x

print(count)