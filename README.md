Author
==========
"Decker, Benjamin", deckerbd
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

1. Works in required way in required time.
2. ^
3. ^
4. ^
5. ^
6. ^
7. ^
8. ^

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

For the most part, we wouldn't remove anything from the methods or variables, but rather tweak them to work with a Stack. We would still keep track of the amount of items that's in the data structure, that way we'd be able to use it in logic statements. We would also probably implement a peek method which allowed us to look at the next value in the Stack without popping it off of the stack. We would change remove to a pop function which just popped off the next item in the stack. We'd also change the add method into a push method to put things on top of the stack.

#### 3. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

Be careful of the order in which you do things; when manipulating these types of arrays, values you may be relying on can change between two lines of code where you may not expect a change to occur at a glance.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?

class ArrayQueue : public Queue <T>

#### 5. What is the purpose of "templates" in C++?

Its purpose is to make sure that anything declared with that class template also has some of the same local variables and methods.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?

int [10] newArray = new int[]; 

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?

In C++, destructors are used in order to delete dynamically allocated variables. Unlike Java, C++'s garbage collector does not clean up after you very well at all in regards to keeping track of what dynamically allocated variables are no longer being used and deleting them for you. This task is left for you to perform on your own in C++. The destructor is the place where you're deleting all of the variables for the object/the object itself from this dynamic allocation in order to potentially stop leaking memory which is not being used. In layman's terms, any object created with the use of the word "new" must also be deleted by you at some point, otherwise the memory allocated towards the object will never be released, causing a section of memory to no longer be available, a.k.a. a memory leak. Within this lab, the backingArray is dynamically allocated, as seen in the constructor, like so:

backingArray=new T[START_SIZE];

The backing array is actually deleted in two places: the destructor and the grow method:
// destructor
template <class T>
ArrayQueue<T>::~ArrayQueue() {
	delete[] backingArray;
}
// grow method
void ArrayQueue<T>::grow(){
... // Creating another array using new and putting values of old array into new 
backingArraySize=backingArraySize*2;
	delete[] backingArray;
	backingArray=largerBackingArray;
}

In the destructor, this is just deleting the backingArray since it will no longer be in use after the object is deleted.

In the grow method, we're using delete in order to delete the old array before setting the backingArray to the new larger backing array. In this way, we don't keep the old backing array floating around in memory without a way of it being removed (or at least very easily at all removed).

It's important to also note that any pointers also created with new must be deleted as well, otherwise their resource will also result in a memory leak if unable to be deleted due to a change in ability to access the pointer. Example of this would be:

int* b = new int(10);
// later in the program, this pointer must be deleted in order to return its resources
delete b;


Running Time Analysis
===========

#### 1. add - For add, without calling grow, add will perform in constant time (O(1)). This is due to the slot of the array we're going to insert our data is immediately known and able to accept our new data without having to loop through any part of the array. When add is called while also calling grow however, add will perform in linear time (O(n)). This is due to the fact that for each spot in the array, the call to grow is going to take O(n) time. This lead us to...

#### 2. grow - Grow performs in linear time (O(n)). This is due to having to reach every current value within the array while putting them all into a bigger array of arraySize*2, making it linear probing being done which takes linear time.

#### 3. remove - Like add, remove takes constant time. Because the remove method already knows where to remove our information from and we are never going to have to do any linear probing like add does when having to call grow, remove is always done in a constant amount of operations not dependant on the size of the array, making it constant time (O(1)).

#### 4. getNumItems - since this is just returning a local int and the size of the array doesn't affect this value at all since nothing is being added or removed from the array in this method, the running time for this method is constant time (O(1)).
