#include <iostream>
#include <cstdlib>

struct Node {
	int data;
	Node *next;
};
using namespace std;

class Stack {
	private:
		Node *Top;
	public:
		Stack(){
			Top=0;
		}

		void Push(int k){

			Node *tmp;
			tmp=new Node();
			tmp->data=k;
			tmp->next=Top;
			Top=tmp;
		}

		void Pop(){

			if(Top!=0){
				Node *tmp=Top;
				Top=Top->next;

			}
		}

		void print (){
			Node *tmp=Top;
			if (tmp==0) cout<<"steki carielia";
			while (tmp->next!=0){
				cout<<tmp->data<<"---";
				tmp=tmp->next;
			}
			cout<<tmp->data;
		}
        int GetTop(){
        	int p=Top->data;
        	return p;
		}
};



int main(int argc, char** argv) {
	Stack *A=new Stack();
	Stack *B=new Stack();
	int n; cout<<"n="; cin>>n;
    int m; cout<<"m="; cin>>m;

	for (int i=0; i<n; i++){
	   int s; cout<<i<<" elementi="; cin>>s;
	   A->Push(s);
	}
		for (int i=0; i<m; i++){
	   int s; cout<<i<<" elementi="; cin>>s;
	   B->Push(s);
	}
	Stack *C=new Stack();

    for (int i=0; i<n; i++){
    	C->Push(A->GetTop());
    	A->Pop();
	}	
    for (int i=0; i<m; i++){
    	C->Push(B->GetTop());
    	B->Pop();
	}
	C->print();

	 	 for (int i=0; i<2; i++){
	 	B->Push(A->GetTop());
	    A->Pop();
	}
	 cout<<A->GetTop()<<endl;
	B->print();

	system("pause");
	return 0;
}
