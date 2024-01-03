#include<iostream>
#include<string>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Character
{
    string name;
    int hp;
    int atk_max;
    int atk_min;
};

struct Enemy
{
    string name;
    int hp;
    int atk_max;
    int atk_min;
};

// Player Data
string player_name;
int score = 0;
void playerdata()
{
    cout << endl;
    cout << "Enter Player Name: ";
    getline(cin, player_name);
}

// Player Data Display
void playerdatadisplay()
{
    cout << endl;
    cout << "---------------------------------------" << endl;
    cout << "Name: " << player_name << endl;
    cout << "Score: " << score;
    cout << endl;
    cout << "---------------------------------------" << endl;
}
// Special
bool specials_unlocked = false;
// Currency
int currency = 30;

// XP Points
int xp = 0;

// Inventory Items
int Healing_Portion = 2;
int Poison_Spell = 1;

// Special Items

// Speacial Powers
bool warrior_sp = false;
bool mage_sp = false;
bool rouge_sp = false;
bool sp_used = false; //True when special power is once used

// Max Level Limiters
bool warrior_max = false;
bool mage_max = false;
bool rouge_max = false;

// Selected Character
Character Selected_Char;
// Selected Enemy
Enemy Active_Enemy;

// Initialize Characters
Character Warrior = { "Warrior",100,15, 5 };
Character Mage = { "Mage",200,10,5 };
Character Rouge = { "Rouge",70,70,50 };
Character Old_Wizard = { "Old Wizard",520,480,420 };//Special Character

// Initialize Enemies
Enemy Dragon = { "Dragon",50,15,5 };
Enemy Skeleton = { "Skeleton",30,10,5 };
Enemy Ghost = { "Ghost",90,30,15 };
Enemy Centaur = { "Centaur",100,30,20 };
Enemy GrimReaper = { "Grim Reaper",150,70,60 };
Enemy Shadow_Overlord = { "Shadow Overlord",1000,150,110 };
Enemy Fairy_King = { "Fairy King",800,200,170 };

// Enemy Decision
// Easily Create Enemy in Quest
void enemyDecision(Enemy& enemy)
{
    Active_Enemy.name = enemy.name;
    Active_Enemy.hp = enemy.hp;
    Active_Enemy.atk_max = enemy.atk_max;
    Active_Enemy.atk_min = enemy.atk_min;
}

// Character Stats Display
void CharStatDisplay(Character& character)
{
    cout << endl;
    cout << "---------------------------------------" << endl;
    cout << "Your Stats: " << endl;
    cout << " -> " << character.name << endl;
    cout << "  -> HP: " << character.hp << endl;
    cout << "  -> ATK: " << character.atk_max << endl;
}

// Enemy Stats Display
void EnemyStatDisplay(Enemy& enemy)
{
    cout << endl;
    cout << "Enemy Stats: " << endl;
    cout << " -> " << enemy.name << endl;
    cout << "  -> HP: " << enemy.hp << endl;
    cout << "  -> ATK: " << enemy.atk_max << endl;
}

// Attack Function
void attack(Character& character, Enemy& enemy)
{

    // Character attacks enemy
    int char_generated_atk = character.atk_min + rand() % (character.atk_max - character.atk_min + 1);
    enemy.hp -= char_generated_atk;
    cout << endl;
    cout << "* " << character.name << " attacks " << enemy.name << " with " << char_generated_atk << " damage! *" << endl;

    // Check if enemy is defeated
    if (enemy.hp <= 0)
    {
        cout << endl;
        cout << "* " << enemy.name << " is defeated! *" << endl;
    }

    // Enemy attacks character (if still alive)
    if (enemy.hp > 0)
    {
        int enemy_generated_atk = enemy.atk_min + rand() % (enemy.atk_max - enemy.atk_min + 1);
        character.hp -= enemy_generated_atk;
        cout << endl;
        cout << "* " << enemy.name << " attacks back with " << enemy_generated_atk << " damage! *" << endl;

        // Check if character is defeated
        if (character.hp <= 0)
        {
            cout << endl;
            cout << "* " << character.name << " is defeated! *" << endl;
        }
    }
}

//// Character Upgrade Display
void char_display_upgrade()
{
    cout << endl;
    cout << "---------------------------------------" << endl;
    cout << "Select Character for Upgrade: " << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Rouge" << endl;
    cout << endl;
    cout << "Enter Selection: ";
}

