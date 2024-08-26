#include<iostream>
#include <memory>
#include <string>
#include"headers/Attack.hpp"

using std::cout,std::cin;

short Attack::RollDamage(std::mt19937& rng){
    short curFace = 4;
    short damage = 0;
    std::shared_ptr<short[]> dice = GetDice();
    for(short i = 0; i < 5; ++i){
        if(dice[i] == 0){
            curFace += 2;
            continue;
        }
        std::uniform_int_distribution<std::mt19937::result_type> dist(1,curFace);
        string rollVals = "";
        for(short j = 0; j < dice[i]; ++j){
            short roll = dist(rng);
            damage += roll;
            rollVals += std::to_string(roll);
            rollVals.push_back(',');
        }
        rollVals.pop_back();
        cout << rollVals << ' ';
        curFace += 2;
    }
    cout << "You deal " << damage << " +" << GetDamageBonus() <<
    " = " << damage + GetDamageBonus() << " damage!\n";
    return damage + GetDamageBonus();
}

short Attack::RollToHit(std::mt19937& rng){
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,20);
    short roll = dist(rng);
    cout << "You got a " << roll << " +" << GetHitBonus() <<
    " = " << roll + GetHitBonus() << '\n';
    return roll + GetHitBonus();
}

void Attack::DoAttacks(std::mt19937& rng){
    short numAttacks;
    cout << "How many attacks?: ";
    cin >> numAttacks;
    for(short i = 0; i < numAttacks; ++i){
        cout << "--------------------------------\n";
        cout << "Attack " << i + 1 << '\n';
        RollToHit(rng);
        RollDamage(rng);
        cout << "--------------------------------\n";
    }
}
