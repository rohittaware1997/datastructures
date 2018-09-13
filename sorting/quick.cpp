# include <bits/stdc++.h>

using namespace std;


int divide(int a[],int start,int end)
{
	int pivote=a[end],temp;
	int pointer=start;
	for(int i=start;i<end;i++)
	{
		if(pivote>=a[i])
		{
			temp=a[pointer];
			a[pointer]=a[i];
			a[i]=temp;
			pointer+=1;
		}
	}
	temp=a[pointer];
	a[pointer]=a[end];
	a[end]=temp;
	return pointer;
}
void partition(int a[],int start,int end)
{
	if(start<end)
	{
		int p=divide(a,start,end);
		partition(a,start,p-1);	
		partition(a,p+1,end);
	}
	
}

int main()
{
	int n,a[10];
	cout<<"Enter elements";
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>a[i];

	partition(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<"  ";
	return 0;
}
