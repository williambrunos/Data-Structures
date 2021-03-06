# About this repository

Hey you! This is my repository for studies on Data Structures algorithms area 
using C and Python(and maybe some Java, maybe). There will be the code fully 
explained above and some important concepts in this README.

## What are pointers?

### Definition

Pointers are special variables which holds a different value. This is different 
value is an address, an memory address of another variable or structure. With 
this powerful instrument, you can have access to other variables or even change
their contents without putting your hands(or code)on it! When we declare a 
pointer without initializing it, it will points for somewhere on our main 
memory, which means that it will have a random value on it, and we can change 
this scenario just initializing the pointer.

### How to declare pointers

Pointers, in the C language, are declared as any other variable, but with a "*"
 on it. Like this:

```C
int normalVariable = 12;
int *pointer;
```

The pointer holds a memory address, so we can make that pointer we just created 
hold the address of the other normal variable? Yes, and we can even change the 
value of the normal variable with the pointer, using *p. *p give to us the value
 which p pointers. Confuse? On the next case, pointer will point to te normal 
 variable based on its address, and we will change it value with *p;

```C
int normalVariable = 12;
int *pointer;
pointer = &normalVariable // pointer holds the address of normalVariable
*pointer = 14; 
/* The value which pointer points is now changed to be 14,
 which means that the value of the normal variable is now 14.
*/
```

*obs: The address which the pointer holds can only be of a variable with the 
same type of the pointer.

If we don't want to work anymore with our pointer, we can free it with the 
function free() or even saying that the pointer will not point to 
anywhere(NULL).

```C
free(pointer);
// or pointer = NULL;
```

### Operations with pointers

We can only sum and subtracts integer values from the pointers. However, this 
operations respects the size of the type of the variables which the pointer 
points. Because of this, any operation made with a pointer like: 
pointer = pointer +- n, n is an integer, will be interpreted 
like: address = address +- n * sizeof(pointer_type), address is the address of 
the variable which the pointer points. 

Furthermore, we can compare the address hold by pointers using comparison 
operators: ==, !=, >, <, >=, <=.

### Pointers and Arrays

Arrays, at theirs essence, are nothing more than one pointer that access the
first value of the array and with the arithmetic operations(+ and -) with this
pointer, the program has access to the another values, based on the size of  
the data inside the array. The name of the array, without [], is the address 
of the first value of it.

```C
int array[5] = {1, 2, 3, 4, 5};
int *pointer = array; // pointer -> first value of the array
// pointer ++ -> second value of the array
// pointer ++ -> third value of the array and so on...

int i;
for(i = 0; i < 5; i++) {
  printf("array[%d] = %d \n", i, array[i]);
}

for(i = 0; i < 5; i++) {
  printf("array[%d] = %d \n", i, pointer[i]);
}

for(i = 0; i < 5; i++) {
  printf("array[%d] = %d \n", i, *(pointer + i));
}
/// These 3 for loops will print on the console the same results
```

We can also create an array of pointers. How does it works? It's a array as we 
worked since before, but each value of it is a pointer, which means that each 
value points to other memory region. Why to use it? We can make an value of the
array points to other value or array of different types, and this is how we 
create dynamic matrices!

```C
dataType *arrayName[size];
```

### Pointers for pointers

In C, we can make arbitrary pointers for pointers, which ones the number of '*' 
on its declarations represents the number of levels of the pointer.

```C
int x = 10;
int *intPtr = &x;
int **intPtrPtr = &intPtr;
int ***intPtrPtrPtr = &intPtrPtr;

printf("intPtrPtrPtr = %d \n", intPtrPtrPtr); // &intPtrPtr
printf("*intPtrPtrPtr = %d \n", *intPtrPtrPtr); // &intPtr
printf("**intPtrPtrPtr = %d \n", **intPtrPtrPtr); // &x
printf("***intPtrPtrPtr = %d \n", ***intPtrPtrPtr); // x
```

## Algorithms Complexity

This term, "complexity", is nothing more than the analysis of the resources needed
by the algorithm to run. This resources are: memory and CPU, as you have known,
a code needs memory to store the variables and CPU for processing the data,

This notation is an approximation, just to let us analyse how the algorithm consume
resources of the computer as the length of the input raises.

* Location complexity => Measure how much memory the algorithm needs
* Time complexity => Measure how much processing time the algorithm needs.

## Abstract Data Type(ADT)

On our course of Data Structures, we will have to create our own structs of data,
as in C as in Python. But, what are these ADT's? ADT's are collections of data
(variables) with a logical connection among them. We store an amount of variables
and functions in one unique data structure. For these ADT's, the data is encapsuled,
which means that we can add, remove or even have access to the content of the data
without calling functions.

We are concerned on the implementation of the functions, not on the "how" they are
done(specification).

- Specification -> Headers and semantic -> headers of the functions
- Implementation -> Algorithms -> Encapsuled -> Public Interface

In C, the default method to implement a ADT is:

