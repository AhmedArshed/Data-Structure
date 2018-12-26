#include<iostream>
using namespace std;

int pow(int x , int y)
{
	int result = x;
	for(int i = 1 ; i < y ;i++){
		result = result*x;
	}
	return result;
}
float fac(int x)
{
	if(x == 0)
		return 1;
	else{
		return x = x * fac(x-1);
	}
}
void equation()
{
	int x;
	int n;
	int z;
	float value = 1;
	cout << "Enter number of terms"<<endl;
	cin >> n;
	cout << "Enter value of x"<<endl;
	cin >> x;
	for(int i = 1 ; i < n ; i++)
	{
		z = 2*i;
		if(i % 2 == 0)
			value += pow(x,i) / fac(z);
		else
			value -= pow(x,i) / fac(z);
		// cout << value << endl;
	}
	cout << value;
}
void equation2()
{
	int x;
	int n;
	int z;
	cout << "Enter number of terms"<<endl;
	cin >> n;
	cout << "Enter value of x"<<endl;
	cin >> x;
	float value = x;
	for(int i = 1 ; i<n ; i++){
		z = 2*i;
		int y = z - 1;
		if(i %2 == 0)
			value += pow(x,(y) / fac(z));
		if(i %2 != 0)
			value -= pow(x,(y) / fac(z));
	}
	cout << value <<endl;
}
