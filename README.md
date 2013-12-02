Author
==========
"Bailey, Sam", baileys2
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

1. The remove method takes O(1) time as it should, as there are no loops, recursive calls, or other things that would cause a variable run time.
2. The add method takes O(1) time as it should, as there are no loops, recursive calls, or other things that would cause a variable run time unless grow is called. If grow is called then add will take O(n) time because the run time of grow is dependent on the number of items currently in the queue (n items).
3. The grow method is only called if numItems = backingArraySize (as seen in the add method) and the size of hte array is doubled during grow (as seen in the first line of the grow method).
4. The grow method takes O(n) time because it is dependent on the number of items currently in the array (n items).
5. No memory is leaked while the program is being run, as the destructor and grow method perform as they should.
6. The getNumItems method takes O(1) time because all that it does is simply call the numItems variable.
7. The add method throws and exception when ______________ and the remove method throws an exception when it is called and there are no items currently in the queue.
8. The array used to store all of the item data is used in a circular fashion.

#### 2. If we did a Stack instead of a Queue, which of the private methods and variables would we need to keep, and which could we get rid of? Explain your answer.

If a Stack was used instead of a Queue, the grow method would need to be kept, along with the backingArray and numItems variables. The front and backingArraySize variables would no longer be necessary, however, as the size of the array would be determined by the numItems variable and when an item is removed each iem after it is simply moved over one slot to the left.

#### 3. What is one question that confused you about this excercise, or one piece of advice you would share with students next semester?

One piece of advice that I would share with students next semester is to pay special attention to the order in which things are written in the methods, as I encountered some errors with the place in my remove method in which I updated the front variable.

#### 4. In Java you might write "class ArrayQueue extends Queue" ... how do you write the same thing in C++?



#### 5. What is the purpose of "templates" in C++?



#### 6. What would the syntax be for dynamically allocating an array of 10 ints, in C++?



#### 7. What is the purpose of a class destructor in C++? Why don't you need them in Java?

