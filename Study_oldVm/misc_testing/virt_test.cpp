#include <iostream>
#include<typeinfo>
using namespace std;

class base{
public:
	int a;
        int c;
        int d;
        //int n;
	base():a(0)
	{}
        virtual  int getA(){return a;}
};
class der:public base
{
public:
	int b;
	der():b(1)
	{}
	int getB(){return b;}
};
void display(base *obj, int ele)
{  
        cout <<"\n WE are in display\n";
	for(int i = 0; i < ele; i++)
	{
        cout << "valuee===" << (obj+i)->getA() << endl;//->getA() <<endl;
	}
}

int main()
{

    int i = 3;
    base arrb[i];
    display(arrb, 3);
    der arrd[i];
    display(arrd, 3);
    return 0;
}
