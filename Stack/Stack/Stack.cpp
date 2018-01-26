// Stack.cpp : Defines the entry point for the console application.
//

#include "Stack.hpp"
#include "iostream"
#include "ctime"
#include "random"
#include "iomanip"
using namespace std;


void Stack::push(int n)
{
	if (top_of_index == TEN + EMPTY) {
		cerr << "Array full, ERROR" << endl;
	}
	else {
		stckarr[++top_of_index] = n;
	}
	
}

void Stack::pop()
{
	if (top_of_index == EMPTY) {
		cerr << "Array Empty, cannot pop, ERROR" << endl;
	}
	else {
		top_of_index--;
	}
}

int Stack::top() const
{
	if (top_of_index == EMPTY) {
		return -1;
	}
	else {
		return stckarr[top_of_index];
	}
}

bool Stack::empty() const
{
	return top_of_index == -1;
}

bool Stack::full() const
{
	return top_of_index == 10;
}

void Stack::print() const
{
	for (int i = top_of_index; i >= 0; i--) {
		cout << setw(5) << "value: " << stckarr[i] << "  index: " << i << endl;
	}
}

void Stack::addRandom()
{
	default_random_engine generator(time(0));
	uniform_real_distribution <double> distrubition(0, 10);
	int TEN = 10;
	
	int arraySize = TEN - sizeof(stckarr);
	int* randomArr = new int[arraySize];
	//int randomArr[arraySize];
	cout << "adding items directly to the stack" << endl;
	for (int i = 0; i < arraySize; i++) {
		double myRandom = distrubition(generator);
		randomArr[i] = myRandom;
		cout << setw(8) << "Adding: " << randomArr[i] << " to index: " << getIndex() << endl;
		push(randomArr[i]);
	}
}
