/*
Creational Pattern: SINGLETON
Author: Rajesh V.S
Language: C++
Email: rajeshvs@msn.com
*/

#include <iostream>


using namespace std;

class Singleton
{
private:
    static bool instanceFlag;
    static Singleton *single;

    static int db_conn;

    static int db_iniatlize();
    Singleton()
    {
       std::cout<< "\n Hello iam in constructor  and " << db_iniatlize() ; //private constructor
    }
public:
    static Singleton * getInstance();
    void method();
    ~Singleton()
    {
        instanceFlag = false;
    }
};



int Singleton::db_iniatlize()
{
  db_conn = 5;
//return db_conn;

}



int Singleton::db_conn= 9;
bool Singleton::instanceFlag = false;
Singleton* Singleton::single = NULL;
Singleton* Singleton::getInstance()
{
    if(! instanceFlag)
    {
        single = new Singleton();
        instanceFlag = true;
        return single;
    }
    else
    {
        return db_conn;
    }
}

void Singleton::method()
{
    cout << "Method of the singleton class" << endl;
}

int main()
{

   // Singleton sc4;
    Singleton *sc1,*sc2;
    sc1 = Singleton::getInstance();
    sc1->method();
    sc2 = Singleton::getInstance();
    sc2->method();

    return 0;
}
