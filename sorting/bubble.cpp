# include <bits/stdc++.h>
using namespace std;

void divide(int a[],int f,int l)
{
	int m=(f+l)/2;
	if(f<l)
	{
		divide(a,f,m);
		divide(a,m+1,l);
		merge(a,f,m,l);
	}
	
}

void merge(int a[],int f,int m, int l)
{
	int l1[10],l2[10];
	int i,j=0,n1=0,n2=0;

	for(int i=f;i<m;i++)
	{
		l1[j++]=a[i];n1++;
	}

	for(int i=m+1;i<l;i++)
	{
		l2[j++]=a[i];n2++;
	}
	i=0;j=0
	while(i<n1 && j<n2)
	{
		if(l1[i]>l2[j])
		{
			a[f++]=l2[j++];	
		}
		else
		{
			a[f++]=l1[i++];
		}
	}

	while(i<n1)
	{
		a[f++]=l1[i++];
	}
	
	while(j<n2)
	{
		a[f++]=l2[j++];
	}
}

int main()
{
	int n,a[100];
	cout<<"Enter how many elements you want to enter";
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"we are in merge sort";
	divide(a,0,n-1);	
	cout<<"displaying data";
	for(int i=0;i<n;i++)
		cout<<a[i]<<"  ";
	return 0;
}
