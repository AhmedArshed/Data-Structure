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
	int number , max;
public:

	link()
	{
		head = NULL;
		temp = NULL;
		ptr = NULL;
		temp1 = NULL;
		number = 0;
		max = 0;
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
	}


	void search()
	{
		temp = head;
		cout << "Enter value to search " << endl;
		cin >> number;
		while (temp != NULL)
		{
			if (temp -> info == number)
			{
				cout << "Number "<<number <<" found :";
				return;
			}
		temp = temp -> next;
		}
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

void max1()
{
	temp = head;
	max = temp -> info;
	while(temp != NULL)
	{
		if (temp ->next -> info > max)
		{
			max = temp -> next -> info;
		}
	temp = temp -> next;
	}
}

void delete_max()
{
	temp = head;
	while (temp != NULL)
	{
	if (temp -> next -> info == max)
		{
			cout <<"qwerrrr    " << max << "   ";
			ptr = temp -> next;
			temp -> next = temp -> next -> next;
			delete ptr;
			ptr = NULL;
			return;
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
void fourth_eliment()
	{
		temp = head;
		if(temp->next != NULL)
			if(temp->next->next != NULL)
				if(temp->next->next->next != NULL)
					if(temp->next->next->next->next != NULL)
					ptr = temp->next->next->next->next;
		while(ptr != NULL){
			temp = temp->next;
			ptr = ptr->next;
		}
		cout <<endl<< "Fourth value from end is :";
		cout << temp->info <<endl;
	}
};


int main()
{
	link l;
	for(int i = 0 ; i < 5 ; i++){
	l.insert_right();
	}
//	l.print();
//	l.inserts();
//	l.print();
//	l.delet();
//	l.print();
//	l.search();
	l.max1();
	l.delete_max();
	l.print();
}
