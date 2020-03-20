#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../parser.h"

/**
 * test basique de parse
 * le parser doit retourner false dans les cas suivant:
 *      - aucun fichier n'est donné en entré
 *      - le fichier n'existe pas
 *      - l'extension du fichier n'existe pas
 *      - le parsing du fichier à rencontrer une erreur
 * le parser doit retourner true dans les cas suivant :
 *      - le parser à finaliser le parsing
 **/
TEST_CASE("test parser", "[parser]"){
    Parser parser;
    
    SECTION("test lors de différentes entrée dans la méthode parse"){
        CHECK_FALSE(parser.parse());
        CHECK_FALSE(parser.parse("fichier_non_existant.txt"));
        CHECK_FALSE(parser.parse("extensionNonReconnu.test"));
        CHECK_FALSE(parser.parse("erreurInParse.txt"));
        CHECK(parser.parse("testParse.txt"));
    }
}

