#include <iostream>
#include <vector>
#include <algorithm>

const int Maxsize=5;

using namespace std;
int main()
{

  std::vector<int> num;
  int n;
  std::cout <<"\n enter 5 elements";
  for (int i = 0; i < Maxsize ; i++)
  {

  std::cin >> n;
   num.push_back(n);
  }
 

  
  if (num.size() == 0) 
     return -1;
  if (num.size() == 1)
   return 0;
  
  vector<pair<int, int> > toSort; 
  for (int i = 0; i < num.size(); i++)
  {
   toSort.push_back(make_pair(num[i], i));
  }
 
 sort(toSort.begin(), toSort.end());
 int len = toSort.size();
 int maxIndex = toSort[len - 1].second; 
 int ans = 0;
 
 for (int i = len - 2; i >= 0; i--)
  { ans = max(ans, maxIndex - toSort[i].second);
    maxIndex = max(maxIndex, toSort[i].second);
  } 
 std::cout <<"\n max distanc===="<<maxIndex;

}
