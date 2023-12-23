#include<iostream>
using namespace std;

struct Character
{
    string name;
    int hp;
    int atk;
};

struct Enemy
{
    string name;
    int hp;
    int atk;
};

// Selected Character
Character Selected_Char;

// Initialize Characters
Character Warrior = { "Warrior", 100, 15 };
Character Mage = { "Mage", 200, 10 };
Character Rouge = { "Rouge", 70, 70 };

// Initialize Enemies
Enemy Dragon = { "Dragon", 50, 15 };
Enemy Skeleton = { "Skeleton",30,10 };
Enemy Ghost = { "Ghost",90,30 };
Enemy Centaur = { "Centaur",100,30 };
Enemy GrimReaper = { "Grim Reaper",150,70 };

// Quest Menu Display
void QuestDisplay()
{
    cout << "RPG GAME" << endl;
    cout << "\nMenu" << endl;
    cout << "\n1. Start a Quest!" << endl;
    cout << "2. Go to Shop" << endl;
    cout << "3. View Inventory" << endl;
    cout << "\nEnter Selection: ";
}

// Character Selection Menu Display
void CharSelectMenu()
{
    cout << endl;
    cout << "Select a Character: " << endl;
    cout << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Rouge" << endl;
    cout << endl;
    cout << "Selection: ";
}

// Character Selection
void charSelect(int char_attack_choice)
{
;
    switch (char_attack_choice)
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
    }
}

// Character Stats Display
void CharStatDisplay(Character& character)
{
    cout << endl;
    cout << "Your Stats: " << endl;
    cout << " -> " << character.name << endl;
    cout << "  -> HP: " << character.hp << endl;
    cout << "  -> ATK: " << character.atk << endl;
}

// Enemy Stats Display
void EnmStatDisplay(Enemy& enemy)
{
    cout << endl;
    cout << "Enemy Stats: " << endl;
    cout << " -> " << enemy.name << endl;
    cout << "  -> HP: " << enemy.hp << endl;
    cout << "  -> ATK: " << enemy.atk << endl;
    cout << "\nAttack(y/n): ";
}


// Attack Function
void attack(Character& character, Enemy& enemy) 
{
   
    // Character attacks enemy
    enemy.hp -= character.atk;
    cout << endl;
    cout << "* " << character.name << " attacks " << enemy.name << " with " << character.atk << " damage! *" << endl;

    // Check if enemy is defeated
    if (enemy.hp <= 0)
    {
        cout << endl;
        cout << "* " << enemy.name << " is defeated! *" << endl;
    }

    // Enemy attacks character (if still alive)
    if (enemy.hp > 0)
    {
        character.hp -= enemy.atk;
        cout << endl;
        cout << "* " << enemy.name << " attacks back with " << enemy.atk << " damage! *" << endl;

        // Check if character is defeated
        if (character.hp <= 0) 
        {
            cout << endl;
            cout << "* " << character.name << " is defeated! *" << endl;
        }
    }
}

char attack_choice;
int char_select_main;

