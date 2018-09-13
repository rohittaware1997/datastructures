# include <stdio.h>
# include <stdlib.h>

int v,e;
int visited[100];
typedef struct node
{
	int f,s,w;
}sp2;
void initialize()
{
	for(int i=0;i<e;i++)
	{
		visited[i]=i;
	}
}
int find(int u)
{
	while(visited[u]!=u)
		u=visited[u];
	return u;
}
void sort1(sp2 sp[])
{
	sp2 temp;
	for(int i=0;i<e-1;i++)
	{
		for(int j=0;j<e-1-i;j++)
		{
			if(sp[j].w>sp[j+1].w)
			{
				temp=sp[j];
				sp[j]=sp[j+1];
				sp[j+1]=temp;		
			
			}			
		}
	}
}
void display(sp2 sp[])
{
	for(int i=0;i<v;i++)
	{
		printf("%d  %d  = %d\n",sp[i].f,sp[i].s,sp[i].w);
	}
}
void uni(int x,int y)
{
	while(visited[x]!=x)
		x=visited[x];

	visited[x]=y;
}
void kru(sp2 sp[],sp2 fin[])
{
	int ed=0;
	int fi=0;
	int u,v,w;
	int weight=0;
	for(int i=0;i<e;i++)
	{
		u=sp[ed].f;
		v=sp[ed].s;
		w=sp[ed++].w;

		if(find(u)!=find(v))
		{
			fin[fi].f=u;
			fin[fi++].s=v;
			weight=weight+w;
			uni(u,v);
			if(fi==v-1)
				break;
		}
	}

	for(int i=0;i<v;i++)
	{
		printf("%d--->%d\n",fin[i].f,fin[i].s);
	}
	printf("\n");
	printf("weight= %d",weight);
}
int main()
{
	int temp;
	sp2 sp[10];
	sp2 fin[10];
	printf("Enter how many edges you want to enter");
	scanf("%d",&e);
	printf("Enter how many vertex you want to enter");
	scanf("%d",&v);

	for(int i=0;i<e;i++)
	{
		printf("Enter first \n");
		scanf("%d",&sp[i].f);
		printf("Enter second \n");
		scanf("%d",&sp[i].s);
		printf("Enter weight \n");
		scanf("%d",&sp[i].w);
			
	}
	initialize();
	display(sp);
	sort1(sp);
	printf("-------------------\n");
	display(sp);
	kru(sp,fin);
	return 0;
}

