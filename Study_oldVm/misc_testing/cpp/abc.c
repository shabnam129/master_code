//#include <iostream>
#include <stdio.h>

int main()
{

 int  i =10;

 char *elem_char_pointer  = ( char * )  (&i);

 printf("\nchar *==== %d and  i==== %d" ,*elem_char_pointer  ,  *  ( char * )  (&i) );;
}
