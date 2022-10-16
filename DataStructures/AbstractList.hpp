#pragma once

namespace DataStructures {
	template <typename E, typename Countable>
	struct AbstractList {
		virtual bool add(E) = 0;
		virtual bool insert(Countable, E) = 0;
		virtual E set(Countable, E) = 0;
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
		virtual Countable size() = 0;
		virtual void clear() = 0;
	};
}

