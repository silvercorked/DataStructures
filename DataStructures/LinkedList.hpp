#pragma once

#include <limits.h>
#include <assert.h>

#include "AbstractList.hpp"

namespace DataStructures {
	template <typename E>
	class LinkedListNode { // doubley-linked
		template <typename T>
		friend class LinkedList;
		protected:
			E value;
			LinkedListNode<E>* prev;
			LinkedListNode<E>* next;
		public:
			LinkedListNode(E, LinkedListNode<E>*, LinkedListNode<E>*);
			~LinkedListNode();
	};
	template <typename E>
	LinkedListNode<E>::LinkedListNode(E item, LinkedListNode<E>* p, LinkedListNode<E>* n) {
		this->value = item;
		this->prev = p;
		this->next = n;
	}
	template <typename E>
	LinkedListNode<E>::~LinkedListNode() { }

	template <typename E>
	class LinkedList : public AbstractList<E, unsigned int> {
		LinkedListNode<E>* head;
		LinkedListNode<E>* tail;
		unsigned int length;
		LinkedListNode<E>* getNode(unsigned int);
		public:
			LinkedList();
			bool add(E);
			bool insert(unsigned int, E);
			bool set(unsigned int, E);
			E get(unsigned int);
			unsigned int indexOf(E);
			E remove(unsigned int);
			bool contains(E);
			bool isEmpty();
			E peek();
			bool push(E);
			E pop();
			bool enqueue(E);
			E dequeue();
			unsigned int size();
			void clear();
			E* toArray();
			~LinkedList();
	};
	template <typename E>
	LinkedList<E>::LinkedList() {
		this->length = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}
	template <typename E>
	LinkedListNode<E>* LinkedList<E>::getNode(unsigned int index) {
		assert(index < this->length); // "LinkedList index out of bounds!"
		if (index == 0) return this->head;
		else if (index == this->length - 1) return this->tail;
		const unsigned int half = this->length / 2;
		unsigned int i;
		LinkedListNode<E>* curr;
		if (index <= half) {
			i = 1;
			curr = this->head->next;
			while (i++ != index) {
				curr = curr->next;
			}
		}
		else {
			i = this->length - 2; // tail is this->length - 1
			curr = this->tail->prev;
			while (i-- != index) {
				curr = curr->prev;
			}
		}
		return curr;
	}
	template <typename E>
	bool LinkedList<E>::add(E item) {
		if (this->length == UINT_MAX)
			return false;
		LinkedListNode<E>* n = new LinkedListNode<E>(item, this->tail, nullptr);
		if (this->length == 0) {
			this->head = n;
			this->tail = n;
		}
		else {
			this->tail->next = n;
			this->tail = n;
		}
		this->length++;
		return true;
	}
	template <typename E>
	E LinkedList<E>::get(unsigned int index) {
		return this->getNode(index)->value;
	}
	template <typename E>
	bool LinkedList<E>::insert(unsigned int index, E item) {
		if (this->size() == index) return this->add(item);
		LinkedListNode<E>* n = this->getNode(index);
		if (n->next != nullptr)
			assert(n == n->next->prev);
		LinkedListNode<E>* curr = new LinkedListNode<E>(item, n->prev, n);
		if (index == 0)
			this->head = curr;
		n->prev = curr;
		this->length++;
		return true;
	}
	template <typename E>
	bool LinkedList<E>::set(unsigned int index, E item) {
		this->getNode(index)->value = item;
		return true;
	}
	template <typename E>
	E LinkedList<E>::remove(unsigned int index) {
		LinkedListNode<E>* curr = this->getNode(index);
		bool wasTail = index == this->length - 1;
		bool wasHead = index == 0;
		if (wasTail || wasHead) {
			if (wasTail && wasHead) {
				this->head = nullptr;
				this->tail = nullptr;
			}
			else if (wasTail) {
				this->tail = curr->prev;
				this->tail->next = nullptr;
			}
			else if (wasHead) {
				this->head = curr->next;
				this->head->prev = nullptr;
			}
		}
		else {
			curr->prev->next = curr->next;
		}
		this->length--;
		E item = curr->value;
		delete curr;
		return item;
	}
	template <typename E>
	bool LinkedList<E>::isEmpty() {
		return this->length == 0;
	}
	template <typename E>
	bool LinkedList<E>::contains(E item) {
		LinkedListNode<E>* curr = this->head;
		unsigned int i = 0;
		while (i < this->length && curr->value != item) {
			i++;
			curr = curr->next;
		}
		if (i == this->length) // if hit length, couldn't have found value
			return false;
		else // if not at length, must have found it, ending iteration early
			return true;
	}
	template <typename E>
	E LinkedList<E>::peek() {
		assert(!this->isEmpty()); // "LinkedList is empty! Nothing to peek at!"
		return this->head->value;
	}
	template <typename E>
	inline bool LinkedList<E>::push(E item) {
		return this->insert(0, item);
	}
	template <typename E>
	inline E LinkedList<E>::pop() {
		return this->remove(0);
	}
	template <typename E>
	inline bool LinkedList<E>::enqueue(E item) {
		return this->push(item);
	}
	template <typename E>
	inline E LinkedList<E>::dequeue() {
		return this->remove(this->length - 1);
	}
	template <typename E>
	inline unsigned int LinkedList<E>::size() {
		return this->length;
	}
	//template <typename E>
	//E* LinkedList<E>::toArray() {
//
	//}
	template <typename E>
	LinkedList<E>::~LinkedList() {
		while (this->head != nullptr) {
			this->tail = this->head->next;
			delete this->head;
			this->head = this->tail;
		}
	}
}