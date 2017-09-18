#https://www.hackerrank.com/challenges/the-great-xor
#!/bin/python3
import sys
def theGreatXor(x):
    i = 0
    result = 0
    # Complete this function
    while(x>>i):        
        if(x>>i & 1 == 0):
            result = result + 2**(i)
        i = i+1
    return result
                

q = int(input().strip())
for a0 in range(q):
    x = int(input().strip())
    result = theGreatXor(x)
    print(result)
