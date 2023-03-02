#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node* prev;
	node* next;
		// Constructor - 
		node(int d)
		{
			this ->data = d;
			this ->prev= NULL;	
			this ->next= NULL; 	
		}
		// Destructor -
		~node()
		{
			int val = this->data;
			if(next!= NULL)
			{
				delete next;
				next =NULL;
			}
		cout<<"Memory free of node carrying the data :- "<<val<<endl;
		}
		
};
node* head =NULL;
node* tail	=NULL;
int insertAtHead(int data)
{
	if(head==NULL)
	{
		node* temp= new node(data);
		head =temp;
		tail=temp;
		tail->next=head;
	}
	else
	{
		node* newnode= new node(data);
		newnode->next=head;
		head= newnode;
	}
}
		
int insertAtEnd(int data)
{
	if(head==NULL)
	{
		node* temp= new node(data);
		head =temp;
		tail=temp;
		tail->next=head;
	}
	else
	{
		node* temp=head;
		while(temp!=tail)
		{
			temp= temp->next;
		}
		node* newnode= new node(data);
		temp->next=newnode;
		tail=newnode;
		tail->next=head;
		
	}
}
int insertAtPosition(int pos, int data)
{
	if(head==NULL)
	{
		cout<<"The List is Empty So First Insertion Will happen At Head";
		node* temp= new node(data);
		head =temp;
		tail=temp;
		tail->next=head;
	}
	else
	{
		node* current= head;
		node* previous= NULL;
		int count=1;
		while(count<pos)
		{
			previous=current;
			current=current->next;
			count++;	
		}
		node* newnode =new node(data);
		previous->next=newnode;
		newnode->next=current;	
	}
}

int deleteFromHead()
{
	if(head==NULL)
	{
		cout<<"The Head is Already Empty!!";
	}
	node* temp= head;
	int value =temp->data;
	head=head->next;
	temp->next=NULL;
	delete temp;
	return value;
}

int deleteFromEnd()
{
	if(head==NULL)
	{
		cout<<"The Head is Already Empty!!";
	}
	node* temp =head;
	int value =temp->data;
	node* prev	=NULL;	 
	while(temp!=tail)
	{
		prev=temp;
		temp=temp->next;
	}
	tail=prev;
	tail->next=head;
	temp->next=NULL;
	delete temp;
	return value;
}

int deleteFromPosition(int pos)
{
	if(head==NULL)
	{
		cout<<"The Head is Already Empty!!";
		cout<<"Here"<<endl;
	}
	int count=1;
	node* current= head;
	node* previous= NULL;
	while(count<pos)
	{
		previous=current;
		current=current->next;
		count++;
	}
	previous->next=current->next;
	int value= current->data;
	current->next=NULL;
	delete current;
}

int display()
{
	if(head==NULL)
	{
		cout<<"The List is Empty"<<endl;
		return -1;
	}
	node* temp =head;
	do
	{
		cout<<temp ->data<<" --> ";
		temp = temp->next;
	}while(temp!= tail);
	cout<<"Head."<<endl;
}
int main()
{
	display();
	cout<<endl<<"Insertion At head :"<<endl;
	insertAtHead(10);
	display();
	cout<<endl;
	insertAtHead(20);
	insertAtHead(30);
	insertAtHead(40);
	display();
	cout<<endl<<"Insertion At end :"<<endl;
	insertAtEnd(100);
	insertAtEnd(90);
	display();
	cout<<endl<<"Insertion At Position :"<<endl;
	insertAtPosition(3, 999);
	insertAtPosition(2, 888);
	display();
	
	cout<<endl<<"Delete From Head :"<<endl;
	deleteFromHead();
	display();
	cout<<endl<<"Delete From End :"<<endl;
	deleteFromEnd();
	display();
	cout<<endl<<"Delete From Position :"<<endl;
	deleteFromPosition(2);
	display();
	
	return 0;
}
