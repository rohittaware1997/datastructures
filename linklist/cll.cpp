# include <bits/stdc++.h>

using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}node;

void display(node *head)
{
	node *ptr=head;
	cout<<ptr->data<<"  ";
	ptr=ptr->next;	
	while(ptr!=head)
	{
		cout<<ptr->data<<"  ";
		ptr=ptr->next;
	}
	
}
node* create_node(int data)
{
	node *ptr=new node;
	ptr->data=data;
	ptr->next=NULL;
}

node* insert_start(int no,node* head)
{	
	node *t;
	node *temp=create_node(no);
	temp->next=head;
	t=temp;
	temp=head;
	while(temp->next!=head)	temp=temp->next;
	temp->next=t;
	return t;
	
}
node * insert_end(int no,node * head)
{
	node *t=head;
	while(t->next!=head)  t=t->next;
	node *temp=create_node(no);
	t->next=temp;
	temp->next=head;
}
void insert_middle(int no,int temp1,node *head)			//no concept of insert at middle as no end
{
	node *ptr=head;
	node *temp=create_node(temp1);	
	if(ptr->data==no)
	{
		temp->next=ptr->next;
		ptr->next=temp;
		cout<<"sdfa";
	}
	else{

	while(ptr->data!=no && ptr!=head)
			ptr=ptr->next;
	
	if(ptr==head)
		cout<<"no specified element found"<<endl;
	else{temp->next=ptr->next;
		ptr->next=temp;}
		
	}
}
node* reverse(node *head)
{
	node *t,*ptr=head->next;
	stack<node*> st;
	st.push(head)	;
	while(ptr!=head)
	{
		st.push(ptr);
		ptr=ptr->next;
	}

	ptr=st.top();	st.pop();
	t=ptr;		
	while(!st.empty())
	{
		ptr->next=st.top();  st.pop();
		ptr=ptr->next;
	}
	
	ptr->next=t;
	return t;
}
node* delete_node(int no,node *head)
{
	node *ptr=head,*ptr1=head;
	if(ptr->data==no)
	{
		head=ptr->next;
		ptr=ptr->next;
		while(ptr->next!=ptr1) ptr=ptr->next;
		ptr->next=head;
		return head;
	}
	else 
	{
		node *ptr1=head;
		ptr=ptr->next;
		while(ptr!=head && ptr->data!=no) {ptr1=ptr;ptr=ptr->next;}
		if(ptr==head)
			{
				cout<<"cannot"<<endl;
			}
		else if (ptr->next==head)
		{
			ptr1->next=head;
		}
		else
		{
			cout<<"dd";
			ptr1->next=ptr->next;
		}
	}
	return head;
}
int main()
{
	node *head=NULL,*temp;
	int n,temp1;
	cout<<"enter how many elements you wnat to enter";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>temp1;
		if(head==NULL)
		{
			head=create_node(temp1);
			head->next=head;
			temp=head;
		}
		else
		{
			temp->next=create_node(temp1);	
			temp=temp->next;
			temp->next=head;
		}
	}
	cout<<"enter no you want to enter";
	int t;
	cin>>t;
	//cout<<"enter no you want to enter after";
	//int tt;
	//cin>>tt;
	//head=insert_start(t,head);
	//insert_end(t,head);
	//insert_middle(tt,t,head);
	//head=reverse(head);
	head=delete_node(t,head);	
	display(head);
	return 0;	
	
}
