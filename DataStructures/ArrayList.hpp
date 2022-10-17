#pragma once

#include <iostream>
#include <limits.h>
#include <assert.h>

#include "List.hpp"

namespace DataStructures {
	template <typename E>
	class ArrayList : public List<E> {
		using List<E>::length;
		E* items;
		const unsigned int DEFAULT_SIZE = 10;
		unsigned int currMaxSize;

		void expand();
		public: 
			ArrayList();
			bool add(E);
			bool insert(unsigned int, E);
			bool set(unsigned int, E);
			E get(unsigned int);
			unsigned int indexOf(E);
			E remove(unsigned int);
			bool contains(E);
			using List<E>::isEmpty;
			using List<E>::peek;
			using List<E>::push;
			using List<E>::pop;
			using List<E>::enqueue;
			using List<E>::dequeue;
			using List<E>::size;
			void clear();
			E* toArray();
			~ArrayList();
	};
	template <typename E>
	ArrayList<E>::ArrayList() {
		this->items = new E[DEFAULT_SIZE];
		this->length = 0;
		this->currMaxSize = DEFAULT_SIZE;
	}
	template <typename E>
	void ArrayList<E>::expand() {
		assert(this->length != UINT_MAX); // "ArrayList out of space!"
		unsigned int nLen = this->length <= UINT_MAX / 2 ? this->length * 2 : UINT_MAX;
		E* arr = new E[nLen];
		for (unsigned int i = 0; i < this->length; i++) {
			arr[i] = this->items[i];
		}
		delete[] this->items;
		this->items = arr;
		this->currMaxSize = nLen;
	}
	template <typename E>
	bool ArrayList<E>::add(E item) {
		if (this->length == this->currMaxSize)
			this->expand();
		this->items[this->length++] = item;
		return true;
	}
	template <typename E>
	bool ArrayList<E>::insert(unsigned int index, E item) {
		if (this->length == 0) return this->add(item);
		if (this->length == this->currMaxSize)
			this->expand();
		for (unsigned int i = this->length - 1; i > index; i--) // from to be inserted till new len
			this->items[i + 1] = this->items[i]; // scooch each over 1 to make space
		this->items[index + 1] = this->items[index]; // if index == 0, loop never ends w/ >=, so ignore last item and handle manually
		this->items[index] = item;
		this->length++; // new len = len + 1
		return true;
	}
	template <typename E>
	bool ArrayList<E>::set(unsigned int index, E item) {
		assert(index < this->length);
		this->items[index] = item;
		return true;
	}
	template <typename E>
	E ArrayList<E>::get(unsigned int index) {
		assert(index < this->length);
		return this->items[index];
	}
	template <typename E>
	unsigned int ArrayList<E>::indexOf(E item) {
		for (unsigned int i = 0; i < this->length; i++)
			if (this->items[i] == item)
				return i;
		return -1;
	}
	template <typename E>
	E ArrayList<E>::remove(unsigned int index) {
		assert(index < this->length);
		E temp = this->items[index];
		for (unsigned int i = index; i < this->length - 1; i++)
			this->items[i] = this->items[i + 1];
		this->length--;
		return temp;
	}
	template <typename E>
	bool ArrayList<E>::contains(E item) {
		unsigned int i = 0;
		while (i < this->length && this->items[i] != item) {
			i++;
		}
		if (i == this->length) // if hit length, couldn't have found value
			return false;
		else // if not at length, must have found it, ending iteration early
			return true;
	}
	template <typename E>
	void ArrayList<E>::clear() {
		delete[] this->items;
		this->items = new E[DEFAULT_SIZE];
		this->length = 0;
		this->currMaxSize = DEFAULT_SIZE;
	}
	template <typename E>
	E* ArrayList<E>::toArray() {
		E* arr = new E[this->length];
		for (unsigned int index = 0; index < this->length; index++) {
			arr[index] = this->items[index];
		}
		return arr;
	}
	template <typename E>
	ArrayList<E>::~ArrayList() {
		delete[] this->items;
	}
}
