#include <iostream>
using namespace std;


struct node{
	int info;
	node *right, *left;
};

class bst{
private:
	node *temp1 , *temp;
	bool changeRoot;

public:
	node *root;
	
	bst() {
		root = NULL;
		temp1 = NULL;
		changeRoot = false;
	}


	void traversal(node *temp) {
		if (root == NULL) {
			cout << "the tree is empty" << endl;
			return;
		}

		if(temp->left != NULL) {
			traversal(temp->left);
		}
		
		cout << "Value  : " << temp->info << endl;
		cout << "Balance: " << balance(temp) << endl;

		if(temp->right != NULL) {
			traversal(temp->right);
		}
	}

	int height(node *temp) {
		int lh = 0;
		int rh = 0;
		int h = 0;

		if(temp->left != NULL) {
			lh++;
			lh += height(temp->left);
		}

		if(temp->right != NULL) {
			rh++;
			rh += height(temp->right);
		}

		if (lh > rh) {
			h = lh;
		}
		else if (rh > lh) {
			h = rh;
		}
		else {
			h = rh;
		}

		return h;
	}

	int balance(node *temp) {
		int leftHeight = 0;
		int rightHeight = 0;

		if (temp == NULL) {
			return 0;
		}

		if (temp->left != NULL)
			leftHeight = height(temp->left) + 1;

		if (temp->right != NULL)
			rightHeight = height(temp->right) + 1;

		return leftHeight - rightHeight;
	}

	void insert(node *temp, int val) {
		if (root == NULL) {
			temp1 = new node;
			temp1->info = val;
			temp1->right = NULL;
			temp1->left = NULL;
			root = temp1;
			temp = root;
			temp1 = NULL;
			cout << "Value entered" << endl;
		}
		else if (val > temp->info) {
			if (temp->right == NULL){
				temp1 = new node;
				temp1->info = val;
				temp1->right = NULL;
				temp1->left = NULL;
				temp->right = temp1;
				temp1 = NULL;
				cout << "Value entered" << endl;
			}
			else {
				insert(temp->right, val);
			}
		}
		else if (val < temp->info) {
			if (temp->left == NULL) {
				temp1 = new node;
				temp1->info = val;
				temp1->right = NULL;
				temp1->left = NULL;
				temp->left = temp1;
				temp1 = NULL;
				cout << "Value entered" << endl;
			}
			else {
				insert(temp->left, val);
			}
		}

///////////////////////////////////////////////////AVL
		if (temp == root) {
			if (balance(temp) == 2) {
		 		if (balance(temp->left) == 1){
		 			changeRoot = true;
		 			rightRotation(temp);
			cout << "test out" << endl;
		 			return;
		 		}
		 		else if (balance(temp->left) == -1) {
		 			temp1 = temp->left;
		 			leftRotation(temp);
		 			changeRoot = true;
		 			rightRotation(temp);
		 			return;
		 		}
			}
			else if (balance(temp) == -2) {
				if (balance(temp->right) == -1) {
					changeRoot = true;
					leftRotation(temp);
					return;
				}
				else if (balance(temp->right) == 1) {
					temp1 = temp->right;
					rightRotation(temp);
					changeRoot = true;
					leftRotation(temp);
					return;
				}
			}
		}


		if (balance(temp->left) == 2){
			if (balance(temp->left->left) == 1) {
				temp1 = temp->left;            
				rightRotation(temp);
			}
			else if (balance(temp->left->left) == -1) { // first down rotation then to balance 2 rotation
				temp1 = temp->left->left;
				leftRotation(temp->left);
				temp1 = temp->left;
				rightRotation(temp);
			}
		}
		else if (balance(temp->left) == -2) {
			if (balance(temp->left->right) == 1) {
				temp1 = temp->left->right;
				rightRotation(temp->left);
				temp1 = temp->left;
				leftRotation(temp);
			}
			else if (balance(temp->left->right) == -1) {
				temp1 = temp->left;
				leftRotation(temp);
			}
		}

        // right side balance
		if (balance(temp->right) == 2) {
			if (balance(temp->right->left) == 1) {
				temp1 = temp->right;
				rightRotation(temp);
			}
			if (balance(temp->right->left) == -1) {
				temp1 = temp->right->left;
				leftRotation(temp->right);
				temp1 = temp->right;
				rightRotation(temp);
			}
		}
		else if (balance(temp->right) == -2) {
			if (balance(temp->right->right) == -1) {
				temp1 = temp->right;
				leftRotation(temp);
			}
			if (balance(temp->right->right) == 1) {
				temp1 = temp->right->right;
				rightRotation(temp->right);
				temp1 = temp->right;
				leftRotation(temp);
			}
		}
	}



	void rightRotation(node *temp) {
		if ((temp == root) && (changeRoot == true)) {
			root = temp->left;
			temp->left = root->right;
			root->right = temp;
			changeRoot = false;
			return;
		}

		if (temp1 == temp->left) {
			temp->left = temp1->left;
			temp1->left = temp->left->right;
			temp->left->right = temp1;
		}
		else if (temp1 == temp->right) {
			temp->right = temp1->left;
			temp1->left = temp->right->right;
			temp->right->right = temp1;
		}
		return;
	}
	void leftRotation(node *temp) {
		if ((temp == root) && (changeRoot == true)) {
			root = temp->right;
			temp->right = root->left;
			root->left = temp;
			changeRoot = false;
			return;
		}

		
		if (temp1 == temp->left) {
			temp->left = temp1->right;
			temp1->right = temp->left->left;
			temp->left->left = temp1;
		}
		else if (temp1 == temp->right) {
			temp->right = temp1->right;
			temp1->right = temp->right->left;
			temp->right->left = temp1;
		}

		return;
	}
};


int main() {
	bst tree;
	int val;
//int array[10];
int array[11] = {100,90,98,80,81,82,70,101,102,103,104};
	for(int i = 0; i< 11 ;i++){
//	cout << "Enter the new Value: " << endl;
	val = array[i];
	tree.insert(tree.root, val);
	 tree.traversal(tree.root);
	}
	// cout << "Height: " << tree.height(tree.root) << endl;

	// cout << "Balance of Root->rigth: " << tree.height(tree.root->right->left)-tree.height(tree.root->right->right) << endl;

	// cout << "Enter the Value to delete: ";
	// cin >> val;

	// tree.del(tree.root, val);

	

	// cout << "Enter the Value to delete: ";
	// cin >> val;


	// tree.del(tree.root, val);

	// tree.traversal(tree.root);
}
