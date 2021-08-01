#include <iostream>


int main()
{

 int  i =10;

 char *elem_char_pointer  = ( char * )  (&i);

 std::cout << "\n value of element chararacterwis == " << (static_cast <int> (*elem_char_pointer) ) << "valuei ===" << * ( ( char * )  (&i) );;
}
