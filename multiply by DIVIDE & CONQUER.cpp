#include<iostream>
#include<cmath>
using namespace std;

struct node
{
	int info;
	node *next;
};

class multiply
{
private:
	node *temp , *ptr , *head , *head1 , *head2 , *temp2 , *ntemp , *ptemp;
	int d1_count , d2_count , y ,count;
	int x;
public:
	int num1 , num2;
	int digit;
	multiply(){
		temp2 = head2 = head1 = head = temp = ptr = NULL;
		d1_count = d2_count = count = 0;
		cout << "Enter first number "<<endl;
		cin >> num1;
		cout << "Enter second number "<<endl;
		cin >> num2;
		x = num1; 
		while (x != 0) { // count digites
		    x = x / 10; 
		    d1_count++; 
		}
		x = num2; 
		while (x != 0) { // count digites
		    x = x / 10; 
		    d2_count++; 
		}
		y = 0;
	}
	~multiply(){
		delete head;
		delete temp;
	}
	void insert2()
	{
		if(head1 == NULL){
			head1 = new node;
			head1 -> info = digit;
			head1 -> next = NULL;
			return;
		}
		temp = new node;
		temp ->info = digit;
		temp -> next = head1;
		head1 = temp;
	}
	void insert()
	{
		if(head == NULL)
		{
			head = new node;
			head -> info = digit;
			head -> next = NULL;
		return;
		}
		temp = new node;
		temp ->info = digit;
		temp -> next = head;
		head = temp;
	}
	void odd(){
		if(d1_count % 2 != 0){
			temp = new node;
			temp->info = 0;
			temp->next = head;
			head = temp;
		}
		if(d2_count % 2 != 0){
			temp = new node;
			temp->info = 0;
			temp->next = head1;
			head1 = temp;
		}
	}
	void restore(){
		if(head2 == NULL)
		{
			head2 = new node;
			head2 -> info = y;
			head2 -> next = NULL;
			return;
		}
		temp2 = new node;
		temp2 ->info = y;
		temp2 -> next = head2;
		head2 = temp2;
	}
	void add(){
		temp = head2;
		x = 0;
		while(temp != NULL){
			x += temp->info;
			temp = temp->next;
		}
		cout << x;
	}
	void mul(){
		temp = head;
		while(temp != NULL){
			ptr = head1;
			y = temp->info;
			while(ptr != NULL){
				x = 0;
				for(int i = 0 ; i < ptr->info ; i++)
					x += y;
				ntemp = temp;
				ptemp = ptr;
				d1_count = 0;
				while(ntemp != NULL){
					d1_count++;
					ntemp = ntemp->next;
				}
				while(ptemp != NULL){
					d1_count++;
					ptemp = ptemp->next;
				}
				d1_count = d1_count-2;
					y = x;
				int add;
				for (int i = 0; i <d1_count ; ++i) {
		    		add = y;
		   		 for (int j = 1; j < 10; ++j) {
	     		   y += add;
	    }
	}
				restore();
				y = temp->info;
				ptr = ptr->next;
			}
		temp = temp->next;
		}
	}
};
int main(){
	multiply m;
while(m.num1 > 0)
     {
          m.digit = m.num1%10;
          m.insert();
          m.num1 /= 10;
     }
while(m.num2 > 0)
     {
          m.digit = m.num2%10;
          m.insert2();
          m.num2 /= 10;
     }
    m.odd();
	m.mul();
	m.add();
}
