#include <iostream>
using namespace std;


struct node{
	int info;
	node *right, *left;
};

class bst{
private:
	node *temp;

public:
	node *root;
	
	bst() {
		root = NULL;
		temp = NULL;
	}

	void insert(node *temp1, int val) {
		if (root == NULL) {
			temp = new node;
			temp->info = val;
			temp->right = NULL;
			temp->left = NULL;
			root = temp;
			temp = NULL;
			cout << "Value entered" << endl;
			return;
		}

		if (val > temp1->info) {
			if (temp1->right == NULL){
				temp = new node;
				temp->info = val;
				temp->right = NULL;
				temp->left = NULL;
				temp1->right = temp;
				temp = NULL;
				cout << "Value entered" << endl;
				return;
			}
			else {
				insert(temp1->right, val);
				return;
			}
		}
		else if (val < temp1->info) {
			if (temp1->left == NULL) {
				temp = new node;
				temp->info = val;
				temp->right = NULL;
				temp->left = NULL;
				temp1->left = temp;
				temp = NULL;
				cout << "Value entered" << endl;
				return;
			}
			else {
				insert(temp1->left, val);
				return;
			}
		}
	}


	void del(node *temp1, int val) {
		node *temp2;

		if (temp1->info == val) {
			if (temp1->right == NULL && temp1->left == NULL) {
				delete temp1;
				root = NULL;
				temp1 = NULL;
				return;
			}
			else if (temp1->right == NULL && temp1->left != NULL) {
				root = temp1->left;
				delete temp1;
				temp1 = NULL;
				return;
			}
			else if (temp1->right != NULL && temp1->left == NULL) {
				root = temp1->right;
				delete temp1;
				temp1 = NULL;
				return;
			}
			else if (temp1->right != NULL && temp1->left != NULL) {
				temp2 = temp1->right;

				if (temp2->left != NULL) {
					while (temp2->left->left != NULL) {
						temp2 = temp2->left;
					}
					
					root = temp2->left;
					temp2->left = root->right;
					root->left = temp1->left;
					root->right = temp1->right;
					delete temp1;
					temp1 = NULL;
					return;
				}
				else{
					temp2->left = temp1->left;
					delete temp1;
					temp1 = NULL;
					root = temp2;
					return;
				}
			}
		}

		if(val > temp1->info) {
			if (temp1->right->info == val) {
				if (temp1->right->left == NULL && temp1->right->right == NULL) {
					delete temp1->right;
					temp1->right == NULL;
					return;
				}
				if (temp1->right->left != NULL && temp1->right->right == NULL) {
					temp = temp1->right;
					temp1->right = temp1->right->left;
					delete temp;
					temp = NULL;
					return;
				}
				if (temp1->right->left == NULL && temp1->right->right != NULL) {
					temp = temp1->right;
					temp1->right = temp1->right->right;
					delete temp;
					temp = NULL;
					return;
				}
				if (temp1->right->left != NULL && temp1->right->right != NULL) {
					temp = temp1->right->right;

					if (temp->left != NULL) {
						while (temp->left->left != NULL) {
							temp = temp->left;
						}

						temp2 = temp1->right;
						temp1->right = temp->left;
						temp->left = temp1->right->right;
						temp1->right->left = temp2->left;
						temp1->right->right = temp2->right;
						delete temp2;
						temp2 = NULL;
						return;
					}
					else {
						temp = temp1->right;
						temp->right->left = temp->left;
						temp1->right = temp->right;
						delete temp;
						temp = NULL;
						return;
					}
				}
			}
			else {
				del(temp1->right, val);
				return;
			}
		}

		if(val < temp1->info) {
			if(temp1->left->info == val) {
				if (temp1->left->left == NULL && temp1->left->right == NULL) {
					// cout << "test" << endl;
					delete temp1->left;
					temp1->left = NULL;
					// cout << "test1" << endl;
					return;
				}
				if (temp1->left->left != NULL && temp1->left->right == NULL) {
					temp = temp1->left;
					temp1->left = temp1->left->left;
					delete temp;
					temp = NULL;
					return;
				}
				if (temp1->left->left == NULL && temp1->left->right != NULL) {
					temp = temp1->left;
					temp1->left = temp1->left->right;
					delete temp;
					temp = NULL;
					return;
				}
				if (temp1->left->left != NULL && temp1->left->right != NULL) {
					temp = temp1->left;

					if(temp->right != NULL) {
						while (temp->right->right != NULL) {
							temp = temp->right;
						}

						temp2 = temp1->left;
						temp1->left = temp->right;
						temp->right = temp1->left->left;
						temp1->right->left = temp2->left;
						temp1->left->left = temp2->right;
						delete temp2;
						temp2 = NULL;
						return;
					}
					else {
						temp = temp1->left;
						temp->left->right = temp->right;
						temp1->left = temp->left;
						delete temp;
						temp = NULL;
						return;
					}
				}
			}
			else {
				cout << "test" << endl;
				del(temp1->left, val);
				return;
			}
		}
	}

	void traversal(node *temp1) {
		if (root == NULL) {
			cout << "the tree is empty" << endl;
			return;
		}

		if(temp1->left != NULL) {
			traversal(temp1->left);
		}
		
		cout << temp1->info << " ";

		if(temp1->right != NULL) {
			traversal(temp1->right);
		}
	}
};


int main() {
	bst tree;
	int val;

	cout << "Enter the new Value: " << endl;
	cin >> val;

	tree.insert(tree.root, val);

	cout << "Enter the new Value: " << endl;
	cin >> val;

	tree.insert(tree.root, val);
	
	cout << "Enter the new Value: " << endl;
	cin >> val;

	tree.insert(tree.root, val);

	cout << "Enter the new Value: " << endl;
	cin >> val;

	tree.insert(tree.root, val);

	cout << "Enter the new Value: " << endl;
	cin >> val;

	tree.insert(tree.root, val);

	cout << "Enter the new Value: " << endl;
	cin >> val;

	tree.insert(tree.root, val);

	cout << "Enter the new Value: " << endl;
	cin >> val;

	tree.insert(tree.root, val);

	tree.traversal(tree.root);

	cout << "Enter the Value to delete: ";
	cin >> val;

	tree.del(tree.root, val);

	tree.traversal(tree.root);

	cout << "Enter the Value to delete: ";
	cin >> val;


	tree.del(tree.root, val);

	tree.traversal(tree.root);
}