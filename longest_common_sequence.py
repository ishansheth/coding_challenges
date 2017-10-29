# LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. 
#A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.

def abbreviation(a, b):
    if (len(b) == 0):
      return ""
    pos = a.find(b[0])
    if(pos >= 0):
      b = b[1::1]
      return a[pos] + abbreviation(a,b)
    else:
      b = b[1::1]
      return abbreviation(a,b)
      
a = "AGGTAB"
b = "GXTXAYB"
result = abbreviation(a, b)
print(result)
