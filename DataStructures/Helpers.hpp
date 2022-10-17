#pragma once

namespace DataStructures {
	namespace Helpers {
		template <typename E>
		struct SingleyLinkedNode {
			E value;
			SingleyLinkedNode<E>* next;
			SingleyLinkedNode(E, SingleyLinkedNode<E>*);
			~SingleyLinkedNode();
		};
		template <typename E>
		SingleyLinkedNode<E>::SingleyLinkedNode(E item, SingleyLinkedNode<E>* n) {
			this->value = item;
			this->next = n;
		}
		template <typename E>
		SingleyLinkedNode<E>::~SingleyLinkedNode() { }

		template <typename E>
		struct DoubleyLinkedNode {
			E value;
			DoubleyLinkedNode<E>* prev;
			DoubleyLinkedNode<E>* next;
			DoubleyLinkedNode(E, DoubleyLinkedNode<E>*, DoubleyLinkedNode<E>*);
			~DoubleyLinkedNode();
		};
		template <typename E>
		DoubleyLinkedNode<E>::DoubleyLinkedNode(E item, DoubleyLinkedNode<E>* p, DoubleyLinkedNode<E>* n) {
			this->value = item;
			this->prev = p;
			this->next = n;
		}
		template <typename E>
		DoubleyLinkedNode<E>::~DoubleyLinkedNode() {}
	};
};