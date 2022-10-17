#pragma once

#include <limits.h>
#include <assert.h>

#include "AbstractStack.hpp"
#include "Helpers.hpp"

namespace DataStructures {
	using namespace Helpers;

	template <typename E>
	class Stack : public AbstractStack<E, unsigned int> {
		using AbstractStack<E, unsigned int>::length;
		SingleyLinkedNode<E>* head;
	public:
		Stack() {
			this->length = 0;
			this->head = nullptr;
		};
		E peek() {
			assert(this->length != 0);
			return this->head->value;
		};
		bool push(E item) {
			assert(this->length != UINT_MAX);
			SingleyLinkedNode<E>* node = new SingleyLinkedNode<E>(item, this->head);
			this->head = node;
			return true;
		};
		E pop() {
			assert(this->length != 0);
			SingleyLinkedNode<E>* node = this->head;
			this->head = node->next;
			E val = node->value;
			delete node;
			this->length--;
			return val;
		};
		bool isEmpty() {
			return this->length == 0;
		};
		using AbstractStack<E, unsigned int>::size;
		~Stack() {
			SingleyLinkedNode<E>* temp;
			while (this->head != nullptr) {
				temp = this->head->next;
				delete this->head;
				this->head = temp;
			}
		};
	};
};
