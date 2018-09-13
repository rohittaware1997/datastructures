node* delete(int no,node* head)
{
	if(head==NULL)	
		return NULL;
	else if(no>head->data) head->right=delete(no,head->right);
	else if(no<head->data) head->left=delete(no,head->left);
	else
	{
		//leaf node
		if(head->left==NULL && head->right==NULL)
		{
			free(head);
			return head;	
		}
		else if(head->left==NULL)
		{
			node* temp=head->right;
			free(head);
			return 	temp;
		}
		else if(head->right==NULL)
		{
			node* temp=head->left;
			free(temp);
			return temp;		
		}
		else
		{
			int no=min(head->right);
			head->data=no;
			head->right=delete(head->right,no);
			return head;
		}
	}
	else return head;
}
