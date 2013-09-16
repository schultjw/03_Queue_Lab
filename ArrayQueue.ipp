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
	int n = 0;
	int j = 0;
	T[] array = new T[START_SIZE];
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {
	for(int i = 0; i < array.length; i++)
		delete array[i];
	delete[] array;
}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	array[n]=toAdd;
	n++;
	if(this.getNumItems = array.length)
		grow();
}

template <class T>
T ArrayQueue<T>::remove(){
	result = array[j];
	delete array[j];
	j++;
	return result;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return (j+i)%array.length;
}

template <class T>
void ArrayQueue<T>::grow(){
	T[] newArray = new T[array.length*2];
	T[] switcher;
	int i = n;
	int k = 0;
	do{
		newArray[k] = array[i];
		k++;
		i++;
		if(i==array.size)
			i=0;
	} while {i != n);
	n=k;
	j=0;
	switcher = array;
	array = newArray;
	switcher.~ArrayQueue;
}
