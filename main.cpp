#include <iostream>
#include <string>
#include <fstream>

#include "include\CommandReader.h"

using namespace std;

void readInput();
void executeCommands();

int selectedDataStructure;

int main(int argc, char **argv){

    if(argc != 2){
        cerr << "No argument given. Please use one argument of value 1, 2 or 3 to select data structure";
        return -1;
    }
    if((string)argv[1] == "1"){
        selectedDataStructure = 1;
    } else if ((string)argv[1] == "2"){
        selectedDataStructure = 2;
    } else if ((string)argv[1] == "3"){
        selectedDataStructure = 3;
    } else {
        cerr << "Invalid argument given. Please use one argument of value 1, 2 or 3 to select data structure";
        return -1;
    }

    executeCommands();

}

void readInput(){
    int node, neighbor;
    ifstream input;
    input.open("input.txt");
    if(!input.is_open()){
        throw "Error opening input.txt";
    }

    while(!input.eof()){
        input >> node  >> neighbor;
        cout << node << "/" << neighbor << endl;
    }
    input.close();
}

void executeCommands(){
    int node, neighbor;
    string selectedCommand;

    try {
        CommandReader commandreader;

        while(commandreader.readNextCommand(selectedCommand, node, neighbor)){
            if(selectedCommand == "READ_DATA"){

            } else if(selectedCommand == "WRITE_INDEX"){

            } else if(selectedCommand == "INSERT_LINK"){

            } else if(selectedCommand == "DELETE_LINK"){

            } else if(selectedCommand == "FIND_NEIGHBORS"){

            } else if(selectedCommand == "FIND_NUM_CONNECTED_COMPONENTS"){

            }
        }
    } catch(string error) {
        cerr << error;
    }


}
