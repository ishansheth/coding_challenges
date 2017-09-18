#https://www.hackerrank.com/challenges/encryption
#!/bin/python3
import sys
import math

def convert_str(input_str,col):
    mat_str=[]
    for i in range(0,len(input_str),col):
        mat_str.append(input_str[i:i+col])
    return mat_str

s = input().strip()
s = s.replace(" ","")
rows = math.floor(math.sqrt(len(s)))
cols = math.ceil(math.sqrt(len(s)))
if(rows*cols < len(s)):
    rows = math.ceil(len(s)/cols)
residue = abs((rows*cols) - len(s))
s = s+ " "*residue
str_list = convert_str(s,cols)
result = " ".join(["".join(list(map(lambda x:x[i],str_list))) for i in range(0,cols)]).replace("  "," ")
print(result)
