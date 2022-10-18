#pragma once

#include <limits.h>
#include <assert.h>

#include "List.hpp"
#include "Helpers.hpp"

namespace DataStructures {
	using namespace Helpers;

	template <typename E>
	class LinkedList : public List<E> {
		using List<E>::length;
		DoubleyLinkedNode<E>* head;
		DoubleyLinkedNode<E>* tail;
		DoubleyLinkedNode<E>* getNode(unsigned int);
		public:
			LinkedList();
			bool add(E);
			bool insert(unsigned int, E);
			bool set(unsigned int, E);
			E get(unsigned int);
			unsigned int indexOf(E);
			E remove(unsigned int);
			bool contains(E);
			using List<E>::isEmpty;
			using List<E>::peek;
			using List<E>::push;
			using List<E>::pop;
			using List<E>::enqueue;
			using List<E>::dequeue;
			using List<E>::size;
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
	DoubleyLinkedNode<E>* LinkedList<E>::getNode(unsigned int index) {
		assert(index < this->length); // "LinkedList index out of bounds!"
		if (index == 0) return this->head;
		else if (index == this->length - 1) return this->tail;
		const unsigned int half = this->length / 2;
		unsigned int i;
		DoubleyLinkedNode<E>* curr;
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
		DoubleyLinkedNode<E>* n = new DoubleyLinkedNode<E>(item, this->tail, nullptr);
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
	bool LinkedList<E>::insert(unsigned int index, E item) {
		if (this->size() == index) return this->add(item);
		DoubleyLinkedNode<E>* n = this->getNode(index);
		if (n->next != nullptr)
			assert(n == n->next->prev);
		DoubleyLinkedNode<E>* curr = new DoubleyLinkedNode<E>(item, n->prev, n);
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
	E LinkedList<E>::get(unsigned int index) {
		return this->getNode(index)->value;
	}
	template <typename E>
	unsigned int LinkedList<E>::indexOf(E item) {
		unsigned int index = 0;
		DoubleyLinkedNode<E>* temp = this->head;
		while (temp != nullptr && temp->value != item) {
			temp = temp->next;
			index++;
		}
		if (temp == nullptr) return -1; // if broke while cause nullptr, then return -1 as index.
		else return index; // otherwise, must have broke because item was the same, in which case, return index
	};
	template <typename E>
	E LinkedList<E>::remove(unsigned int index) {
		DoubleyLinkedNode<E>* curr = this->getNode(index);
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
			curr->next->prev = curr->prev;
			curr->prev->next = curr->next;
		}
		this->length--;
		E item = curr->value;
		delete curr;
		return item;
	}
	template <typename E>
	bool LinkedList<E>::contains(E item) {
		DoubleyLinkedNode<E>* curr = this->head;
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
	void LinkedList<E>::clear() {
		while (this->head != nullptr) {
			this->tail = this->head->next;
			delete this->head;
			this->head = this->tail;
		}
		this->length = 0;
	}
	template <typename E>
	E* LinkedList<E>::toArray() {
		E* arr = new E[this->length];
		unsigned int index = 0;
		DoubleyLinkedNode<E>* temp = this->head;
		while (temp != nullptr) {
			arr[index] = temp->value;
			temp = temp->next;
			index++;
		}
		return arr;
	}
	template <typename E>
	LinkedList<E>::~LinkedList() {
		while (this->head != nullptr) {
			this->tail = this->head->next;
			delete this->head;
			this->head = this->tail;
		}
	}
}