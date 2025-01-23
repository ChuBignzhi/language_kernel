/**
 * @file game_example.cpp
 * @author chu_bingzhi (chu_bingzhi@domain.com)
 * @brief 魔法门之英雄无敌
 * 游戏中有很多种怪物，每种怪物都有一个类与之对应，每个怪物就是一个对象。
 * 怪物能够互相攻击，攻击敌人和被攻击时都有相应的动作，动作是通过对象的成员函数实现的。
 * 游戏版本升级时，要增加新的怪物--雷鸟。如何编程才能使升级时的代码改动和增加量较小?
 * @version 0.1
 * @date 2025-01-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */

/**
 * @brief 
 * 为每个怪物类编写 Attack、FightBack和 Hurted成员函数。
 * Attact函数表现攻击动作，攻击某个怪物，
 * 并调用被攻击怪物的Hurted函数，以减少被攻击怪物的生命值，
 * 同时也调用被攻击怪物的 FightBack成员函数，遭受被攻击怪物反击。
 * Hurted函数减少自身生命值，并表现受伤动作。
 * FightBack成员函数表现反击动作，并调用被反击对象的Hurted成员函数，使被反击对象受伤。
 */

//不使用多态实现
#include <iostream>
using namespace std;

class CCreature {
    protected:
    int nPower ;//代表攻击力
    int nLifeValue ;//代表生命值
};
class CWolf:public CCreature{ //这两都有问题，写来不报红而已
    public : 
    void Hurted(int nPower_){}
    void FightBack(CCreature *enemy){}
};
class CGhost:public CCreature{ //这两都有问题，写来不报红而已
    public :  
    void Hurted(int nPower_){}
    void FightBack(CCreature *enemy){}
};
class CDragon:public CCreature {
    public:
    void Attack(CWolf* pWolf){
        //表现攻击动作的代码
        pWolf->Hurted( nPower);
        pWolf->FightBack( this);
    }
    void Attack( CGhost * pGhost){
        //表现攻击动作的代码
        pGhost->Hurted( nPower);
        pGhost->FightBack( this);
    }
    void Hurted ( int nPower){
        //表现受伤动作的代码
        nLifeValue -= nPower;
    }
    void FightBack( CWolf * pWolf){
        //表现反击动作的代码
        pWolf ->Hurted( nPower /2);
    }
    void FightBack( CGhost * pGhost){
        //表现反击动作的代码
        pGhost->Hurted( nPower /2 );
    }
};

/*显然当有n种怪物的话，CDragon类中就会有n个Attack成员函数，
以及n个FightBack成员函数。对于其他类也是如此*/

/*如果游戏版本升级，增加了新的怪物雷岛 CThunderBird,则程序改动较大。
所有的类都需要增加两个成员函数:
void Attack( CThunderBird * pThunderBird);
void FightBack( CThunderBird * pThunderBird)

在怪物量很大的时候需要改动的工作量大的吓人。
 */


