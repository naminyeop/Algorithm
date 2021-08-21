# 자료형
a = 777
print(a)

a = a+1
print(a)


# 실수형
a = 154.302
print(a)

a = -154.302
print(a)

a = 154.
print(a)

a = -.4
print(a)

# 자료형 연산
a = 7
b = 3
print(a/b)
print(a%b)
print(a//b)

# 리스트
a = [1,2,3,4,5,6,7,8,9]
print(a)
print(a[3])
print(a[1:4])

# 크기가 n인 리스트 초기화
n = 10
a = [0] * n
print(a)

# 리스트 컴프리헨션 : 리스트를 초기화 하는 방법 중 하나
array = [i for i in range(10)]
print(array)

array = [i for i in range(20) if i%2 == 1]
print(array)

array = [i*i for i in range(10)]
print(array)

n = 4
m = 3
# n X m 2차원 배열 초기화
array = [[0] * m for _ in range(n)]
print(array)

# 리스트 관련 메서드
# 변수명.append() : 리스트에 원소를 하나 삽입
# 변수명.sort()   : 기본 정렬기능(오름차순)
# 변수명.sort(reverse = True) : 내림차순 정렬
# 변수명.insert(인덱스, 값)
# 변수명.count(값) : 리스트에서 특정 값을 가지는 데이터의 갯수
# 변수명.remove : 리스트에서 특정 값을 제거하는데 사용. 같은 값을 가진 원소가 여러개면 하나만 제거->따로 코딩 필요

a = [1,2,3,4]
print(a)
a.reverse()
print(a)

a.insert(2,6)
print(a)

print(a.count(3))
a.remove(1)
print(a)

a = [1,2,3,4,5,5,5]
remove_set = {3,5}
result = [i for i in a if i not in remove_set]
print(result)

# 문자열 자료형
data = 'hello world'
print(data)

data = "Don't you know \"python\"?"
print(data)

# 문자열 연산
a = "hello"
b = "world"
print(a+" "+b)

a = "string"
print(a*3)

a = "ABCDEF"
print(a[2:4])

# a[2] = 'X' --> 문자열에서 하나의 원소 변경 못함

# 튜플 자료형 : 한번 선언된 값을 변경할 수 없습니다. 소괄호 이용
a = (1,2,3,4)
print(a)
# a[2] = 7 원소 할당 지원x = 변경 x

#튜플 사용 case : 서로 다른 성질의 데이터를 묶어서 관리 할때 사용
#튜플 사용 case : 해싱의 키 값으로 사용(변경이 불가능하기 때문)
#튜플 사용 case : 리스트보다 메모리를 더 효율적으로 사용할때

#사전 자료형
data = dict() # 사전 자료형 초기화
data['사과'] = 'Apple'
data['바나나'] = 'Banana'
data['코코넛'] = 'Coconut'

print(data)

if '사과' in data:
    print("'사과'가 존재 합니다")

key_list = data.keys()
value_list = data.values()

print(key_list)
print(value_list)

for key in key_list:
    print(data[key])

a = dict()
a['홍길동'] = 97
a['이순신'] = 98

print(a)

b = {
    '홍길동' : 97,
    '이순신' : 98
}
print(b)
print(b['홍길동'])

key_list = list(b.keys())
print(key_list)
print(key_list[1])

#집합 자료형
## 중복을 허용하지 않는다.
## 순서가 없다.
## 리스트 혹은 문자열을 이용해서 초기화 가능(set 함수 이용)

# 집합 자료형 연산
a = set([1,2,3,4,5])
b = set([3,4,5,6,7])
print(a|b)
print(a&b)
print(a-b)

# 집합 자료형 관련 함수
data = set([1,2,3])
data.add(4)
print(data)

data.update([5,6])
print(data)

data.remove(3)
print(data)

#기본 입출력
# input() 함수 : 한 줄의 문자열을 입력 받는 함수
# map() 함수 : 리스트의 모든 원소에 각각 특정한 함수를 적용할 때 사용
# 공백을 기준으로 데이터를 입력 받을 때는 다음과 같이 사용
## list(map(int, input().split()))
## a,b,c = map(int, input.split())

# @@@@ 데이터의 개수 입력 @@@@
n = int(input())
data = list(map(int, input().split()))
print(data)

# 빠르게 입력 받기
import sys
data = sys.stdin.readline().rstrip()
print(data)

#출력을 위한 전형적인 소스코드
a = 1
b = 2
print(a,b)
print(7, end=" ")
print(8, end=" ")
answer = 7
print("정답은 " + str(answer) + "입니다.")
