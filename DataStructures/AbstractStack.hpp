#pragma once

#include "AbstractBag.hpp"

namespace DataStructures {
	template <typename E, typename Countable>
	struct AbstractStack : virtual public AbstractBag<E, Countable> {
		using AbstractBag<E, Countable>::length;
		virtual E peek() = 0;
		virtual bool push(E) = 0;
		virtual E pop() = 0;
		virtual bool isEmpty() = 0;
		using AbstractBag<E, Countable>::size;
	};
};
