#include<random>
#include<string>
#include<memory>

using std::string;

class Attack{
public:
    Attack(string name, short hitBonus, short damageBonus, std::shared_ptr<short*> dice) : _name(name), _hitBonus(hitBonus), _damageBonus(damageBonus), _dice(dice)
    {};
    Attack(){};
    short RollDamage(std::mt19937& rng);
    short RollToHit(std::mt19937& rng);
    const string& GetName() const { return _name; }
    const short& GetHitBonus() const { return _hitBonus; }
    const short& GetDamageBonus() const { return _damageBonus; }
    std::shared_ptr<short*> GetDice() const { return _dice; }
    void DoAttacks(std::mt19937& rng);
private:
    string _name;
    short _hitBonus;
    short _damageBonus = 0;
    std::shared_ptr<short*> _dice; //number of dice, index's: 0 = d4, 1 = d6, 2 = d8, 3 = d10, 4 = d12
};