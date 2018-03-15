// Kristian John Estrabillo
// Ingredient class implementation file

#include "ingredient.h"

// INGREDIENT CONSTRUCTORS AND DESTRUCTORS
Ingredient::Ingredient() {
    name = "";
    macro = 0;
}

Ingredient::Ingredient(std::string nme, int mac) {
    name = nme;

    // if macro is within 0 to 3 inclusive, set macro to parameter mac
    if (0 <= mac && mac <= 3) macro = mac;
    // else set macro to 0
    else macro = 0;
}

Ingredient::Ingredient(std::string nme, std::string mac) {

    name = nme;

    // if ingredient defined as a ...
    // carb, set macro to 1
    if (mac == "carb") macro = 1;
    // fat, set macro to 2
    else if (mac == "fat") macro = 2;
    // protein, set macro to 3
    else if (mac == "protein") macro = 3;
    // if none of the above or undefined, set macro to 0
    else macro = 0;
}

Ingredient::~Ingredient() {}

// INGREDIENT SETTERS AND GETTERS
void Ingredient::setName(std::string nme) {
    name = nme;
}

void Ingredient::setMacro(int mac) {
    if (0 <= mac && mac <= 3) macro = mac;
    else macro = 0;
}

std::string Ingredient::getName() {
    return name;
}

int Ingredient::getMacro() {
    return macro;
}