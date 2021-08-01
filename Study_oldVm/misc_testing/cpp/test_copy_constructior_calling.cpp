  #include<iostream>

//When an object of the class is passed (to a function) by value as an argument. HERE IN FUN2 is passing t1 as by value
using namespace std;
 
class Test
{
   /* Class data members */
public:
   Test(const Test &t) { std::cout <<"\n HI AIM IN COpy COnstructor \n";/* Copy data members from t*/}  
   Test()        { std::cout <<"\n HI AIM IN SIMPLE COnstructor "; /* Initialize data members */ }

  void  fun2(Test t ) { std::cout <<"\n hello ji copy constr sould be called";}
   
};
 
Test fun()
{
    cout << "\nfun() Called\n";
    Test t;
    return t;
}
 
int main()
{
    Test t1;
    //t1.fun2(t1);
    Test t2 = fun(t1);
    return 0;
}
