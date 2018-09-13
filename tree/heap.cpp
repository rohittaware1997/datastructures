# include <bits/stdc++.h>
using namespace std;
void heapy_fy(int a[],int index,int n)
{
	int l=index*2,temp;
	int r=index*2+1;
	int larger=index;
	if(l<=n && a[l]>a[index])
	{
		larger=l;
	}
	if(r<=n && a[larger]<a[r])
	{	
		larger=r;
	}
	if(larger!=index)
	{
		temp=a[larger];	
		a[larger]=a[index];
		a[index]=temp;
		
		heapy_fy(a,larger,n);
	}
}
void create_heap(int a[],int n)
{
	
	for(int i=n/2;i>0;i--)
		heapy_fy(a,i,n);
}
int main()
{
	int n,a[10];
	cout<<"Enter how many elements you want to enter";
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];

	create_heap(a,n);	
	for(int i=1;i<=n;i++)
	cout<<"  "<<a[i];
	cout<<endl;
	return 0;
}
