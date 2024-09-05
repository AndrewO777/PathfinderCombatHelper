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
Enemy CloneEnemy(const Enemy& aEnemy);
void Attack(Enemy& aEnemy);

std::random_device dev;
std::mt19937 rng(dev());

int main()
{
    //Use heap and pointer for maps
    map<string,Enemy> Enemies = AddEnemies();
    cout << "Welcome to the combat helper!\n";

    while(true)
    {
        cout << '|';
        for(const auto& [key,value] : Enemies){
            cout << value.GetName();
            cout << '|';
        }
        cout << '\n';

        cout << "who (type \'end\' to quit, \'add\' to add a new enemy or \'clone\' to clone an existing enemy)?: ";
        string input;
        cin >> input;

        if(input == "end"){
            break;
        }
        else if(input == "add"){
            Enemy aEnemy = AddEnemy();
            if(aEnemy.GetName() == "DontAdd"){
                continue;
            }
            Enemies[aEnemy.GetName()] = aEnemy;
            continue;
        }
        else if(input == "clone"){
            cout << "Which enemy to clone?: ";
            string cloneName;
            cin >> cloneName;
            if(Enemies.find(cloneName) == Enemies.end()){
                cout << "Enemy not found\n";
                continue;
            }
            Enemy clone = CloneEnemy(Enemies[cloneName]);
            if(clone.GetName() != cloneName){
                Enemies[clone.GetName()] = clone;
            }
            continue;
        }
        else if(Enemies.find(input) == Enemies.end()){
            cout << input << " not found\n";
            continue;
        }

        short opt;
        cout << "1. hurt:\n2. heal:\n3. stats:\n4. add attack:\n5. attack:\n6. cancel\n";
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
                Enemies[input].AddAttack();
                break;
            case 5:
                Attack(Enemies[input]);
                break;
            case 6:
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
    cout << "How many enemies(\'0\' to return)?: ";
    cin >> enemyCount;
    for(short i = 0; i < enemyCount; ++i)
    {
        Enemy aEnemy = AddEnemy();
        enemies[aEnemy.GetName()] = aEnemy;
    }
    return enemies;
}

Enemy AddEnemy(){
    short vals[6];
    cout << "hp(\'0\' to cancel)?:";
    cin >> vals[0];
    if(vals[0] == 0){
        return Enemy("DontAdd",vals[0],vals[1],vals[2],vals[3],vals[4],vals[5]);
    }
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
    string name;
    cout << "name?:";
    cin >> name;
    return Enemy(name,vals[0],vals[1],vals[2],vals[3],vals[4],vals[5]);
}

Enemy CloneEnemy(const Enemy& aEnemy){
    Enemy newEnemy = aEnemy;
    cout << "name(\'cancel\' to return)?:";
    string name;
    cin >> name;
    if(name == "cancel"){
        return aEnemy;
    }
    newEnemy.SetName(name);
    return newEnemy;
}

void Attack(Enemy& aEnemy){
    string attackName;
    cout << '|';
    for(const auto& [key,value] : aEnemy._attacks){
        cout << value.GetName();
        cout << '|';
    }
    cout << '\n';
    while(true){
        string attackName;
        cout << "which attack(\'cancel\' to return)?: ";
        cin >> attackName;
        if(attackName == "cancel"){
            return;
        }
        if(aEnemy._attacks.find(attackName) == aEnemy._attacks.end()){
            cout << "Attack not found\n";
        }
        else{
            aEnemy._attacks[attackName].DoAttacks(rng);
            break;
        }
    }
}
