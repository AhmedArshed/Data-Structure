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
	void insert()
	{
		cout << "Enter value where to add "<<endl;
		cin >> key;
		temp = head;
		if (temp -> info == key)
		{
			ptr = temp;
			temp = new node;
			cout << "Enter value "<<endl;
			cin >> temp -> info;
			head = temp;
		}
		temp = head -> next;
		while (temp != head)
		{
			if (temp -> info == key)
			{
				ptr = temp;
				temp = new node;
				cout << "Enter value "<<endl;
				cin >> temp -> info;
				temp -> next = ptr -> next;
				ptr -> next = temp;
				return;
			}
			temp = temp -> next;
		}
		if (temp -> info == key)
		{
//			ptr = temp;
			ptr = new node;
			ptr -> next = head;
			temp -> next = ptr;
//			ptr = temp;
			return;
		}
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
		if (head -> info == key)
		{
			head = head -> next;
			delete temp;
			temp = NULL;
			return;
		}
		temp = head -> next;
		while (temp != head)
		{
			if (temp -> next -> info == key)
			{
				ptr = temp -> next;
				temp -> next = ptr -> next;
				delete ptr;
				ptr = NULL;
			}
			temp = temp -> next;
		}
		if (temp ->next -> info == key)
		{
			ptr = temp -> next;
			temp -> next = head;
			delete ptr;
			ptr = NULL;
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
