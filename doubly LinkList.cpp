#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
	node * pre;
};

class doubly{
	private:
		node *temp , *ptr , *head;
		int key;
	public:
		doubly()
		{
			temp = ptr = head = NULL;
		}
		void start()
		{
			temp = head;
			if (head == NULL)
			{
				head = new node;
				cout << "Enter value to insert" << endl;
				cin >> head -> info;
				head -> next = NULL;
				head -> pre = NULL;
				return;
			}
			while (temp -> next != NULL)
				temp = temp -> next;
			
			ptr = temp;
			temp = new node;
			cout << "Enter value " <<endl;
			cin >> temp -> info;
			ptr -> next = temp;
			temp -> pre = ptr;
			temp -> next = NULL;
	}
	void insert()
	{
		temp = head;
		if (head == NULL)
		{
			head = new node;
			cout << "Enter info about head "<<endl;
			cin >> head -> info;
			head -> next = NULL;
			head -> pre =NULL;
			return;
		}
		cout <<"Enter key to add "<<endl;
		cin >> key;
		while (temp != NULL)
		{
			if (temp -> info == key)
			{
				ptr = temp;
				temp = new node;
				cout << "Enter value to add "<<endl;
				cin >> temp -> info;
				temp -> next = ptr -> next;
				ptr -> next = temp;
				ptr -> next ->pre = temp;
				temp -> pre = ptr;
				return;
			}
			temp = temp -> next;
		}
	}
	
	void delet()
	{
		cout << "Enter value to delete "<<endl;
		cin >> key;
		temp = head;
		if (temp == NULL)
		{
			cout << "Link list is empty "<<endl;
			return;
		}
		else if (head -> info == key)
		{
			head = head -> next;
			head -> pre = NULL;
			delete temp;
			temp = NULL;
			return;
		}
		while (temp ->next != NULL)
		{
			if (temp -> info == key)
			{
				ptr = temp;
				temp = temp -> next;
				ptr -> pre -> next = temp;
				ptr -> next -> pre = ptr -> pre;
				delete ptr;
				ptr = NULL;
				return;
			}
			temp = temp -> next;
		}
		if (temp -> info == key)
		{
			temp -> pre -> next = temp -> next;
			delete temp;
			temp = NULL;
			return;
		}
		
	}
	void print()
	{
		temp = head;
		while(temp != NULL)
		{
			cout << temp -> info <<" ";
			temp = temp -> next;
		}
		cout << endl;
	}
	
};



int main()
{
	doubly d;
	for(int i = 0 ; i< 5 ; i++)
		d.start();
	d.print();
	d.insert();
	d.print();
	d.delet();
	d.print();
}
