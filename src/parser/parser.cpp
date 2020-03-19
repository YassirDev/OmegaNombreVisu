#include "Parser.h"

void Parser::parse(const char* name_file){

    int cpt = 1; //permet de savoir où on en est dans le fichier à parser
    int nb_coord = 0;   // 2 pou 2D ou 3 pour 3D, le nombre de coordonnées par points
    int cpt_coord = 0;  // permet de compter les coordonnées pour les attribuer facilement à chaque points
    int cpt_pts = 0;    // permet de savoir le numéro du point traité

    std::ifstream myFile(name_file);
    while(myFile.good())
    {
        std::string line;
        getline(myFile, line);
        char* sArr = new char[line.length() + 1];
        strcpy(sArr, line.c_str());
        char* token = std::strtok(sArr, ";");

        while (token != NULL) {
            if(cpt<3){

                if(cpt==1){
                    std::cout << "La fonction utilisée: " << token << '\n';

                }else{  //cpt==2
                    if(strcmp(token,"2D")==0){
                        nb_coord = 2;
                    }else{
                        nb_coord = 3;
                    }
                    std::cout << "2D ou 3D: " << token << '\n';
                    std::cout << "Nb coord par point: " << nb_coord << '\n';
                }

            }else{  //cpt>=3

                if(cpt%3==0){
                    std::cout << "Rang numéro: " << token << '\n';

                }else if(cpt%3==1){
                    std::cout << "Nombre de points: "<< token << '\n';

                }else if(cpt%3==2){
                    char* coord = std::strtok(sArr, " ");
                    while (coord != NULL){
                        if(cpt_coord % nb_coord == 0){ // nouveau points toutes les 2 ou 3 coord selon si on est on 2D ou 3D
                            std::cout << "\nPoint n°" << cpt_pts+1 << ": ";
                            cpt_pts++;
                        }
                        cpt_coord++;
                        std::cout << coord << ' ';
                        coord = std::strtok(NULL, " ");
                        
                    }
                    cpt_pts = 0;
                    cpt_coord = 0;
                    std::cout << '\n';
                }

            }
            token = std::strtok(NULL, ";");
            cpt++;
        }
    }
    myFile.close();
}