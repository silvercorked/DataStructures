#pragma once

#include "AbstractList.hpp"

namespace DataStructures {
	template <typename E>
	struct List : AbstractList<E, unsigned int> {
		using AbstractList<E, unsigned int>::length;
		virtual bool add(E) = 0;
		virtual bool insert(unsigned int, E) = 0;
		virtual bool set(unsigned int, E) = 0;
		virtual E get(unsigned int) = 0;
		virtual unsigned int indexOf(E) = 0;
		virtual E remove(unsigned int) = 0;
		virtual bool contains(E) = 0;
		inline virtual bool isEmpty() {
			return this->length == 0;
		};
		inline virtual E peek() {
			return this->get(0);
		};
		inline virtual bool push(E item) {
			return this->insert(0, item);
		};
		inline virtual E pop() {
			return this->remove(0);
		};
		inline virtual bool enqueue(E item) {
			return this->push(item);
		};
		virtual E dequeue() {
			return this->remove(this->length - 1);
		};
		inline virtual unsigned int size() {
			return this->length;
		};
		virtual void clear() = 0;
		virtual E* toArray() = 0;
	};
};
