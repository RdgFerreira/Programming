class Node:
    def __init__(self):
        self.n = None
        self.e = ''

class Stack:
    def __init__(self):
        self.v = [Node()]
        # self.isEmpty = True
        self.topIdx = 0
    
    def add(self, val):
        self.topIdx += 1
        newNode = Node()
        newNode.n = self.topIdx + 1
        newNode.e = val
        print("Stacking...: (Next: ", newNode.n, ", str: ", newNode.e, ")")
        self.v = self.v + [newNode]

    def remove(self):
        removedNode = self.v.pop()
        print("Popping...: (Next: ", removedNode.n, ", str: ", removedNode.e, ")")
        self.topIdx -= 1
        # print(removedNode.e)

    def isNotEmpty(self) -> bool:
        return self.topIdx != 0

s = Stack()
s.add("oaidjoiajdoiasjdoiajds")
s.add("aijdijaodijaoidjoais")
s.add("abcdefghijklmopqrstuvwxyz")
s.remove()
s.remove()
s.remove()
s.add("aa")
s.add("bb")
s.add("cc")
s.remove()
s.remove()
s.remove()