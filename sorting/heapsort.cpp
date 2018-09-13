
# include <bits/stdc++.h>
using namespace std;
void heapy_fy(int a[],int index,int n)
{
	int l=index*2;
	int r=index*2+1;
	int temp,larger=index;
	if(l<=n && a[index]<a[l])
	{
		larger=l;
	}
	if(r <= n && a[larger]<a[r])
	{
		larger=r;
	}

	if(index!=larger)
	{
		temp=a[larger];
		a[larger]=a[index];
		a[index]=temp;

		heapy_fy(a,larger,n);
	}
}

void create_heap(int a[],int n)
{
	for(int i=n/2;i>0;i--)  					//till first element
	{
		cout<<i<<endl;
		heapy_fy(a,i,n);
	
	}
}
void heapsort(int a[],int n)
{
	create_heap(a,n);
	
	int temp;
	int t=n;
	for(int i=1;i<t;i++)
	{
		temp=a[1];
		a[1]=a[n];
		a[n]=temp;
			
		n=n-1;
		
		heapy_fy(a,1,n);
		printf("after one iteration");
		for(int j=1;j<=t;j++)
			cout<<a[j]<<"  ";
		cout<<endl;
	}	
}
int main()
{
	int n,a[10];
	printf("Enter how many elements you want to enter");
	cin>>n;

	for(int i=1;i<=n;i++)
		cin>>a[i];

	heapsort(a,n);
	//
	for(int i=1;i<=n;i++)
		cout<<a[i]<<"  ";

}
