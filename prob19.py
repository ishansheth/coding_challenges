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
    temp = [i for i in freq_set if i != min(freq_set)]
    if(len(temp)==1 or freq_set.count(freq_set[0]) == len(freq_set) or (abs(min(freq_set) - max(freq_set)) == 1)):
        result="YES"
    if((abs(min(freq_set) - max(freq_set)) > 1) or len(temp) > 1 ):
        result="NO"
    return result
        
        
s = input().strip()
result = isValid(s)
print(result)
