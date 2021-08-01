#include <iostream>


int  fun(int n , int &ref)
{
 std::cout << "\n hi iam in fun";

}


int main()
{
 int i =0 ;

 std::cout << "\n data reutrn from funf === " <<fun(i , i);


}

