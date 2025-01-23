#include <iostream>
using namespace std;

//基类 CCreature:
class CCreature{
    protected :
    int m_nLifeValue, m_nPower;
    public :
    virtual void Attack( CCreature * pCreature){}
    virtual void Hurted( int nPower){}
    virtual void FightBack( CCreature * pCreature){ }
};
//基类只有一个 Attack成员函数;
//也只有一个FightBack成员函数;
//所有CCreature的派生类也是这样。

//派生类 CDragon:
class CDragon : public CCreature {
    public:
    virtual void Attack( CCreature* pCreature);
    virtual void Hurted( int nPower);
    virtual void FightBack( CCreature * pCreature);
};

void CDragon::Attack(CCreature *p){
    //表现攻击动作的代码
    p->Hurted(m_nPower);//多态
    p->FightBack(this);//多态
}
void CDragon::Hurted( int nPower){
    //表现受伤动作的代码
    m_nLifeValue -= nPower;
}
void CDragon::FightBack(CCreature * p){
    //表现反击动作的代码
    p->Hurted(m_nPower/2);//多态
}

/**
 * @brief 
 * 如果游戏版本升级，增加了新的怪物雷岛 CThunderBird……
 * 只需要编写新类CThunderBird,不需要在已有的类里专门为新怪物增加:
 * void Attack( CThunderBird * pThunderBird)
 * void FightBack( CThunderBird * pThunderBird)
 * 成员函数，已有的类可以原封不动，没压力啊!!!
 */

// CDragon Dragon; 
// CWolf Wolf; 
// CGhost Ghost;
// CThunderBird Bird;
// Dragon.Attack( & Wolf);//(1)
// Dragon.Attack( & Ghost);//(2)
// Dragon.Attack( & Bird);//(3)
//根据多态的规则，上面的(1)，(2)，(3)进入到CDragon::Attack函数
//后能分别调用:
//CWolf::Hurted
//CGhost::Hurted
//CBird::Hurted
// void CDragon::Attack(CCreature * p){
//     p->Hurted(m_nPower);//多态
//     p->FightBack(this);//多态
// }