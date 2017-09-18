#https://www.hackerrank.com/challenges/sum-vs-xor
#!/bin/python3
import sys
n = int(input().strip())
no_zeros = 0
while(n>0):
    if(0 == (n & 0x01)):
        no_zeros += 1
    n = n//2
c = pow(2,no_zeros)
print(c)
