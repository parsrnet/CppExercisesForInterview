#include <string>

#include "Stack.h"

using namespace std;

/*
	If you know how a Stack works, there is very little to say here. This is a bare-minimum stack container with the ability to reverse for 
*/

// Constructors //
Stack::Stack(size_t _size)
{
	stack = new int[_size];
	size = _size;
	topIdx = 0;
}

// Pushing  //
void Stack::push(int newVal)
{
	if (topIdx < size)
	{
		stack[topIdx++] = newVal;
	}
}

// Popping //
int Stack::pop()
{
	return stack[--topIdx];
}

// Peeking //
int Stack::peek()
{
	return stack[topIdx - 1];
}

// Getters and Helpers //
bool Stack::isEmpty()
{
	return topIdx == 0;
}

bool Stack::isFull()
{
	return topIdx == size - 1;
}

size_t Stack::getCount()
{
	return topIdx;
}