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

Information about the Von Neumann computing model may be helpful. This optional reading is section 2.2 of "Algorithms and Data Structures: A Basic Toolbox" by Melhorn and Sanders. A free copy may be found here: http://www.mpi-inf.mpg.de/~mehlhorn/ftp/Toolbox/Introduction.pdf

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Works. The remove() method verifies the array is not empty, then increments front and returns what was at the old front of the array.
2. Works. If grow() is not called, the new item is placed at the end (or rather, the first empty spot. The 'end' of the currently used information).
3. Works. The add() method checks if numItems is >= backingArraySize, and grows if that is true.
4. Works. Because the grow() method needs to copy the information into a new array, it is O(n) running time.
5. Works. delete[] is called when necessary.
6. Works. returns numItems, so very clearly is O(1) running time.
7. Works. If there are 0 items in the array, remove() will throw a string saying so.
8. Works. That's what the front variable is for, along with the modulus operator. 

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.
	If we used a Stack instead of a Queue, we would still need the grow() method, as well as a backingArray, backingArraySize, and numItems.
		We would NOT need the front variable, because a Queue is a first in first out structure, while a stack is a last in first out structure.
		We used front so that we could "remove" the first item in the Queue without needing a new array, but with a Stack, removing is done from the end, so numItems will serve that purpose.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?
	Remember that the grow() method is the ONLY place where the array should change sizes. If you add the grow() method after implementing the add(T) method,
		then the add(T) method needs to change it's implementation to reflect that.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?
	We write "class ArrayQueue : public Queue <T>".

#### 5. What is the purpose of "templates" in C++?
	Templates let a class be written while using generic types. Without a template, the class would need to be rewritten for each type (int, double, string, etc),
		while a template lets the class use all of those.

#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?
	int* array = new int[10];

#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?
	The destructor lets the class release (deallocate) any memory that was reserved for that instance of the class. This prevents a whole mess of problems
		that will be caused by leaving that memory allocated and inaccessible.