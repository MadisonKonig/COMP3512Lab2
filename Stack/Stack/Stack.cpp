// Stack.cpp : Defines the entry point for the console application.
//

#include "Stack.hpp"
using namespace std;

void Stack::push(int n)
{
	top_of_index++;
	stckarr[top_of_index] = n;
}


