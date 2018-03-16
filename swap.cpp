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
    int macro;
    try
    {
        for (int i = 0; i < list.size(); i++)
        {
            std::cout << i + 1 << ". " << std::setw(20) << std::left << list[i].getName() << "Macro:\t";
            macro = list[i].getMacro();

            if (macro == 1) std::cout << "carb";
            else if (macro == 2) std::cout << "fat";
            else if (macro == 3) std::cout << "protein";
            else if (macro == 0) std::cout << "undefined";
            else throw "NO_MACRO";

            std::cout << std::endl;
        }
    }
    catch (std::string err) { std::cerr << "ERROR: " << err << " caught\n"; }
}

void swap(std::vector<Ingredient> &recipe, std::vector<Ingredient> &healthy)
{
    std::string unhealthy;
    int unhealthyIndex = 0;
    bool found = false;
    do {
        std::cout << "What ingredient in your recipe do you want to swap?\n";
        std::cin >> unhealthy;
        
        for (int i = 0; i < recipe.size(); i++) {
            if (unhealthy == recipe[i].getName()) {
                found = true;
                unhealthyIndex = i;
            }
        }
        if (!found) std::cout << unhealthy << " not found in recipe.\n";
    } while (!found);

    char choice;
    for (int i = 0; i < healthy.size(); i++) {
        if (recipe[unhealthyIndex].getMacro() == healthy[i].getMacro()) {
            std::cout << "Do you want to swap " << recipe[unhealthyIndex].getName() << " with " << healthy[i].getName() << "? (y/n)\n";
            std::cin >> choice;

            if (choice == 'y' || choice == 'Y') {
                recipe[unhealthyIndex].setName(healthy[i].getName());
                recipe[unhealthyIndex].setMacro(healthy[i].getMacro());
                return;
            }
        }
    }
    return;
}

int main()
{
    std::vector<Ingredient> healthyIngredients;
    std::vector<Ingredient> recipe;

    std::string filename;

    try {
        std::cout << "Enter the file name of the healthy alternative ingredients list.\n";
        std::cin >> filename;

        if (!readRecipe(filename, healthyIngredients)) throw "FileError";
        
        std::cout << "Enter the file name of your recipe.\n";
        std::cin >> filename;

        if (!readRecipe(filename, recipe)) throw "FileError";


    }
    catch (std::string) { std::cerr << "ERROR: Could not open file " << filename << std::endl; }

    std::cout << "-- Alternative Ingredients --\n";
    display(healthyIngredients);

    std::cout << std::endl;

    std::cout << "-- Recipe --\n";
    display(recipe);

    swap(recipe, healthyIngredients);

    std::cout << std::endl << "-- NEW RECIPE --\n";

    display(recipe);
    
    std::cout << std::endl;

    return 0;
}