// Character Upgrade
void char_upgrade()
{
    int  upgrade_choice = 0;
    char_display_upgrade();
    cin >> upgrade_choice;
    switch (upgrade_choice)
    {
    case 1:
        if (Warrior.hp >= 140)
        {
            warrior_max = true;
        }
        if (!warrior_max)
        {
            Warrior.hp += 10;
            Warrior.atk_max += 5;
            cout << "---------------------------------------" << endl;
            cout << "Warrior Upgraded Successfully!" << endl;
            cout << endl;
            cout << "---------------------------------------" << endl;
        }
        if (warrior_max)
        {
            cout << "---------------------------------------" << endl;
            cout << "Warrior is already at max level" << endl;
            cout << endl;
            cout << "---------------------------------------" << endl;
        }
        break;
    case 2:
        if (Mage.hp >= 280)
        {
            mage_max = true;
        }
        if (!mage_max)
        {
            Mage.hp += 20;
            Mage.atk_max += 20;
            cout << "---------------------------------------" << endl;
            cout << "Mage Upgraded Successfully!" << endl;
            cout << endl;
            cout << "---------------------------------------" << endl;
        }
        if (mage_max)
        {
            cout << endl;
            cout << "---------------------------------------" << endl;
            cout << "Mage is already at max level" << endl;
            cout << "---------------------------------------" << endl;
        }
        break;
    case 3:
        if (Rouge.hp >= 90)
        {
            rouge_max = true;
        }
        if (!rouge_max)
        {
            Rouge.hp += 5;
            Rouge.atk_max += 10;
            cout << "---------------------------------------" << endl;
            cout << "Rouge Upgraded Successfully!" << endl;
            cout << endl;
            cout << "---------------------------------------" << endl;
        }
        if (rouge_max)
        {
            cout << "---------------------------------------" << endl;
            cout << "Rouge is already at max level" << endl;
            cout << endl;
            cout << "---------------------------------------" << endl;
        }
        break;
    default:
        cout << "Wrong Entry!" << endl;
    }
}
// Shop Display
void shop()
{
    int shop_choice = 0;
    char shop_loop;
    do
    {
        cout << "---------------------------------------" << endl;
        cout << endl;
        cout << "Welcome to Shop!" << endl;
        cout << endl;
        cout << "Please select an item to purchase: " << endl;
        cout << "1. Healing Potion - 20$" << endl;
        cout << "2. Poison Spell - 50$" << endl;
        cout << "3. Press any key to return" << endl;
        cout << endl;
        cout << "Your Currency: " << currency << "$" << endl;
        cout << endl;
        cout << "Enter Selection: ";
        cin >> shop_choice;
        cout << endl;
        cout << "---------------------------------------" << endl;
        switch (shop_choice)
        {
        case 1:
            if (currency < 20)
            {
                cout << "Insufficient Currency!";
                cout << endl;
                cout << "---------------------------------------" << endl;
            }
            if (currency >= 20)
            {
                currency -= 20;
                Healing_Portion += 1;
                cout << endl;
                cout << "Healing Potion purchased!";
                cout << endl;
                cout << "---------------------------------------" << endl;
            }
            break;
        case 2:
            if (currency < 50)
            {
                cout << "Insufficient Currency!";
                cout << endl;
                cout << "---------------------------------------" << endl;
            }
            if (currency >= 50)
            {
                currency -= 50;
                Poison_Spell += 1;
                cout << endl;
                cout << "Healing Potion purchased!";
                cout << endl;
                cout << "---------------------------------------" << endl;
            }
            break;
        default:
            break;
        }
        cout << "Return to Shop?(y/n): ";
        cin >> shop_loop;

    } while (shop_loop == 'y');
}

// Inventory Display
void inventory_diplay()
{
    cout << "---------------------------------------" << endl;
    cout << endl;
    cout << "1. Healing Potion = " << Healing_Portion << endl;
    cout << "2. Poison Spell = " << Poison_Spell << endl;
    cout << "---------------------------------------" << endl;
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
            cout << endl;
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
        Selected_Char.atk_max = Active_Enemy.atk_max;
        Selected_Char.atk_min = Active_Enemy.atk_min;
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
        if (sp_used)
        {
            cout << endl;
            cout << "Special Ability can only be used only once!" << endl;
        }
        if (!sp_used)
        {
            special_ability();
            sp_used = true;
        }
        break;
    }
}

// Character Selection Menu Display
void CharSelectMenu()
{
    cout << endl;
    cout << "---------------------------------------" << endl;
    cout << endl;
    cout << "Select a Character: " << endl;
    cout << endl;
    cout << "1. Warrior" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Rouge" << endl;
    if (!specials_unlocked)
    {
        cout << "4. Character Locked" << endl;
    }
    if (specials_unlocked)
    {
        cout << "4. Old Wizard" << endl;
    }
}

