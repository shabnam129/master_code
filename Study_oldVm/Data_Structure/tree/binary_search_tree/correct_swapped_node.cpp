#include <iostream>
#include <cstdlib>
#include <stack>
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

int corr_swapped_node(struct node *  );

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node = (struct node *)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

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
	// struct node *root = NULL;
	/* root = insert(root, 50);
	   insert(root, 30);
	   insert(root, 20);
	   insert(root, 40);
	   insert(root, 70);
	   insert(root, 60);
	   insert(root, 80);*/

	struct node *root = newNode(6);
	root->left        = newNode(10);
	root->right       = newNode(2);
	root->left->left  = newNode(1);
	root->left->right = newNode(3);
	root->right->right = newNode(12);
	root->right->left = newNode(7);

	// print inoder traversal of the BST
	inorder(root);
	std::cout <<"\n value of kth element =====" << corr_swapped_node(root );


}


int corr_swapped_node(struct node *root )
{
	/* struct node *root  = new_node(1);
	   root->left             = new_node(2);
	   root->right           = new_node(3);
	   root->left->left     = new_node(4);
	   root->left->right   = new_node(5);

	   root->left->right->left   = new_node(6);*/

	struct node * node = root;

	std::stack<struct node * > stack;

	stack.push(root);

	std::cout << "\n inoreder ===";

	int count  = 0;

	struct node *temp_node = NULL;
	struct node *corr_node = NULL;
	struct node *corr_node_parent = NULL;

	while(!stack.empty()  || node!=NULL )
	{
		// node =stack.top();
		while( node!=NULL )
		{
			if(node!=root) //becasuse root is already added into the stack
			{
				stack.push(node);
			} //push intop stack before moving so that the right element also get added
			node = node->left;
		}
		node = stack.top();

		std::cout << "  " << node->data;
		stack.pop();

		if(stack.empty()) 
			temp_node=NULL;
		else
			temp_node = stack.top();

		if( temp_node !=NULL && node->data > temp_node->data  )
		{

			corr_node = node ;
			corr_node_parent = temp_node;
			std::cout << "\n the corer node data ==" << corr_node->data  <<" Parent data of it will be ====" << corr_node_parent->data;
			break;
		}


		node = node->right;


	}
       
        
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


