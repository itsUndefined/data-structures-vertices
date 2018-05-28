#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
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
		void showNeighbors(int node, std::ostream& output);
		int depthFirstSearch();
	private:
		Structure data;
		void quickSort(std::vector<int>& arr);
		void depthFirstSearchVisit(Instance& node);
};

#endif // GRAPH_H
