#https://www.hackerrank.com/challenges/fibonacci-modified/
a = input().split(' ')
first = int(a[0])
second = int(a[1])
limit = int(a[2])
third = 0
for i in range(3,limit+1):
    third = second**2 + first
    first = second
    second = third
print(third)

