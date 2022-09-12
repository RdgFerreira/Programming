NULL = -1 # The null link

class HeapManager :
  """ Implements a very simple heap manager ."""

  def __init__(self,memorySize) :
    """ Constructor . Parameter initialMemory is the array of
        data that we will
        use to represent the memory ."""
    self.memory = [0] * memorySize
    self.memory[0] = self.memory.__len__()
    self.memory[1] = NULL
    self.freeStart = 0

  # complete a função abaixo com a estratégia best-fit
  def allocate(self, requestSize):
    print("\nAllocating size: ", requestSize)
    size = requestSize + 1

    currentBlockSize = self.memory[self.freeStart]
    currentBlockIdx = self.freeStart
    lag = NULL

    minBlockSize = self.memory.__len__() + 1
    minBlockIdx = 0
    minLag = 0

    memorySize = self.memory.__len__()

    while True:
        print("lag: ", lag)
        print("currentBlockSize: ", currentBlockSize)
        print("currentBlockIdx: ", currentBlockIdx)
        if currentBlockSize == size: 
            minBlockSize = currentBlockSize
            minBlockIdx = currentBlockIdx
            minLag = lag
            break
        if currentBlockSize < minBlockSize and currentBlockSize > size: 
            minBlockSize = currentBlockSize
            minBlockIdx = currentBlockIdx
            minLag = lag
        
        if currentBlockIdx + self.memory[currentBlockIdx] >= memorySize: 
            print("HERE!")
            break
        
        lag = currentBlockIdx
        currentBlockIdx = self.memory[currentBlockIdx + 1]
        currentBlockSize = self.memory[currentBlockIdx]
    
    print("minlag: ", minLag)
    print("minBlockSize: ", minBlockSize)
    print("minBlockIdx: ", minBlockIdx)
    # self.memory[address] = idxNextFree
    nextFree = self.memory[minBlockIdx + 1]
    print("Nextfree: ", nextFree)

    unused = self.memory[minBlockIdx] - size
    print("unused: ", unused)
    if unused > 1:
      nextFree = minBlockIdx + size
      self.memory[nextFree]= unused
      self.memory[nextFree + 1] = self.memory[minBlockIdx + 1]
      self.memory[minBlockIdx]= size
    if minLag == NULL:
      self.freeStart = nextFree
    else:
      self.memory[minLag + 1] = nextFree
    
    print(self.memory, "freeStart: ", self.freeStart)
    return minBlockIdx + 1

    

  def deallocate(self, address):
    print("\ndeallocating address: ", address)
    if address < self.freeStart:
        self.memory[address] = self.freeStart
        self.freeStart = address - 1
    else:
        idxPrevFree = self.freeStart + 1  
        idxNextFree = self.memory[self.freeStart + 1]
        # print(idxPrevFree, idxNextFree)
        while(idxNextFree <= address):
            idxPrevFree = idxNextFree + 1
            idxNextFree = self.memory[idxNextFree + 1]
            # print(idxPrevFree, idxNextFree)
        self.memory[idxPrevFree] = address - 1
        self.memory[address] = idxNextFree
    print(self.memory, "freeStart: ", self.freeStart)



h = HeapManager(14)
a = h.allocate(4)
b = h.allocate(2)
c = h.allocate(3)
h.deallocate(a)
h.deallocate(c)
d = h.allocate(2)
print("\n\n",d)