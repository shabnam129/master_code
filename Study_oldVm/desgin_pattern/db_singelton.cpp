#include <iostream>

Class DB_CONN
{

   public:
    static int db_value;
    static DB_CONN *instance;
    static int flag = 0;
  
   private: 
    DB_CONN()
    { std::cout <<"\nIAM IN Connstructor";}
 
   static DB_CONN * get_instance()
   {
   if(flag==0)
   {
    instance = new DB_CONN();
    DB_CONN = 10;

   
   
    
    
   

   

} 
