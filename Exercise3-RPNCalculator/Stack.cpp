#include <string>

#include "Stack.h"

using namespace std;

// Constructors //
Stack::Stack(size_t size)
{
	this->stack = new int[size];
	this->size = size;
	this->topIdx = 0;
}

// Pushing 
void Stack::push(int newVal)
{
	if (this->topIdx < this->size)
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

// Getters //
bool Stack::isEmpty()
{
	return this->topIdx == 0;
}

bool Stack::isFull()
{
	return this->topIdx == this->size - 1;
}

size_t Stack::getCount()
{
	return this->topIdx;
}

// Swapping //
void Stack::swap(unsigned int idxA, unsigned int idxB)
{
	if (idxA >= 0 && idxA <= this->topIdx && idxB >= 0 && idxB <= this->topIdx && idxA != idxB)
	{
		int tempA = this->stack[idxA];
		this->stack[idxA] = stack[idxB];
		this->stack[idxB] = tempA;
	}
}

// Reverse function //
void Stack::reverse()
{
	for (int i = 0; i < (int) this->getCount() / 2; i++)
		swap(i, this->getCount() - 1 - i);
}