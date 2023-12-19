#include <iostream>
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
        cout << enemy.name << " attacks with " << enemy.attackPower << " damage!" << endl;

        // Check if character is defeated
        if (character.health <= 0) {
            cout << character.name << " is defeated!" << endl;
        }
    }
}

void main() {
    // Initialize character and enemy
    Character hero = { "Mage", 100, 25 };
    Enemy goblin = { "Dragon", 50, 15 };

    // Print initial stats
    cout << "Hero: " << hero.name << " (" << hero.health << " HP, " << hero.attackPower << " AP)" << endl;
    cout << "Goblin: " << goblin.name << " (" << goblin.health << " HP, " << goblin.attackPower << " AP)" << endl;

    // Simulate attack
    attack(hero, goblin);

}