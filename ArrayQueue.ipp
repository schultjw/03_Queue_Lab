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
	T* backingArray = new T[START_SIZE];
	numItems = 0;
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	delete[] backingArray;
// cannnot delete objects that are not pointers
	//delete [] testQueue;
	
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
// ACTUALLY ADD TO ARRAY!
	int end = (front+numItems) % backingArraySize;
	//backingArray[end] = toAdd;
	backingArray[0] = toAdd;
	
	numItems++;
	
		
}

template <class T>
T ArrayQueue<T>::remove(){
// REMOVE FROM ARRAY!
	//throw (std::string) "Improper!";
	//int x = backingArray[front];
	front = (front + 1) % backingArraySize;
	numItems--;
	
	//return x;
return 6;

}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
// if (numItems == backingArraySize)
// not constant time
// old array too small,  make new array(twice as big) copy old data into array
// running time n
}
