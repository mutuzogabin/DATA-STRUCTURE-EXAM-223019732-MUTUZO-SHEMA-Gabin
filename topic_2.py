class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class CircularLinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            self.head.next = self.head
        else:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            temp.next = new_node
            new_node.next = self.head

    def display(self):
        if not self.head:
            print("Circular Linked List is empty")
            return
        result = []
        temp = self.head
        while True:
            result.append(temp.data)
            temp = temp.next
            if temp == self.head:
                break
        print("Circular Linked List:", result)


class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, root, data):
        if not root:
            return TreeNode(data)
        if data < root.data:
            root.left = self.insert(root.left, data)
        else:
            root.right = self.insert(root.right, data)
        return root

    def display_inorder(self, root):
        if not root:
            return []
        return self.display_inorder(root.left) + [root.data] + self.display_inorder(root.right)


# Demo
cll = CircularLinkedList()
cll.append(10)
cll.append(20)
cll.append(30)
cll.display()

bt = BinaryTree()
bt.root = bt.insert(bt.root, 15)
bt.root = bt.insert(bt.root, 10)
bt.root = bt.insert(bt.root, 20)
print("Binary Tree Inorder Traversal:", bt.display_inorder(bt.root))
