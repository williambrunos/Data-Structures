# Location Complexity => 3 + n
# Time Complexity => 1 + 2 * n => O(n)

def linearSearch(list, key):
  ''' Returns the index of the element on the list or None if it doesn't find'''
  n = len(list)
  for i in range(n):
    if list[i] == key:
      return i 
  
  return None

# Location Complexity => 4 + n 
# Time Complexity => O(log(n)) 
def binarySearch(list, key):
  begin = 0
  end = len(list) - 1
    
  while(begin != end):
    mid = (begin + end) // 2
    if key < list[mid]:
      end = mid - 1
    elif key > list[mid]:
      begin = mid + 1
    elif key == list[mid]:
      return mid
  
  return None
    
myList = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
index = linearSearch(myList, "Python")

if index is None:
  print("Not found")
else:
  print("Found at the index {}".format(index))
      