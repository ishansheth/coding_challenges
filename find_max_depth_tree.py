# https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
from collections import deque 

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


#n3 = TreeNode(2,n1,n2)


n1 = TreeNode(15)
n2 = TreeNode(7)

n5 = TreeNode(9)
n6 = TreeNode(20,n1,n2)
r1 = TreeNode(3,n5,n6)

#r1 = TreeNode(4,n3,n6)


def dfsAlgo(root):
    
    def helper(node,d,maxd):
        if node == None:
            return d
        
        d += 1
            
        v1 = helper(node.left,d,maxd)
        v2 = helper(node.right,d,maxd)
        maxd = max(v1,v2)
        return maxd
        
    depth = 0    
    maxd = 0
    temp = root
    r = helper(temp,depth,maxd)
    print(r)



def itrativeTraverse(root):
    if not root:
        return 0
        
    stack = [[root,1]]
    res = 1
    
    while stack:
        node,val = stack.pop()
        
        if node:
            res = max(res,val)
            stack.append([node.right,val+1])
            stack.append([node.left,val+1])
    
    return res

def levelOrderTraverse(root):
    if not root:
        return 0
    
    result = 0
    q = deque([root])
    
    while q:

        for i in range(len(q)):
            node = q.popleft()
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        
        result += 1
        
    return result    
        
        
print(levelOrderTraverse(r1))
