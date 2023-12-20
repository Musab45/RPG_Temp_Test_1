#include<iostream>
using namespace std;

struct Character {
    string name;
    int health;
    int attackPower;
};

struct Enemy {
    string name;
    int health;
    int attackPower;
};


// Function to handle character and enemy attack
void attack(Character& character, Enemy& enemy) {
    // Character attacks enemy
    enemy.health -= character.attackPower;
    cout << character.name << " attacks " << enemy.name << " for " << character.attackPower << " damage!" << endl;

    // Check if enemy is defeated
    if (enemy.health <= 0) {
        cout << enemy.name << " is defeated!" << endl;
    }

    // Enemy attacks character (if still alive)
    if (enemy.health > 0) {
        character.health -= enemy.attackPower;
        cout << enemy.name << " attacks back with " << enemy.attackPower << " damage!" << endl;

        // Check if character is defeated
        if (character.health <= 0) {
            cout << character.name << " is defeated!" << endl;
        }
    }
}

int main()
{
    // Initialize character and enemy
    Character Mage = { "Mage", 100, 20 };
    Enemy Dragon = { "Dragon", 50, 15 };

    char return_choice;
    do
    {
        int menu_choice;
        cout << "RPG GAME" << endl;
        cout << "\nMenu" << endl;
        cout << "1. Start a Quest!" << endl;
        cout << "2. Go to Shop" << endl;
        cout << "3. View Inventory" << endl;
        cout << "Enter Selection: ";
        cin >> menu_choice;
        switch (menu_choice)
        {
        case 1:
            //Quests
            cout << "A wild Dragon appeared!" << endl;

            char choice;
            do
            {

                cout << "\nAttack(y/n): ";
                cin >> choice;
                // Print initial stats
                cout << "\nYou: " << Mage.name << " (" << Mage.health << " HP, " << Mage.attackPower << " AP)" << endl;
                cout << "Enemy: " << Dragon.name << " (" << Dragon.health << " HP, " << Dragon.attackPower << " AP)" << endl;

                // Simulate attack
                attack(Mage, Dragon);
                if (Mage.health <= 0 || Dragon.health <= 0)
                {
                    break;
                }
            } while (choice == 'y');

            cout << "\nAnother wild Dragon appeared!" << endl;
            do
            {

                cout << "\nAttack(y/n): ";
                cin >> choice;
                // Print initial stats
                cout << "\nYou: " << Mage.name << " (" << Mage.health << " HP, " << Mage.attackPower << " AP)" << endl;
                cout << "Enemy: " << Dragon.name << " (" << Dragon.health << " HP, " << Dragon.attackPower << " AP)" << endl;

                // Simulate attack
                attack(Mage, Dragon);
                if (Mage.health <= 0 || Dragon.health <= 0)
                {
                    break;
                }
            } while (choice == 'y');

            break;

        case 2:
            //Shop
            cout << "2";
            break;

        case 3:
            //View Inventory
            cout << "3";
            break;

        default:
            //Default Case
            cout << "4";
        }
        cout << "\nReturn to Menu?(y/n): ";
        cin >> return_choice;
    } while (return_choice == 'y');

    return 0;
}