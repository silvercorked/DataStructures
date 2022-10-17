#pragma once

#include "AbstractQueue.hpp"
#include "AbstractStack.hpp"

namespace DataStructures {
	template <typename E, typename Countable>
	struct AbstractList : public AbstractQueue<E, Countable>, virtual public AbstractStack<E, Countable> {
		using AbstractQueue<E, Countable>::length;
		virtual bool add(E) = 0;
		virtual bool insert(Countable, E) = 0;
		virtual bool set(Countable, E) = 0;
		virtual E get(Countable) = 0;
		virtual Countable indexOf(E) = 0;
		virtual E remove(Countable) = 0;
		virtual bool contains(E) = 0;
		virtual bool isEmpty() = 0;
		virtual E peek() = 0;
		virtual bool push(E) = 0;
		virtual E pop() = 0;
		virtual bool enqueue(E) = 0;
		virtual E dequeue() = 0;
		using AbstractQueue<E, Countable>::size;
		virtual void clear() = 0;
		virtual E* toArray() = 0;
	};
}
