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
int Healing_Portion = 2;
int Poison_Spell = 1;

// Speacial Powers
bool warrior_sp = false;
bool mage_sp = false;
bool rouge_sp = false;
bool sp_used = false; //True when special power is once used

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

// Enemy Decision
// Easily Create Enemy in Quest
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
    cout << "---------------------------------------" << endl;
    cout << "Your Stats: " << endl;
    cout << " -> " << character.name << endl;
    cout << "  -> HP: " << character.hp << endl;
    cout << "  -> ATK: " << character.atk << endl;
}

// Enemy Stats Display
void EnemyStatDisplay(Enemy& enemy)
{
    cout << endl;
    cout << "Enemy Stats: " << endl;
    cout << " -> " << enemy.name << endl;
    cout << "  -> HP: " << enemy.hp << endl;
    cout << "  -> ATK: " << enemy.atk << endl;
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
    cout << "1. Healing Potion = "<< Healing_Portion << endl;
    cout << "2. Poison Spell = " << Poison_Spell << endl;
    cout << endl;
    cout << "Enter Selection: ";
}
// Inventory Selection
void inventory_selection(int& choice)
{
    switch (choice)
    {
    case 1:
        cout << "---------------------------------------" << endl;
        cout << endl;
        cout << "Out of Healing Potions";
        cout << endl;
        if (Healing_Portion > 0)
        {
            Selected_Char.hp += 30;
            cout << endl;
            cout << Selected_Char.name << " gained 30 HP" << endl;
            Healing_Portion -= 1;
            cout << endl;
            cout << "---------------------------------------" << endl;
        }
        break;
    case 2:
        if (Poison_Spell <= 0)
        {
            cout << "---------------------------------------" << endl;
            cout << endl;
            cout << "Out of Poison Spells";
            cout << endl;
        }
        if (Poison_Spell > 0)
        {
            Active_Enemy.hp -= 50;
            cout<<endl;
            cout << Selected_Char.name << " used poison on " << Active_Enemy.name << " and dealed 50 Damage" << endl;
            Poison_Spell -= 1;
            if (Active_Enemy.hp <= 0)
            {
                cout << endl;
                cout << Active_Enemy.name << " is defeated" << endl;
            }
            cout << endl;
            cout << "---------------------------------------" << endl;
        }
        break;
    default:
        cout << "Wrong Entry!" << endl;
    }
}

// Special Power Use
void special_ability()
{
    if (warrior_sp == true)
    {
        Selected_Char.hp = Active_Enemy.hp;
        Selected_Char.atk = Active_Enemy.atk;
        cout << Selected_Char.name << " shapeshifted to " << Active_Enemy.name << endl;
    }
    if (mage_sp == true)
    {
        Selected_Char.hp = 200;
        cout << Selected_Char.name << " restored full HP" << endl;

    }
    if (rouge_sp == true)
    {
        Active_Enemy.hp -= 150;
        cout << Selected_Char.name << " rage attacks " << Active_Enemy.name << endl;
        if (Active_Enemy.hp <= 0)
        {
            cout << endl;
            cout << Active_Enemy.name << " is defeated!" << endl;
        }
    }
}

int action_choice = 0;
int inventory_choice = 0;

// Action Function
void action()
{
    cout << endl;
    cout << "1. Attack        2. Inventory      3. Ability       " << endl;
    cout << "4. Press any key to flee " << endl;
    cout << endl;
    cout << "Enter Choice: ";
    cin >> action_choice;
    cout << endl;
    cout << "---------------------------------------" << endl;
    switch (action_choice)
    {
    case 1:
        if (Active_Enemy.hp > 0)
        {
            attack(Selected_Char, Active_Enemy);
        }
        break;
    case 2:
        inventory_diplay();
        cin >> inventory_choice;
        inventory_selection(inventory_choice);
        break;
    case 3:
        special_ability();
        break;
    }
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
}

// Character Selection
void charSelect()
{
    int choice = 0;
    do
    {
        cout << endl;
        cout << "Selection: ";
        cin >> choice;
        switch (choice)
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
            //Remove when final version is ready
        default:
            cout << endl;
            cout << "Wrong Entry! Enter Again";
        }
    } while (choice > 4);
}

