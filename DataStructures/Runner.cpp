
#include <iostream>
#include <assert.h>

#include "LinkedList.hpp"
#include "ArrayList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "Set.hpp"

using namespace DataStructures;

void testStack(Stack<int>*);
void testQueue(Queue<int>*);
void testList(List<int>*, std::string);
void testSet(Set<int>*);

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

void testSetAdd(Set<int>*);
void testSetContains(Set<int>*);
void testSetFirst(Set<int>*);
void testSetLast(Set<int>*);
void testSetDiscard(Set<int>*);
void testSetPeek(Set<int>*);
void testSetIsEmpty(Set<int>*);
void testSetSize(Set<int>*);
void testSetClear(Set<int>*);
void testSetToArray(Set<int>*);

int main() {
	std::cout << "hello world" << std::endl;
	List<int>* l = new LinkedList<int>();
	List<int>* a = new ArrayList<int>();
	Stack<int>* s = new Stack<int>();
	Queue<int>* q = new Queue<int>();
	Set<int>* set = new Set<int>();
	testList(l, "linkedlist");
	testList(a, "arraylist");
	testStack(s);
	testQueue(q);
	testSet(set);
	return 0;
}

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
	testClear(l);
	testToArray(l);
	std::cout << "all asserts passed. " << testing << " is good." << std::endl;
}

void testQueue(Queue<int>* q) {
	testQueueEnqueue(q);
	testQueuePeek(q);
	testQueueDequeue(q);
	std::cout << "Queue looking good." << std::endl;
}
void testStack(Stack<int>* s) {
	testStackPush(s);
	testStackPeek(s);
	testStackPop(s);
	std::cout << "Stack looking good." << std::endl;
}
void testSet(Set<int>* s) {
	testSetAdd(s);
	testSetContains(s);
	testSetFirst(s);
	testSetLast(s);
	testSetDiscard(s);
	testSetPeek(s);
	testSetIsEmpty(s);
	testSetSize(s);
	testSetClear(s);
	testSetToArray(s);
	std::cout << "Set looking good." << std::endl;
}

void testAdd(List<int>* l) {
	l->add(5);
	assert(l->get(0) == 5 && l->peek() == 5);
	l->remove(0);
	for (int i = 0; i < 100; i++) {
		l->add(i);
		assert(l->get(i) == i);
	}
	assert(l->size() == 100);
	assert(!l->isEmpty());
	for (int i = 0; i < 100; i++) {
		assert(l->remove(0) == i);
	}
	assert(l->size() == 0);
	assert(l->isEmpty());
};
void testInsert(List<int>* l) {
	l->add(5);
	assert(l->get(0) == 5);
	l->insert(0, 3);
	assert(l->get(0) == 3 && l->get(1) == 5);
	l->remove(0);
	l->remove(0);
	for (int i = 0; i < 100; i++) {
		l->insert(0, i);
		assert(l->get(0) == i);
	}
	assert(l->size() == 100);
	assert(!l->isEmpty());
	for (int i = 0; i < 100; i++) {
		l->remove(0);
	}
	assert(l->size() == 0);
	assert(l->isEmpty());
};
void testSet(List<int>* l) {
	l->add(5);
	assert(l->get(0) == 5);
	assert(l->size() == 1);
	l->set(0, 3);
	assert(l->get(0) == 3);
	assert(l->size() == 1);
	l->remove(0);
	assert(l->isEmpty());
};
void testGet(List<int>* l) {
	l->add(5);
	assert(l->get(0) == 5);
	l->remove(0);
	for (int i = 0; i < 100; i++) {
		l->add(i);
		assert(l->get(i) == i);
	}
	assert(!l->isEmpty());
	l->clear();
	assert(l->isEmpty());
};
void testIndexOf(List<int>* l) {
	l->add(5);
	assert(l->indexOf(5) == 0);
	l->add(10);
	assert(l->indexOf(10) == 1);
	assert(l->indexOf(l->get(1)) == 1);
	assert(l->get(l->indexOf(10)) == 10);
	assert(l->indexOf(50) == -1);
	l->remove(0);
	l->remove(0);
	assert(l->isEmpty());
};
void testRemove(List<int>* l) {
	l->add(5);
	assert(l->size() == 1);
	assert(l->remove(0) == 5 && l->size() == 0);
	for (int i = 0; i < 100; i++) {
		l->add(i);
	}
	for (int i = 99; i >= 0; i--) {
		assert(l->size() == i + 1 && l->remove(i) == i && l->size() == i);
	}
	assert(l->isEmpty());
};
void testContains(List<int>* l) {
	l->add(5);
	assert(l->contains(5));
	assert(!l->contains(10));
	l->remove(0);
};
void testClear(List<int>* l) {
	l->clear();
	for (int i = 0; i < 1000000; i++)
		l->add(i);
	assert(!l->isEmpty());
	l->clear();
	assert(l->isEmpty());
};
void testToArray(List<int>* l) {
	int* t = l->toArray(); // list should be empty, so if this works, this compiler has an extension, according to a stack overflow post
	delete[] t;
	l->add(5);
	t = l->toArray();
	assert(t[0] == 5);
	delete[] t;
	l->add(10);
	assert(l->size() == 2);
	t = l->toArray();
	assert(t[0] == 5);
	assert(t[1] == 10);
	delete[] t;
	l->clear();
	assert(l->isEmpty());
};

