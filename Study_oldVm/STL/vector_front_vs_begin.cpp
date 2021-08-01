#include<iostream>

#include<vector>

using namespace std;

int main()
{
 static std::vector<int > v;//
 v.push_back(1);
 v.push_back(2);
 
 vector<int>::iterator it;

 vector<int>::reverse_iterator it_r;
 
 it = v.begin();
 std::cout<<"\n begin it===" << *it;
 it_r = v.rbegin();
 std::cout<<"\n reversre iterator ===" << *it_r;

 //std::cout<<"begin=" <<v.begin();
 std::cout<<"\nfront=" <<v.front();





}
