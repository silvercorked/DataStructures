
#include <iostream>
#include <assert.h>

#include "LinkedList.hpp"


using namespace DataStructures;

void testLinkedList();
void fill(LinkedList<int>*);

int main() {
	std::cout << "hello world" << std::endl;
	LinkedList<int>* l = new LinkedList<int>();
	for (int i = 0; i < 100000; i++)
		l->push(i);
	std::cout << "full " << l->size() << std::endl;
	for (int i = 0; i < 100000; i++)
		l->dequeue();
	std::cout << "empty " << l->size() << std::endl;
	for (int i = 0; i < 100000; i++)
		l->push(i);
	std::cout << "full " << l->size() << std::endl;
	for (int i = 0; i < 100000; i++)
		l->dequeue();
	std::cout << "empty " << l->size() << std::endl;
	for (int i = 0; i < 100000; i++)
		l->push(i);
	std::cout << "full " << l->size() << std::endl;
	for (int i = 0; i < 100000; i++)
		l->dequeue();
	std::cout << "empty " << l->size() << std::endl;
	delete l;
	//testLinkedList();
	return 0;
}

void testLinkedList() {
	LinkedList<int>* l = new LinkedList<int>();
	int temp;
	assert(l->size() == 0);
	assert(l->isEmpty());
	
	fill(l);
	assert(l->size() == 1000);
	for (int i = 0; i < 1000; i++)
		assert(l->get(i) == i);
	assert(l->contains(500));
	assert(!l->contains(4000));
	for (int i = 0; i < 1000; i++)
		assert(l->remove(0) == i);
	
	for (int i = 999; i >= 0; i--)
		assert(l->insert(0, i));
	for (int i = 0; i < 1000; i++) {
		temp = l->get(i);
		std::cout << "insert at " << i << " was " << temp << std::endl;
		assert(temp == i);
	}
	temp = l->dequeue();
	std::cout << temp << std::endl;
	for (int i = 0; i < 999; i++)
		assert(l->get(i) == i);
	assert(temp == 999);
	assert(l->size() == 999);
	l->enqueue(temp);
	assert(l->size() == 1000);
	assert(l->get(0) == 999);
	temp = l->get(l->size() - 1);
	std::cout << temp << std::endl;
	assert(temp == 998);
	for (int i = 1; i < 1000; i++)
		assert(l->get(i) == i - 1);
	temp = l->get(1);
	std::cout << temp << std::endl;
	assert(temp == 0);
	l->insert(0, 50);
	assert(l->size() == 1001);
	assert(l->get(0) == 50);
	assert(l->get(1) == 999);
	assert(!l->isEmpty());
	assert(l->get(0) == l->peek());
	assert(l->pop() == 50);
	assert(l->peek() == l->pop());
	for (int i = 0; i < 999; i++) {
		temp = l->pop();
		std::cout << "popped was: " << temp << std::endl;
		assert(temp == i);
	}
	

	std::cout << "all asserts passed. LinkedList is good." << std::endl;
}

void fill(LinkedList<int>*  l) {
	for (int i = 0; i < 1000; i++) {
		l->add(i);
	}
}