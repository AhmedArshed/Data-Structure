#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class link{
private:
	node *head;
	node *temp;
	node *ptr ;
	node *temp1;
	int number , swap , key;
	int nodes;
public:

	link()
	{
		head = NULL;
		temp = NULL;
		ptr = NULL;
		temp1 = NULL;
		number = 0;
		swap = 0;
		nodes = 0;
	}
	~link()
	{
		delete head;
		delete temp;
	}

	void insert_left()
	{
		if(head == NULL)
		{
			head = new node;
			cout << "insert value for head :";
			cin >> head -> info;
			head -> next = NULL;
		return;
		}
		temp = head;
		temp = new node;
		cout << "Insert value :";
		cin >> temp ->info;
		temp -> next = head;
		head = temp;
}

	void insert_right()
	{
		temp = head;
	if(head == NULL)
		{
			head = new node;
			cout << "insert value for head :";
			cin >> head -> info;
			head -> next = NULL;
			nodes++;
			return;
		}
		while(temp -> next != NULL)
		{
			temp = temp->next;
		}
		ptr = temp;
		temp = new node;
		cout << "Enter value "<<endl;
		cin >> temp -> info;
		ptr -> next = temp;
		temp -> next = NULL;
		nodes++;
	}




void inserts()
{
	int key;
	if(head == NULL)
		{
			head = new node;
			cout << "insert value for head :";
			cin >> head -> info;
			head -> next == NULL;
			nodes++;
			return ;
		}
		cout << "Enter adderes to add value " <<endl;
		cin >> key;
		temp = head;
		while(temp != NULL)
		{
			if(temp -> info == key)
			{
				ptr = temp -> next;
				temp = temp -> next;
				temp = new node;
				cout << "Enter value to add" << endl;
				cin >> temp -> info;
				temp -> next = ptr;
				nodes++;
				return;
			}
			temp = temp -> next;
		}
}

void delet()
{
	int key1;
	temp = head;
	cout << "Enter key to delete " << endl;
	cin >> key1;
	if(temp == NULL)
		return;
	else if(head->info == key1)
	{
		head = head -> next;
		delete temp;
		return;
	}
	temp = head;
	while(temp != NULL)
	{
		if(temp -> next ->info == key1)
		{
			temp1 = temp -> next;
			temp -> next = temp -> next -> next;
			delete temp1;
			temp1 = NULL;
//			return;
		}
		temp = temp -> next;
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

void insert_mid()
	{
		temp = head;
		cout << "Enter key where to insert new node" << endl;
		cin >> key;
		if(head->info == key)
		{
			temp = new node;
			cout << "Enter value for new root" <<endl;
			cin >> temp->info;
			temp->next = head->next;
			head->next = temp;
			return;
			
		}
		while(temp->next->info != key)
			temp = temp->next;
		if(temp->next->info == key)
		{
			ptr = temp->next;
			temp = new node;
			cout << "Enter value "<<endl;
			cin >> temp->info;
			temp->next = ptr->next;
			ptr -> next = temp;

		}
		else
		{
			cout << "Key is not there" <<endl;
			return;
		}
}

void selection()
	{
		temp = head;
		if(temp == NULL)
		{
			cout << "List is empty"<<endl;
			return;
		}
		if(temp->next == NULL)
		{
			cout << "List is already in sorted form "<<endl;
			return;
		}
		while(temp != NULL)
		{
			ptr = temp->next;
			while(ptr != NULL)
			{
				if(temp->info > ptr->info)
				{
					swap = temp->info;
					temp->info = ptr->info;
					ptr->info = swap;
				}
				ptr = ptr->next;
			}
			temp = temp->next;
		}
	}
	void bubble()
	{
		temp = head;
		if(temp == NULL)
		{
			cout << "List is empty" <<endl;
			return;
		}
		if(temp->next == NULL)
		{
			cout << "List is already in sorted form" << endl;
			return;
		}
		for(int i = 0 ; i < nodes ;i++)
		{
			temp = head;
		while(temp ->next != NULL){
			if(temp->info > temp->next->info)
			{
				swap = temp->info;
				temp->info = temp->next->info;
				temp->next->info = swap;
			}
			temp = temp->next;
		}
	}
}
	void merge(node *temp)
	{
		if(nodes/2 != 0)
			nodes = nodes/2;
	}
};


int main()
{
	link l;
	for(int i = 0 ; i < 5 ; i++){
	l.insert_right();
	}
	l.print();
	l.insert_mid();
	l.print();
	// l.selection();
	l.bubble();
//	l.delet();
//	l.print();
//	l.search();
//	l.swap1();
//	l.delete_swap();
	l.print();
}


	
