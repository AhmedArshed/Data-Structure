#include<iostream>
using namespace std;

void table(int x , int y , int z){
	if(z > y){
		return;
	}
	else{
		cout << x <<" X " << z <<" = " << x*z <<endl;
		table(x,y,z+1);
	}
}

int main(){
	int value , number ,z;
	cout <<"Enter number to campute table "<<endl;
	cin >> number;
	cout<<"Enter value you want to get through table"<<endl;
	cin >> value;
	z = 0;
	table(number, value, z);
}
