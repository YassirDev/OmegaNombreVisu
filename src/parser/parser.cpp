#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
 
int main(int argc, char *argv[]) 
{
    char* name_file = argv[0];

    FILE* fp = std::fopen(name_file, "r");

    if(!fp) {
	    std::perror("File opening failed");
	    return EXIT_FAILURE;
	}


    char *token = std::strtok(fp, " ");
    while (token != '\n') {
        std::cout << token << '\n';
        //token = std::strtok(NULL, " ");
    }
}