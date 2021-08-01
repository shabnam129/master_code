#include <iostream>
#include <cstdlib>
struct node 
{
  int data;
  struct node *left;
  struct node *right;

};


struct node * new_node(int data)
{

  struct node *node = (struct node *) malloc(sizeof(struct node) );
  node->data = data;
  node->left = NULL;
  node->right =NULL;

  return node;

}


struct node * insert ( struct node * , int );
void inorder(struct node * );
int sum_till_kth_elem(struct node *  , int & ,int , int & );


int main()
{

  int i = 0;
  //struct node * root = NULL;
  int data = 0;

    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 75);
    insert(root, 90);
    insert(root, 85);
    insert(root, 100);
   
  
    // print inoder traversal of the BST
    inorder(root);

     int count = 0;
     int key = 10;
     int sum = 0;

     std::cout << "\n addres of sum===" << (int *) &sum;
     std::cout << "\n BACK TO MAIN AND found sum ===  " << sum_till_kth_elem(root, count,key , sum );// << " and value of summ===" <<sum;
    
     std::cout << "\n sum=====" << sum;

 
}


struct node * insert ( struct node *node  , int data)
{
  static struct node * root  = node ;
  
  if(root ==NULL)
  {
   root= new_node( data);
   node = root;
  return root ;

  }

  if(node ==NULL)
  return new_node(data)  ;

  

  if( data > (node)->data)
  {
    
    (node)->right = insert( (node)->right , data);

  }

  if( data <  (node)->data)
  {
   (node)->left = insert(  (node)->left , data);

  } 
   
  
  return node;
}
  
 





void inorder(struct node * node)
{

  if(node ==NULL) //DOnt put node->next= Null bcaouse when its reaches to 5 then since its deosnt have any child sto its revert back to node(node->rihgt) and it will not get printted

   return ;

   inorder(node->left);
   std::cout << " " << node->data;
   inorder(node->right);

}
 



int sum_till_kth_elem(struct node *  node , int &count ,int key, int &sum )
{

  if(node ==NULL)
   {
   /* if(count!=key)
     return count;
    else
     return 1;*/
    return count;
  

   }

/* int found   = 0;
   found =  sum_till_kth_elem (node->left , count , key , sum);
  */
 count    =   sum_till_kth_elem (node->left , count , key , sum);
 //std::cout <<" \n found === " << count << "curr node data ===" << node->data << " and summ ====" << sum  << "and aress of  summ==" << (int * ) &sum;
 
// std::cout << "\n";

   if(count < key)
    {
      sum = sum + node->data;
      count++;

     sum_till_kth_elem( node->right , count , key , sum ) ; 
     return count ;

    }


     if(count ==key)
     {

     std::cout <<" \n  Yipees key found and sum  ====" <<sum;
    /* std::cout <<" \n HELLOO COunt found found === " << found << "curr node data ===" << node->data << " and summ ====" << sum;
      sum = sum +  node->data;
      found = 1;*/
      return count ;

     }


}
