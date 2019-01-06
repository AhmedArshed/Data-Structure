#include <iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class link
{
private:
	node *temp , *head , *head2 , *ptr;
	int l_count;
	int m_count;
	int count1;
	int count2;
	int lcount;
	int mcount;
public:
	link()
	{
		temp = head2 = head = ptr = NULL;
		l_count = m_count = 0;
		count1 = count2 = 0;
		lcount = mcount = 0;
	}
	~link()
	{
		delete temp;
		delete head;
		delete ptr;
	}
	void insert()
	{
		cout << "Enter value for first link list" <<endl;
		if(head == NULL)
		{
			head = new node;
			cout << "Enter value" <<endl;
			cin >> head->info;
			head->next = NULL;
			count1++;
			return;
		}
		temp = head;
		temp = new node;
		count1++;
		cout << "Enter value "<<endl;
		cin >> temp->info;
		temp->next = head;
		head = temp;
	}
	void print()
	{
		cout << "Value of 1st link list are" <<endl;
		temp = head;
		while(temp != NULL)
		{
			cout << temp->info << " ";
			temp = temp->next; 
		}
		cout << endl;
	}
	
	void insert2()
	{
		cout << "Enter value for 2nd link list" <<endl;
		if(head2 == NULL)
		{
			cout << "Enter value "<<endl;
			head2 = new node;
			count2++;
			cin >> head2->info;
			head2->next = NULL;
			return;
		}
		temp = new node;
		count2++;
		cout << "ENter value "<<endl;
		cin >> temp->info;
		temp->next = head2;
		head2 = temp;
	}
	void print2()
	{
		cout << "Value to 2nd link list are" <<endl;
		ptr = head2;
		while(ptr != NULL)
		{
			cout << ptr->info << " ";
			ptr = ptr->next;
		}
		cout << endl;
	}
	void less_count()
	{
		ptr = head2;
		while(ptr != NULL)
		{
			temp = head;
			l_count = 0;
			while(temp != NULL)
			{
				
				if(ptr->info < temp->info)
				{
					l_count++;
					if(count1 == l_count)
						lcount++;
				}
			temp = temp->next;
			}
			ptr = ptr->next;
		}
		cout << "less value are "<<lcount <<endl;
	}
void more_count()
	{
		ptr = head2;
		while(ptr != NULL){
			temp = head;
			m_count = 0;
			while(temp != NULL){
				
				if(temp->info < ptr->info){
					m_count++;
					if(m_count == count1)
						mcount++;
				}
				temp = temp->next;
			}
			ptr = ptr->next;
		}
		cout << "more value are "<<mcount <<endl;
	}

};

int main()
{
	link l;
	for (int i = 0; i < 5; i++)
	{
		l.insert();
	}
		for (int i = 0; i < 5; i++)	
		{
			l.insert2();	
		}
		l.print();
		l.print2();	
	l.less_count();
	l.more_count();
}
