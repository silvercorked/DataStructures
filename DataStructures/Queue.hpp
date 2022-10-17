#pragma once

#include <limits.h>
#include <assert.h>

#include "AbstractQueue.hpp"
#include "Helpers.hpp"

namespace DataStructures {
	using namespace Helpers;

	template <typename E>
	class Queue : public AbstractQueue<E, unsigned int> {
		using AbstractQueue<E, unsigned int>::length;
		SingleyLinkedNode<E>* head;
		SingleyLinkedNode<E>* tail;
		public:
			Queue() {
				this->length = 0;
				this->head = nullptr;
				this->tail = nullptr;
			};
			E peek() {
				assert(this->length != 0);
				return this->head->value;
			};
			bool enqueue(E item) {
				assert(this->length != UINT_MAX);
				SingleyLinkedNode<E>* node = new SingleyLinkedNode<E>(item, nullptr);
				if (this->length == 0) {
					this->head = node;
					this->tail = node;
				}
				else {
					this->tail->next = node;
					this->tail = this->tail->next;
				}
				this->length++;
				return true;
			};
			E dequeue() {
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
			using AbstractQueue<E, unsigned int>::size;
			~Queue() {
				while (this->head != nullptr) {
					this->tail = this->head->next;
					delete this->head;
					this->head = this->tail;
				}
			};
	};
};
