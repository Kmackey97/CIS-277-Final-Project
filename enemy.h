#include <iostream>
using namespace std;

class Enemy
{
  public: 
    Enemy(int damage = 10);
    void virtual TauntPlayer() const; //overridden eventually
    void virtual Attack() const; //""

  private:
    int m_Attack;
};

Enemy::Enemy(int damage);
  m_Damage(damage)
{}

void Enemy::Taunt() const
{
  cout << "The enemy says he will fight you." << endl;
  //alternates?
}

void Enemy::Attack() const
{
  cout << "You've been attacked. " << m_Damage << " points damaged." << endl;
  //minus some player attribute?
}

class StickMan : public Enemy
{
  public:
    int m_DamageMultiplier;

    StickMan();
    void SpecialAttack() const;
};

StickMan::StickMan():
  m_DamageMultiplier(3)
{}

void StickMan::SpecialAttack() const
{
  cout << "Special Attack inflicts" << m_DamageMultiplier * m_Damage);
  cout << " damage points." << endl;
}

class SlimePal : public Enemy
{
  public:
    int m_DamageMultiplier;

    SlimePal();
    void SpecialAttack() const;
};

SlimePal::SlimePal():
  m_DamageMultiplier(2)
{}

void SlimePal::SpecialAttack() const
{
  cout << "Special Attack inflicts" << m_DamageMultiplier * m_Damage);
  cout << " damage points." << endl;
}

class LichLizard : public Enemy
{
  public:
    int m_DamageMultiplier;

    LichLizard();
    void SpecialAttack() const;
};

LichLizard::LichLizard():
  m_DamageMultiplier(3)
{}

void LichLizard::SpecialAttack() const
{
  cout << "Special Attack inflicts" << m_DamageMultiplier * m_Damage);
  cout << " damage points." << endl;
}

class BossLady : public Enemy
{
  public:
    Boss (int damage = 30);
    void Taunt() const;
    void Attack() const;
    //int m_DamageMultiplier;

    void SpecialAttack() const;
};

BossLady::BossLady(int damage):
  Enemy(damage) //calls constructor
  m_DamageMultiplier(4)
{}

void BossLady::SpecialAttack() const
{
  cout << "Special Attack inflicts" << m_DamageMultiplier * m_Damage);
  cout << " damage points." << endl;
}