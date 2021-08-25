# https://www.youtube.com/watch?v=2zjoKjt97vQ&list=PLRx0vPvlEmdAghTr5mXQxGpHjWqSz0dgC&index=3

array = list(input())
#print(array)
#print(len(array))

# 첫번째 문자를 숫자로 변경
result = int(array[0])
#print(result)

# 두번째 숫자부터 for문
for x in range(1,len(array)):

    print(array[x])
    num = int(array[x])
    # 두번째 숫자가 1이하이거나 첫번째 숫자가 1이하이면 그냥 덧셈연산
    if num <= 1 or result <= 1:
        result += num
    else:
        result *= num

    #print("result : " + str(result))
