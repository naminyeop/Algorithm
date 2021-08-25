# 조건문
"""
if 조건문1:
elif 조건문2:
else:
"""

score = 55

if score >= 70:
    print("성적이 70점 이상입니다")
    if score >= 90:
        print("성적이 90점 이상입니다")
else:
    print('성적이 70점 미만입니다')


# 논리 연산자
"""
True/False 사용
X and Y
X or Y
not X
"""

if True or False:
    print("Yes")

a = 15
if a <= 20 and a >= 0:
    print("Yes")

# 파이썬의 기타 연산자
"""
x in 연산자 : 리스트, 튜플, 문자열, 딕셔너리 안에 x가 있을때 참(True) 
x not in 연산자 : 리스트, 튜플, 문자열, 딕셔너리 안에 x가 없을때 참(True)
리스트, 튜플, 문자열, 딕셔너리 모두 사용 가능
"""

# pass 키워드
"""
아무거도 처리하고 싶지 않을때 pass 키워드 사용
"""
a = 50
if a >= 30:
    pass
else:
    print("30 미만입니다")

#반복문 while

i = 1
result = 0

while i <= 9:
    result += i
    i = i + 1
print(result)

#반복문 for
"""
for 변수 in 리스트:
    실행할 소스코드
"""

array = [9,8,7,6]
for x in array:
    print(x)

for x in range(1,10):
    print(x)
















