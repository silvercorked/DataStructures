#pragma once

namespace DataStructures {
	template <typename E, typename Countable>
	struct AbstractBag {
		virtual E peek() = 0;
		virtual bool isEmpty() = 0;
		inline virtual Countable size() {
			return this->length;
		};
		protected:
			Countable length;
	};
};
