#include "Parser.h" 

Parser::Parser(const char* name_file){

    std::ifstream myFile(name_file);
    while(myFile.good())
    {
        std::string line;
        getline(myFile, line);
        char* sArr = new char[line.length() + 1];
        strcpy(sArr, line.c_str());
        char* token = std::strtok(sArr, ";");

        while (token != NULL) {
            std::cout << token << '\n';
            token = std::strtok(NULL, ";");
        }
    }
    myFile.close();
}