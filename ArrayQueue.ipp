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
	//Declare private Variables
	new unsigned long backingArraySize = START_SIZE;
	T* backingArray;
	unsigned long numItems = 0;
	unsigned long front = 0;

}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	//De-allocate used memory
	delete[] backingArray;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	//if(numItems == backingArraySize) grow();

	//toAdd = a[(j+n) % backingArraySize]; n++;
}

template <class T>
T ArrayQueue<T>::remove(){
	//T toAdd = a[j];
	//j = (j+1) % a.length;
	//n--;
	//if (a.length >= 3*n) grow();
	//return toAdd;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){

}

template <class T>
void ArrayQueue<T>::grow(){
	//array<T> b(max(1,2*n));
	//for (int k = 0; k < n; k++)
		//b[k] = a[(j+k)%a.length];
	//a = b;
}
