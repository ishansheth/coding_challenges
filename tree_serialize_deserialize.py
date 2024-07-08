# leetcode coding problem solution
# https://leetcode.com/problems/serialize-and-deserialize-bst/

from collections import deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


"""
          0
        /   \
       1     5
      / \   / \
     2  3  4   6
"""

n7 = TreeNode(3)
n6 = TreeNode(2)
n5 = TreeNode(1, n6, n7)

n4 = TreeNode(6)
n3 = TreeNode(4)
n2 = TreeNode(5, n3, n4)

root = TreeNode(0, n5, n2)

def serialize(root):
    q = deque([root])
    tree = ""
    while q:
        qlen = len(q)
        for i in range(qlen):
            node = q.popleft()
            if node:
                tree += str(node.val) + ","
                q.append(node.left)
                q.append(node.right)
            else:
                tree += "N,"

    return tree

def deserialize(treestr):
    values = treestr.split(",")
    values.pop()

    # pinter for the values list
    idx = 0
    if values[idx] == "N":
        return None
    root = TreeNode(values[idx])
    # push the root node in q
    q = deque([root])
    # increase the index
    idx += 1
    while q:
        qlen = len(q)
        for i in range(qlen):
            # pop the node qlen times
            node = q.popleft()

            # create left and right child of the popped node from q
            if values[idx] != "N":
                node.left = TreeNode(values[idx])
                q.append(node.left)
            else:
                node.left = None
            idx += 1
            if values[idx] != "N":
                node.right = TreeNode(values[idx])
                q.append(node.right)
            else:
                node.right = None
            idx += 1

        if idx == len(values):
            break

    return root


def dfs(root):
    if not root:
        return

    print(root.val)
    dfs(root.left)
    dfs(root.right)

treestr = serialize(root)
treenode = deserialize(treestr)
dfs(treenode)
