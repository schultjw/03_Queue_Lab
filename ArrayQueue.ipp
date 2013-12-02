//You will need this so you can make a string to throw in
// remove
#include <string>


//Syntax note: This uses the pre-processor to create a constant
// You could also use "const static" to make a constant, as in Java.
// Notice, however, that START_SIZE is NOT a variable! Instead, any
// place that the pre-processor sees "START_SIZE" it will replace it with
// 10 ... so this is like a global "find and replace".
#define START_SIZE 10

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this ArrayQueue() method belongs to the
// ArrayQueue<T> class.

template <class T>
ArrayQueue<T>::ArrayQueue()
{

        //Initizlize the size of array as 10.
        backingArraySize = START_SIZE;

        //Allocate the memory.
        backingArray = new T[backingArraySize];

        //The front index of element in array.
        front = 0;

        //Record the number of elements in the array.
        numItems = 0;
}

template <class T>
ArrayQueue<T>::~ArrayQueue()
{

        //Free the memory.
        delete [] backingArray;

        //Set backingArray to be NULL.
        backingArray = NULL;
}

template <class T>
void ArrayQueue<T>::add(T toAdd)
{

//To check if backingArray is full.

  if(numItems + 1 > backingArraySize)

     {

     if(backingArray == NULL)
     {

        throw std::string("Error! Something bad happens in array");

     }


           grow();

     }

  //The reason to do "front + numItems" here is to let the array be circular.
  //For instance, you add an element at index 0 and then delete it, the "front"
  //will be 1(check remove method), then you add an element at index 1 and delete it
  //the "front" will be 2...and so on. If the size of array is 10 and you add an element
  //at index 9 and delete it, the "front" will be 0(see remove method), which means you start to add elements
  //at the first index of array. Therefore it is circular.
  backingArray[ ( front + numItems) % backingArraySize ] = toAdd;

  //After adding one element in the array, increase the number of element as one.
  numItems++;
}

template <class T>
T ArrayQueue<T>::remove()
{

   //Create a object which will hold a element that needs to be removed.
   T rm;

  //Throw a exception if no element in the array.
  if(numItems == 0)
      {
          throw std::string("Error! There is no element is the queue.");
      }

  rm = backingArray[front];



  //After delete a element, increase the index of front element as one.
  //Therefore, the array will be circular and you don't need to resize
  //the array as long as you add an element in an array and then delete it.
  //For instance, the array size is 10 and after you remove an element in index 9,
  //then the "front" will be 0.
  front = ( (front+1) % (backingArraySize) );

  //Decrease the number of element in the array.
  numItems--;

  //Return rm.
  return rm;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){

        return numItems;

}

template <class T>
void ArrayQueue<T>::grow()
{


    //To increase the front index of array.
    int count = 0;

    T *newArray = new T[2 * backingArraySize];

        while(count<numItems){

                /*
                  The reason to do "front+count" is because the "front"
                  is not always be 0. For example, the original size of
                  array is 10. You can add "1" and delete "1", add "2" and delete "2",
                  add "3" and delete "3". After this, you keep adding elements 1000 times without
                  removing. In this case the "front" is 3.

                  The reason to do "( front+count ) % backingArraySize" is because
                  the backingArraySize will change after "grow()". To avoid array being out
                  of bound.
                */
                newArray[ (front + count) ] = backingArray[ ( front+count ) % backingArraySize ];

                count++;
        }

        backingArraySize = 2 * backingArraySize;

        delete[]backingArray;
        backingArray = NULL;
        backingArray = newArray;


}

