#include<iostream>
#include"headers/Enemy.hpp"
#include<memory>
#include<array>

using std::cout,std::cin;

void Enemy::TakeDamage(short& damage){
    _hp -= damage;
    if (_hp <= 0){
        _hp = 0;
        cout << _name << " dies!\n";
    }
}

void Enemy::Heal(short& heal){
    if(_hp + heal <= _maxHp){
        _hp += heal;
    }
    else {
        _hp = _maxHp;
    }
}

void Enemy::PrintStats() const{
    cout << "---------------\n";
    cout << "hp:           " << _hp << std::endl;
    cout << "ac:           " << _ac << std::endl;
    cout << "reflex:       " << _reflex << std::endl;
    cout << "fort:         " << _fort << std::endl;
    cout << "will:         " << _will << std::endl;
    cout << "dc:           " << _dc << std::endl;
    cout << "---------------\n";
}

void Enemy::AddAttack(){
    string name;
    short hitBonus;
    short damageBonus;
    //auto dice = std::make_shared<std::array<short,5>>(std::array<short,5>{});
    std::shared_ptr<short*> dice = std::make_shared<short*>(new short[5]);
    cout << "name?: ";
    cin >> name;
    cout << "hit bonus?: ";
    cin >> hitBonus;
    cout << "damage bonus?: ";
    cin >> damageBonus;
    cout << "How many d4s?: ";
    cin >> (*dice)[0];
    cout << "How many d6s?: ";
    cin >> (*dice)[1];
    cout << "How many d8s?: ";
    cin >> (*dice)[2];
    cout << "How many d10s?: ";
    cin >> (*dice)[3];
    cout << "How many d12s?: ";
    cin >> (*dice)[4];
    _attacks[name] = Attack(name,hitBonus,damageBonus,dice);
}
