from stack import Stack

pilha = Stack()
for i in range(0, 11):
  pilha.push(i)

for i in range(0, 3):
  pilha.pop()
  
print(pilha)
  