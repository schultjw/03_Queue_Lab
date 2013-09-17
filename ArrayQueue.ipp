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

	int* backingArray = new int [START_SIZE];
	int arrayLength = START_SIZE;
	int numItems = 0;
	int front = 0;
	int end = (front + numItems)%arrayLength;
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	delete [] backingArray;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	if (toAdd + 1 > backingArray.arrayLength) 
		grow();
	backingArray[(front + numItems)] % backingArray.arrayLength = toAdd;
	numItems++;	 
}

template <class T>
T ArrayQueue<T>::remove(){
  int x = a[front];
  front = (front + 1) % backingArray.arrayLength;
  numItems--;
  if (backingArray.arrayLength >= 3*n) 
	grow();
return x;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){
	array<int> grow(max(1, 2*n));
	for (int i = 0; i < numItems; i++) 
		grow[i] = backingArray[(front + i) % backingArray.arrayLength];
	backingArray = grow;
}
