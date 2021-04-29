# About this repository

Hey you! This is my repository for studies on Data Structures algorithms area using C and Python(and maybe some Java, maybe). There will be the code fully explained above and some important concepts in this README.

## What are pointers?

### Definition

Pointers are special variables which holds a different value. This is different value is an address, an memory address of another variable or structure. With this powerful instrument, you can have access to other variables or even change their contents without putting your hands(or code)on it! When we declare a pointer without initializing it, it will points for somewhere on our main memory, which means that it will have a random value on it, and we can change this scenario just initializing the pointer.

### How to declare pointers

Pointers, in the C language, are declared as any other variable, but with a "*" on it. Like this:

```C
int normalVariable = 12;
int *pointer;
```

The pointer holds a memory address, so we can make that pointer we just created hold the address of the other normal variable? Yes, and we can even change the value of the normal variable with the pointer, using *p. *p give to us the value which p pointers. Confuse? On the next case, pointer will point to te normal variable based on its address, and we will change it value with *p;

```C
int normalVariable = 12;
int *pointer;
pointer = &normalVariable // pointer holds the address of normalVariable
*pointer = 14; 
/* The value which pointer points is now changed to be 14,
 which means that the value of the normal variable is now 14.
*/
```

If we don't want to work anymore with our pointer, we can free it with the function free() or even saying that the pointer will not point to anywhere(NULL).

```C
free(pointer);
// or pointer = NULL;
```