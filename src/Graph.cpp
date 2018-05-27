#include "../include/Graph.h"
#include <iostream>
template <class Structure, class Instance> Graph<Structure, Instance>::Graph() {

}

template <class Structure, class Instance> Graph<Structure, Instance>::~Graph() {
	//dtor
}

template <class Structure, class Instance> void Graph<Structure, Instance>::insertEdge(int nodeA, int nodeB) {
	Instance node(nodeA);
	try {
		Instance& temp = this->data.search(node);
		try {
			temp.neighbors.search(nodeB);
		}
		catch (char const* notFound) {
			temp.neighbors.insert(nodeB);
		}
	}
	catch (char const* notFound) {
		notFound;
		node.neighbors.insert(nodeB);
		this->data.insert(node);
	}
	Instance node1(nodeB);
	try {
		Instance& temp = this->data.search(node1);
		try {
			temp.neighbors.search(nodeA);
		}
		catch (char const* notFound) {
			temp.neighbors.insert(nodeA);
		}
	} catch (char const* notFound) {
		notFound;
		node1.neighbors.insert(nodeA);
		this->data.insert(node1);
	}
}

template <class Structure, class Instance> void Graph<Structure, Instance>::deleteEdge(int nodeA, int nodeB) {
	Instance node(nodeA);
	try {
		data.search(node).neighbors.purge(nodeB);
	} catch (char const* notFound) {
		notFound;
		throw "notFound";
	}
}

template <class Structure, class Instance> int* Graph<Structure, Instance>::findNeighbors(int nodeA) {
	Instance node(nodeA);
	try {
		int* returningData = new int[10];
		data.search(node).neighbors.forEach([](int node) {
			std::cout << node << std::endl;
		});
		return returningData;
	}
	catch (char const* notFound) {
		notFound;
		throw "notFound";
	}

}

template <class Structure, class Instance> int Graph<Structure, Instance>::depthFirstSearch() {
	int count = 0;
	this->data.forEach([&](Instance& node) {
		node.visited = false;
	});

	this->data.forEach([&](Instance& node) {
		if (!node.visited) {
			count++;
			this->depthFirstSearchVisit(node);
		}
	});
	return count;
}

template <class Structure, class Instance> void Graph<Structure, Instance>::depthFirstSearchVisit(Instance& node) {
	std::vector<Instance*> unvisitedNodes;
	unvisitedNodes.push_back(&node);
	while (unvisitedNodes.size()) {
		Instance* currentNode = unvisitedNodes.back();
		unvisitedNodes.pop_back();
		if (!currentNode->visited) {
			currentNode->visited = true;
			currentNode->neighbors.forEach([&](int neighbor) {
				unvisitedNodes.push_back(&this->data.search(Instance(neighbor)));
			});
		}
	}
}



// Tell the compiler for what types to compile the class.
template class Graph<ArrayImplementation, NodeWithArray>;
template class Graph<AVLTreeImplementation, NodeWithAVLTree>;
template class Graph<HashTableImplementation, NodeWithHashTable>;
