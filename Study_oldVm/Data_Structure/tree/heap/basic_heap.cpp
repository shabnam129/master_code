#include <iostream>
#include <vector>
const int size =9;

/*Logic heap
 Insert (check current node with parent):: In case of insert the element is added latest index thats is need to be fil. After  inserting the data chheck if the parent to current node/index is greater or not(to findout parent use formula in program) ..if its then heapfiy/swap and contiue this process until parent is smaller than child.

Delete case(check current node with child)::In case of delete.We need index of the data which needs to deleted.By difault in my progm iam passing the index,otherwise we need to findout the index by linar seach in array(0(n)).replace index data which needs to be deleted with last index data filled in the array.lets suppose array is of 50 size and u have filled till 10 only and need to delte 2nd index.Replace the current index which needs to deleted with last filled index in arr like 10 in our example.Since its mip heap then we know current node must be greater than child, so no need check for parent thats why put flag.So check for child relatedion current node until the current node is greater than left or right child

*/

typedef std::vector<int> vec_def;
void heap_insert(std::vector<int> &, int , int);
void heap_delete(vec_def &a, int ,int);
void disp_arr(vec_def &a);
void heapify(vec_def &, int);
int main()
{
 int i = 0;
 int data;
 vec_def a(size);
 
 
 while(i<size)
  {
    std::cout <<"\n enter the data element=";
    std::cin>> data;
    heap_insert(a,data , i);
    i++; 
  }
  
  disp_arr(a);
  std::cout <<"\n enter the index to be deleted";
 int d_i;
 std::cin >>d_i;
 std::cout <<"\n last index==" <<i;
 heap_delete(a,d_i,i-1);//i will be 
 disp_arr(a);

}
//min heap
void heap_insert(vec_def &a,int data,int i)
{

   a[i]=data; 
   int p_i= (i-1)/2;//parent_index
   if(a[p_i] > a[i])
   
   //heapify which can be done swapping
   { 
     heapify(a,i);
   }
  
   
    
}

void heapify(vec_def &a, int c_i)
{
  int temp = 0;
  int p_i= (c_i-1)/2;//parent_index
     int flag =0;
 
   //Case::Insert (check  current index with parent index)
    //heapify bottom to top
 
    while(a[p_i] > a[c_i])
     {
         temp = a[c_i];
         a[c_i] = a[p_i];
         a[p_i] = temp;
         
         c_i=p_i;
         p_i= (c_i-1)/2;//parent_index
        
   
       flag=1;
     } 

   if(flag==1)
    return ;

   //Case ::Delete ( //Here check current index with left child and right child index)

   //Heapify from top to bottom
   p_i = c_i;//make current node as parent node 
   int c_l_i = (2*p_i)+1;//left child index for current node  
   int c_r_i = (2*p_i)+2; //right child index for current node
    
   if(a[p_i] > a[c_l_i])
    c_i = c_l_i; //if left child is small then make this as the node to be check c_i
   else
   c_i = c_r_i; //if right  child is small then make this as the node to be check
   while(a[p_i] > a[c_i])
     { //swapping
         temp = a[c_i];
         a[c_i] = a[p_i];
         a[p_i] = temp;
   
       //make child index as parent and now check child for this new parent which is used to be child (TOP to BOTTOM hipfy)  
       p_i = c_i;
 
      c_l_i = (2*p_i)+1;//left child index for current node  ...d_i is index to be delete check parent heapfiy and then child index heafpfy
      c_r_i = (2*p_i)+2; //right child index for current node
    
   if(a[p_i] > a[c_l_i])
    c_i = c_l_i;
   else
   c_i = c_r_i; 
 
              
   
     }
 
     
}

void heap_delete(vec_def &a,int d_i , int l_i) //d_i is delete index ,l_i is latest last index in array
{
 std::cout <<"\nwe are in heap delete";
 int c_l_i = (2*d_i)+1;//left child index for current node  ...d_i is index to be delete check parent heapfiy and then child index heafpfy
 int c_r_i = (2*d_i)+2; //right child index for current node
  
 a[d_i] = a[l_i]; 

 int p_i= (d_i-1)/2;//parent_index
   if(a[p_i] > a[d_i])
   //heapify which can be done swapping
   { 
     heapify(a,d_i);
   }
  
   if(a[d_i] > a[c_l_i])
   //heapify which can be done swapping
   { 
   //  while(
     heapify(a,d_i);
     
   }
 
  if(a[d_i] > a[c_r_i])
   //heapify which can be done swapping
   { 
     heapify(a,d_i);
   }
  
  a[l_i] = -1;

  
}

void disp_arr(vec_def &a)      
{   
 int i=0;
  while(i<size)
  {
   std::cout<<" " << a[i];
   i++;
  }

}
