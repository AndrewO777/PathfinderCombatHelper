#include<iostream>
#include<random>
#include<map>
#include<string>
#include"headers/Enemy.hpp"

using std::cout,std::cin,std::string,std::map;

map<string,Enemy> AddEnemies();
void RollDamage(const Enemy& aEnemy);
void RollHits(const Enemy& aEnemy);
Enemy AddEnemy();

std::random_device dev;
std::mt19937 rng(dev());

int main()
{
    map<string,Enemy> Enemies = AddEnemies();

    while(true)
    {
        cout << '|';
        for(const auto& [key,value] : Enemies){
            cout << value.GetName();
            cout << '|';
        }
        cout << '\n';

        cout << "who (type \'end\' to quit or \'add\' to add a new enemy)?: ";
        string input;
        cin >> input;

        if(input == "end"){
            break;
        }
        else if(input == "add"){
            Enemy aEnemy = AddEnemy();
            Enemies[aEnemy.GetName()] = aEnemy;
            continue;
        }
        else if(Enemies.find(input) == Enemies.end()){
            cout << input << " not found\n";
            continue;
        }

        short opt;
        cout << "1. hurt:\n2. heal:\n3. stats:\n4. roll damage:\n5. roll to hit: ";
        cin >> opt;
        switch(opt){
            case 1:
                short dam;
                cout << "damage amount?: \n";
                cin >> dam;
                Enemies[input].TakeDamage(dam);
                if(Enemies[input].GetHp() <= 0)
                    Enemies.erase(input);
                break;
            case 2:
                short heal;
                cout << "heal amount?: \n";
                cin >> heal;
                Enemies[input].Heal(heal);
                break;
            case 3:
                Enemies[input].PrintStats();
                break;
            case 4:
                RollDamage(Enemies[input]);
                break;
            case 5:
                RollHits(Enemies[input]);
                break;
            default:
                cout << "Invalid choice\n";
                break;
        }
    }

    return 0;
}

map<string,Enemy> AddEnemies()
{
    short enemyCount;
    map<string,Enemy> enemies;
    cout << "How many enemies?: ";
    cin >> enemyCount;
    for(short i = 0; i < enemyCount; ++i)
    {
        Enemy aEnemy = AddEnemy();
        enemies[aEnemy.GetName()] = aEnemy;
    }
    return enemies;
}

void RollDamage(const Enemy& aEnemy){

    short dice[5]; //Each index represent a different side count, ie: 4, 6, 8, 10, 12

    cout << "How many d4s?: ";
    cin >> dice[0];
    cout << "How many d6s?: ";
    cin >> dice[1];
    cout << "How many d8s?: ";
    cin >> dice[2];
    cout << "How many d10s?: ";
    cin >> dice[3];
    cout << "How many d12s?: ";
    cin >> dice[4];

    short curFace = 4;
    short damage = 0;
    for(short& dieCount : dice){
        if(dieCount == 0){
            curFace += 2;
            continue;
        }
        std::uniform_int_distribution<std::mt19937::result_type> dist(1,curFace);
        for(short i = 0; i < dieCount; ++i){
            short roll = dist(rng);
            cout << roll << ',';
            damage += roll;
        }
        curFace += 2;
    }
    cout << "You deal " << damage << " +" << aEnemy.GetDamageBonus() <<
    " = " << damage + aEnemy.GetDamageBonus() << " damage!\n";
}

void RollHits(const Enemy& aEnemy){
    short rolls;
    cout << "How many rolls?: ";
    cin >> rolls;
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,20);
    for(short i = 0; i < rolls; ++i){
        short roll = dist(rng);
        cout << "You got a " << roll << " +" << aEnemy.GetHitBonus() <<
        " = " << roll + aEnemy.GetHitBonus() << '\n';
    }
}


Enemy AddEnemy(){
    short vals[8];
    cout << "hp?:";
    cin >> vals[0];
    cout << "ac?:";
    cin >> vals[1];
    cout << "reflex?:";
    cin >> vals[2];
    cout << "fort?:";
    cin >> vals[3];
    cout << "will?:";
    cin >> vals[4];
    cout << "dc?:";
    cin >> vals[5];
    cout << "damage bonus?:";
    cin >> vals[6];
    cout << "hit bonus?:";
    cin >> vals[7];
    string name;
    cout << "name?:";
    cin >> name;
    return Enemy(name,vals[0],vals[1],vals[2],vals[3],vals[4],vals[5],vals[6],vals[7]);
}
