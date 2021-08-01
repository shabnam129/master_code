#include <iostream>
#include <cassert>
using namespace std;


//: C04:CLib.h
// Header file for a C-like library
// An array-like entity created at runtime
typedef struct CStashTag {
int size; // Size of each space
int quantity; // Number of storage spaces
int next; // Next empty space
// Dynamically allocated array of bytes:
unsigned char* storage;
} CStash;


void initialize(CStash* s, int size);
void cleanup(CStash* s);
int add(CStash* s, const void* element);
void* fetch(CStash* s, int index);
int count(CStash* s);
void inflate(CStash* s, int increase);



// Quantity of elements to add
// when increasing storage:
const int increment = 100;

void initialize(CStash* s, int sz) {
s->size = sz;
s->quantity = 0;
s->storage = 0;
s->next = 0;
}



int add(CStash* s, const void* element) 
{
if(s->next >= s->quantity) //Enough space left?
inflate(s, increment);
// Copy element into storage,
// starting at next empty space:
int startBytes = s->next * s->size;
unsigned char* e = (unsigned char*)element;
for(int i = 0; i < s->size; i++)
s->storage[startBytes + i] = e[i];
s->next++;
return(s->next - 1); // Index number
}


void* fetch(CStash* s, int index) {
// Check index boundaries:
assert(0 <= index);
if(index >= s->next)
return 0; // To indicate the end
// Produce pointer to desired element:
//return &(s->storage[index * s->size]);
}


int count(CStash* s) {
return s->next; // Elements in CStash
}


void inflate(CStash* s, int increase)
{
assert(increase > 0);
int newQuantity = s->quantity + increase;
int newBytes = newQuantity * s->size;
int oldBytes = s->quantity * s->size;
unsigned char* b = new unsigned char[newBytes];
for(int i = 0; i < oldBytes; i++)
b[i] = s->storage[i]; // Copy old to new
delete [](s->storage); // Old storage
s->storage = b; // Point to new memory
s->quantity = newQuantity;
}




int main()
{


  CStash* a;
  int i =10;

  add(a,&i);


}
