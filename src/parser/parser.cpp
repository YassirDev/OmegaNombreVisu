#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <iostream>  

 
int main(int argc, char *argv[]) 
{
    char* name_file = argv[1];

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