from node import Node

node1 = Node(5)
node2 = Node(10)
print(node1.data)
print(node1.next)

node1.next = node2 
# Returns an object and its memory address
print(node1.next)
# Returns the value of data hold by the object on the
# attribute "next"
print(node1.next.data)