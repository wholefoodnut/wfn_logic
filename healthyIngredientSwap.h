// Kristian John M. Estrabillo
#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <iostream>
#include <string>
class Ingredient {
    private:
    string name;    // name of the ingredient
    int macro;      // macro:   0 - undefined
                    //          1 - carb
                    //          2 - fat
                    //          3 - protein
    public:
    Ingredient(string nme, int mac);
    ~Ingredient();

    void setName(string nme);
    void setMacro(string mac);

    string getName();
    string getMacro();


};

#endif