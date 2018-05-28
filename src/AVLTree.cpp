#include "AVLTree.h"

template <class T> AVLTree<T>::AVLTree() {
	head = nullptr;
}

template <class T> AVLTree<T>::AVLTree(const AVLTree& obj) {
	head = nullptr;
	preOrder(obj.head, [&](TreeNode<T>& currentNode) { //TODO: levelOrder maybe?
		insert(currentNode.value);
	});
}

template <class T> AVLTree<T>& AVLTree<T>::operator=(AVLTree& obj) {
	head = nullptr;
	preOrder(obj.head, [&](TreeNode<T>& currentNode) { //TODO: levelOrder maybe?
		insert(currentNode.value);
	});

	return *this;
}

template <class T> AVLTree<T>::~AVLTree() {
	postOrder(head, [&](TreeNode<T>& node) {
		delete &node;
	});
}

template <class T> void AVLTree<T>::insert(T value) {
	if (head == nullptr) {
		head = new TreeNode<T>(value);
		return;
	}
	insert(head, value);
}

template <class T> TreeNode<T>& AVLTree<T>::insert(TreeNode<T>* node, T& value) {
	if (node == nullptr) {
		node = new TreeNode<T>(value);
	}
	else if (value < node->value) {
		node->pLeft = &insert(node->pLeft, value);
		node->pLeft->parent = node;
	}
	else if (value > node->value) {
		node->pRight = &insert(node->pRight, value);
		node->pRight->parent = node;
	}

	recalculateHeight(*node);
	return rebalanceNode(*node);
}
//Handling deletion of a node that has 1 or 0 childs.
template <class T> void AVLTree<T>::deleteNode(TreeNode<T>& node) {
	if (node.parent == nullptr) {
		TreeNode<T>* newRoot = node.pLeft != nullptr ? node.pLeft : node.pRight;
		if (newRoot != nullptr) {
			newRoot->parent = nullptr;
		}
	}
	else {
		TreeNode<T>* parent = node.parent;
		TreeNode<T>* nonNullChild = node.pLeft != nullptr ? node.pLeft : node.pRight;
		if (node.isRightOfParent()) {
			if (nonNullChild != nullptr) {
				parent->setRight(*nonNullChild);
			}
			else {
				parent->pRight = nullptr;
			}
		}
		else {
			if (nonNullChild != nullptr) {
				parent->setLeft(*nonNullChild);
			}
			else {
				parent->pLeft = nullptr;
			}
		}
	}
	delete &node;
}

template <class T> void AVLTree<T>::purge(T value) {
	try {
		TreeNode<T>& nodeForDeletion = search(*head, value);

		TreeNode<T>* returnNode;

		if (nodeForDeletion.pLeft == nullptr || nodeForDeletion.pRight == nullptr) { // One or zero childs
			if (nodeForDeletion.pLeft != nullptr) {
				returnNode = nodeForDeletion.pLeft;
			}
			else if (nodeForDeletion.pRight != nullptr) {
				returnNode = nodeForDeletion.pRight;
			}
			else {
				returnNode = nodeForDeletion.parent;
			}
			deleteNode(nodeForDeletion);
			if (returnNode == nullptr) { // The avltree is empty
				head = nullptr;
			}
			while (returnNode != nullptr) {
				recalculateHeight(*returnNode);
				rebalanceNode(*returnNode);
				returnNode = returnNode->parent;
			}
		}
		else { // Has two children
			TreeNode<T>* smallestChild = nodeForDeletion.pRight; // Will get the smallest child of the right subtree
			while (smallestChild->pLeft != nullptr) {
				smallestChild = smallestChild->pLeft;
			}

			T temp = nodeForDeletion.value; // Exchanging the value of the node for deletion with the smallest child of the right subtree
			nodeForDeletion.value = smallestChild->value;
			smallestChild->value = temp; // TODO: CHECK THAT THIS DOES WORK

			returnNode = smallestChild->parent;
			deleteNode(*smallestChild);
			while (returnNode != nullptr) {
				recalculateHeight(*returnNode);
				rebalanceNode(*returnNode);
				returnNode = returnNode->parent;
			}
		}
	}
	catch (char const* notFound) {
		return;
	}
	

	

}


template <class T> T& AVLTree<T>::search(T value) {
	return search(*head, value).value;
}

template <class T> TreeNode<T>& AVLTree<T>::search(TreeNode<T>& node, T& value) {
	if (&node == nullptr) {
		throw "notFound";
	}
	else if (value == node.value) {
		return node;
	}
	else if (value < node.value) {
		return search(*node.pLeft, value);
	}
	else {
		return search(*node.pRight, value);
	}
}

template <class T> void AVLTree<T>::forEach(std::function<void(T& value)> callback) {
	inOrder(head, [&](TreeNode<T>& node) {
		callback(node.value);
	});
}

template <class T> void AVLTree<T>::preOrder(TreeNode<T>* node, std::function<void(TreeNode<T>& value)> callback) {
	if (node == nullptr) {
		return;
	}
	callback(*node);
	preOrder(node->pLeft, callback);
	preOrder(node->pRight, callback);
}

template <class T> void AVLTree<T>::inOrder(TreeNode<T>* node, std::function<void(TreeNode<T>& value)> callback) {
	if (node == nullptr) {
		return;
	}
	inOrder(node->pLeft, callback);
	callback(*node);
	inOrder(node->pRight, callback);
}

