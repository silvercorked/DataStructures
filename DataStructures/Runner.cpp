
#include <iostream>
#include <assert.h>

#include "LinkedList.hpp"
#include "ArrayList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

using namespace DataStructures;

/*
void testStack(Stack<int>*);
void testQueue(Queue<int>*);
void testList(List<int>*, std::string);

void testAdd(List<int>*);
void testInsert(List<int>*);
void testSet(List<int>*);
void testGet(List<int>*);
void testIndexOf(List<int>*);
void testRemove(List<int>*);
void testContains(List<int>*);
void testClear(List<int>*);
void testToArray(List<int>*);

void testStackPeek(Stack<int>*);
void testQueuePeek(Queue<int>*);
void testListPeek(List<int>*);

void testStackPush(Stack<int>*);
void testListPush(List<int>*);

void testStackPop(Stack<int>*);
void testListPop(List<int>*);

void testQueueEnqueue(Queue<int>*);
void testListEnqueue(List<int>*);

void testQueueDequeue(Queue<int>*);
void testListDequeue(List<int>*);

void testIsEmpty(AbstractBag<int, unsigned int>*);
void testSize(AbstractBag<int, unsigned int>*);
*/

int main() {
	std::cout << "hello world" << std::endl;
	List<int>* l = new LinkedList<int>();
	List<int>* a = new ArrayList<int>();
	/*for (int i = 0; i < 100000; i++)
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
	delete l;*/
	//testList(l, "linkedlist");
	//testList(a, "arraylist");
	return 0;
}
/*
void testList(List<int>* l, std::string testing) {
	std::cout << "testing : " << testing << std::endl;
	testAdd(l);
	testInsert(l);
	testSet(l);
	testGet(l);
	testIndexOf(l);
	testRemove(l);
	testContains(l);
	testClear(l);
	testToArray(l);
	testListPeek(l);
	testListPush(l);
	testListPop(l);
	testListEnqueue(l);
	testListDequeue(l);
	testIsEmpty(l);
	testSize(l);
	testClear(l);
	testToArray(l);
	std::cout << "all asserts passed. " << testing << " is good." << std::endl;
}

void testQueue(Queue<int>* q) {
	testQueueEnqueue(q);
	testQueuePeek(q);
	testQueueDequeue(q);
	testIsEmpty(q);
	testSize(q);
}
void testStack(Stack<int>* s) {
	testStackPush(s);
	testStackPeek(s);
	testStackPop(s);
	testIsEmpty(s);
	testSize(s);
}

void testAdd(List<int>*);
void testInsert(List<int>*);
void testSet(List<int>*);
void testGet(List<int>*);
void testIndexOf(List<int>*);
void testRemove(List<int>*);
void testContains(List<int>*);
void testClear(List<int>*);
void testToArray(List<int>*);

void testStackPeek(Stack<int>*);
void testQueuePeek(Queue<int>*);
void testListPeek(List<int>*);

void testStackPush(Stack<int>*);
void testListPush(List<int>*);

void testStackPop(Stack<int>*);
void testListPop(List<int>*);

void testQueueEnqueue(Queue<int>*);
void testListEnqueue(List<int>*);

void testQueueDequeue(Queue<int>*);
void testListDequeue(List<int>*);

void testIsEmpty(AbstractBag<int, unsigned int>*);
void testSize(AbstractBag<int, unsigned int>*);*/
