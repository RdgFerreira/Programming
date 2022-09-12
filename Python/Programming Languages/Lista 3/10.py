# Você pode modificar a classe Node, se necessário
class Node:
  def __init__(self):
    self.n = None
    self.e = ''

class MinStack:
    def __init__(self):
        self.v = [Node()]
        self.topIdx = 0
    
    def add(self, val : str):
        self.topIdx += 1
        newNode = Node()
        newNode.n = self.topIdx + 1
        newNode.e = val
        self.v = self.v + [newNode]

    def remove(self) -> Node:
        removedNode = self.v.pop()
        self.topIdx -= 1
        return removedNode

    def isNotEmpty(self) -> bool:
        return self.topIdx != 0
    
    def getSmaller(self) -> str:
        i = self.topIdx
        minStr = self.v[i].e
        
        while i != 0:
            if self.v[i].e < minStr: minStr = self.v[i].e
            i -= 1
        
        return minStr