#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
	node *previous;
};

class dub_ring{
private:
	node *head , *ptr , *temp;
	int key;
public:
	dub_ring()
	{
		head = temp = ptr = NULL;
		key = 0;
	}
	~dub_ring()
	{
		delete head;
		delete temp;
	}
	void insert()
	{
		if(head == NULL)
		{
			cout <<"Enter value "<<endl;
			head = new node;
			cin >> head->info;
			head->next = head;
			head->previous = head;
			return;
		}
		if(head->next == head)
		{
			cout << "Enter value" <<endl;
			temp = new node;
			cin >> temp->info;
			temp->next = head;
			temp->previous = head;
			head->next = temp;
			head->previous = temp;
			return;
		}
		while(temp->next != head)
			temp = temp->next;
		ptr = temp;
		temp = new node;
		cout << "Enter value" <<endl;
		cin >> temp->info;
		temp->next = head;
		temp->previous = ptr;
		ptr->next = temp;
		return;
	}
	void print()
	{
		temp = head;
		cout << temp->info <<" ";
		temp = head->next;
		while(temp != head)
		{
			cout << temp->info << " ";
			temp = temp->next;		
		}
		cout << endl;
	}	
void insert_mid()
	{
		cout << "Enter key to insert value "<<endl;
		cin >> key;
			do{
				if(temp->info == key){
					ptr = temp;
					temp = new node;
					cout << "Enter value "<<endl;
					cin >> temp->info;
					temp->next = ptr->next;
					temp->previous = ptr;
					temp->next->previous = temp;
					ptr->next = temp;
					
				}
				temp = temp->next;
			}
			while(temp != head);
	}
	void delet(){
			cout << "Enter the Delete Number " << endl;
			int key;
			cin >> key;
			temp = head;
			if(head == NULL)
				cout << "No value in Link list" << endl;
			else{
				do{
					if(key == temp->next->info && temp->next->info== head->info){
						ptr = head;
						head = head->next;
						temp->next = head;
						head->previous = temp;
						delete ptr;
						ptr = NULL;
						return;
					}
					else if(temp->next->info == key){
						ptr = temp->next;
						temp->next = ptr->next;
						ptr->next->previous = temp;
						delete ptr;
						ptr = NULL;
						return;
					}
					temp = temp->next;
				}
				while(temp != head);
			}
		}
};

int main()
{
	dub_ring d;
	for(int i = 0 ; i < 9 ; i++)
		d.insert();
	d.print();
	d.insert_mid();
	d.print();
	d.delet();
	d.print();
}
