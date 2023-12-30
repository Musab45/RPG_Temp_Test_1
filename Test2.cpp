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

// Inventory Items
int Healing_Portion = 0;
int Poison_Spell = 0;

// Selected Character
Character Selected_Char;
// Selected Enemy
Enemy Active_Enemy;

// Initialize Characters
Character Warrior = { "Warrior", 100, 15 };
Character Mage = { "Mage", 200, 10 };
Character Rouge = { "Rouge", 70, 70 };
Character Nigger = { "Nigger", 1000, 1000 };//Test Character

// Initialize Enemies
Enemy Dragon = { "Dragon", 50, 15 };
Enemy Skeleton = { "Skeleton",30,10 };
Enemy Ghost = { "Ghost",90,30 };
Enemy Centaur = { "Centaur",100,30 };
Enemy GrimReaper = { "Grim Reaper",150,70 };

// Speacial Powers
bool warrior_sp = false;
bool mage_sp = false;
bool rouge_sp = false;
bool sp_used = false; //True when special power is once used

// Special Power Use
void special_ability()
{
    if (warrior_sp == true)
    {
        Selected_Char.hp = Active_Enemy.hp;
        Selected_Char.atk = Active_Enemy.atk;
    }
    if (mage_sp == true)
    {
        Selected_Char.hp = 200;
    }
    if (rouge_sp == true)
    {
        Active_Enemy.hp -= 150;
    }
}

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
        warrior_sp = true;
        break;
    case 2:
        Selected_Char.name = Mage.name;
        Selected_Char.hp = Mage.hp;
        Selected_Char.atk = Mage.atk;
        mage_sp = true;
        break;
    case 3:
        Selected_Char.name = Rouge.name;
        Selected_Char.hp = Rouge.hp;
        Selected_Char.atk = Rouge.atk;
        rouge_sp = true;
        break;
    case 4:
        Selected_Char.name = Nigger.name;
        Selected_Char.hp = Nigger.hp;
        Selected_Char.atk = Nigger.atk;
        break;
        //Remove if char select > 4 when final version is ready
    default:
        cout << endl;
        cout << "Wrong Entry!";
    }
}

