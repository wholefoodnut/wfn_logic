// Kristian John M. Estrabillo
// Ingredient Class
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

    // Exception handling classes
     class OutOfRange{}; // thrown when macro is out of range. 

    // Ingredient constructor and destructor
     Ingredient();
     Ingredient(std::string nme, int mac);
     ~Ingredient();

    // setters and getters
     void setName(std::string nme);
     void setMacro(std::string mac);

     std::string getName();
     int getMacro();
};

#endif