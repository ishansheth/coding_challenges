#https://www.hackerrank.com/challenges/lonely-integer
#!/usr/bin/py
# Head ends here
import functools
def lonelyinteger(b):
    answer = functools.reduce((lambda x, y: x^y), b)
    return answer
# Tail starts here
if __name__ == '__main__':
    a = int(input())
    b = map(int, input().strip().split(" "))
    print(lonelyinteger(b))
