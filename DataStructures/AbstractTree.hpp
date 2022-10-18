#pragma once

#include "AbstractBag.hpp"

namespace DataStructures {
	template <typename E, typename Countable>
	struct AbstractTree : virtual public AbstractBag<E, Countable> {

	};
};
