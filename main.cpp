#include <iostream>
#include <string>
#include <fstream>

#include "./include/CommandReader.h"

#include "./include/Graph.h"


using namespace std;

template <class T, class Y> void executeCommands();



int main(int argc, char **argv) {
	if (argc != 2) {
		cerr << "No argument given. Please use one argument of value 1, 2 or 3 to select data structure";
		return -1;
	}

	if ((string)argv[1] == "1") {
		executeCommands<ArrayImplementation, NodeWithArray>();
	}
	else if ((string)argv[1] == "2") {
		executeCommands<AVLTreeImplementation, NodeWithAVLTree>();
	}
	else if ((string)argv[1] == "3") {
		executeCommands<HashTableImplementation, NodeWithHashTable>();
	}
	else {
		cerr << "Invalid argument given. Please use one argument of value 1, 2 or 3 to select data structure";
		return -1;
	}

	system("PAUSE");
}

template <class T, class Y> void readData(Graph<T, Y>* graph) {
	int node, neighbor;
	ifstream input;
	input.open("input.txt");
	if (!input.is_open()) {
		throw "Error opening input.txt";
	}

	while (!input.eof()) {
		input >> node >> neighbor;
		graph->insertEdge(node, neighbor);
	}

	input.close();
}


template <class T, class Y> void executeCommands() {
	Graph<T, Y> graph;
	string selectedCommand;
	int node, neighbor;
	try {
		CommandReader commandreader;

		while (commandreader.readNextCommand(selectedCommand, node, neighbor)) {
			if (selectedCommand == "READ_DATA") {
				readData<T, Y>(&graph);
			}
			else if (selectedCommand == "INSERT_LINK") {
				graph.insertEdge(node, neighbor);
			}
			else if (selectedCommand == "DELETE_LINK") {
				graph.deleteEdge(node, neighbor);
			}
			else if (selectedCommand == "FIND_NEIGHBORS") {
				graph.findNeighbors(node); // OUTPUT.TXT
			}
			else if (selectedCommand == "FIND_NUM_CONNECTED_COMPONENTS") {
				cout << graph.depthFirstSearch() << endl; // OUTPUT.TXT
			}

		}
	}
	catch (char const* error) {
		cerr << error;
	}


}
