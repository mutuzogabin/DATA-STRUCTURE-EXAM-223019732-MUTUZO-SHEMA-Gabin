class ServiceTreeNode:
    def __init__(self, name):
        self.name = name
        self.children = []

    def add_child(self, child):
        self.children.append(child)

    def display(self, level=0):
        result = "  " * level + self.name + "\n"
        for child in self.children:
            result += child.display(level + 1)
        return result


# Demo
root = ServiceTreeNode("Laundry Services")
wash = ServiceTreeNode("Washing")
dry = ServiceTreeNode("Dry Cleaning")
fold = ServiceTreeNode("Folding")
root.add_child(wash)
root.add_child(dry)
wash.add_child(fold)
print(root.display())