* Create an archive with .h extension and declare the prototypes of the functions
of the struct. -> **Specification**

* Create an archive with .c extension with the same name of the .h and declare
the struct and construct the functions that had been declared yet in the .h 
archive. -> **Implementation**

* Create an archive with .c extension to implement the structs and functions of
the other archives.

* obs: It's important to include the .h archive in the others .c files to have 
access to the functions prototypes. Like this:

```C
#include "name_of_the_archive.h"
```

### Advantages for using ADT's:

We can see on our work three main advantages for using these abstract data types:

- Reusing: We just need to compile the implementation of the functions one time
and reuse it whenever we need.

- Maintenance: If we modify only the **implementation** of the functions, not the
specification, it will not change the source code that uses this function.

- Abstraction: The implementation of the functions are abstracts, so the user of
these doesn't need to know every detail of it, just the header and what data pass
as arguments to see the function acting.

## Sequency Allocated List:

Is a common list, declared and created in memory with values in sequencial
position, accessed by the first one and the data types. In python, as we can
store data with different data types, we store all them as pointers, with the
"pointer" type, and use them to access these values.

* Element adding: In a list, when we add an element in it, the computer will "push"
the others to the left to fill the list => Time Complexity: O(n)

* Element removing: When we remove an element on some index, the computer will
"pull" the others to the left to fill the list => Time Complexity: O(n)


## Linked List

In a linked list, the data is not sequency allocated in memory, it is scattered
in the RAM memory. How do these data can have access to each other? Through 
some structures named **Nodes**. Nodes are structures that holds the data we want
to store and a variable that points to the next Node.

So, the code of this structure is simple, because all of the manipulations in the
linked list will be done by another class, the list itself.

- Code in Python for the Node Structure

```Python
class Node:
  def __init__(self, data):
    self.data = data
    self.next = None
```

At the initialization of a node, we don't have to initialize the variable next,
since we don't have another node(yet) to link it.

### Adding elements at the end of the list

In this algorithm we have two cases:

* The list is empty so we can just put the data in the head(first node) of the list
* The list is not empty, and we have to search throughout all the list until we
find the last node and put the data given as a parameter in the next node

In the worst case, the time complexity of the "append" function is O(n), 'n' is 
the length of the linked list at some point.

### Getting some data from the list

We pass as argument an index which one we will get the element at it on the list.
The variable "pointer" will go through all the list, and at the point given as
argument, it will stop and return the data of the pointer.next at that point.

* Time complexity of this algorithm is O(n), as n is the list length

### Setting some data at an index of the list

In this algorithm, at the worst case, we have a O(n) situation. Our variable
pointer will go trough all the list until find the Node with the index passed
as argument for the function.
 
## Stacks

Stacks are data structures which the data are ordered in a stack, with access
politics being FILO, First In Last Out, which means that the first element added
at the stack will be the last one to get removed, and the last element added, will
be the first to be removed.

### Adding elements in a Stack(Push)

In this function, we create a node(like the ones in linked lists), add the
reference of the second and consequently, to the rest of the stack, for the new
node created with the value received as parameter. Update the top reference to
be the new node added a the stack.

### Removing elements in a Stack(Pop)

In this function, we create a pointer(reference) to the top of the stack, make 
the top of the stack be the next sequencial node, and returns the other reference
and cleans it from memory.

### Returning the element at the top(Peek)

In this function, we just have to return the data in the node of the top of the
stack.

## Queues

Queues are data structures with access politics based on FIFO(First In First Out),
which means that the first element added at the list will the first one to get
removed. 

This structure is simple, constructed based on nodes to get more scalability for
our queue. 

## Sorting Algorithms

### QuickSort

The quicksort algorithm is based at: managing the algorithm in all the array, sort
it partially, apply the algorithm at the rest of the array which is not sorted,
recursively. Continue sorting until the sub array to be sorted has length equal to
0 or 1.

**Algorithm**

- Step 1:

Choose, arbitrary, a pivot element in the array.

- Step 2:

Declare variables 'a' and 'b', 'a' will be in position of the array which is next
to(to the right) the pivot, 'b' will be in the last position of the array(v[length-1]).

- Step 3:

Move 'a' forward to the right in the array until the program find an element major
than the pivot and 'b' backward in the array until the program find an element
minor or equal to the pivot.

- Step 4:

Once the program have accomplished step 3, hold 'a' and 'b' at their positions,
if a < b => exchange v[a] and v[b], increment 'a' by 1 and decrement 'b' by -1.

Repeat step 3. 

if a > b => exchange the pivot with v[b]. The value at 'b' now will no longer
exchange. So, now we have a sub array on the right of 'b' and on left of 'b'.
-Step 5:

Repeat recursively the algorithm for the both sub arrays that had left.

**Time Complexity**
The time complexity of the QuickSort algorithm is O(nlog(n)) at the medium case.
At the worst case(the array is already sorted) the time complexity is O(n??).
