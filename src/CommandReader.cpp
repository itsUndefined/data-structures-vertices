#include "CommandReader.h"

CommandReader::CommandReader() {
	this->file.open("commands.txt");
	if (!this->file.is_open()) {
		throw "Error opening commands.txt";
	}
}

CommandReader::~CommandReader() {
	this->file.close();
}

bool CommandReader::readNextCommand(std::string& command, int& node, int& neighbor) {//Returns T/F depending on if there are unprocessed commands remaining in the file
	if (this->file.eof()) {
		return false;
	}
	this->file >> command;
	if (command == "INSERT_LINK" || command == "DELETE_LINK") {
		this->file >> node >> neighbor;
	}
	else if (command == "FIND_NEIGHBORS") {
		this->file >> node;
	}
	return true;
}
