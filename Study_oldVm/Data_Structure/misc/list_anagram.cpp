#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>

using namespace std;

int main()
{

 map<string , int> my_map;//contains keys  as one anagram key and value as number of counts

 map<string , list<string> > my_map_2;//first string will be sorted string and 2 para ot this map will contain all anagram for that sorted string
 int i=0;
 string temp;

 list<list<string> > my_list;
 vector<string> input;
 input.push_back("cat");
 input.push_back("hello");
 input.push_back("elloh");
 input.push_back("tac");
 input.push_back("faceoff");
 input.push_back("offface");
 input.push_back("act");
 input.push_back("dlloh");

 //intialy set value map value to zero 
 for( i = 0; i < input.size(); i++)
 {
   temp = input[i];
   sort(temp.begin() ,temp.end());
   std::cout << "\ntemp==" << temp;

     my_map[temp] = 0;
 }

 //fill my_map_2 key 
 for( i = 0; i < input.size(); i++)
 {
   temp = input[i];
   sort(temp.begin() ,temp.end());
  
   if(my_map[temp] ==0)
    {
       my_map[temp] = 1;
       my_map_2[temp].push_back(input[i]);
    }
  //add correspoding anagram into list of string with  sorted string as key ...like key is act and anagaram is cat sot my_map_2[act].list(cat) 
   else
     {
       my_map[temp] =  my_map[temp] + 1;
       my_map_2[temp].push_back(input[i]);
     }     

 }

 
 typename map<string, int>::const_iterator it = my_map.begin();
 
 std::cout <<"\n print the map";
 
 for (; it != my_map.end(); it++) 
 { 
  cout << "\nKey: " << it->first << ", Value: " << it->second;

 }

  
 typename map<string, list<string> >::const_iterator it2 = my_map_2.begin();
 
// (it2->second).sort();
 //it2 = my_map_2.begin();

 for ( ;it2!=my_map_2.end() ;it2++)
 {
  cout << "\nKey: " << it2->first ;
//<< //", Value: " << it->second;

  list <string >  s1 =it2->second;
   s1.sort();
 
for(list<string>::iterator it3=  s1.begin(); it3 !=  s1.end(); it3++)
  {
   cout << "  string data ===" << *it3;
  }
  
 }





}

 

