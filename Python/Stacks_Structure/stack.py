from node import Node
class Stack:
  def __init__(self):
    self.top = None 
    self._size = 0
    pass

  # This method called "push" add an element(node) at the top of the stack,
  # references the last first node and change the reference of the head for it.
  def push(self, data):
    node = Node(data)
    if self.top == None:
      self.top = node 
    else:
      node.next = self.top
      self.top = node 
    self._size += 1
    pass 

  # Removes the element from the top of the stack and returns this node
  def pop(self):
    if self._size == 0:
      raise IndexError("Stack is already empty!")
    else:
      node = self.top
      self.top = node.next
      self._size -= 1
      return node.data
    pass
  
  def __len__(self):
    return self._size
  
  # Returns the element on the top of the stack without removing it
  def peek(self):
    if self._size > 0:
      return self.top.data
    else:
      raise IndexError("Stack is emprty!")
    pass
  
  def __repr__(self):
    r = ""
    pointer = self.top
    while(pointer != None):
      r = r + str(pointer.data) + "\n"
      pointer = pointer.next
      
    return r 
    
  def __str__(self):
    return self.__repr__()