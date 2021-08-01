#include <iostream>
#define increment 100


//Logic ::: Chec

class  myVector{
public:
   int size; //size of each space in array which cab 1 byte or 4byte depeneds
   int quantity;//Total bytes allocated for array...

   int next;//next index avaibale  in array for allocation
   unsigned char *storage;//starting address of array
   int add(void  * );//function to add element
   int front();

   myVector( int );//constructor
   void inflate ( int ); //reszie array
   

};


myVector::myVector( int user_size )
{
  std::cout << "\n we are in constructor " ;
  size = user_size;
  quantity = 0;

  next = 0 ;
  storage =NULL;

}


int  myVector::add( void  * num)
{
 std::cout << "\n we are in add" ;
 if(next >= quantity)
 inflate(increment);

 
 int start_index =  next *size;
  int i=0;

 std::cout << "\n size ===" << size;
 
 //get the first byte of element which can be int or char  
 unsigned char *elem_char_pointer  = (unsigned char * )  num;
 int j =3;

 //Due to litlle endian the the lowest address contains the LSB so we no to do this.decrement pointer addess ...its like 10 is store at 2000 ,2001 2002 and 2003 contains 0
 unsigned char * p = (unsigned char *) (elem_char_pointer -3 );
 
 for(i = 0 ; i <  4 ; i++ , p++)

 {
  storage[ start_index + i ] = *p;
  std::cout << "\n array index====" << (start_index + i) << "and storage === " << static_cast <int > ( storage[ start_index + i ] );

 }

 next++;
 
} 




void myVector ::inflate( int new_increment)
{
   
   std::cout << "\n hi we are in inflate";
   int new_quanitity = quantity + new_increment; //get the new quanity by current quanatity + fixed size by that it will be increasedi ...like for ex 100+100
   int new_bytes = new_quanitity * size ;// so new bytes for for newly craeted quantity ....ie for ex  new_quantiy means 200* 4
   int old_bytes = quantity * size;//old bye ....for ex 100*4
   unsigned char *new_storage = new  unsigned char[ new_bytes] ; //request new memory equal to new_bytes 
  
   for(int i = 0; i < old_bytes ; i++)
   {
     new_storage[i] =  storage[i]; //copy old data into new memory until the  old number of bytes
   }
   storage = new_storage; //changes pointer to new localtion
   quantity = new_quanitity;//changes old quanity to new quantity i.e for eg 200
   
    
}      
 
   
int myVector::front()
{
// int i = storage[( next*size) -1 ];
 // static_cast < int> (storage[( next*size) -1 ] ) ;
// std::cout << "hello iam in fron and i===" << i;


 return ( storage[( next*size) -1 ] );  
 
}

int main()
{

 myVector vec(sizeof(int));
 int  i =10;
 int j =20;
 int m = 40;

  /*char *elem_char_pointer  = ( char * )  (&i);

   std::cout << "\n value of element chararacterwis == " << static_cast<int > (*elem_char_pointer) << "valuei ===" << * ( ( char * )  (&i) );;

 for(m = 0 ; m <  4 ; m++ , elem_char_pointer++)
  std::cout << "\n value of element chararacterwis == " << static_cast<int > (*elem_char_pointer) << "and dree==" << static_cast<char* > (elem_char_pointer);
  */
  

 vec.add(&i);
 vec.add(&j);
 vec.add(&m);
 
 int front_elem  = vec.front();
  
 std::cout << "\n vector ..front ===" << front_elem;//vec.front();



}
