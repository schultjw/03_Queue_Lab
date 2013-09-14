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
ArrayQueue<T>::ArrayQueue(){
    return new ArrayQueue(START_SIZE);
    front = 0;
    int end = 0;
    int size = START_SIZE;

}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
   this.delete[];

}

template <class T>
void ArrayQueue<T>::add(T toAdd){
    if(end>size)
    this.grow();
    this[end] = toAdd;
    end ++;

}

template <class T>
  T ArrayQueue<T>::remove(){
  T thingToRemove = this[start];
  front ++;
  if (front>=size)
  front = 0;
  
  return thingToRemove;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
    return ((size+end)-front)%size;

}

template <class T>
void ArrayQueue<T>::grow(){
   ArrayQueue original = this;
   ArrayQueue created = new ArrayQueue();

}
