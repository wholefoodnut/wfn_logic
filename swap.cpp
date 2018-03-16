// Kristian John M. Estrabillo
// Swap program using ingredient class and file

#include "ingredient.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>

bool readRecipe(std::string filename, std::vector<Ingredient> &ingredients)
{
    std::ifstream fin;
    std::string tempName;
    int tempMacro;

    fin.open(filename.c_str());

    if (!fin) return false;
    else {
        while (fin >> tempName >> tempMacro) {
            Ingredient tempIng;
            tempIng.setName(tempName);
            tempIng.setMacro(tempMacro);
            ingredients.push_back(tempIng);
        }

        return true;
    }
}

void display(std::vector<Ingredient> &list)
{
    for (int i = 0; i < list.size(); i++)
    {
        std::cout << i + 1 << ". " << std::setw(20) << std::left << list[i].getName() << "Macro:\t" << list[i].getMacro() << std::endl;
    }
}

int main()
{
    std::vector<Ingredient> healthyIngredients;
    std::vector<Ingredient> recipe;

    std::string filename;

    try {
        std::cout << "Enter filename of healthy ingredients list.\n";
        std::cin >> filename;

        if (!readRecipe(filename, healthyIngredients)) throw "FileError";
        
        std::cout << "Enter filename containing formatted recipe.\n";
        std::cin >> filename;

        if (!readRecipe(filename, recipe)) throw "FileError";


    }
    catch (std::string) { std::cerr << "ERROR: Could not open file " << filename << std::endl; }

    std::cout << "-- Healthy Ingredients --\n";
    display(healthyIngredients);

    std::cout << "-- Recipe --\n";
    display(recipe);

    return 0;
}