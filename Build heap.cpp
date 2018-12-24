#include<iostream>
#include<cmath>
using namespace std;

struct node{
	int info;
	node *left , *right;
	int index;
};
class cbt
{
private:
	node *temp , *temp1 , *ptr , *current;
	bool flage;
	int height , h , nodes , count;
	int number;
	int check_index;
	int swap;
public:
	node *root;
	int value;
	cbt()
	{
		root = temp = temp1 = ptr = current = NULL;
		height = h = check_index = nodes = count = 0;
		number = 1;
	}
	~cbt(){
		delete root;
		delete temp;
	}
	void set(node *temp)
	{
		if(temp->left != NULL && h < height)
		{
			h++;
			set(temp->left);
			h--;
		}
		if(temp->right != NULL && h < height)
		{
			h++;
			set(temp->right);
			h--;
		}
		if((temp->left == NULL && h == height-1)||(temp->right == NULL && h == height-1))
		{
			if(flage == false)
			{
				ptr = temp;
				flage = true;
				return;
			}
		}
	}
	void insert(node *temp)
	{
		flage = false;
		if(root == NULL)
		{
			root = new node;
			root->info = value;
			root->index = number;
			root->left = NULL;
			root->right = NULL;
			temp = root;
			nodes++;
			count++;
			return;
		}
		if(count == nodes)   //if height is at it's max
		{
			count = 0;
			nodes = pow(2,height+1);
			height++;
			cout << "Nodes are :" <<nodes <<endl;
				cout << "height is :" << height <<endl;
			while(temp->left != NULL)
				temp = temp->left;
			temp->left = new node;
			temp->left->info = value;
			temp->left->index = ++number;
			
			temp->left->left = NULL;
			temp->left->right = NULL;
			count++;
			return;
		}
		if(count != nodes)
		{
			set(temp);
			if(ptr->left == NULL && ptr->right == NULL)
			{
				ptr->left = new node;
				ptr->left->info = value;
				ptr->left->index = ++number;
				ptr->left->left = NULL;
				ptr->left->right = NULL;
				count++;
				return;
			}
			if(ptr->left != NULL && ptr->right == NULL)
			{
				ptr->right = new node;
				ptr->right->info = value;
				ptr->right->index = ++number;
				ptr->right->left = NULL;
				ptr->right->right = NULL;
				count++;
				return;
			}
		}
	}
	void print(node *temp)
	{
		if(root == NULL)
		{
			cout << "Tree is empty"<<endl;
			return;
		}
		if(temp->left != NULL)
		{
			print(temp->left);
		}
		cout << temp->info <<" ";
		if(temp->right != NULL)
			print(temp->right);
	}
	void build_heap(node *temp)
	{
//		cout << "kia" <<endl;
		if(root->left == NULL || root == NULL)
			return;
		check_index = number/2;
		while(check_index != 0){
				buildSet(root);
				if(ptr->right == NULL){
					if(ptr->info > ptr->left->info){
						swap = ptr->info;
						ptr->info = ptr->left->info;
						ptr->left->info = swap;
						temp = ptr->left;
					}
					
				}
					if(ptr->left->info < ptr->right->info && ptr->info > ptr->left->info){
						swap = ptr->info;
						ptr->info = ptr->left->info;
						ptr->left->info = swap;
						temp = ptr->left;
					}
					if(ptr->left->info > ptr->right->info && ptr->info > ptr->right->info){
						swap = ptr->info;
						ptr->info = ptr->right->info;
						ptr->right->info = swap;
						temp = ptr->right;
					}
				while((temp->left != NULL && temp->info > temp->left->info) || (temp->right != NULL && temp->info > temp->right->info)){
					if(temp->right == NULL){
						if(temp->left->info < temp->right->info && temp->info > temp->left->info){
							swap = temp->info;
							temp->info = temp->left->info;
							temp->left->info = swap;
							temp = temp->left;
						}
					}
					if(temp->left->info < temp->right->info && temp->info > temp->left->info){
						swap = temp->info;
						temp->info = temp->left->info;
						temp->left->info = swap;
						temp = temp->left;
					}
					else if(temp->left->info > temp->right->info && temp->info > temp->right->info){
						swap = temp->info;
						temp->info = temp->right->info;
						temp->right->info = swap;
						temp = temp->right;	
					}
				}
			check_index--;
		}
	}
	void buildSet(node *temp)
	{
		if(temp->left != NULL)
			buildSet(temp->left);
		if(temp->index == check_index)
			ptr = temp;
		if(temp->right != NULL)
			buildSet(temp->right);
	}
	
	void delet(node *temp)
	{
		DelSet(temp);
		if(root->left == NULL)
		{
			delete root;
			root = NULL;
			return;
		}
		while(temp->left != NULL)
			temp = temp->left;
		temp1 = temp;
		if(ptr->right != NULL)
		{
			delete ptr->right;
			ptr->right = NULL;
			return;
		}
		if(ptr->left != NULL)
		{
			if(ptr->left == temp1)
				{
					delete temp1;
					temp1 = NULL;
					height--;
				}
			delete ptr->left;
			ptr ->left = NULL;
			return;
		}
	}
	void DelSet(node *temp)
	{
		if(temp->left != NULL && h < height){
			h++;
			DelSet(temp->left);
			h--;
		}
		if(temp->right != NULL && h < height)
		{
			h++;
			DelSet(temp->right);
			h--;
		}
		if(temp->left != NULL && h == height-1)
			ptr = temp;
	}
};

int main()
{
	cbt c;
	int array[15] = {65,31,32,26,21,19,68,13,24,15,14,16,5,70,12};
	for(int i = 0 ; i < 15 ;i++){
	// cout << "Enter values" <<endl;
	c.value = array[i];
	c.insert(c.root);
	}
	c.print(c.root);
	cout << endl;
//		c.delet(c.root);
//		c.delet(c.root);
		cout << endl;
		c.build_heap(c.root);
	c.print(c.root);
	cout << endl;

}

