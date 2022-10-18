#pragma once

#include <limits.h>
#include <assert.h>

#include "AbstractSet.hpp"
#include "Helpers.hpp"

namespace DataStructures {
	using namespace Helpers;

	template <typename E>
	class Set : virtual public AbstractSet<E, unsigned int> {
		using AbstractSet<E, unsigned int>::length;
		DoubleyLinkedNode<E>* head;
		DoubleyLinkedNode<E>* tail;
		public:
			Set();
			bool add(E);
			bool contains(E);
			E first();
			E last();
			bool discard(E);
			E peek();
			bool isEmpty();
			using AbstractSet<E, unsigned int>::size;
			void clear();
			E* toArray();
			~Set();
	};
	template <typename E>
	Set<E>::Set() {
		this->length = 0;
		this->head = nullptr;
		this->tail = nullptr;
	}
	template <typename E>
	bool Set<E>::contains(E item) {
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
	bool Set<E>::add(E item) {
		if (this->length == UINT_MAX)
			return false;
		if (this->contains(item))
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
	E Set<E>::first() {
		assert(this->length > 0);
		return this->head->value;
	}
	template <typename E>
	E Set<E>::last() {
		assert(this->length > 0);
		return this->tail->value;
	}
	template <typename E>
	bool Set<E>::discard(E item) {
		DoubleyLinkedNode<E>* curr = this->head;
		unsigned int i = 0;
		while (i < this->length && curr->value != item) {
			i++;
			curr = curr->next;
		}
		if (i == this->length)
			return false;
		else {
			bool wasTail = i == this->length - 1;
			bool wasHead = i == 0;
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
			delete curr;
			this->length--;
			return true;
		}
	}
	template <typename E>
	E Set<E>::peek() {
		return this->first();
	}
	template <typename E>
	bool Set<E>::isEmpty() {
		return this->length == 0;
	}
	template <typename E>
	void Set<E>::clear() {
		while (this->head != nullptr) {
			this->tail = this->head->next;
			delete this->head;
			this->head = this->tail;
		}
		this->length = 0;
	}
	template <typename E>
	E* Set<E>::toArray() {
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
	Set<E>::~Set() {
		while (this->head != nullptr) {
			this->tail = this->head->next;
			delete this->head;
			this->head = this->tail;
		}
	}
}