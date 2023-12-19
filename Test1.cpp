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
  Character Mage = {"Mage", 100, 20};
  Enemy Dragon = {"Dragon", 80, 15};
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
  } while (choice == 'y');

  return 0;
}