#https://www.hackerrank.com/challenges/maximizing-xor
#!/usr/bin/python3
def maxXor(l, r):
    a = l^r
    count = 0
    sum = 0
    while(a > 0):
        count+=1
        a = a >> 1
    count = count - 1
    while(count > -1):
        sum += pow(2,(count))
        count -= 1
    return(sum)
        

if __name__ == '__main__':
  l = int(input())
  r = int(input())
  print(maxXor(l, r))
