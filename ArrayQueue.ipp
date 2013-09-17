//You will need this so you can make a string to throw in
// remove
#include <string>

int n = 0;

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
	front = 0;
	backingArray = new T[START_SIZE];
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	delete[] backingArray;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	if(getNumItems() == backingArraySize)
		grow();
	else if(n==backingArraySize)
		n=0;
	backingArray[n]=toAdd;
	n++;
}

template <class T>
T ArrayQueue<T>::remove(){
	if(getNumItems() == 0)
		throw std::string("That space in the queue is empty!");
	else{
		T result = backingArray[front];
		front++;
		return result;
	}
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return (front+n)%backingArraySize;
}

template <class T>
void ArrayQueue<T>::grow(){
	T* newArray = new T[backingArraySize*2];
	T* switcher;
	int i = front;
	int k = 0;
	do{
		newArray[k] = backingArray[i];
		k++;
		i++;
		if(i==backingArraySize)
			i=0;
	} while (i != n);
	n=k;
	front = 0;
	switcher = backingArray;
	backingArray = newArray;
	delete[] switcher;
}
