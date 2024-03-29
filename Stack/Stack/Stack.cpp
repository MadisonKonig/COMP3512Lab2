// Stack.cpp : Defines the entry point for the console application.
//

#include "Stack.hpp"
#include <ctime>
#include <random>
#include <iomanip>


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

//void stack::print() const
//{
//	cout << stckarr;
//	
//}

ostream& operator<<(ostream& out, const Stack& stack)
{
	for (int i = stack.top_of_index; i >= 0; i--) {
		out << setw(5) << "value: " << stack.stckarr[i] << "  index: " << i << endl;
	}
	return out;
}

Stack& Stack::operator=(Stack other)
{
	swap(*this, other);
	return *this;
}

void Stack::addRandom()
{
	default_random_engine generator(time(0));
	uniform_real_distribution <double> distrubition(0, 10);
	int TEN = 10;

	int randomArr[10];
	cout << "adding items directly to the stack" << endl;
	for (int i = 0; i < size(randomArr); i++) {
		double myRandom = distrubition(generator);
		randomArr[i] = myRandom;
		cout << setw(8) << "Adding: " << randomArr[i] << " to index: " << getIndex() << endl;
		push(randomArr[i]);
	}
}

void Stack::addFull()
{
	int TWENTY = 20;
	const int NEIN = 9;

	for (int i = TWENTY; i > NEIN; i--) {
	cout << "adding: " << i << " to index: " << getIndex() << endl;
	push(i);
	}
}


