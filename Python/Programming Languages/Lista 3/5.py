from audioop import add
from curses.ascii import NUL


NULL = -1 # The null link

class HeapManager :
  """ Implements a very simple heap manager ."""

  def __init__(self, memorySize) :
    """ Constructor . Parameter initialMemory is the array of
        data that we will
        use to represent the memory ."""
    self.memory = [0] * memorySize
    self.memory[0] = self.memory.__len__()
    self.memory[1] = NULL
    self.freeStart = 0
    print("initial:", self.memory, "\n")

  def allocate(self, requestSize) :
    """Allocates a block of data , and return its address . The parameter requestSize is the amount of space that must be allocaed."""
    print("\nAllocating size: ", requestSize)
    size = requestSize + 1
    # Do first-fit search: linear search of the free list for the first block
    # of sufficient size .
    p = self.freeStart
    lag = NULL
    while p != NULL and self.memory[p] < size :
      lag = p
      p = self.memory[p + 1]
    if p == NULL :
      raise MemoryError()
    nextFree = self.memory[p + 1]
    # Now p is the index of a block of sufficient size ,
    # lag is the index of p’s predecessor in the
    # free list , or NULL , and nextFree is the index of
    # p’s successor in the free list , or NULL .
    # If the block has more space than we need , carve
    # out what we need from the front and return the
    # unused end part to the free list .
    unused = self.memory[p] - size
    if unused > 1:
      nextFree = p + size
      self.memory[nextFree]= unused
      self.memory[nextFree + 1] = self.memory[p + 1]
      self.memory[p]= size
    if lag == NULL :
      self.freeStart = nextFree
    else :
      self.memory[lag + 1] = nextFree
    
    print(self.memory, self.freeStart)
    return p + 1
    
  # complete a função abaixo
  def deallocate(self, address):
    print("\ndeallocating address: ", address)
    if address < self.freeStart:
        self.memory[address] = self.freeStart
        self.freeStart = address - 1
    else:
        idxPrevFree = self.freeStart + 1  
        idxNextFree = self.memory[self.freeStart + 1]
        print(idxPrevFree, idxNextFree)
        while(idxNextFree <= address):
            idxPrevFree = idxNextFree + 1
            idxNextFree = self.memory[idxNextFree + 1]
            print(idxPrevFree, idxNextFree)
        self.memory[idxPrevFree] = address - 1
        self.memory[address] = idxNextFree
    print(self.memory)
    print("freeStart: ", self.freeStart)

    

test = 1
if test == 0:
    h = HeapManager(14)
    a = h.allocate(4)
    # print(a, "\n")
    b = h.allocate(2)
    # print(b, "\n")
    c = h.allocate(3)
    # print(c, "\n")
    # print(h.memory)
    h.deallocate(a)
    h.deallocate(c)
elif test == 1:
    h28 = HeapManager(39)
    p0 = h28.allocate(3); h28.deallocate(p0); p0 = h28.allocate(6); p1 = h28.allocate(3); h28.deallocate(p0)

