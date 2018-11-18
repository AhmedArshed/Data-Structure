#include<iostream>
using namespace std;

class array{
private:
	int size , add;
	int *set;
	int *ptr;
	int *endptr;
	int *rmv;

public:
	array()
	{
		set = NULL;
		ptr = NULL;
		endptr = NULL;
		rmv = NULL;
		cout << "Enter the size of array "<<endl;
		cin >> size;
		set = new int[size];
		ptr = set;

	}
	~array()
	{
		delete [] set;
	}



	void get()
	{
		set = ptr;
		cout << "Enter value for array " << endl;
		for(int i = 0 ;i < size ; i++)
		{
			cin >> *ptr;
			ptr++;
		}
		ptr = set; 
	}
	void find()
	{
		int q;
		cout << "Enter a Number to found" << endl;
		cin >> q;
		for(int i = 0; i < size ; i++)
		{
			if (*ptr == q)
			{
				cout << "Number is found" << endl;
				break;
			}
			else
				ptr++;
		}
		ptr = set;
	}

	void update()
	{
		int c ,z;
		cout <<"Enter number to be update " << endl;
		cin >> c;
		for (int i = 0; i < size; i++)
		{
			if (*ptr == c)
			{
				cout <<"Number found" << endl << "Plz enter value to upgrade that value" << endl;
				cin >> z;
				*ptr = z;

				break;
			}
			else
				ptr++;
		}
		ptr = set;
		for(int i = 0 ; i < size; i++)
		{
			cout << *ptr;
			ptr++;
		}
		cout << endl;
	// ptr = set;

	}

int length()
{
	ptr = set;
	int counter = 0;
	for(int i = 0 ; i < size ; i++)
	{
		if (ptr != &size)
		{
			ptr++;
			counter++;
		}
	}
		ptr--;
		cout <<"The length is "<< counter << endl;
		endptr = ptr;
		// ptr = set;
}

int back()
{
	cout << "Back function is called :";
	// cout << *ptr << endl;
	for(int i = 0 ; i < size ; i++)
	{
		if (ptr == set)
		{
			cout << "Number cannot move back " << endl;
			break;
		}
	}
	ptr--;
	cout<< *ptr << endl;
	ptr = set;
}

void next()
{
	cout << "Next function is called :";
	// cout << *ptr << endl;
	for(int i = 0 ; i < size ; i++)
	{
		if (ptr == endptr)
		{
			cout << "Number cannot move next " << endl;
			break;
		}
	}
	ptr++;
	cout<< *ptr << endl;
}

void start()
{
	cout << "Start function is called :" ;
	// cout << *ptr << endl;
	for(int i = 0 ; i < size ; i++)
	{
		if (ptr != set)
		{
			ptr--;
		}
	}
	cout << *ptr << endl;
}

void end()
{
	cout << "End function is called :";
	for(int i = 0 ; i< size ; i++)
	{
		if (ptr == endptr)
		{
			cout << *ptr << endl;
			break;
		}
	ptr++;
	}
	ptr = set;
}

void Remove()
{
	rmv = ptr +1;
	int y;
	cout << "Enter a index to Remove value : ";
	cin >> y;
	for(int i = 0 ; i < size ; i++)
	{
		if(*ptr == y)
		{
			ptr = NULL;
			ptr -= 1;
			rmv -= 1;
			i -= 1;
		}
		else if(ptr == NULL)
		{
			*ptr = *rmv;
		}
	}
	if (endptr == NULL)
	{
		endptr -= 1;
		size -= 1;
	}
	for(int i = 0 ; i < size; i++)
	{
		cout << *rmv;
		rmv++;
	}
	cout << endl;
	ptr = set;
}

void Add()
{
	// cout << "Enter a Number to add";
	// cin >> add;
	// for (int i = 0; i < size; ++i)
	// {
		
	// }


}


void even()
{
	ptr = set;
	for(int i = 0 ; i < size ;i++)
	{
		if(*ptr % 2 == 0)
		{
			cout << *ptr <<" ";
		}
		ptr++;
	}
	cout << endl;
}

};

int main()
{
	array a1;
	a1.get();
	a1.length();
	// a1.find();
	// a1.update();
	// a1.back();
	// a1.next();
	// a1.start();
	// a1.end();
	a1.Remove();
	// a1.Add();
	// a1.even();
}