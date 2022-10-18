#pragma once

#include <assert.h>

#include "AbstractTreeSet.hpp"
#include "Helpers.hpp"

namespace DataStructures {
	template <typename E>
	class BinaryTreeSet : virtual public AbstractTreeSet<E, unsigned int> {
		bool reveresed;
		BinaryTreeNode<E>* root;
		BinaryTreeNode<E>* addRecurse(BinaryTreeNode<E>*, E);
		void findNodeByValue(BinaryTreeNode<E>*&, E, BinaryTreeNode<E>*&);
		BinaryTreeNode<E>* getSuccessorNode(void (*)(BinaryTreeNode<E>*), BinaryTreeNode<E>*);
		BinaryTreeNode<E>* getPreOrderSuccessor(BinaryTreeNode<E>*);
		BinaryTreeNode<E>* getInOrderSuccessor(BinaryTreeNode<E>*);
		BinaryTreeNode<E>* getPostOrderSuccessor(BinaryTreeNode<E>*);
		void preOrderAndDo(BinaryTreeNode<E>*, void (*)(BinaryTreeNode<E>*) = nullptr);
		void inOrderAndDo(BinaryTreeNode<E>*, void (*)(BinaryTreeNode<E>*) = nullptr);
		void postOrderAndDo(BinaryTreeNode<E>*, void (*)(BinaryTreeNode<E>*) = nullptr);
		public:
			BinaryTreeSet();
			bool add(E);
			bool contains(E);
			E first();
			E last();
			bool reverse();
			bool discard(E);
			bool isEmpty();
			unsigned int size();
			void clear();
			E* toArray();
			~BinaryTreeSet();
			/*
				instead of get minimum key (in order traversal successor)
				getSuccessor(fn*, Node) // grabs successor according to given function
				getInOrderSuccessor(Node) { getSuccessor(InOrder, Node) }
				getPreOrderSuccessor(Node) { getSuccessor(PreOrder, Node) }
				getPostOrderSuccessor(Node) { getSuccessor(PostOrder, Node) }
				E* getInOrderArray(Node) { curr = root; while ((curr = getInOrderSuccessor(curr)) != nullptr) { arrToRet.add(curr) } }
			*/
	};
	template <typename E>
	BinaryTreeSet<E>::BinaryTreeSet() {
		this->reveresed = false;
		this->root = nullptr;
	}
	template <typename E>
	BinaryTreeNode<E>* BinaryTreeSet<E>::addRecurse(BinaryTreeNode<E>* curr, E item) {
		if (curr == nullptr)
			return new BinaryTreeNode<E>(item, nullptr, nullptr);
		if (this->reversed) { // reversed
			if (item < curr->value)
				curr->right = this->addRecurse(curr->right, item);
			else if (item > curr->value) // prevents dupe insertion
				curr->left = this->addRecurse(curr->left, item);
		}
		else { // normal
			if (item > curr->value)
				curr->right = this->addRecurse(curr->right, item);
			else (item < curr->value) // prevents dupe insertion
				curr->left = this->addRecurse(curr->left, item);
		}
		return curr;
	}
	template <typename E>
	void BinaryTreeSet<E>::findNodeByValue(BinaryTreeNode<E>*& curr, E item, BinaryTreeNode<E>*& parent) {
		auto getNextCurr = (this->reveresed
			? [](BinaryTreeNode<E>* &curr, E item) -> BinaryTreeNode<E>* {
				if (curr->value > item)
					return curr->left;
				else
					return curr->right;
			}
			: [](BinaryTreeNode<E>*& curr, E item) -> BinaryTreeNode<E>*& {
				if (curr->value < item)
					return curr->left;
				else
					return curr->right;
			}
		);
		while (curr != nullptr && curr->value != item) {
			parent = curr;
			curr = getNextCurr(curr, item);
		}
	}
	template <typename E>
	BinaryTreeNode<E>* BinaryTreeSet<E>::getSuccessorNode(void (*successorFunc)(BinaryTreeNode<E>*), BinaryTreeNode<E>* node) {
		return successorFunc(node);
	}
	template <typename E>
	BinaryTreeNode<E>* BinaryTreeSet<E>::getPreOrderSuccessor(BinaryTreeNode<E>* node) {
		return this->getSuccessorNode(this->preOrderAndDo, node);
	}
	template <typename E>
	BinaryTreeNode<E>* BinaryTreeSet<E>::getInOrderSuccessor(BinaryTreeNode<E>* node) {
		return this->getSuccessorNode(this->inOrderAndDo, node);
	}
	template <typename E>
	BinaryTreeNode<E>* BinaryTreeSet<E>::getPostOrderSuccessor(BinaryTreeNode<E>* node) {
		return this->getSuccessorNode(this->postOrderAndDo, node);
	}
	template <typename E>
	void BinaryTreeSet<E>::preOrderAndDo(BinaryTreeNode<E>* node, void (*doFunc)(BinaryTreeNode<E>*)) {
		if (node == nullptr) return;
		if (doFunc != nullptr) doFunc(node);
		this->preOrderAndDo(node->left);
		this->preOrderAndDo(node->right);
	}
	template <typename E>
	void BinaryTreeSet<E>::inOrderAndDo(BinaryTreeNode<E>* node, void (*doFunc)(BinaryTreeNode<E>*)) {
		if (node == nullptr) return;
		this->inOrderAndDo(node->left);
		if (doFunc != nullptr) doFunc(node);
		this->inOrderAndDo(node->right);
	}
	template <typename E>
	void BinaryTreeSet<E>::postOrderAndDo(BinaryTreeNode<E>* node, void (*doFunc)(BinaryTreeNode<E>*)) {
		if (node == nullptr) return;
		this->postOrderAndDo(node->left);
		this->postOrderAndDo(node->right);
		if (doFunc != nullptr) doFunc(node);
	}
	template <typename E>
	bool BinaryTreeSet<E>::add(E item) {
		this->root = this->addRecurse(this->root, item);
	}
	template <typename E>
	bool BinaryTreeSet<E>::contains(E item) {
		BinaryTreeNode<E>* parent = nullptr;
		BinaryTreeNode<E>* curr = this->root;
		this->findNodeByValue(curr, item, parent);
		if (curr == nullptr) return false;
		return true;
	}
	template <typename E>
	E BinaryTreeSet<E>::first() {
		assert(this->root != nullptr);
		BinaryTreeNode<E>* curr = this->root;
		while (curr->left != nullptr)
			curr = curr->left;
		return curr->value;
	}
	template <typename E>
	E BinaryTreeSet<E>::last() {
		assert(this->root != nullptr);
		BinaryTreeNode<E>* curr = this->root;
		while (curr->right != nullptr)
			curr = curr->right;
		return curr->value;
	}
	template <typename E>
	bool BinaryTreeSet<E>::reverse() {
		this->reveresed = !this->reveresed;
	}
	template <typename E>
	bool BinaryTreeSet<E>::discard(E item) {
		BinaryTreeNode<E>* parent = nullptr;
		BinaryTreeNode<E>* curr = this->root;
		this->findNodeByValue(curr, item, parent);
		if (curr == nullptr) return false; // not found
		// Case 1: node being deleted is leaf node
		if (curr->left == nullptr && curr->right == nullptr) {
			if (curr != this->root) { // if not root, parent is defined
				if (parent->left == curr)
					parent->left = nullptr;
				else
					parent->right = nullptr;
			}
			else // treeset is empty
				this->root = nullptr;
			delete curr; // free mem
		}
		// Case 2: node being deleted has both left and right children
		else if (curr->left && curr->right) {
			BinaryTreeNode<E>* successor = curr;
			// because has left and right, in order traversal in minimal val of the sub tree with root curr.
			// so can use a simplification of in order traversal, since left is guarenteed
			while (successor->left != nullptr)
				successor = successor->left;
			E data = successor->value;
			// successor is guarenteed to be Case 1 or Case 3
			this->discard(E);
			curr->value = data;
		}
		// Case 3: node being deleted has left or right
		else {
			BinaryTreeNode<E>* child = (curr->left
				? curr->left
				: curr->right
			);
			if (curr != root) { // parent available
				if (parent->left == curr)
					parent->left = child;
				else
					parent->right = child;
			}
			else
				this->root = child;
			delete curr;
		}
	}
	template <typename E>
	bool BinaryTreeSet<E>::isEmpty() {
		return this->root == nullptr;
	}
	template <typename E>
	unsigned int BinaryTreeSet<E>::size() {
		return 0;
	}
	template <typename E>
	void BinaryTreeSet<E>::clear() {
		this->postOrderAndDo( // from post order, every node we touch will be a leaf node,
			this->root, // as parent calling nodes will only have nullptrs once we get to em
			[](BinaryTreeNode<E>* leafNode) {
				delete leafNode;
			}
		);
	}
	template <typename E>
	E* BinaryTreeSet<E>::toArray() {
		E* temp = new E[5];
		return temp;
	}
	template <typename E>
	BinaryTreeSet<E>::~BinaryTreeSet() {
		this->clear();
	}
}
