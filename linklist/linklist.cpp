# include <bits/stdc++.h>

using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}node;

void display(node *ptr)
{
	while(ptr!=NULL)
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

void insert_end(int temp1,node* temp)
{
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=create_node(temp1);
}
node* insert_start(int temp1,node* temp)
{
	node *ptr=create_node(temp1);
	ptr->next=temp;
	return ptr;
}
node* insert_middle(int temp1,int no,node* head)
{
	node *ptr=head;
		while(ptr->data!=no)
			ptr=ptr->next;
		node *tempp=create_node(temp1);
		tempp->next=ptr->next;
		ptr->next=tempp;
	 
	return head;
}
node* delete_node(int no,node *head)
{
	node *ptr1=head,*ptr2=head;
	if(head->data==no)
		return head->next;
	else
	{
		while(ptr1!=NULL && ptr1->data!=no)
		{	
			
			ptr2=ptr1;
			ptr1=ptr1->next;
			
		}		
		if(ptr1==NULL)
		{
			printf("Cannnot found number");
			return head;
		}
		ptr2->next=ptr1->next;
		return head;
		
	}
	
}
node* reverse(node* head)
{
	stack<node*> st;
	while(head!=NULL)	
	{
		st.push(head);
		head=head->next;
	}
	head=st.top();
	st.pop();
	node* ptr=head;
	while(!st.empty())
	{
		ptr->next=st.top();
		ptr=ptr->next;
		st.pop();	
	}
	ptr->next=NULL;
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
			temp=head;
		}
		else
		{
			temp->next=create_node(temp1);
			temp=temp->next;	
		}
	}

	display(head);
	
	int kk;
	cout<<"enter element to insert at end";
	cin>>temp1;
	//insert_end(temp1,head);
	//head=insert_start(temp1,head);	
	//cout<<"element after which to insert";
	//cin>>kk;
	//head=insert_middle(temp1,kk,head);	
	head=reverse(head);
	//head=delete_node(temp1,head);	
	display(head);
	return 0;	
	
}
