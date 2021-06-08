from node import Node

class LinkedList:
  def __init__(self):
    # Head is the firs element of the list, which one we use to earch for the
    # other ones trgought the structure.
    self.head = None
    self._size = 0
    pass
    
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
    pass
      
  # Recieves an index of the list(starting with 0) and the data. 
  # Create a node with the data and inserts it in the list
  def insert(self,data, index):
    if index == 0:
      node = Node(data)
      node.next = self.head
      self.head = node
    else:
      pointer = self.head
      counter = 1
      while ((pointer != None) and (counter != (index - 1))):
        pointer = pointer.next
        counter += 1
      if pointer != None:
        node = Node(data)
        node.next = pointer.next
        pointer.next = node 
      else:
        raise ValueError('Index is out of the bounds of list')
    self._size += 1
    pass
      
  # returns the length of the list
  def __len__(self):
    return self._size
    pass
  
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
    pass
    
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
    pass
    
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
    pass
  
  def print_list(self):
    pointer = self.head
    i = 1
    while(pointer != None):
      print("\n| Node {} : \n| Data: {} \n".format(i, pointer.data))
      i += 1
      pointer = pointer.next
    pass
  
  def remove_node_by_value(self, value):
    pointer_after = self.head.next
    
    if self.head == None:
      print("List is already empty!")
    elif self.head.data == value:
      self.head = pointer_after  
    else:
      pointer_before = self.head
      while((pointer_after != None) and (pointer_after.data != value)):
        pointer_before = pointer_after
        pointer_after = pointer_after.next
      pointer_before.next = pointer_after.next
      pointer_after = None
    pass