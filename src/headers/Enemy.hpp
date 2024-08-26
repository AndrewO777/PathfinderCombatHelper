#include<string>
#include<map>
#include"Attack.hpp"

using std::string,std::map;
class Enemy
{
public:
    Enemy(string name, short hp, short ac, short reflex, short fort, short will, short dc) :
        _name(name), _maxHp(hp), _ac(ac), _reflex(reflex), _fort(fort), _will(will), _dc(dc)
        { _hp = _maxHp; };
    Enemy(){};
    void TakeDamage(short& damage);
    void Heal(short& damage);
    void PrintStats() const;

    //Setters
    void AddAttack();

    //Getters
    const short& GetHp() const { return _hp; }
    const string& GetName() const { return _name; };

    //variables
    map<string,Attack> _attacks;
private:
    string _name;
    short _hp;
    short _maxHp;
    short _ac;
    short _reflex;
    short _fort;
    short _will;
    short _dc;
};
