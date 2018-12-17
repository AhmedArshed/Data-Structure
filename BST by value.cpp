#include <iostream>
using namespace std;
struct node{
int info;
node *left , *right;
};
class bst
	{
	private:
		node *temp ,*ptr ,*temp1 , *temp2,*current;
	public:
		node *root;
		int key;
		int number;
		int swap;
		int find;
		int left_count;
		int right_count;
		int flage;
		bst()
		{
			temp1 = temp = ptr = root = NULL;
			key = 0;
			find = 0;
		}
		~bst(){
			delete root;
			delete temp;
		}
		void insert(node *temp)
		{
			if(root == NULL)
			{
				temp = new node;
				temp->info = number;
				temp->right = NULL;
				temp->left = NULL;
				root = temp;
				return;
			}
			if(temp->info == number){
				cout << "number already in BST "<<endl;
				return;
			}
			if(temp->info < number)
			{
				if(temp->right == NULL)
				{
					temp->right = new node;
					temp->right->info = number;
					temp1 = temp->right;
					temp1->right = NULL;
					temp1->left = NULL;
					return;
				}
				else{
					insert(temp->right);
				}
			}
			if(temp->info > number)
			{
				if(temp->left == NULL)
				{
					temp->left = new node;
					temp->left->info = number;
					temp1 = temp->left;
					temp1->right = NULL;
					temp1->left = NULL;
					return;
				}
				else{
					insert(temp->left);
					return;
				}
			}
		}
		
	void delet(node *temp)
	{
		if(temp == NULL)
		{
			cout << "Tree is empty"<<endl;
			return;
		}
		if(root->info == key){ //when root is key
			temp = root;
				 if(temp->right == NULL && temp->left == NULL)
				 {
				 	delete temp->right;
				 	temp->right = NULL;
				 	return;
				 }
				 if(temp->right == NULL && temp->left != NULL)
				 {
				 	temp1 = temp->right;
				 	temp = temp1->left;
				 	delete temp1;
				 	temp1= NULL;
				 	return;
				 }
				 if(temp->right != NULL && temp->left == NULL)
				 {
				 	temp1 = temp->left;
				 	temp= temp1->right;
				 	delete temp1;
				 	temp1 = NULL;
				  	return;
				 }
				 if(temp->right != NULL && temp->left != NULL){
				 	temp1 = temp->right;
				 	current = temp1;
				 	if(temp1->left != NULL)
				 	{
				 		current = temp1->left;
						while (current->left!= NULL){
						    temp1 = temp1->left;
						    current = temp1->left;
						}
				 	}
						cout <<"Current  "<< current->info <<endl;
				 	if(current->right == NULL) 			// find immediate successor having no child
				 	{
				 	cout <<"aya"<<endl;
					swap = current->info;
			 		current->info = temp->info;
			 		temp->info = swap;
			 		temp1->left = NULL;
//				 	temp2->right = NULL;
				 	delete current;
					current = NULL;
			 		return;
			 		}
			 		if(current->right != NULL){ 	// find immediate successor having right child
				 		swap = current->info;
				 		current->info = temp->info;
				 		temp->info = swap;
						temp1->left = current ->right;
			 			delete current;
			 			current= NULL;
			 			return;
					 }
			 	}
			 }
		if(temp->info < key)
		{
			if(temp->right->info == key)
			{
				// Case#1
				 if(temp->right->right == NULL && temp->right->left == NULL)
				 {
				 	delete temp->right;
				 	temp->right = NULL;
				 	return;
				 }
				 // case#2
				 if(temp->right->right == NULL && temp->right->left != NULL)
				 {
				 	temp1 = temp->right;
				 	temp->right = temp1->left;
				 	delete temp1;
				 	temp1= NULL;
				 	return;
				 }
				 if(temp->right->right != NULL && temp->right->left == NULL)
				 {
				 	temp1 = temp->left;
				 	temp->left = temp1->right;
				 	delete temp1;
				 	temp1 = NULL;
				  	return;
				 }

				// Case#3
				 if(temp->right->right != NULL && temp->right->left != NULL){
				 	temp1 = temp->right;
				 	temp2 = temp1->right;
				 	current = temp2;
				 	if(temp2->left != NULL)
				 	{
				 		current = temp2->left;
						while (current->left!= NULL){
						    temp2 = temp2->left;
						    current = temp2->left;
						}
				 	}
						cout <<"Current  "<< current->info <<endl;
				 	if(current->right == NULL) 			// find immediate successor having no child
				 	{
					swap = current->info;
			 		current->info = temp1->info;
			 		temp1->info = swap;
			 		temp2->left = NULL;
//				 	temp2->right = NULL;
				 	delete current;
					current = NULL;
			 		return;
			 		}
			 		if(current->right != NULL){ 	// find immediate successor having right child
				 		cout <<"aya"<<endl;
				 		swap = current->info;
				 		current->info = temp1->info;
				 		temp1->info = swap;
						temp2->left = current ->right;
			 			delete current;
			 			current= NULL;
			 			return;
					 }
			 	}
			}
		else{     							// if temp -> right ->info != key then perfom this
			delet(temp->right);
			return;
		}
	}
		else if(temp -> info > key)
		{
			if(temp->left->info == key)
			{
				//Case#1
				 if(temp->left->right == NULL && temp->left->left == NULL)
				 {
				 	delete temp->left;
				 	temp->left = NULL;
				 	return;
				 }
				// Case#2
				  if(temp->left->left == NULL && temp->left->right != NULL)
				 {
				 	temp1 = temp->left;
				 	temp->left = temp1->right;
				 	delete temp1;
				 	temp1 = NULL;
				 	return;
				 }
				 if(temp->left->left != NULL && temp->left->right == NULL)
				 {
				 	temp1 = temp->left;
				 	temp->left = temp1->left;
				 	delete temp1;
				 	temp1 = NULL;
				  	return;
				 }

				// Case#3
				if(temp->left->left != NULL && temp->left->right != NULL){
					temp1 = temp->left;
				 	temp2 = temp1->right;
				 	 current = temp2;
				 	if(temp2->left != NULL)
				 	{
				 		current = temp2->left;
						while (current->left !=NULL){  // finding immediate predecessor
						    temp2 = temp2->left;
						    current = temp2->left;
						}
				 	}
				 	
					cout <<"Current  "<< current->info <<endl;
				 	if(current->right == NULL) 			// find immediate successor having no child
				 	{
				 		cout << "ok" << endl;
						swap = current->info;
				 		current->info = temp1->info;
				 		temp1->info = swap;
				 	//	temp1->right = NULL;
						delete temp2->left;
						temp2->left = NULL;
				 		return;
			 		}
			 		if(current->right != NULL){ 	// find immediate successor having right child
				 		cout <<"aya"<<endl;
				 		swap = current->info;
				 		current->info = temp1->info;
				 		temp1->info = swap;
						temp2->left = current ->right;
			 			delete current;
			 			current= NULL;
			 			return;
					 }
			 	}
			}
			else{
				delet(temp->left);
				 return;
			}
		}
	}
		void print(node *temp)
		{
			if(temp == NULL)
			{
				cout << "BST is empty"<<endl;
				return;
			}
			if(temp->left != NULL)
				print(temp->left);
			cout << temp->info <<" ";
			if(temp->right != NULL)
				print(temp->right);
				return;
		}
		void leaf(node *temp)
		{
			if(root == NULL){
				return;
			}
			if(temp->left == NULL && temp->right == NULL){
				cout << temp->info <<" ";
	//			return;
			}
			if(temp->left != NULL)
				leaf(temp->left);
			if(temp->right != NULL)
				leaf(temp->right);
		}

	void search(node *temp){
		if(key == temp->info){
			find = 1;
			return;
		}
		if(key > temp->info){
			if(temp->right != NULL)
				search(temp->right);
			return;
		}
		if(key < temp->info){
			if(temp->left != NULL)
				search(temp->left);
			return;
		}
	}
	void count_left(node *temp){  // Fuction to check wather BST is strictly bineary tree
		if(root->left != NULL){
			if(temp->left != NULL){
				left_count++;
				count_left(temp->left);
				}
			if(temp->right != NULL){
				right_count++;
				count_left(temp->right);
			}
			if(left_count == right_count){
				flage = 0;
			}
			if(left_count != right_count){
				flage = 1;
				return;
			}
		}
	}
	void count_right(node *temp){
		if(root->right){
			if(temp->left != NULL){
				left_count++;
				count_left(temp->left);
				}
			if(temp->right != NULL){
				right_count++;
				count_left(temp->right);
			}
			if(left_count == right_count){
				flage = 0;
			}
			if(left_count != right_count){
				flage = 1;
				return;
			}
		}
	}
	
//	Function to check wather left and right subtree have same number of child or not

};                               
int main()
{
	bst b;
	int array[10] = {35,40,39,30,20,50,45,32,6,4};
//    int array[8] = {10,9,15,16,12,13,11,8};
	for (int i = 0; i < 10; i++)
	{
//		cout << "Enter value to insert "<<endl;
		b.number = array[i];
		b.insert(b.root);
	}
	b.print(b.root);
	cout <<endl;
//	for(int i = 0 ; i < 10 ; i++)
//	{
	cout << "Enter number to delete"<<endl;
	cin >> b.key;
	b.delet(b.root);
	b.print(b.root);
//	}
	cout <<endl;
	cout << "Leaves of tree are"<<endl;
	b.leaf(b.root);
	cout <<endl;
	cout << "Enter key to search in BST" <<endl;
	cin >> b.key;
	b.search(b.root);
	if(b.find == 0)
	{
		cout << "Key does not exist in BST"<<endl;
	}
	else{
		cout << "Key found in BST" << endl;
	}
	b.count_left(b.root->left);
	b.count_right(b.root->right);
	cout << b.flage <<endl;
	if(b.flage == 0)
	{
		cout << "Both side have same hight "<<endl;
		return 0;
	}
	else if(b.flage == 1)
	{
		cout << "Both side doesnot have same side "<<endl;
		return 0;
	}
}	
