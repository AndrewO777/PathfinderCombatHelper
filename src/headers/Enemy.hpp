#include<iostream>
#include<string>

using std::string;

class Enemy
{
public:
    Enemy(string name, short hp, short ac, short reflex, short fort, short will, short dc,
            int damageBonus, int hitBonus) :
        _name(name), _maxHp(hp), _ac(ac), _reflex(reflex), _fort(fort), _will(will), _dc(dc),
        _damageBonus(damageBonus), _hitBonus(hitBonus)
        { _hp = _maxHp; };
    Enemy(){};
    void TakeDamage(short damage);
    void Heal(short damage);
    void PrintStats() const; 
    short GetHp() const { return _hp; } 
    string GetName() const { return _name; };
    int GetDamageBonus() const { return _damageBonus; }
    int GetHitBonus() const { return _hitBonus; }
private:
    string _name;
    short _hp;
    short _maxHp;
    short _ac;
    short _reflex;
    short _fort;
    short _will;
    short _dc;
    int _damageBonus;
    int _hitBonus;
};
