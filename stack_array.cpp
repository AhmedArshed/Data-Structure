#include<iostream>
using namespace std;

class stack{
	private:
		int *ptr , *temp ,*top, *array;
		int size , count;
	public:
	stack()
	{
		ptr = temp = top = array = NULL;
		count = size = 0;
		cout << "Enter size of array "<< endl;
		cin >> size;
		array = new int [size];
	}
	~stack()
	{
		delete [] array;
	}
	void push()
	{
		if(count == size)
		 {
			cout << "overflow" << endl;
			return;
		}
		if (top == NULL)
		{
			cout << "Enter value" << endl;
			top = array;
			cin >> *top;
			count++;
			return;
		}
		else if(size > count)
		{
		top++;
		cout << "Enter value" << endl;
		cin >> *top;
		count++;
		return;
		}
	}
	void pop()
	{
		if(top == NULL)
		{
			cout << "Stack is empty "<< endl;
			return;
		}
		else if (count = 1)
		{
			top = NULL;
			count --;
			cout << *top << " ";
			return;
		}
		top--;
		count--;
	}
	void print()
	{
		for(int i = 0 ; i < size ; i++)
		{
			cout << array[i] <<" ";
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
	s.print();
	s.pop();
	s.pop();
	s.pop();
	s.print();
	cout << "ok";
		
}
