#pragma once

namespace DataStructures {
	template <typename E>
	class ArrayList : public AbstractList<E, unsigned int> {
		E* items;
		const unsigned int DEFAULT_SIZE = 10;
		unsigned int length;

		void expand();
		public: 
			ArrayList();
			bool add(E) = 0;
			bool insert(unsigned int, E) = 0;
			bool add(E) = 0;
			bool insert(unsigned int, E) = 0;
			E set(unsigned int, E) = 0;
			E get(unsigned int) = 0;
			unsigned int indexOf(E) = 0;
			E remove(unsigned int) = 0;
			bool contains(E) = 0;
			bool isEmpty() = 0;
			E peek() = 0;
			bool push(E) = 0;
			E pop() = 0;
			bool enqueue(E) = 0;
			E dequeue() = 0;
			unsigned int size() = 0;
			void clear() = 0;
			~ArrayList();
	};

	template <typename E>
	void ArrayList<E>::expand() {

	}
}
