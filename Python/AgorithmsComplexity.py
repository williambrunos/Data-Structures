# Location complexity => 4 + N
# Time complexity => 2 + 4 * (N/2) = 2 + 2 * N => 2*N => O(N)

def invertList(list):
  N = len(list)
  limit = int(N / 2)
  for i in range(limit):
    aux = list[i]
    list[i] = list[(N - 1) - i]
    list[(N - 1) - i] = aux
    
  return list

# Location complexity => 2 + 2 * N
# Time complexity => 2 + N => N => O(N)

def secondInvertList(list):
  invertedList = []
  N = len(list)
  for i in range(N):
    invertedList.append(list[(N - 1) - i])
    
  return invertedList

# Location Complexity => 2 + N
# Time Complexity => 2 + 2 * N => O(N) 

def haveDuplicateValues(list):
  N = len(list)
  for i in range(N):
    if(list.count(list[i]) != 1):
      return True
  
  return False

# Time Complexity => N - 1 + N - 2 + ... + 1 => N*(N)/2 => O(N²)
# Location Complexity => 2 + N

def haveDuplicateValuesSecondOption(list):
  for i in range(len(list)-1):
    for j in range((i+1), len(list)):
      if(list[i] == list[j]):
        return True
  
  return False