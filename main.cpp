#include <iostream>
#include <string>
#include <fstream>

#include "CommandReader.h"

#include "Graph.h"


using namespace std;

template <class T, class Y> void executeCommands();



int main(int argc, char **argv) { //Checking if the argument is valid
	if (argc != 2) {
		cerr << "No argument given. Please use one argument of value 1, 2 or 3 to select data structure";
		return -1;
	}

	if ((string)argv[1] == "1") { //When argument is 1,use the Array data structure
		executeCommands<ArrayImplementation, NodeWithArray>();
	}
	else if ((string)argv[1] == "2") { //When argument is 2,use the AVL Tree data structure
		executeCommands<AVLTreeImplementation, NodeWithAVLTree>();
	}
	else if ((string)argv[1] == "3") { //When argument is 3,use the HashTable data structure
		executeCommands<HashTableImplementation, NodeWithHashTable>();
	}
	else { //If the argument isn't 1,2 or 3,it is invalid
		cerr << "Invalid argument given. Please use one argument of value 1, 2 or 3 to select data structure";
		return -1;
	}

}

template <class T, class Y> void readData(Graph<T, Y>* graph) { //Reading data from the input.txt file and inserting them in the graph
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


template <class T, class Y> void executeCommands() { //Executing the right command, depending on the Commands.txt file
	Graph<T, Y> graph;

	string selectedCommand;
	int node, neighbor;

	ofstream output;
	output.open("output.txt");
	if (!output.is_open()) {
		cerr << "Error opening output.txt" << endl;
		return;
	}

	try {
		CommandReader commandreader;

		while (commandreader.readNextCommand(selectedCommand, node, neighbor)) { //Reading Data
			if (selectedCommand == "READ_DATA") {
				readData<T, Y>(&graph);
			}
			else if (selectedCommand == "INSERT_LINK") { //Inserting Links
				graph.insertEdge(node, neighbor);
			}
			else if (selectedCommand == "DELETE_LINK") { //Deleting Links
				graph.deleteEdge(node, neighbor);
			}
			else if (selectedCommand == "FIND_NEIGHBORS") { //Finding Neighbors of the node
				output << "Neighbors of node " << node << ": ";
				graph.showNeighbors(node, output);
				output << endl;
			}
			else if (selectedCommand == "FIND_NUM_CONNECTED_COMPONENTS") { //Finding the connected components of the graph
				cout << "finished reading" << endl;
				output << "Number of connected components: " << graph.depthFirstSearch() << endl;
			}

		}
	}
	catch (char const* error) {
		cerr << error << endl;
		return;
	}


}
