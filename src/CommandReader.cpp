#include "CommandReader.h"

#include <iostream>

CommandReader::CommandReader(){
    this->file.open("commands.txt");
    if(!this->file.is_open()){
        throw "Error opening commands.txt";
    }
}

CommandReader::~CommandReader(){
    this->file.close();
}

bool CommandReader::readNextCommand(std::string& command, int& node, int& neighbor){
        if(this->file.eof()){
            return false;
        }
        this->file >> command;
        if(command == "INSERT_LINK" || command == "DELETE_LINK"){
            this->file >> node >> neighbor;
        } else if(command == "FIND_NEIGHBORS"){
            this->file >> node;
        } else if(command != "READ_DATA" && command != "WRITE_INDEX" && command != "FIND_NUM_CONNECTED_COMPONENTS"){
            return true;
        }
        return true;
}
