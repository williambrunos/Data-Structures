from node import Node

class LinkedList:
  def __init__(self):
    # Head is the firs element of the list, which one we use to earch for the
    # other ones trgought the structure.
    self.head = None
    self._size = 0
    
  # Appending some data at the list
  def append(self, data):
    if self.head == None:
      # Adding the first element on the list
      self.head = Node(data)
      self._size += 1
    else:
      # Adding the data at some position at the list while it already has at least
      # one element
      pointer = self.head
      
      while(pointer.next != None):
        pointer = pointer.next

      pointer.next = Node(data)
      
      self._size += 1
      
  # returns the length of the list
  def __len__(self):
    return self._size
    
  # get some data from an index of the list
  def __getitem__(self, index):
    pointer = self.head
      
    for i in range(index):
      if pointer != None:
        pointer = pointer.next
      else:
        raise IndexError("list index ot of range")
        
    if pointer != None:
      return pointer.data
     
    raise IndexError("list index out of range")
    
  # set a data at some index of the list
  def __setitem__(self, index, data):
    pointer = self.head
      
    for i in range(index):
      if pointer != None:
        pointer = pointer.next
      else:
        raise IndexError("list index out of range")
        
    if pointer != None:
      pointer.data = data
    else:
      raise IndexError("list index out of range")
    
  # Return the index of the data at the list
  def index(self, data):
    pointer = self.head
    i = 0
    
    while(pointer != None):
      if pointer.data == data:
        return i 
      pointer = pointer.next
      i += 1
      
    raise ValueError("{} is not in list".format(data))