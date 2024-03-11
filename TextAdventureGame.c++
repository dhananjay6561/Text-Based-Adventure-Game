#include <iostream>
#include <ctime>
using namespace std;

class Player {
    private:
    int health = 100;

    int maxDamage = 35;
    int minDamage = 25;

    int maxHealing = 20;
    int minHealing = 10;

    public:
    Player() {
        cout<<"\nHi! My name is Rossy! We need to save Juily and get her back"<<endl;
        cout<<"Here are some stats that might be useful for you going ahead"<<endl;

        cout<<"\nRossy's Health: "<<health;
        cout<<"\n_______________________________________________\n";
        cout<<"Rossy's Attack Range is between "<<minDamage<<"-"<<maxDamage<<".";
        cout<<"\n_______________________________________________\n";
        cout<<"Rossy's Healing Range is between "<<minHealing<<"-"<<maxHealing<<".";
    }

    int getHealth() {
        return health;
    }

    void takeDamage(int damage) {
        cout<<"Ohh No, a critical hit to player"<<endl;
        cout<<"Enemy is dealing damage of "<<damage<<" to the Rossy"<<endl;
        health = health - damage;
            
        if (health > 0) {
            cout<<"Rossy's current health after receiving damage is: "<<health<<endl;
        } else {
            cout<<"Rossy died.... YOU LOST!!"<<endl;
        }
    }

    int giveDamage() {
        srand(time(0));
        int randomDamage = (rand() % (maxDamage - minDamage + 1) + minDamage);

        cout<<"Rossy is performing hit of "<<randomDamage<<" to the Enemy"<<endl;

        return randomDamage;
    }

    void Heal() {
        srand(time(0));
        int randomHealing = (rand() % (maxHealing - minHealing) + minHealing);

        health = health + randomHealing;

        cout<<"Rossy healed with HP of "<<randomHealing<<endl;
        cout<<"Rossy's health after healing "<<health<<endl;
    }
};

class Enemy {
    private:
    int health = 100;

    int maxDamage = 30;
    int minDamage = 20;

    public: 
    Enemy() {
        cout<<"Ha ha ha, I am the Lord of the darkness!!"<<endl;
    }

    int getHealth() {
        return health;
    }

    void takeDamage(int damage) {
        cout<<"Yeah, a critical hit to enemy"<<endl;
        cout<<"Rossy is dealing damage of "<<damage<<" to the Enemy"<<endl;
        health = health - damage;

        if (health > 0) {
            cout<<"Enemy's current health after receiving damage is: "<<health<<endl;
        } else {
            cout<<"Enemy died.... YOU WON!!"<<endl;
        }
    }

    int giveDamage() {
        srand(time(0));
        int randomDamage = (rand() % (maxDamage - minDamage + 1) + minDamage);

        cout<<"Enemy is performing hit of "<<randomDamage<<" to the Rossy"<<endl;

        return randomDamage;
    }
};

void gameStory() {
    cout<<"\n_______________________________________________\n";
    cout<<"Rossy : A true Warrior |";
    cout<<"\n_______________________________________________\n";
    cout<<"\nOnce upon a time there was a kingdom full of happiness. The king named Garelt had a beautiful cat named Juily."<<endl;
    cout<<"\n_______________________________________________\n";
    cout<<"Unfortunately, on one evil day, the Hollow Knight kidnapped Juily.\nNow the entire kingdom is at stake. Hollow Knight is a ruler of the dark world.";
    cout<<"\n";
}

void gameLoop(Player player, Enemy enemy) {
    char playerChoice;
    do {
        cout<<"\nPress A to attack or H to heal: ";
        cin>>playerChoice;

        if (playerChoice == 'a' || playerChoice == 'A') {
            // perform attack
            enemy.takeDamage(player.giveDamage());

            if (enemy.getHealth() > 0) {
                cout<<"Ha ha ha! It's my turn"<<endl;

                player.takeDamage(enemy.giveDamage());
            }
        } else if (playerChoice == 'h' || playerChoice == 'H') {
            // perform heal
            player.Heal();

            if (enemy.getHealth() > 0) {
                cout<<"Ha ha ha! It's my turn"<<endl;

                player.takeDamage(enemy.giveDamage());
            }
        } else {
            cout<<"Invaild Input!!!"<<endl;
        }

    } while (player.getHealth() > 0 && enemy.getHealth() > 0);
}

int main() {
    gameStory();
    char userInput;

    do {
        cout<<"Please enter S to start or any other key to exit: ";
        cin>>userInput;
        if (userInput == 'S' || userInput == 's') {
            Player playerObj;
            Enemy enemyObj;
            gameLoop(playerObj, enemyObj);
        } else {
            cout<<"\nThanks for playing Rossy...."<<endl;
        }
    } while (userInput == 'S' || userInput == 's');

    return 0;
}
