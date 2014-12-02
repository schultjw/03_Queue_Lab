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
	numItems = 0;
	backingArray = new T[numItems];
	//backingArraySize = numItems; //MODDED
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	//clean up after yourself
	delete[] backingArray;
	backingArray = NULL;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	/*
	numItems++;

	//Make a new array, put in the new item;
	T* myNewArray = new T[numItems];
	myNewArray[numItems - 1] = toAdd;

	//Copy over all the old items;
	for(unsigned int i=0;i<numItems-1;i++){
		myNewArray[i] = backingArray[i];
	}

	//delete[], not delete
	delete[] backingArray; //use delete/delete[] to remove things created using 'new'

	backingArray = myNewArray;
	//Now backingArray points to the new array, which is one size larger
	
	*/
	
	//Redo it with grow() and 'front'. Assume grow() works as intended.
	numItems++;

	if(numItems>backingArraySize){
		grow();
	}

	T* myNewArray = new T[numItems];
	myNewArray[(front+numItems)%backingArraySize] = toAdd;
	for(unsigned int i = 0; i<numItems;i++){
		myNewArray[i] = backingArray[i];
	}
	delete[] backingArray;
	backingArray = myNewArray;

}

template <class T>
T ArrayQueue<T>::remove(){
	if(numItems < 1){
		throw std::string("Queue is already empty, attempted to remove.");
		T ret = 0;
		return ret;
	}
	
	numItems--;

	//Make a new array, store old item
	T* myNewArray = new T[numItems];

	T retVal = backingArray[0];

	//Copy old items
	for(unsigned int i=0;i<numItems;i++){
		myNewArray[i]=backingArray[i+1];
	}

	//repoint backingArray
	delete[] backingArray;
	backingArray = myNewArray;

	//return removed item
	return retVal;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
	backingArraySiz = backingArraySize * 2;
	T* myNewArray = new T[backingArraySize];
	for(unsigned int i=0;i<numItems;i++){
		myNewArray[i] = backingArray[i];
	}
	delete[] backingArray;
	backingArray = myNewArray;
}
//update code so add(T toAdd) and remove() dont change array size by themselves if there's no room
//instead use grow() to double size of array so that there IS room
//((front+numArray)%backingArraySize) <- use that as the pointer, it will loop around to front of allocated memory if we hit the back