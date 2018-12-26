#include<iostream>
using namespace std;

void nTh()
{
	//if input to the programe is 9 6 3 and value of n is 6 then the series generated should look like : 9 6 3 18 27 48
	int z;
	cout << "Enter number of terms " << endl;
	cin >> z;
	int a;
	int array[z]; 
	cout << "Enter three terms"<<endl;
	cin >> array[0];
	cin >> array[1];
	cin >> array[2];
	for (int i = 0; i < z; ++i)
	{
		array[3+i] = array[i]+ array[i+1]+array[i+2];
	}
	for(int i = 0 ; i < z ; i++)
		cout << array[i] <<" ";
}

int main()
{
	nTh();
}
