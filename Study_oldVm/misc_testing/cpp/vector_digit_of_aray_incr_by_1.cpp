#include <iostream>
#include <vector>

using namespace std;
vector<int> plusOne(vector<int> &);



int main()
{

  vector<int > A;
  A.push_back(1);
  A.push_back(1);
  A.push_back(9);
  int i = 0;

  plusOne(A);
  for(i = 0 ; i <  A.size() ; i++)
   {
    std::cout << " " << A[i];

   }



  
 


}

vector<int> plusOne(vector<int> &A) 
{
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


	int N = A.size() - 1;
	int  i = 0;
	int carry_bit = 0;

	for(i = N ; i >=  0 ; i-- )
	{
		std::cout << "\n we are in for loop";
		if(i==N)
		{
			std::cout << "\n the last msb ====" << A[i];
			if  ( (A[i] + 1) % 10 == 0 )
			{      carry_bit = 1;
				A[i] = 0 ;
			}        
			else
				A[i] = A[i] + 1;

			continue;

		}
		if( A[i] &&   ( ( A[i] + carry_bit) % 10 == 0 )    )
		{    A[i] = 0;
			carry_bit = 1;
		}

		else
		{
			A[i] = A[i]+carry_bit;
			break;

		}          
	}

	return A;

}
