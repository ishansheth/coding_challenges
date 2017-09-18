#https://www.hackerrank.com/challenges/is-fibo
import math

def is_fibonacci(n):
    phi = 0.5 + 0.5 * math.sqrt(5.0)
    a = phi * n
    return n == 0 or abs(round(a) - a) < 1.0 / n

for _ in range(int(input())):
    x =  int(input().strip())
    if (is_fibonacci(x)):
        print('IsFibo')
    else:
        print('IsNotFibo')
