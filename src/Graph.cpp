#include "Graph.h"

template <class Structure, class Instance> Graph<Structure, Instance>::Graph() {

}

template <class Structure, class Instance> Graph<Structure, Instance>::~Graph() {
	//dtor
}

template <class Structure, class Instance> void Graph<Structure, Instance>::insertEdge(int nodeA, int nodeB) { //Inserting edges in the graph
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
		node1.neighbors.insert(nodeA);
		this->data.insert(node1);
	}
}

template <class Structure, class Instance> void Graph<Structure, Instance>::deleteEdge(int nodeA, int nodeB) { //Deleting Edges in the graph
	Instance node1(nodeA);
	Instance node2(nodeB);
	try {
		data.search(node1).neighbors.purge(nodeB);
		data.search(node2).neighbors.purge(nodeA);
	} catch (char const* notFound) {
		// we don't care silence the error....
	}
}

template <class Structure, class Instance> void Graph<Structure, Instance>::showNeighbors(int nodeA, std::ostream& output) { //Showing neighbors of the requested Node
	Instance node(nodeA);
	data.search(node).neighbors.forEach([&](int node) {//Searching the requested node
		output << node << ", ";
	});
}

template <> void Graph<HashTableImplementation, NodeWithHashTable>::showNeighbors(int nodeA, std::ostream& output) {
	NodeWithHashTable node(nodeA);
	std::vector<int> sortedValues;
	data.search(node).neighbors.forEach([&](int node) { //Storing the node's neighbors in a vector array
		sortedValues.push_back(node);
	});
	this->quickSort(sortedValues); //Calling the quicksort function for the vector array
	for (typename std::vector<int>::iterator i = sortedValues.begin(); i != sortedValues.end(); ++i) {
		output << *i << ", ";
	}
}

template  <class Structure, class Instance> void Graph<Structure, Instance>::quickSort(std::vector<int>& arr) { //Sorting the vector array using the quicksort method
	std::vector<int> stack;
	int left, right;
	stack.push_back(arr.size() - 1);
	stack.push_back(0);

	while (stack.size()) {
		left = stack.back();
		stack.pop_back();
		right = stack.back();
		stack.pop_back();

		if (right <= left) {
			continue;
		}
		int i = left - 1;
		int j = right;
		int temp;
		int o = arr[j];

		while (true) {
			while (arr[++i] < o) {
				if (i == right) {
					break;
				}
			}

			while (o < arr[--j]) {
				if (j == left) {
					break;
				}
			}

			if (i >= j) {
				break;
			}

			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		temp = arr[i];
		arr[i] = arr[right];
		arr[right] = temp;

		if (i - left > right - i) {
			stack.push_back(i - 1);
			stack.push_back(left);
			stack.push_back(right);
			stack.push_back(i + 1);
		}
		else {
			stack.push_back(right);
			stack.push_back(i + 1);
			stack.push_back(i - 1);
			stack.push_back(left);
		}
	}
}

template <class Structure, class Instance> int Graph<Structure, Instance>::depthFirstSearch() { //Using DFS method for finding the connected components
	int count = 0;
	this->data.forEach([&](Instance& node) { //Checking if we've visited this node
		node.visited = false;
	});

	this->data.forEach([&](Instance& node) { //Counting the nodes we haven't visited yet
		if (!node.visited) {
			count++;
			this->depthFirstSearchVisit(node);
		}
	});
	return count;
}

template <class Structure, class Instance> void Graph<Structure, Instance>::depthFirstSearchVisit(Instance& node) {
	std::vector<Instance*> unvisitedNodes; //Storing the unvisited nodes in a vector array
	unvisitedNodes.push_back(&node);
	while (unvisitedNodes.size()) {
		Instance* currentNode = unvisitedNodes.back();
		unvisitedNodes.pop_back(); //Deleting a visited Node from the vector array
		if (!currentNode->visited) {
			currentNode->visited = true;
			currentNode->neighbors.forEach([&](int neighbor) {
				unvisitedNodes.push_back(&this->data.search(Instance(neighbor))); //Inserting a new neighbor in the vector array
			});
		}
	}
}

// Tell the compiler for what types to compile the class.
template class Graph<ArrayImplementation, NodeWithArray>;
template class Graph<AVLTreeImplementation, NodeWithAVLTree>;
template class Graph<HashTableImplementation, NodeWithHashTable>;
