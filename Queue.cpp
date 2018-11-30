#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class queue{
	private:
		node *front , *rear , *temp;
		int count , size;
	public:
		queue()
		{
			front = rear = temp = NULL;
			count = 0;
			cout << "Enter size for queue "<<endl;
			cin >> size;
		}
		~queue()
		{
			delete rear;
		}
		void En_queue() // insert
		{
			if (count == size)
			{
				cout <<"Over flow "<<endl;
				return;
			}
			if (rear == NULL)
			{
				rear = new node;
				cout << "Enter info for First person "<<endl;
				cin >> rear -> info;
				rear -> next = NULL;
				front = rear;
				count ++;
				return;
			}
			rear -> next = new node;
			rear = rear -> next;
			cout << "Enter info "<<endl;
			cin >> rear ->info;
			rear -> next = NULL;
			count ++;
			return;
		}
	void dq_queue() //delete from queue
	{
		if (front == NULL && count == 0)
		{
			cout << "Under flow " << endl;
			return;
		}
		temp = front;
		front = front -> next;
		delete temp;
		temp = NULL;
		count --;
		return;
	}
	
	void print()
	{
		temp = front;
		while(temp != NULL)
		{
			cout << temp -> info;
			temp = temp -> next;
		}
		cout << endl;
	}
	
};


int main()
{
	queue q;
	for(int i = 0 ; i< 5 ; i++)
		q.En_queue();
	q.print();
	q.dq_queue();
	q.dq_queue();
	q.print();
}
