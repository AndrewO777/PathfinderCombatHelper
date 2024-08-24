#include<iostream>
#include"headers/Enemy.hpp"

using std::cout;

void Enemy::TakeDamage(short damage){
    _hp -= damage;
    if (_hp <= 0){
        _hp = 0;
        cout << _name << " dies!\n";
    }
}

void Enemy::Heal(short heal){
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
    cout << "damage bonus: " << _damageBonus << std::endl;
    cout << "hit bonus:    " << _hitBonus << std::endl;
    cout << "---------------\n";
}

