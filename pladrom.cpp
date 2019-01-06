#include <iostream>
#include<stdio.h>
using namespace std;

class palindrome{
	private:
		
	public:
		char * start;
		char * last;
		char * array;
		char *temp;
		char value;
		int size;
	public:
		palindrome(){
			start = NULL;
			last  = NULL;
			size = 0;
			array = new char[1000];
			temp = array;
			for(int i = 1;i<1000; i++){
				cout << "Enter the value: " << endl;
				cin >> *temp;
				temp++;
				
				cout << "enter the value: Y" << " otherwise: N" << endl ;
				cin >> value;
				if(value == 'y'){
					continue;
				}
				else{
					break;
				}
			}
			
		}
		void checkingpalindrome()
		{
			start  = array;
			last = array;
			while(*last != '\0'){
				last++;
				size++;
			
			}
			last--;
			for(int i = 1; i <= size/2 + 1 ; i++){
				if(*start == *last){
				start++;
				last--; 
			}
				else{
					cout << "it is not palindrome:"<<endl;
					return;
				}
						
		}
				cout << "It is Palindrome:"<<endl;
		
		}
};
int main(){
	palindrome pald;
	pald.checkingpalindrome();
}
