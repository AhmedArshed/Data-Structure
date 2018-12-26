#include<iostream>
using namespace std;

struct node
{
	int info;
	node *left , *right;
};
// insertion in tree in the form of zigzag
class zigzag
{
private:
	node *temp , *ptr , *temp1;
public:
	node *root;
	int number;
	int key;
	bool flage;
	int swap;
	int count;
	zigzag()
	{
		root = temp = ptr = temp1 = NULL;
		count = 0;
		flage = false;
	}
	~zigzag()
	{
		delete root;
		delete temp;
	}
	void insert()
	{
		if(root == NULL)
		{
			root = new node;
			root->info = number;
			root->left = NULL;
			root->right = NULL;
			temp = root;
			return;
		}
	if(temp->left == NULL && temp->right == NULL)
	{
		if(count % 2 == 0)
		{
			temp->right = new node;
			temp->right->info = number;
			temp->right->left = NULL;
			temp->right->right = NULL;
			temp = temp->right;
			ptr = temp;
			count++;
			return;
		}
		else if(count % 2 != 0){
			temp->left = new node;
			temp->left->info = number;
			temp->left->left = NULL;
			temp->left->right = NULL;
			temp = temp->left;
			temp1 = temp;
			count++;
			return;
		}
	}
}
	void print()
	{
		if(root == NULL)
		{
			cout << "Tree is empty " <<endl;
			return;
		}
		temp = root;
		if(ptr->left == NULL && ptr->right == NULL)
		{
				while(temp != ptr){
					if(temp->left != NULL || temp->right != NULL){
						cout << temp->info <<" ";
					if(temp->left != NULL)
					{
						temp = temp->left;
					}
					else if(temp->right != NULL)
					{
						temp = temp->right;
					}
				}
			}
			cout << ptr->info;
			cout << endl;
		}
		if(temp1->left == NULL && temp1->right == NULL){
				while(temp != temp1){
					if(temp->left != NULL || temp->right != NULL){
				cout << temp->info <<" ";
				if(temp->left != NULL)
				{
					temp = temp->left;
				}
				else if(temp->right != NULL)
				{
					temp = temp->right;
				}
			}
		}
	}
	cout << temp1->info;
	cout << endl;
}
	void print1(node *temp){	
		if(root == NULL){
			cout << "Tree is empty"<<endl;
			return;
		}
		if(temp->left != NULL)
			print1(temp->left);
		cout << temp->info <<" ";
		if(temp->right != NULL)
			print1(temp->right);
	}
};

int main()
{
	zigzag z;
	for (int i = 0; i < 5; ++i)
	{
		cout << "Enter values "<<endl;
		cin >> z.number;
	z.insert();
	}
	z.print();
	z.print1(z.root);
}
