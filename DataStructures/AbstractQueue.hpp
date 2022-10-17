#pragma once

#include "AbstractBag.hpp"

namespace DataStructures {
	template <typename E, typename Countable>
	struct AbstractQueue : virtual public AbstractBag<E, Countable> {
		using AbstractBag<E, Countable>::length;
		virtual E peek() = 0;
		virtual bool enqueue(E) = 0;
		virtual E dequeue() = 0;
		virtual bool isEmpty() = 0;
		using AbstractBag<E, Countable>::size;
	};
};
