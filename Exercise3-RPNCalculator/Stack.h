#define MAX_STACK_SIZE 1024

class Stack
{
protected:
	int* stack;
	size_t size;
	unsigned int topIdx;

	void swap(unsigned int idxA, unsigned int idxB);
public:
	Stack(size_t size = MAX_STACK_SIZE);
	
	void push(int newVal);
	int pop();
	int peek();
	void reverse();

	bool isEmpty();
	bool isFull();
	unsigned int getCount();
};