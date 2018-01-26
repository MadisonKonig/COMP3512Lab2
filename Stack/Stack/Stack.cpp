// Stack.cpp : Defines the entry point for the console application.
//

#include "Stack.hpp"
using namespace std;

void Stack::push(int n)
{
	//top_of_index++;
	stckarr[++top_of_index] = n;
}

void Stack::pop(int n)
{
	top_of_index--;
}

int Stack::top(int n) const
{
	return stckarr[top_of_index];
}

bool Stack::empty() const
{
	return top_of_index == -1;
}


