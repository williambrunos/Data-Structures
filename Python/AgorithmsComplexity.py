# Spacial complexity => 4 + N
# Temporal complexity => 2 + 3 * (N/2)

def invertList(list):
  N = len(list)
  limit = int(N / 2)
  for i in range(limit):
    aux = list[i]
    list[i] = list[(N - 1) - i]
    list[(N - 1) - i] = aux
    
  return list

# Spacial complexity => 2 + 2 * N
# Temporal complexity => 2 + N

def secondInvertList(list):
  invertedList = []
  N = len(list)
  for i in range(N):
    invertedList.append(list[(N - 1) - i])
    
  return invertedList

myList = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print(invertList(myList))
print(secondInvertList(myList))