void testStackPeek(Stack<int>* s) {
	s->push(5);
	s->push(10);
	assert(s->peek() == 10);
	assert(s->peek() == 10);
	assert(s->pop() == 10);
	assert(s->peek() == 5);
	assert(s->peek() == 5);
	s->push(15);
	assert(!s->isEmpty());
	assert(s->peek() == 15);
	assert(s->peek() == 15);
	assert(s->pop() == 15);
	assert(s->peek() == 5);
	assert(s->pop() == 5);
	assert(s->isEmpty());
};
void testQueuePeek(Queue<int>* q) {
	q->enqueue(5);
	assert(q->peek() == 5);
	q->enqueue(10);
	assert(q->peek() == 5);
	assert(q->dequeue() == 5);
	assert(q->peek() == 10);
	q->enqueue(15);
	assert(q->peek() == 10);
	assert(!q->isEmpty());
	assert(q->dequeue() == 10);
	assert(q->peek() == 15 && q->peek() == q->dequeue());
	assert(q->isEmpty());
};
void testListPeek(List<int>* s) {
	s->push(5);
	s->push(10);
	assert(s->peek() == 10);
	assert(s->peek() == 10);
	assert(s->pop() == 10);
	assert(s->peek() == 5);
	assert(s->peek() == 5);
	s->push(15);
	assert(s->peek() == 15);
	assert(s->peek() == 15);
	assert(s->pop() == 15);
	assert(s->peek() == 5);
	assert(s->pop() == 5);
	assert(s->isEmpty());

	s->enqueue(5);
	assert(s->peek() == 5);
	s->enqueue(10);
	assert(s->peek() == 5);
	assert(s->dequeue() == 5);
	assert(s->peek() == 10);
	s->enqueue(15);
	assert(s->peek() == 10);
	assert(!s->isEmpty());
	assert(s->dequeue() == 10);
	assert(s->peek() == 15 && s->peek() == s->dequeue());
	assert(s->isEmpty());
};

void testStackPush(Stack<int>* s) {
	for (int i = 0; i < 100; i++) {
		s->push(i);
		assert(s->size() == i + 1);
	}
	for (int i = 99; i >= 0; i--) {
		assert(s->pop() == i);
	}
	assert(s->isEmpty());
};
void testListPush(List<int>* s) {
	for (int i = 0; i < 100; i++) {
		s->push(i);
		assert(s->size() == i + 1);
	}
	for (int i = 99; i >= 0; i--) {
		assert(s->pop() == i);
	}
	assert(s->isEmpty());
};

void testStackPop(Stack<int>* s) {
	for (int i = 0; i < 100; i++) {
		s->push(i);
		assert(s->pop() == i);
		assert(s->isEmpty());
	}
	for (int i = 0; i < 100; i++) {
		s->push(i);
		s->push(i + 1);
		assert(s->pop() == i + 1);
		assert(s->pop() == i);
		assert(s->isEmpty());
	}
};
void testListPop(List<int>* s) {
	for (int i = 0; i < 100; i++) {
		s->push(i);
		assert(s->pop() == i);
		assert(s->isEmpty());
	}
	for (int i = 0; i < 100; i++) {
		s->push(i);
		s->push(i + 1);
		assert(s->pop() == i + 1);
		assert(s->pop() == i);
		assert(s->isEmpty());
	}
};

