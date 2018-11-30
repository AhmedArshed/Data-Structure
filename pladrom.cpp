#include<iostream>
using namespace std;

class pa{
	private:
		int size;
		string a;
		char *ptr;
		char *temp;
		char *end;
		char *array;
	public:
		pa(){
			size = 0;
			ptr = temp = end = NULL;
			cout << "Enter string to check paladrom"<<endl;
			cin >>a;
			size = a.length(); 
			array = new char[size];
			ptr = array;
			for(int i = 0 ; i < size ; i++)
			{
				*array = a[i];
				array++;
			}
			end = array;
		}
		~pa(){
			delete [] array;
		}
	void paladrom(){
			
		for(int i = 0; i < size/2 + 1; i++){
		if(*ptr == *end){
			ptr++;
			end--;
		}
		else{
			cout <<"not";
			return;
		}
	}
	cout << "Yes"<<endl;
	}
};

int main()
{
	pa p;
	p.paladrom();
}