// Enemy Decision
void enemyDecision(Enemy& enemy)
{
    Active_Enemy.name = enemy.name;
    Active_Enemy.hp = enemy.hp;
    Active_Enemy.atk = enemy.atk;
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

// Inventory Display
void inventory_diplay()
{
    cout << endl;
    cout << "1. Healing Potion" << endl;
    cout << "2. Poison" << endl;
    cout << endl;
    cout << "Enter Selection: ";
}
// Inventory Selection
void inventory_selection(int& choice)
{
    switch (choice)
    {
    case 1:
        Selected_Char.hp += 30;
        cout << Selected_Char.name << " healed 30 HP" << endl;
        break;
    case 2:
        Active_Enemy.hp -= 50;
        cout << Selected_Char.name << " used poison on " << Active_Enemy.name << " and dealed 50 HP" << endl;
        break;
    default:
        cout << "Wrong Entry!" << endl;
    }
}

// Action Function
void action()
{
    cout << "1. Attack        2. Inventory";
    cout << "3. Ability       4. Flee" << endl;
    int action_choice = 0;
    int inventory_choice = 0;
    cout << "Enter Choice: ";
    cin >> action_choice;
    switch (action_choice)
    {
    case 1:
        if (Selected_Char.hp > 0)
        {
            attack(Selected_Char, Active_Enemy);
        }
        break;
    case 2:
        cin >> inventory_choice;
        inventory_selection(inventory_choice);
        break;
    case 3:
        special_ability();
    }
}

// Choice Variables
char attack_choice = 0;
int char_select_main = 0;
int inventory_choice = 0;

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
            //Easy Quest --------------------------------------------------------------------
            case 1:

                //Character Selection
                CharSelectMenu();
                cin >> char_select_main;
                if (char_select_main > 4)
                {
                    break;
                }
                charSelect(char_select_main);


                // First 2 Enemies -> 2 Skeletons
                enemyDecision(Centaur);
                for (int q1_sk = 1; q1_sk <= 2; q1_sk++)
                {
                    cout << endl;
                    cout << "*A Lvl 1 " << Active_Enemy.name << " Appeared!*" << endl;
                    do
                    {
                        // Print Character Stats
                        CharStatDisplay(Selected_Char);

                        //Print Enemy Stats
                        EnmStatDisplay(Active_Enemy);
                        cin >> attack_choice;

                        // Simulate attack
                        action();

                        //Exit if Enemy/Player Dies
                        if (Selected_Char.hp <= 0 || Active_Enemy.hp <= 0)
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

            // Normal Quest ----------------------------------------------------------------
            case 2:

                //Character Selection
                CharSelectMenu();
                cin >> char_select_main;
                if (char_select_main > 4)
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
            // Hard Quest --------------------------------------------------------------------------
            case 3:
                //Character Selection
                CharSelectMenu();
                cin >> char_select_main;
                if (char_select_main > 4)
                {
                    break;
                }
                charSelect(char_select_main);

                // First 2 Enemies ->  2 Dragons
                for (int q3_drg = 1; q3_drg <= 2; q3_drg++)
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

                // Second 2 Enemies ->  2 Ghosts
                for (int q3_gho = 1; q3_gho <= 2; q3_gho++)
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

                    Ghost.hp = 50;

                    if (attack_choice == 'n')
                    {
                        break;
                    }
                }

                // Last 3 Enemies ->  3 Centaurs
                for (int q3_cen = 1; q3_cen <= 2; q3_cen++)
                {
                    cout << endl;
                    cout << "*A Lvl 1 " << Centaur.name << " Appeared!*" << endl;
                    do
                    {
                        // Print Character Stats
                        CharStatDisplay(Selected_Char);

                        //Print Enemy Stats
                        EnmStatDisplay(Centaur);
                        cin >> attack_choice;

                        // Simulate attack
                        if (attack_choice == 'y')
                        {
                            attack(Selected_Char, Centaur);
                        }

                        //Exit if Enemy/Player Dies
                        if (Selected_Char.hp <= 0 || Centaur.hp <= 0)
                        {
                            break;
                        }

                    } while (attack_choice == 'y');

                    Centaur.hp = 100;

                    if (attack_choice == 'n')
                    {
                        break;
                    }
                }
            //Impossible ---------------------------------------------------------------------------------------
            case 4:
                
                //Character Selection
                CharSelectMenu();
                cin >> char_select_main;
                if (char_select_main > 4)
                {
                    break;
                }
                charSelect(char_select_main);

                //First Enemy -> Centaur
                cout << endl;
                cout << "*A Lvl 1 " << Centaur.name << " Appeared!*" << endl;
                do
                {
                    // Print Character Stats
                    CharStatDisplay(Selected_Char);

                    //Print Enemy Stats
                    EnmStatDisplay(Centaur);
                    cin >> attack_choice;

                    // Simulate attack
                    if (attack_choice == 'y')
                    {
                        attack(Selected_Char, Centaur);
                    }

                    //Exit if Enemy/Player Dies
                    if (Selected_Char.hp <= 0 || Centaur.hp <= 0)
                    {
                        break;
                    }

                } while (attack_choice == 'y');

                Centaur.hp = 100;

                if (attack_choice == 'n')
                {
                    break;
                }

                //Second Enemy -> Ghost
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

                //Last Enemy -> Grim Reaper
                cout << endl;
                cout << "*A Lvl 1 " << GrimReaper.name << " Appeared!*" << endl;
                do
                {
                    // Print Character Stats
                    CharStatDisplay(Selected_Char);

                    //Print Enemy Stats
                    EnmStatDisplay(GrimReaper);
                    cin >> attack_choice;

                    // Simulate attack
                    if (attack_choice == 'y')
                    {
                        attack(Selected_Char, GrimReaper);
                    }

                    //Exit if Enemy/Player Dies
                    if (Selected_Char.hp <= 0 || GrimReaper.hp <= 0)
                    {
                        break;
                    }

                } while (attack_choice == 'y');

                GrimReaper.hp = 150;

                if (attack_choice == 'n')
                {
                    break;
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