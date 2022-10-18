#pragma once

#include "AbstractSet.hpp"

namespace DataStructures {
	template <typename E, typename Countable>
	struct AbstractTreeSet : virtual public AbstractSet<E, Countable> {
		using AbstractSet<E, Countable>::length;
		virtual bool add(E) = 0;
		virtual bool contains(E) = 0;
		virtual E first() = 0;
		virtual E last() = 0;
		virtual bool reverse() = 0;
		virtual bool discard(E) = 0;
		virtual bool isEmpty() = 0;
		using AbstractSet<E, Countable>::size;
		virtual void clear() = 0;
		virtual E* toArray() = 0;
	};
};
