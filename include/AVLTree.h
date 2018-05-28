#include <functional>
#include "Node.h"

template <class T> struct TreeNode {
	TreeNode(T& value) {
		this->value = value;
		this->pLeft = nullptr;
		this->pRight = nullptr;
		this->parent = nullptr;
	};
	void setRight(TreeNode<T>& value) {
		this->pRight = &value;
		this->pRight->parent = this;
	}
	void setLeft(TreeNode<T>& value) {
		this->pLeft = &value;
		this->pLeft->parent = this;
	}
	bool isRightOfParent() {
		if (this->parent == nullptr) {
			return false;
		}
		return this->parent->pRight == this;
	}
	int heightOfLeft() {
		if (this->pLeft == nullptr) {
			return 0;
		}
		return this->pLeft->height;
	}
	int heightOfRight() {
		if (this->pRight == nullptr) {
			return 0;
		}
		return this->pRight->height;
	}
	int height;
	T value;
	TreeNode<T>* parent;
	TreeNode<T>* pLeft;
	TreeNode<T>* pRight;
};

template <class T> class AVLTree {
	
	public:
		AVLTree();
		AVLTree(const AVLTree& obj);
		AVLTree<T>& operator=(AVLTree& obj);
		~AVLTree();
		void insert(T value);
		void purge(T value);
		T& search(T value);
		void forEach(std::function<void(T& value)>);
	private:
		TreeNode<T>* head;
		TreeNode<T>& insert(TreeNode<T>* node, T& value);
		void deleteNode(TreeNode<T>& node);
		TreeNode<T>& search(TreeNode<T>& node, T& value);
		void preOrder(TreeNode<T>* node, std::function<void(TreeNode<T>& value)> callback);
		void inOrder(TreeNode<T>* node, std::function<void(TreeNode<T>& value)> callback);
		void postOrder(TreeNode<T>* node, std::function<void(TreeNode<T>& value)> callback);
		TreeNode<T>& LRotation(TreeNode<T>& node);
		TreeNode<T>& RRotation(TreeNode<T>& node);
		TreeNode<T>& LRRotation(TreeNode<T>& node);
		TreeNode<T>& RLRotation(TreeNode<T>& node);
		TreeNode<T>& findSonForRebalance(TreeNode<T>& node);
		TreeNode<T>& rebalanceNode(TreeNode<T>& node);
		int recalculateHeight(TreeNode<T>& node);
};