//Quest
void quest()
{
    char fight;
    int quest_select = 0;
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
    // Easy Quest
    case 1:
        // 2 Skeletons
        // Set Skeleton as Active Enemy
        enemyDecision(Skeleton);
        for (int q1_sk = 1; q1_sk <= 2; q1_sk++)
        {
            Active_Enemy.hp = 30;
            cout << endl;
            cout << "*A Lvl 1 " << Active_Enemy.name << " Appeared!*" << endl;
            cout << "Fight?(y/n): ";
            cin >> fight;
            do
            {
                CharStatDisplay(Selected_Char);
                EnemyStatDisplay(Active_Enemy);
                action();
                if (Selected_Char.hp <= 0 || Active_Enemy.hp <= 0)
                {
                    break;
                }
            } while (fight == 'y');
        }

        // 1 Dragon
        // Set Dragon as Active Enemy
        enemyDecision(Dragon);
        cout << endl;
        cout << "*A Lvl 1 " << Active_Enemy.name << " Appeared!*" << endl;
        cout << "Fight?(y/n): ";
        cin >> fight;
        do
        {
            CharStatDisplay(Selected_Char);
            EnemyStatDisplay(Active_Enemy);
            action();
            if (Selected_Char.hp <= 0 || Active_Enemy.hp <= 0)
            {
                break;
            }
        } while (fight == 'y');
        break;

    // Normal Quest
    case 2:
        // 3 Skeletons
        // Set Skeleton as Active Enemy
        enemyDecision(Skeleton);
        for (int q2_sk = 1; q2_sk <= 3; q2_sk++)
        {
            Active_Enemy.hp = 30;
            cout << endl;
            cout << "*A Lvl 1 " << Active_Enemy.name << " Appeared!*" << endl;
            cout << "Fight?(y/n): ";
            cin >> fight;
            do
            {
                CharStatDisplay(Selected_Char);
                EnemyStatDisplay(Active_Enemy);
                action();
                if (Selected_Char.hp <= 0 || Active_Enemy.hp <= 0)
                {
                    break;
                }
            } while (fight == 'y');
        }

        // 2 Dragon
        // Set Dragon as Active Enemy
        enemyDecision (Dragon);
        for (int q2_drg = 1; q2_drg <= 2; q2_drg++)
        {
            Active_Enemy.hp = 50;
            cout << endl;
            cout << "*A Lvl 1 " << Active_Enemy.name << " Appeared!*" << endl;
            cout << "Fight?(y/n): ";
            cin >> fight;
            do
            {
                CharStatDisplay(Selected_Char);
                EnemyStatDisplay(Active_Enemy);
                action();
                if (Selected_Char.hp <= 0 || Active_Enemy.hp <= 0)
                {
                    break;
                }
            } while (fight == 'y');
        }

        // 2 Ghost
       // Set Ghost as Active Enemy
        enemyDecision(Ghost);
        for (int q2_gho = 1; q2_gho <= 2; q2_gho++)
        {
            Active_Enemy.hp = 90;
            cout << endl;
            cout << "*A Lvl 1 " << Active_Enemy.name << " Appeared!*" << endl;
            cout << "Fight?(y/n): ";
            cin >> fight;
            do
            {
                CharStatDisplay(Selected_Char);
                EnemyStatDisplay(Active_Enemy);
                action();
                if (Selected_Char.hp <= 0 || Active_Enemy.hp <= 0)
                {
                    break;
                }
            } while (fight == 'y');
        }
    }
}

// Quest Menu Display
void GameMenu()
{
    int menu_choice = 0;
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
        CharSelectMenu();
        charSelect();
        quest();
        break;
    case 2:
        cout << "l";
        break;
    case 3:
        inventory_diplay();
        break;
    }
}

void main()
{
    char escape;
    do
    {
        GameMenu();
        cout << endl;
        cout << "Press y to return to menu" << endl;
        cout << "Press any key to exit" << endl;
        cout << "Selection: ";
        cin >> escape;
    } while (escape == 'y');
}