int main()
{
//Main Start

    // Start
    char return_choice;
    do
    {
        int menu_choice;
        QuestDisplay();
        cin >> menu_choice;
        switch (menu_choice)
        {
        case 1:
            //Quests
            int quest_select;
            cout << endl;
            cout << "Select a Quest: " << endl;
            cout << "1. Easy Quest" << endl;
            cout << "2. Normal Quest" << endl;
            cout << "3. Hard Quest" << endl;
            cout << "4. Impossible Quest" << endl;
            cout << endl;
            cout << "Enter Selection: ";
            cin >> quest_select;
            switch (quest_select)
            {
            //Easy Quest
            case 1:

                //Character Selection
                CharSelectMenu();
                cin >> char_select_main;
                if (char_select_main > 3)
                {
                    break;
                }
                charSelect(char_select_main);


                // First 2 Enemies -> 2 Skeletons
                for (int q1_sk = 1; q1_sk <= 2; q1_sk++)
                {
                    cout << endl;
                    cout << "*A Lvl 1 " << Skeleton.name << " Appeared!*" << endl;
                    do
                    {
                        // Print Character Stats
                        CharStatDisplay(Selected_Char);

                        //Print Enemy Stats
                        EnmStatDisplay(Skeleton);
                        cin >> attack_choice;

                        // Simulate attack
                        if (attack_choice == 'y')
                        {
                            attack(Selected_Char, Skeleton);
                        }

                        //Exit if Enemy/Player Dies
                        if (Selected_Char.hp <= 0 || Skeleton.hp <= 0)
                        {
                            break;
                        }

                    } while (attack_choice == 'y');

                    Skeleton.hp = 30;

                    if (attack_choice == 'n')
                    {
                        break;
                    }
                }

                //Third Enemy -> Dragon
                cout << endl;
                cout << "*A Lvl 1 " << Dragon.name << " Appeared!*" << endl;
                do
                {
                    // Print Character Stats
                    CharStatDisplay(Selected_Char);

                    //Print Enemy Stats
                    EnmStatDisplay(Dragon);
                    cin >> attack_choice;

                    // Simulate attack
                    if (attack_choice == 'y')
                    {
                        attack(Selected_Char, Dragon);
                    }

                    //Exit if Enemy/Player Dies
                    if (Selected_Char.hp <= 0 || Dragon.hp <= 0)
                    {
                        break;
                    }

                } while (attack_choice == 'y');

                Dragon.hp = 50;

                if (attack_choice == 'n')
                {
                    break;
                }
                break;

            // Normal Quest
            case 2:

                //Character Selection
                CharSelectMenu();
                cin >> char_select_main;
                if (char_select_main > 3)
                {
                    break;
                }
                charSelect(char_select_main);


                // First 3 Enemies -> 3 Skeletons
                for (int q2_sk = 1; q2_sk <= 3; q2_sk++)
                {
                    cout << endl;
                    cout << "*A Lvl 1 " << Skeleton.name << " Appeared!*" << endl;
                    do
                    {
                        // Print Character Stats
                        CharStatDisplay(Selected_Char);

                        //Print Enemy Stats
                        EnmStatDisplay(Skeleton);
                        cin >> attack_choice;

                        // Simulate attack
                        if (attack_choice == 'y')
                        {
                            attack(Selected_Char, Skeleton);
                        }

                        //Exit if Enemy/Player Dies
                        if (Selected_Char.hp <= 0 || Skeleton.hp <= 0)
                        {
                            break;
                        }

                    } while (attack_choice == 'y');

                    Skeleton.hp = 30;

                    if (attack_choice == 'n')
                    {
                        break;
                    }
                }
                // Second 2 Enemies -> 2 Dragons
                for (int q2_drg = 1; q2_drg <= 2; q2_drg++)
                {
                    cout << endl;
                    cout << "*A Lvl 1 " << Dragon.name << " Appeared!*" << endl;
                    do
                    {
                        // Print Character Stats
                        CharStatDisplay(Selected_Char);

                        //Print Enemy Stats
                        EnmStatDisplay(Dragon);
                        cin >> attack_choice;

                        // Simulate attack
                        if (attack_choice == 'y')
                        {
                            attack(Selected_Char, Dragon);
                        }

                        //Exit if Enemy/Player Dies
                        if (Selected_Char.hp <= 0 || Dragon.hp <= 0)
                        {
                            break;
                        }

                    } while (attack_choice == 'y');

                    Dragon.hp = 50;

                    if (attack_choice == 'n')
                    {
                        break;
                    }
                }
                // Last 2 Enemies -> 2 Ghosts
                for (int q2_gho = 1; q2_gho <= 2; q2_gho++)
                {
                    cout << endl;
                    cout << "*A Lvl 1 " << Ghost.name << " Appeared!*" << endl;
                    do
                    {
                        // Print Character Stats
                        CharStatDisplay(Selected_Char);

                        //Print Enemy Stats
                        EnmStatDisplay(Ghost);
                        cin >> attack_choice;

                        // Simulate attack
                        if (attack_choice == 'y')
                        {
                            attack(Selected_Char, Ghost);
                        }

                        //Exit if Enemy/Player Dies
                        if (Selected_Char.hp <= 0 || Ghost.hp <= 0)
                        {
                            break;
                        }

                    } while (attack_choice == 'y');

                    Ghost.hp = 90;

                    if (attack_choice == 'n')
                    {
                        break;
                    }
                }
                break;

            }
            cout << "\nReturn to Menu?(y/n): ";
            cin >> return_choice;
        } 
    }while (return_choice == 'y');
    return 0;
//Main End
}