# include <bits/stdc++.h>
using namespace std;
typedef struct node
{
	int data;
	node* left;
        node* right;
}node;


//--------------------------
node *head;
//----------------
node * create_node(int data)
{
	node* ptr=new node;
	ptr->data=data;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}
node * copy(node* head)
{
	if(head==NULL) return NULL;
	node *ptr=new node;
	ptr->data=head->data;
	ptr->left=copy(head->left);
	ptr->right=copy(head->right);

	return ptr;	
}
node * insert(int data)
{
	node *ptr=head;
	if(head==NULL)
	{
		head=create_node(data);
		return head;		
	}
	while(1)
		{		
			if(ptr->data>data)
			{	
				if(ptr->left==NULL)
					{ptr->left=create_node(data);return head;}
				else
					ptr=ptr->left;
			}
			else if(ptr->data<data)
			{
				if(ptr->right==NULL)
					{ptr->right=create_node(data);return head;}
				else
					ptr=ptr->right;
			}
		}	
}
void inorder(node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		cout<<ptr->data<<"  ";
		inorder(ptr->right);
		
	}

}
void preorder(node *ptr)
{
	if(ptr!=NULL)
	{
		
		cout<<ptr->data<<"  ";
		preorder(ptr->left);
		preorder(ptr->right);
		
	}

}
void postorder(node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		cout<<ptr->data<<"  ";
		postorder(ptr->right);
		
	}

}
void min(node* temp)
{
	while(temp->left!=NULL)	temp=temp->left;
	cout<<temp->data<<"\n";
}
int depth(node *ptr)
{
	if(ptr==NULL)
		return 0;
	else
		return 1+max(depth(ptr->left),depth(ptr->right));
}
int no_nodes(node* head)
{
	if(head==NULL)
		return 0;
	else
		return 1 + no_nodes(head->left)+ no_nodes(head->right);
}
void mirror(node *head)
{
	node *ptr=NULL;
	if(head!=NULL)
	{
		ptr=head->left;
		head->left=head->right;
		head->right=ptr;
		mirror(head->left);
		mirror(head->right);
	}
}
int no_1(node *ptr)
{
	if(ptr==NULL) return 0;
	if(ptr->left==NULL && ptr->right==NULL) return 0;
	if(ptr->left==NULL)
		return 1+no_1(ptr->right);
	else if(ptr->right==NULL)
		return 1+no_1(ptr->left);
	else
		return no_1(ptr->right)+no_1(ptr->left);
}
int no_2(node *ptr)
{
	if(ptr==NULL)	return 0;
	if(ptr->left!=NULL && ptr->right!=NULL)
		return 1+no_2(ptr->left)+no_2(ptr->right);
	if(ptr->right==NULL)
		return no_2(ptr->left);
	if(ptr->left==NULL)
		return no_2(ptr->right);
}
int no_leaf(node *ptr)
{
	if(ptr==NULL)
		return 0;
	if(ptr->left==NULL && ptr->right==NULL)
		return 1;
	else 	
		return no_leaf(ptr->left)+no_leaf(ptr->right);

}
int norec_count(node *ptr)	/// non recurssivve no of nodesf
{
	int count=0;
	stack<node*> st;
	node *t;
	st.push(ptr);
	while(!st.empty())
	{
		t=st.top();st.pop();
		if(t!=NULL)
		{
			count+=1;
			if(t->left!=NULL)
				st.push(t->left);
			if(t->right!=NULL)
				st.push(t->right);
		}	

	}
	return count;
}
void level(node *head)
{
	queue<node*> q;
	q.push(head);
	node *temp=NULL;
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		cout<<temp->data<<"  ";
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
	
}
/*int nonrec_height(node *ptr)//////////////////////////////////////////////////////////////height by using queue 


	use two queues one for first level and another for second level
	pop from first and copy its child into second queue and increament height
	now copy content of second queue into first and perfrom same as above till first queue is not empty

{
	queue<node*> q1,q2;
	q1.push()
}*/
node * insert_recor(int temp,node *head)
{

	if(head==NULL)
	{
		head=create_node(temp);
		return head;
	}
	else
	{
		if(head->data>temp)	
		{
			head->left=insert_recor(temp,head->left);
		}
		else
		{
			head->right=insert_recor(temp,head->right);
		}			
			
		
			
	}
	return head;
}
int max(node *ptr)
{
	while(ptr->right!=NULL)
		ptr=ptr->right;
	return ptr->data;
}
int main()
{
	int n,temp,flag;
	node *ptr;
	cout<<"Enter how many elements you want to enter";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		
		cin>>temp;
		head=insert_recor(temp,head);
		
	}
	/*
	cout<<"Enter how many elements you want to enter";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		
		cin>>temp;
		head=insert(temp);
		
	}*/
	//cout<<"depth"<<depth(head);
	//min(head);
	/*inorder(head);
	cout<<endl;
	preorder(head);
	cout<<endl;
	postorder(head);*/
	//cout<<no_nodes(head);
	//inorder(head);	
	//mirror(head);	
	//inorder(head);
	//ptr=copy(head);
	//inorder(head);
	//inorder(ptr);
	//cout<<no_leaf(head);
	//cout<<no_nodes(head);
	//cout<<endl;
	//cout<<norec_count(head);	
	cout<<max(head);
	//level(head);
	return 0;
}
