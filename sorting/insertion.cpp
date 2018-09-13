# include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,a[10];
	cout<<"Enter elements";
	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>a[i];

	int temp,j,hole;
	for(int i=1;i<n;i++)
	{
		temp=a[i];
		hole=i;
		while(hole>0 && a[hole-1]>temp)
		{
			a[hole]=a[hole-1];
			hole=hole-1;
		
		}

		a[hole]=temp;		
		
	}

	for(int i=0;i<n;i++)
		cout<<a[i]<<"  ";
	return 0;
}
