#include <iostream>

using namespace std;

template <typename T>
struct node{
    T data; 
    node *next;
};

template <typename N>
class list{
    private:
    	node<N> *head, *tail;
    public:
    	list(){
			head=NULL;
			tail=NULL;
		}
		void AddKey(N k)
		{
			node<N> *Elem=new node<N>();
			Elem->data=k;
			if (head==0) {head=Elem;tail=Elem;return;}
			if (head->data>Elem->data)
			{
				Elem->next=head;
				head=Elem;
				return;
			}
			if (tail->data<Elem->data)
			{
				tail->next=Elem;
				tail=Elem;
				return;
			}
			node<N> *y=0, *x=head;
			while (Elem->data>x->data)
			{
				y=x;
				x=x->next;
			}
			Elem->next=x;
			y->next=Elem;
		}
		
		void display(){
			node<N> *temp=new node<N>;
			temp=head;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
	
		void delete_first(){
			node<N> *temp=new node<N>;
			temp=head;
			head=head->next;
			delete temp;
		}
		
		N PrintSeparateElement(int pos){
			node<N> *current=new node<N>;
			node<N> *previous=new node<N>;
			current=head;
			for(int i=1;i<pos;i++){
				previous=current;
				current=current->next;
			}
			return current->data;
		}
		
		
		void delete_last(){
			node<N> *current=new node<N>;
			node<N> *previous=new node<N>;
			current=head;
			while(current->next!=NULL){
				previous=current;
				current=current->next;	
			}
			tail=previous;
			previous->next=NULL;
			delete current;
		}
		void delete_position(int pos){
			if(pos==1){
				delete_first();
			}
			node<N> *current=new node<N>;
			node<N> *previous=new node<N>;
			current=head;
			for(int i=1;i<pos;i++){
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
		}
		
		
	
};

double fasi(string a, int n){
	if(a=="Mwvadi") return n * 4.50;
	if(a=="Gvino") return n * 1.50;
	if(a=="Xinkali") return n * 0.30;
	if(a=="Chashushuli") return n * 3.50;
	if(a=="Gomi") return n * 1.70;
	if(a=="Viski") return n * 7.50;
	if(a=="Ludi") return n * 1.20;
	if(a=="Salati") return n * 1.70;
	if(a=="Puri") return n * 1.00;
	if(a=="Xachapuri") return n * 2.50;
}


int main(int argc, char** argv) {
	list<int> tables;
	//magida
	for(int i=1; i<=10; i++){
		tables.AddKey(i);
	}
	tables.display();
	
	cout<<endl<<endl;
	//sakvebi
	list<string> dishes;
	dishes.AddKey("Mwvadi");
	dishes.AddKey("Gvino");
	dishes.AddKey("Xinkali");
	dishes.AddKey("Chashushuli");
	dishes.AddKey("Gomi");
	dishes.AddKey("Viski");
	dishes.AddKey("Ludi");
	dishes.AddKey("Salati");
	dishes.AddKey("Puri");
	dishes.AddKey("Xachapuri");
	
	dishes.display();
	cout<<endl << endl;
	//dajavshna
	
	cout <<"Magida #"<<tables.PrintSeparateElement(2) << endl;
	cout<< dishes.PrintSeparateElement(4) << " " <<fasi(dishes.PrintSeparateElement(4), 8) << " Lari"<< endl; 
	cout<< dishes.PrintSeparateElement(5) << " " <<fasi(dishes.PrintSeparateElement(5), 15) << " Lari"<< endl; 
	cout<< dishes.PrintSeparateElement(1) << " " <<fasi(dishes.PrintSeparateElement(1), 3) << " Lari"<< endl; 
	cout<< dishes.PrintSeparateElement(2) << " " <<fasi(dishes.PrintSeparateElement(2), 4) << " Lari"<< endl; 
	cout<< "---------------------"<< endl; 
	cout<<"sul jami:" << fasi(dishes.PrintSeparateElement(4), 15)+fasi(dishes.PrintSeparateElement(5), 10)
	+fasi(dishes.PrintSeparateElement(1), 5)+fasi(dishes.PrintSeparateElement(2), 2) <<" Lari"<<endl;
	
	return 0;
}
