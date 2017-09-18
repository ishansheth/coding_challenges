#https://www.hackerrank.com/challenges/sherlock-and-valid-string/
#!/bin/python3
import sys
from collections import *

def isValid(s):
    # Complete this function
    str_set = set(s)
    freq_set = []
    result = "NO"
    for i in str_set:
        freq_set.append(s.count(i))
    temp = [abs(i-min(freq_set)) for i in freq_set]
    print(temp,freq_set)
    if(sum(temp) == 0 or sum(temp) == 1):
        result="YES"
    if(sum(temp)>1):
        result="NO"
    return result
        
        
s = input().strip()
result = isValid(s)
print(result)
