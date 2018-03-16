// Kristian John M. Estrabillo
// Ingredient Class header
// - Contains ingredient name and macro type

#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <iostream>
#include <string>

class Ingredient {

    protected:
     std::string name;  // name of the ingredient
     int macro;         // macro:   0 - undefined
                        //          1 - carb
                        //          2 - fat
                        //          3 - protein
    
    public:
     // Ingredient constructor and destructor
     Ingredient();
     Ingredient(std::string nme, int mac);
     Ingredient(std::string nme, std::string mac);
     ~Ingredient();

     // setters and getters
     void setName(std::string nme);
     void setMacro(int mac);

     std::string getName();
     int getMacro();
};

#endif