template <class T> void AVLTree<T>::postOrder(TreeNode<T>* node, std::function<void(TreeNode<T>& value)> callback) {
	if (node == nullptr) {
		return;
	}
	postOrder(node->pLeft, callback);
	postOrder(node->pRight, callback);
	callback(*node);
}

template <class T> TreeNode<T>& AVLTree<T>::LRotation(TreeNode<T>& node) {
	if (node.parent != nullptr) {
		if (node.isRightOfParent()) {
			node.parent->setRight(*node.pRight);
		}
		else {
			node.parent->setLeft(*node.pRight);
		}
	}
	TreeNode<T>& temp = *node.pRight;
	if (temp.pLeft != nullptr) {
		node.setRight(*temp.pLeft);
	}
	else {
		node.pRight = nullptr;
	}
	temp.setLeft(node);
	if (node.parent == nullptr) {
		temp.parent = nullptr;
	}
	return temp;
}

template <class T> TreeNode<T>& AVLTree<T>::RRotation(TreeNode<T>& node) {
	if (node.parent != nullptr) {
		if (!node.isRightOfParent()) {
			node.parent->setLeft(*node.pLeft);
		}
		else {
			node.parent->setRight(*node.pLeft);
		}
	}
	TreeNode<T>& temp = *node.pLeft;
	if (temp.pRight != nullptr) {
		node.setLeft(*temp.pRight);
	}
	else {
		node.pLeft = nullptr;
	}
	temp.setRight(node);
	if (node.parent == nullptr) {
		temp.parent = nullptr;
	}
	return temp;
}

template <class T> TreeNode<T>& AVLTree<T>::LRRotation(TreeNode<T>& node) {
	TreeNode<T>& x = node;
	TreeNode<T>& y = *node.pLeft;
	TreeNode<T>& z = *node.pLeft->pRight;
	if (z.pRight != nullptr) {
		x.setLeft(*z.pRight);
	}
	else {
		x.pLeft = nullptr;
	}
	if (z.pLeft != nullptr) {
		y.setRight(*z.pLeft);
	}
	else {
		y.pRight = nullptr;
	}
	if (x.parent != nullptr) {
		if (!x.isRightOfParent()) {
			x.parent->setLeft(z);
		}
		else {
			x.parent->setRight(z);
		}
	}
	z.setLeft(y);
	z.setRight(x);
	if (x.parent == nullptr) {
		z.parent = nullptr;
	}
	return z;
}

template <class T> TreeNode<T>& AVLTree<T>::RLRotation(TreeNode<T>& node) {
	TreeNode<T>& x = node;
	TreeNode<T>& y = *node.pRight;
	TreeNode<T>& z = *node.pRight->pLeft;
	if (z.pLeft != nullptr) {
		x.setRight(*z.pLeft);
	}
	else {
		x.pRight = nullptr;
	}
	if (z.pRight != nullptr) {
		y.setLeft(*z.pRight);
	}
	else {
		y.pLeft = nullptr;
	}
	if (x.parent != nullptr) {
		if (x.isRightOfParent()) {
			x.parent->setRight(z);
		}
		else {
			x.parent->setLeft(z);
		}
	}
	z.setLeft(x);
	z.setRight(y);
	if (x.parent == nullptr) {
		z.parent = nullptr;
	}
	return z;
}

template <class T> TreeNode<T>& AVLTree<T>::findSonForRebalance(TreeNode<T>& node) {
	int heightDifference = node.heightOfLeft() - node.heightOfRight();
	if (heightDifference > 0) {
		return *node.pLeft;
	}
	else if (heightDifference < 0) {
		return *node.pRight;
	}
	else if (node.isRightOfParent()) {
		return *node.pRight;
	}
	else {
		return *node.pLeft;
	}
}

template <class T> TreeNode<T>& AVLTree<T>::rebalanceNode(TreeNode<T>& node) {
	TreeNode<T>* oldNodeParent = node.parent;
	TreeNode<T>* newRoot = &node;
	int heightDifference = node.heightOfLeft() - node.heightOfRight();
	if (heightDifference < -1 || heightDifference > 1) {
		TreeNode<T>& y = findSonForRebalance(node);
		TreeNode<T>& z = findSonForRebalance(y);
		if (!y.isRightOfParent() && !z.isRightOfParent()) {
			newRoot = &RRotation(node);
		}
		else if (y.isRightOfParent() && z.isRightOfParent()) {
			newRoot = &LRotation(node);
		}
		else if (!z.isRightOfParent()) {
			newRoot = &RLRotation(node);
		}
		else {
			newRoot = &LRRotation(node);
		}
		recalculateHeight(*newRoot->pLeft);
		recalculateHeight(*newRoot->pRight);
		recalculateHeight(*newRoot);
	}
	newRoot->parent = oldNodeParent;
	if (oldNodeParent == nullptr) {
		head = newRoot;
	}
	return *newRoot;
}

template <class T> int AVLTree<T>::recalculateHeight(TreeNode<T>& node) {
	if (&node == nullptr) {
		return 0;
	}
	return node.height = (node.heightOfLeft() > node.heightOfRight() ? node.heightOfLeft() : node.heightOfRight()) + 1;
}


template class AVLTree<int>;
template class AVLTree<Node<AVLTree<int>>>;
