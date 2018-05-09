#ifndef COMMANDREADER_H
#define COMMANDREADER_H

#include <string>
#include <fstream>

class CommandReader{
    public:
        CommandReader();
        ~CommandReader();
        bool readNextCommand(std::string& command, int& node, int& neighbor); //Returns the number of arguments given or -1 for end of file

    private:
        std::ifstream file;
};

#endif // COMMANDREADER_H
