class Node:
    def __init__(val,children):
        self.val=val
        self.children=children
    
def findRoot(nodes):
    children=set()
    for n in nodes:
        for c in n.children:
            children.add(c)
    for n in nodes:
        if n not in children:
            return n
    