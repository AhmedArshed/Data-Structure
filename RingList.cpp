#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class ring{
	private:
		node *temp , *head ,*ptr;
		int key;
	public:
		ring()
		{
			temp = head = ptr = NULL;
			key = 0;
		}
		~ring()
		{
			delete temp;
			delete head;
		}
	void start()
	{
		if (head == NULL)
		{
			head = new node;
			cout << "Enter value to head "<<endl;
			cin >> head -> info;
			head -> next = head;
			return;
		}
		if (head -> next == head)
		{
		temp = new node;
		cout << "Enter info for node" << endl;
		cin >> temp -> info;
		head -> next = temp;
		temp -> next = head;
		return;
		}
		ptr = temp;
		temp = new node;
		cout << "Enter info" << endl;
		cin >> temp -> info;
		ptr -> next = temp;
		temp -> next = head;
	}
void insert(){
			temp = head;
			cout << "Enter value After witch the num is be added" << endl;
			int key;
			cin >> key;
			do{
				if(temp->info == key){
					ptr = temp;
					temp = new node;
					cout << "Enter value" <<endl;
					cin >> temp->info;
					temp->next = ptr->next;
					ptr->next = temp;
					
				}
				temp = temp->next;
			}while(temp != head);
		}
		
	void print()
	{
		temp = head -> next;
		while(temp !=head)
		{
			cout << temp -> info <<" ";
			temp = temp -> next;
		}
		cout << temp -> info <<endl;
	}
	void delet()
	{
		if (head == NULL)
			return;
		cout << "Enter values to remove " <<endl;
		cin >> key;
		temp = head;
			if(head == NULL){
				cout << "No value in Link list" << endl;
			}
			else{
				do{
					if(key == temp->next->info && temp->next->info == head->info){
						ptr = head;
						head = head->next;
						temp->next = head;
						delete ptr;
						ptr = NULL;
					}
					else if(temp->next->info == key){
						ptr = temp->next;
						temp->next = ptr->next;
						delete ptr;
						ptr = NULL;
					}
					temp = temp->next;
				}
				while(temp != head);
			}
		}
};

int main()
{
	ring r;
	r.start();
	r.start();
	r.start();
	r.start();
	r.print();
	r.insert();
	r.print();
	r.delet();
	r.print();
}
