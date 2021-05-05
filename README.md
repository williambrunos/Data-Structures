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

### Algorithms Complexity

This term, "complexity", is nothing more than the analysis of the resources needed
by the algorithm to run. This resources are: memory and CPU, as you have known,
a code needs memory to store the variables and CPU for processing the data,

This notation is an approximation, just to let us analyse how the algorithm consume
resources of the computer as the length of the input raises.

* Spacial complexity => Measure how much memory the algorithm needs
* Temporal complexity => Measure how much processing time the algorithm needs.

### Abstract Data Type(ADT)

On our course of Data Structures, we will have to create our own structs of data,
as in C as in Python. But, what are these ADT's? ADT's are collections of data
(variables) with a logical connection among them. We store an amount of variables
and functions in one unique data structure. For these ADT's, the data is encapsuled,
which means that we can add, remove or even have access to the content of the data
with functions.