#include <iostream>
#include <string>
#include <cstring>

int main()
{

 int i;
 
 char *p ="hello";
 
 char *q = new char[ strlen(p)];
 
 memcpy(q, "world", strlen(p));

 std::cout <<"\n sizeof of q" << strlen(q);

}
