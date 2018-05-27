#ifndef GRAPH_H
#define GRAPH_H

#include "Array.h"
#include "AVLTree.h"
#include "HashTable.h"
#include "Node.h"


typedef Node<Array<int>> NodeWithArray;
typedef Node<AVLTree<int>> NodeWithAVLTree;
typedef Node<HashTable<int>> NodeWithHashTable;

typedef Array<NodeWithArray> ArrayImplementation;
typedef AVLTree<NodeWithAVLTree> AVLTreeImplementation;
typedef HashTable<NodeWithHashTable> HashTableImplementation;

template <class Structure, class Instance> class Graph {
	public:
		Graph();
		~Graph();
		void insertEdge(int nodeA, int nodeB);
		void deleteEdge(int nodeA, int nodeB);
		int* findNeighbors(int node);
		int depthFirstSearch();
	private:
		Structure data;
		void depthFirstSearchVisit(Instance& node);
};

#endif // GRAPH_H