// Character Selection
void charSelect()
{
    int choice = 0;
    // If Grim Reaper Defeated
    if (specials_unlocked)
    {
        do
        {

            cout << endl;
            cout << "---------------------------------------" << endl;
            cout << "Selection: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                Selected_Char.name = Warrior.name;
                Selected_Char.hp = Warrior.hp;
                Selected_Char.atk_max = Warrior.atk_max;
                Selected_Char.atk_min = Warrior.atk_min;
                warrior_sp = true;
                break;
            case 2:
                Selected_Char.name = Mage.name;
                Selected_Char.hp = Mage.hp;
                Selected_Char.atk_max = Mage.atk_max;
                Selected_Char.atk_min = Mage.atk_min;
                mage_sp = true;
                break;
            case 3:
                Selected_Char.name = Rouge.name;
                Selected_Char.hp = Rouge.hp;
                Selected_Char.atk_max = Rouge.atk_max;
                Selected_Char.atk_min = Rouge.atk_min;
                rouge_sp = true;
                break;
            case 4:
                Selected_Char.name = Old_Wizard.name;
                Selected_Char.hp = Old_Wizard.hp;
                Selected_Char.atk_max = Old_Wizard.atk_max;
                Selected_Char.atk_min = Old_Wizard.atk_min;
                break;
            default:
                cout << endl;
                cout << "Wrong Entry! Enter Again";
            }
        } while (choice > 4);
    }

    // If Grim Reaper Not Defeated
    if (!specials_unlocked)
    {
        do
        {

            cout << endl;
            cout << "---------------------------------------" << endl;
            cout << "Selection: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                Selected_Char.name = Warrior.name;
                Selected_Char.hp = Warrior.hp;
                Selected_Char.atk_max = Warrior.atk_max;
                Selected_Char.atk_min = Warrior.atk_min;
                warrior_sp = true;
                break;
            case 2:
                Selected_Char.name = Mage.name;
                Selected_Char.hp = Mage.hp;
                Selected_Char.atk_max = Mage.atk_max;
                Selected_Char.atk_min = Mage.atk_min;
                mage_sp = true;
                break;
            case 3:
                Selected_Char.name = Rouge.name;
                Selected_Char.hp = Rouge.hp;
                Selected_Char.atk_max = Rouge.atk_max;
                Selected_Char.atk_min = Rouge.atk_min;
                rouge_sp = true;
                break;
            default:
                cout << endl;
                cout << "Wrong Entry! Enter Again" << endl;
            }
        } while (choice > 3);
    }
}

