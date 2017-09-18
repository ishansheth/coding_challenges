#https://www.hackerrank.com/challenges/sherlock-and-array
X = int(input().strip())
for i in range(0,X):
    a = int(input().strip())
    b = input().strip().split(" ")
    b = [int(j) for j in b]
    if(len(b) == 1):
        print("YES")
    else:
        for k in range(1,len(b)):
            sum_left = sum(b[0:k])
            sum_right = sum(b[k+1:a])
            if(sum_left == sum_right):
                c = 1
                print("YES")
                break
            else:
                c = 0
        if(c == 0):
            print("NO")