void testQueueEnqueue(Queue<int>* q) {
	q->enqueue(5);
	assert(q->peek() == 5);
	q->enqueue(10);
	assert(q->peek() == 5);
	assert(q->dequeue() == 5);
	assert(q->peek() == 10);
	assert(q->dequeue() == 10);
	assert(q->isEmpty());
};
void testListEnqueue(List<int>* q) {
	q->enqueue(5);
	assert(q->peek() == 5);
	q->enqueue(10);
	assert(q->peek() == 5);
	assert(q->dequeue() == 5);
	assert(q->peek() == 10);
	assert(q->dequeue() == 10);
	assert(q->isEmpty());
};
void testQueueDequeue(Queue<int>* q) {
	for (int i = 0; i < 100; i++) {
		q->enqueue(i);
		assert(q->size() == i + 1);
	}
	for (int i = 0; i < 100; i++) {
		assert(q->dequeue() == i);
		assert(q->size() == 100 - (i + 1));
	}
	assert(q->isEmpty());
};
void testListDequeue(List<int>* q) {
	for (int i = 0; i < 100; i++) {
		q->enqueue(i);
		assert(q->size() == i + 1);
	}
	for (int i = 0; i < 100; i++) {
		assert(q->dequeue() == i);
		assert(q->size() == 100 - (i + 1));
	}
	assert(q->isEmpty());
};
void testSetAdd(Set<int>* s) {
	assert(s->add(5));
	assert(!s->add(5));
	assert(s->add(6));
	assert(s->discard(5));
	assert(s->discard(6));
	for (int i = 0; i < 100; i++)
		assert(s->add(i));
	for (int i = 0; i < 100; i++)
		assert(s->discard(i));
}
void testSetContains(Set<int>* s) {
	assert(s->add(5));
	assert(s->contains(5));
	assert(!s->contains(6));
	assert(s->add(6));
	assert(s->contains(6));
	assert(s->discard(5));
	assert(s->discard(6));
	assert(!s->contains(5) && !s->contains(6));
}
void testSetFirst(Set<int>* s) {
	assert(s->add(5));
	assert(s->first() == 5);
	assert(s->add(6));
	assert(s->first() == 5);
	assert(s->discard(5));
	assert(s->first() == 6);
	assert(s->discard(6));
}
void testSetLast(Set<int>* s) {
	assert(s->add(5));
	assert(s->last() == 5);
	assert(s->add(6));
	assert(s->last() == 6);
	assert(s->discard(5));
	assert(s->last() == 6);
	assert(s->discard(6));
}
void testSetDiscard(Set<int>* s) {
	assert(!s->discard(5));
	assert(s->add(5));
	assert(s->discard(5));
	assert(!s->discard(5));
	for (int i = 0; i < 100; i++)
		assert(s->add(i));
	for (int i = 99; i >= 0; i--)
		assert(s->discard(i));
	assert(s->isEmpty());
}
void testSetPeek(Set<int>* s) {
	assert(s->add(5));
	assert(s->first() == 5);
	assert(s->add(6));
	assert(s->first() == 5);
	assert(s->discard(5));
	assert(s->first() == 6);
	assert(s->discard(6));
}
void testSetIsEmpty(Set<int>* s) {
	assert(s->isEmpty());
	assert(s->add(5));
	assert(!s->isEmpty());
	assert(s->discard(5));
	assert(s->isEmpty());
}
void testSetSize(Set<int>* s) {
	assert(s->size() == 0);
	assert(s->add(5));
	assert(s->size() == 1);
	for (int i = 0; i < 100; i++) {
		assert(i <= 5 ? s->size() == i + 1 : s->size() == i);
		assert(i == 5 ? !s->add(i) : s->add(i));
	}
	for (int i = 0; i < 100; i++)
		assert(s->discard(i));
	assert(s->size() == 0 && s->isEmpty());
}
void testSetClear(Set<int>* s) {
	assert(s->size() == 0);
	s->clear();
	assert(s->size() == 0);
	for (int i = 0; i < 100; i++)
		assert(s->add(i));
	s->clear();
	assert(s->size() == 0 && s->isEmpty());
}
void testSetToArray(Set<int>* s) {
	int* t = s->toArray(); // set should be empty, so if this works, this compiler has an extension, according to a stack overflow post
	delete[] t;
	s->add(5);
	t = s->toArray();
	assert(t[0] == 5);
	delete[] t;
	s->add(10);
	assert(s->size() == 2);
	t = s->toArray();
	assert(t[0] == 5);
	assert(t[1] == 10);
	delete[] t;
	s->clear();
	assert(s->isEmpty());
}
