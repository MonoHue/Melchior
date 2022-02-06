#include <iostream>
#include <vector>

using namespace std;

struct Role{
    long long atk;
    long long health;
}human, monster;

long long coin, datk, dhealth;

bool victory(Role hero, Role mon)   {
    long long heroHit = (mon.health + hero.atk - 1) / hero.atk;
    long long monHit = (hero.health + mon.atk - 1) / mon.atk;
//    cout << heroHit << " " << monHit << endl;
    return heroHit <= monHit;
}

int main()  {
    int testcase;cin >> testcase;
    while (testcase-->0)    {
        cin >> human.health >> human.atk;
        cin >> monster.health >> monster.atk;
        cin >> coin >> datk >> dhealth;

        bool ok = false;
        for(long long atkcoin = 0;atkcoin <= coin && !ok;atkcoin++)  {
            long long healthcoin = coin - atkcoin;
            Role hero = human;
            hero.atk += atkcoin * datk;
            hero.health += healthcoin * dhealth;
//            cout << atkcoin << ":" << hero.atk << " " << hero.health << endl;
//            cout << atkcoin << ":" << monster.atk << " " << monster.health << endl;
            ok = victory(hero, monster);
        }

        if(ok)  cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}