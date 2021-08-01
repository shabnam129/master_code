#include <iostream>


#include<iostream>
#include<stdlib.h>
 
using namespace std;
 
/* A simple stack class with basic stack funtionalities */
class Stack
{
private:
    static const int max = 6;
    int arr[max];
    int top;
   // int min;
public:
    Stack() { top = -1; }
    bool isEmpty();
    bool isFull();
    int pop(Stack &);
    void push(int x,Stack &);
    int getmin(Stack &);
};
 
/* Stack's member method to check if the stack is iempty */
bool Stack::isEmpty()
{
    if(top == -1)
        return true;
    return false;
}
 
/* Stack's member method to check if the stack is full */
bool Stack::isFull()
{
    if(top == max - 1)
        return true;
    return false;
}
 
/* Stack's member method to remove an element from it */
int Stack::pop(Stack &s1)
{
    if(isEmpty())
    {
        cout<<"Stack Underflow";
        abort();
    }
    int x = arr[top];
    top--;
    if(x == s1.arr[s1.top])
    {
       s1.top--;
    }    
  

   return x;   
  
}
 
/* Stack's member method to insert an element to it */
void Stack::push(int x, Stack & s1)
{
    if(isFull())
    {
        cout<<"Stack Overflow";
        abort();
    }
    top++;
    arr[top] = x;
    if(top==0)
    { 
     s1.top++;
     s1.arr[s1.top] = x;
    // s1.min = x;
    }
    else  
    {
     if(x < s1.arr[s1.top])
     {
         s1.top++;
         s1.arr[s1.top] = x;
     }       
    }
}

int Stack::getmin( Stack & s1)
{
 
  return s1.arr[s1.top];
}


/* Driver program to test SpecialStack methods */
int main()
{
    Stack s,s1;
    s.push(18,s1);
   

    s.push(19,s1);
    s.push(29,s1);
  //  cout<<s.getmin(s1)<<endl;
    s.push(15,s1);
    s.push(16,s1);
   // s.push(15,s1);
    cout<<s.getmin(s1);
    s.pop(s1);
    s.pop(s1);
   // s.pop(s1);
  //  s.pop(s1);
    cout<<s.getmin(s1);
    return 0;
}


