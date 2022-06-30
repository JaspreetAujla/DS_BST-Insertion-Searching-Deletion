class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


def inorder(root):
    if root is not None:
    
        inorder(root.left)

        print(str(root.key) + " ", end=' ')

        inorder(root.right)


def insert(node, key):

    if node is None:
        return Node(key)

    if key < node.key:
        node.left = insert(node.left, key)
    else:
        node.right = insert(node.right, key)

    return node

def minValueNode(node):
    current = node

    while(current.left is not None):
        current = current.left

    return current

def deleteNode(root, key):

    if root is None:
        return root

    if key < root.key:
        root.left = deleteNode(root.left, key)
    elif(key > root.key):
        root.right = deleteNode(root.right, key)

    else:
        if root.left is None:
            temp = root.right
            root = None
            return temp

        elif root.right is None:
            temp = root.left
            root = None
            return temp

        temp = minValueNode(root.right)

        root.key = temp.key

        root.right = deleteNode(root.right, temp.key)

    return root 

root = None
root = insert(root, 2)
root = insert(root, 7)
root = insert(root, 5)
root = insert(root, 9)
root = insert(root, 12)
root = insert(root, 10)

print("Inorder traversal: ", end=' ')
inorder(root)

print("\n\nDelete 12")
root = deleteNode(root, 12)

print("Inorder traversal: ", end=' ')
inorder(root)

print("\n\nDelete 9")
root = deleteNode(root, 9)

print("Inorder traversal: ", end=' ')
inorder(root)