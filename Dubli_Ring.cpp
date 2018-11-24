#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
	node *previous;
};

class dub_ring{
	private:
		node *head , *temp , *ptr;
		int key;
	public:
		dub_ring()
		{
			head = temp = ptr = NULL;
			key = 0;
		}
		~dub_ring()
		{
			delete temp;
			delete head;
			delete ptr;
		}
		void start()
		{
			if (head == NULL)
			{
				head = new node;
				cout << "Enter info for head "<<endl;
				cin >> head -> info;
				head -> next = head;
				head -> previous = head;
				return;
			}
			if (head->next == head)
			{
				temp = new node;
				cout << "Enter value "<<endl;
				cin >> temp -> info;
				temp -> next = head;
				head -> next = temp;
				head -> previous = temp;
				temp -> previous = head;
				return;
			}
			temp = ptr;
			ptr = new node;
			cout << "Enter value "<<endl;
			cin >> ptr->info;
			temp -> next = ptr;
			ptr -> next = head;
			ptr -> previous = temp;
			head -> previous = ptr;
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
};
int main()
{
	dub_ring r;
	r.start();
	r.start();
	r.start();
	r.print();
}
