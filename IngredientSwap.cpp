// Test Algorithm
#include <iostream>
#include <string>
using namespace std;

struct Ingredient
{
    string name;  // chicken breast, tofu, etc
    string macro; // carb, fat, protein
};

int main()
{
    Ingredient healthy[3];

    healthy[0].name = "tofu";
    healthy[0].macro = "protein";

    //Ingredient rice;
    healthy[1].name = "rice";
    healthy[1].macro = "carb";

    //Ingredient avocado;
    healthy[2].name = "avocado";
    healthy[2].macro = "fat";

    Ingredient unhealthy[3];

    unhealthy[0].name = "steak";
    unhealthy[0].macro = "protein";

    unhealthy[1].name = "pasta";
    unhealthy[1].macro = "carb";

    unhealthy[2].name = "canola";
    unhealthy[2].macro = "fat";

    for (int i = 0; i < 3; i++)
    {
        cout << "[" << i + 1 << "] " << unhealthy[i].name << " (" << unhealthy[i].macro << ") \n";
    }

    int choice;

    cout << "Enter the number of the ingredient to replace: ";
    cin >> choice;

    for (int i = 0; i < 3; i++)
    {
        if (unhealthy[choice-1].macro == healthy[i].macro)
        {
            unhealthy[i] = healthy[i];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "[" << i + 1 << "] " << unhealthy[i].name << " (" << unhealthy[i].macro << ") \n";
    }
}