# Problem link: https://leetcode.com/problems/destination-city/
# below is the extension of the leet code problem.
# Extension: create a journey string: 
# paths = [["B","C"],["D","B"],["C","A"]]
# Ans: "D" -> "B" -> "C" -> "A"

# this funciton can be modified to return the end city which will be leetcode
# soltion problem
def returnStartCity(values):
    x = set()
    for i in values:
        x.add(i[1])
    
    for i in values:
        if i[0] not in x:
            return i[0]
    
def createPath(values):
    travelled = {}
    for i in values:
        travelled[i[0]] = i[1]
    
    path_str = returnStartCity(values) + "-"
    start_val = returnStartCity(values)
    while True:
        v1 = travelled.get(start_val,None)
        if v1 != None:
            path_str += v1 + "-"
            start_val = v1
        else:
            break
            
        
    print(path_str)
    

x = createPath([["A","B"],["G","H"],["B","C"],["E","F"],["C","D"],["F","G"],["D","E"]])
print(x)
