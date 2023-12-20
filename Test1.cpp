#include<iostream>
using namespace std;

struct Character 
{
    string name;
    int hp;
    int atk;
    int exp;
};

struct Enemy
{
    string name;
    int hp;
    int atk;
};

string selected_char_name;
int selected_char_hp;
int selected_char_atk;

// Function to handle character and enemy attack
void attack(Character& character, Enemy& enemy) {
    // Character attacks enemy
    enemy.hp -= character.atk;
    cout << endl;
    cout << "** " << character.name << " attacks " << enemy.name << " with " << character.atk << " damage! **" << endl;

    // Check if enemy is defeated
    if (enemy.hp <= 0) {
        cout << endl;
        cout <<"** " << enemy.name << " is defeated! **" << endl;
    }

    // Enemy attacks character (if still alive)
    if (enemy.hp > 0) {
        character.hp -= enemy.atk;
        cout << endl;
        cout << "** " << enemy.name << " attacks back with " << enemy.atk << " damage! **" << endl;

        // Check if character is defeated
        if (character.hp <= 0) {
            cout << endl;
            cout << "** " << character.name << " is defeated! **" << endl;
        }
    }
}

int main()
{
    // Initialize character and enemy
    Character Warrior = { "Warrior", 100, 15 };
    Character Mage = { "Mage", 200, 10 };
    Character Rouge = { "Rouge", 70, 70 };
    Enemy Dragon = { "Dragon", 50, 15 };

    //Selected Character;
    Character Selected_Char = { selected_char_name,selected_char_hp,selected_char_atk };

    //Start
    char return_choice;
    do
    {
        int menu_choice;
        cout << "RPG GAME" << endl;
        cout << "\nMenu" << endl;
        cout << "\n1. Start a Quest!" << endl;
        cout << "2. Go to Shop" << endl;
        cout << "3. View Inventory" << endl;
        cout << "\nEnter Selection: ";
        cin >> menu_choice;
        switch (menu_choice)
        {
        case 1:
            //Quests
            int char_select;
            cout << endl;
            cout << "Select a Character: " << endl;
            cout << endl;
            cout << "1. Warrior" << endl;
            cout << "2. Mage" << endl;
            cout << "3. Rouge" << endl;
            cout << endl;
            cout << "Selection: ";
            cin >> char_select;
            switch (char_select)
            {
            case 1: 
                Selected_Char.name = Warrior.name;
                Selected_Char.hp = Warrior.hp;
                Selected_Char.atk = Warrior.atk;
                break;
            case 2:
                Selected_Char.name = Mage.name;
                Selected_Char.hp = Mage.hp;
                Selected_Char.atk = Mage.atk;
                break;
            case 3:
                Selected_Char.name = Rouge.name;
                Selected_Char.hp = Rouge.hp;
                Selected_Char.atk = Rouge.atk;
                break;
            default:
                cout << endl;
                cout << "Wrong Entry!";
                break;
            }
            cout << endl;
            cout << "A Lvl 1 Wild Dragon Appeared!" << endl;

            char choice;
            do
            {
                // Print initial stats
                //cout << "\nYou: " << Mage.name << " (" << Mage.hp << " HP, " << Mage.attack << " AP)" << endl;
                cout << endl;
                cout << "Your Stats: " << endl;
                cout << " -> "<< Selected_Char.name << endl;
                cout << "  -> HP: " << Selected_Char.hp << endl;
                cout << "  -> ATK: " << Selected_Char.atk << endl;
                //cout << "\nEnemy: " << Dragon.name << " (" << Dragon.hp << " HP, " << Dragon.atk << " AP)" << endl;
                cout << endl;
                cout << "Enemy Stats: " << endl;
                cout << "  -> HP: " << Dragon.hp << endl;
                cout << "  -> ATK: " << Dragon.atk << endl;
                cout << "\nAttack(y/n): ";
                cin >> choice;

                // Simulate attack
                attack(Selected_Char, Dragon);
                //Exit if Enemy/Player Dies
                if (Selected_Char.hp <= 0 || Dragon.hp <= 0)
                {
                    break;
                }

            } while (choice == 'y');
            Dragon.hp = 50;

            //Second Dragon
            cout << "Another Lvl 1 Wild Dragon Appeared!" << endl;
            do
            {
                // Print initial stats
                
                //cout << "\nYou: " << Mage.name << " (" << Mage.hp << " HP, " << Mage.attack << " AP)" << endl;

                cout << endl;
                cout << "Your Stats: " << endl;
                cout << " -> " << Selected_Char.name << endl;
                cout << "  -> HP: " << Selected_Char.hp << endl;
                cout << "  -> ATK: " << Selected_Char.atk << endl;

                //cout << "\nEnemy: " << Dragon.name << " (" << Dragon.hp << " HP, " << Dragon.atk << " AP)" << endl;

                cout << endl;
                cout << "Enemy Stats: " << endl;
                cout << "  -> HP: " << Dragon.hp << endl;
                cout << "  -> ATK: " << Dragon.atk << endl;
                cout << "\nAttack(y/n): ";
                cin >> choice;

                // Simulate attack
                attack(Selected_Char, Dragon);

                //Exit if Enemy/Player Dies
                if (Selected_Char.hp <= 0 || Dragon.hp <= 0)
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