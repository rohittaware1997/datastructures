# include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,a[10];
	cout<<"Enter how many elements";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	int min=-99,temp,lo;
	for(int i=0;i<n;i++)
	{	
		min=a[i];lo=i;
		for(int j=i+1;j<n;j++)
		{
		
			if(min>a[j])	{lo=j;min=a[j];}
		}
		
	temp=a[i];
	a[i]=a[lo];
	a[lo]=temp;
	}
		
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}

	return 0;
}