// Battle
void battle()
{
    int fight;
    cout << endl;
    cout << "---------------------------------------" << endl;
    cout << "*A Lvl 1 " << Active_Enemy.name << " Appeared!*" << endl;
    cout << endl;
    cout << "1. Fight     2.Flee" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Selection: ";
    cin >> fight;
    do
    {
        if (fight == 1)
        {
            CharStatDisplay(Selected_Char);
            EnemyStatDisplay(Active_Enemy);
            action();
            if (Selected_Char.hp <= 0 || Active_Enemy.hp <= 0)
            {
                break;
            }
        }
        else
        {
            cout << "Wrong Entry! Try Again." << endl;
        }
        if (fight == 2)
        {
            break;
        }
    } while (fight < 3);
}
//Quest
void quest()
{
    char fight;
    int quest_select = 0;
    cout << "---------------------------------------" << endl;
    cout << endl;
    cout << "Select a Quest: " << endl;
    cout << endl;
    cout << "1. Easy Quest" << endl;
    cout << "2. Normal Quest" << endl;
    cout << "3. Hard Quest" << endl;
    cout << "4. Impossible Quest" << endl;
    if (!specials_unlocked)
    {
        cout << "5. Quest Locked" << endl;
    }
    if (specials_unlocked)
    {
        cout << "5. The Final Battle" << endl;
    }
    cout << endl;
    cout << "---------------------------------------" << endl;
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
            battle();
        }

        // 1 Dragon
        // Set Dragon as Active Enemy
        enemyDecision(Dragon);
        battle();
        // Reward
        cout << "* Easy Quest Completed! *" << endl;
        cout << "* You have earned 5$ and 50 XP *" << endl;
        currency += 5;
        xp += 50;
        break;

        // Normal Quest
    case 2:
        // 3 Skeletons
        // Set Skeleton as Active Enemy
        enemyDecision(Skeleton);
        for (int q2_sk = 1; q2_sk <= 3; q2_sk++)
        {
            Active_Enemy.hp = 30;
            battle();
        }

        // 2 Dragon
        // Set Dragon as Active Enemy
        enemyDecision(Dragon);
        for (int q2_drg = 1; q2_drg <= 2; q2_drg++)
        {
            Active_Enemy.hp = 50;
            battle();
        }

        // 2 Ghost
       // Set Ghost as Active Enemy
        enemyDecision(Ghost);
        for (int q2_gho = 1; q2_gho <= 2; q2_gho++)
        {
            Active_Enemy.hp = 90;
            battle();
        }
        // Reward
        cout << "* Normal Quest Completed! *" << endl;
        cout << "* You have earned 10$ and 100 XP *" << endl;
        currency += 10;
        xp += 100;
        break;

        //Hard Quest
    case 3:
        // 2 Dragon
        // Set Dragon as Active Enemy
        enemyDecision(Dragon);
        for (int q3_drg = 1; q3_drg <= 2; q3_drg++)
        {
            Active_Enemy.hp = 50;
            battle();
        }

        // 3 Ghost
       // Set Ghost as Active Enemy
        enemyDecision(Ghost);
        for (int q3_gho = 1; q3_gho <= 3; q3_gho++)
        {
            Active_Enemy.hp = 90;
            battle();
        }

        // 3 Centaurs
        // Set Ghost as Active Enemy
        enemyDecision(Centaur);
        for (int q3_cen = 1; q3_cen <= 3; q3_cen++)
        {
            Active_Enemy.hp = 90;
            battle();
        }
        // Reward
        cout << "* Hard Quest Completed! *" << endl;
        cout << "* You have earned 20$ and 200 XP *" << endl;
        currency += 20;
        xp += 200;
        break;

        //Impossible
    case 4:
        // 1 Dragon
        // Set Dragon as Active Enemy
        enemyDecision(Dragon);
        battle();

        // 1 Ghost
        // Set Ghost as Active Enemy
        enemyDecision(Ghost);
        battle();

        // 1 Grim Reaper
        // Set Grim Reaper as Active Enemy
        enemyDecision(GrimReaper);
        battle();
        if (Active_Enemy.hp <= 0)
        {
            specials_unlocked = true;
        }
        // Reward
        cout << "* Impossible Quest Completed! *" << endl;
        cout << "* You have earned 50$ and 500 XP *" << endl;
        currency += 50;
        xp += 500;
        break;

        // The Final Battle
    case 5:
        if (specials_unlocked)
        {
            int fate = 0;
            cout << endl;
            cout << "---------------------------------------" << endl;
            cout << "Choose your Fate:" << endl;
            cout << "1. Destroy the Shadow Realm" << endl;
            cout << "2. Destroy the Fairy World" << endl;
            cout << "Enter Selection: ";
            do
            {
                cin >> fate;
                if (fate == 1)
                {
                    //Good Ending
                    enemyDecision(Shadow_Overlord);
                    battle();
                }

                if (fate == 2)
                {
                    //Bad Ending
                    enemyDecision(Fairy_King);
                    battle;
                }
            } while (fate > 2);
        }
        if (!specials_unlocked)
        {
            cout << "Quest Locked!" << endl;
        }
        // Rewards
        cout << "* Impossible Quest Completed! *" << endl;
        cout << "* You have earned 100$ and 1000 XP *" << endl;
        currency += 100;
        xp += 1000;
    }
}

// Quest Menu Display
void GameMenu()
{
    int menu_choice = 0;
    cout << "---------------------------------------" << endl;
    cout << "RPG GAME" << endl;
    cout << endl;
    cout << "---------------------------------------" << endl;
    playerdatadisplay();
    cout << "\nMenu" << endl;
    cout << "\n1. Start a Quest!" << endl;
    cout << "2. Go to Shop" << endl;
    cout << "3. View Inventory" << endl;
    cout << "4. Upgrade Characters" << endl;
    cout << endl;
    cout << "---------------------------------------" << endl;
    cout << "Enter Selection: ";
    cin >> menu_choice;
    switch (menu_choice)
    {
    case 1:
        CharSelectMenu();
        charSelect();
        quest();
        break;
    case 2:
        shop();
        break;
    case 3:
        inventory_diplay();
        break;
    case 4:
        char_upgrade();
        break;
    default:
        cout << "Wrong Entry" << endl;
    }
}

int main()
{
    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));

    char escape;
    do
    {
        playerdata();
        GameMenu();
        cout << endl;
        cout << "---------------------------------------" << endl;
        cout << endl;
        cout << "Press 'y' to Return to Menu" << endl;
        cout << "Press Any Key to Exit Game" << endl;
        cout << endl;
        cout << "---------------------------------------" << endl;
        cout << "Selection: ";
        cin >> escape;
    } while (escape == 'y');
    return 0;
}