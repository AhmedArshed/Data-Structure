#include<iostream>
#include<cmath>
using namespace std;

struct node{
	int info;
	node *left , *right;
};
class cbt
{
private:
	node *temp , *temp1 , *ptr , *current;
	bool flage;
	int height , h , nodes , count;
public:
	node *root;
	int value;
	cbt()
	{
		root = temp = temp1 = ptr = current = NULL;
		height = h = nodes = count = 0;
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
				ptr->left->left = NULL;
				ptr->left->right = NULL;
				count++;
				return;
			}
			if(ptr->left != NULL && ptr->right == NULL)
			{
				ptr->right = new node;
				ptr->right->info = value;
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
	void delet(node *temp)
	{
		if(root->left == NULL)
		{
			delete root;
			root = NULL;
			return;
		}
		DelSet(temp);
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
	for(int i = 0 ; i < 9 ;i++){
	cout << "Enter values" <<endl;
	cin >> c.value;
	c.insert(c.root);
	}
	c.print(c.root);
		c.delet(c.root);
		cout << endl;
	c.print(c.root);

}
