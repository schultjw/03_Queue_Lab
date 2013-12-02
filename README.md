Author
==========
"Zhong, Mingwei", zhongm2
03_Queue_Lab
============

Implement an array-based queue in C++

Note: When you create your project, do NOT add ArrayQueue.ipp to the list of source files, add it to the list of include files. You will see that ArrayQueue.ipp is #included at the bottom of ArrayQueue.h. See ArrayQueue.h for more explanation.

Requirements
------------

1. remove takes O(1) time
2. add takes O(1) time, unless it calls grow (in that case O(n) is okay)
3. grow is only called if the number of items == backingArraySize, and the size of the array is doubled during grow
4. grow takes O(n) time
5. Do not leak memory (make sure grow and the destructor do the right thing)
6. getNumItems is O(1) time
7. add and remove throw excpetions as appropriate
8. You must use the array in a circular fashion. If you don't do this you probably won't be able to get #1, #2 and #3 to all be true.

Reading
=======
"Open Data Structures," Chapter 2, up through section 2.4 (ArrayDequeue). http://opendatastructures.org/ods-cpp/2_Array_Based_Lists.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

********************************************************************************


1. `remove()` method works. First of all, check if it does exist elements in the
array, if it does, remove the front element. Then increase the index of front 
element as one. And then if you call `remove()` again, it will repeat the same 
way to do so. If there is no element in the array, throw an exception. The 
running time of `remove()` method is `O(1)`.

2. `add()` method works. First of all, check if the array is full. If it is full, then check if backingArray is vaild, otherwise throw an exception. The time 
complexity will be `O(1)` without calling `grow()`.

3. `grow()` method works. Create an new array and copy the elements from 
original array to new array.

4. No memory leak, once you use delete[], the given arguement in destructor will be called and free the memory. Also set the pointer to be NULL pointer. 

5. grow takes `O(n)` times, because the runing time of `grow()` method depends 
on how many elements in the array that need to be copied.

6. `getNumItems()` takes `O(1)` time because it simply just returns a value.

7. `remove()` throws an exception appropriately.

8.  Array is circular.

********************************************************************************

### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

********************************************************************************

The methods to keep:

`add()`

`remove()`

`getNumItems()`

`grow()`

The methods we get rid of:

None.

*******************************************************************************


The variables to keep:

`backingArray`

`numItems`

`backingArraySize`


The variable to get rid of: `front`


********************************************************************************


The reason to keep: we need to add, remove,get the number of items in the array  and resize the array.



********************************************************************************

Why get rid of `front`:

The reason is Stack is last in first out policy, so keep tracking the first 

element in the array is useless.


********************************************************************************

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?


Implementing Queue by using circular-array based is very useful.


********************************************************************************


#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?

class ArrayQueue : public Queue {};



********************************************************************************


#### 5. What is the purpose of "templates" in C++?

1. To avoid repeating code which is identical except for different types.

2. To generate code in compile time.


********************************************************************************


#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
 
 //Allocate the memory.

 int *array = new int[10];
 

********************************************************************************


#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?

Java uses managed memory, programmers can allocate memory by using new operator,
and deallocate memory by relying on the garbage collector. Java takes care of
memory management for programmers. However, C++ doesn't handle its own memory, 
every time the programmers use delete() method the destructor of given 
arguement will be called, and return memory allocated by new back to heap in
order to avoid memory leak.

********************************************************************************


