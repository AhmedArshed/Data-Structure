#include<iostream>
using namespace std;

struct node{
	int info;
	node *next;
};

class stack{
	private:
		node *top , *temp;
		int count , size;
	public:
		stack()
		{
			top = temp = NULL;
			size = 0;
			cout << "Enter size "<<endl;
			cin >> size;
		}
		void push()
		{
			if (size == count)
				return;
			if(top == NULL)
			{
				top = new node;
				cout << "Enter value to add in stack "<<endl;
				cin >> top -> info;
				top -> next = NULL;
				count++;
			}
			else{
			temp = top;
			top = new node;
			cout << "Enter value to add" <<endl;
			cin >> top -> info;
			top -> next = temp;
			temp = top;
			count++;
			return;
			}
		}
	void pop()
	{
		temp = top;
		if (count == 0)
		{
			cout << "Under flow" << endl;
			return;
		}
		else if (top != NULL)
		{
			temp = top;
			top = top->next;
			delete temp;
			temp = NULL;
			count--;
			return;
		}
	}
	
	void print()
	{
		temp = top;
		while (temp != NULL)
		{
			cout << temp -> info;
			temp = temp -> next;
		}
		cout << endl;
	}
};
int main()
{
stack s;
s.push();
s.push();
s.push();
s.push();
s.push();
s.print();
s.pop();
//s.pop();
//s.pop();
//s.pop();
s.print();
}
