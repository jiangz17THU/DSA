# include <stdio.h>

bool atleft(int a,int b,int x,int y)//判定点在左方，预防中间变量超过int
{
	long long k=(long long)a*b;
	long long m=(long long)b*x;
	long long n=(long long)a*y;
	return(m+n<k);
}
bool atright(int a,int b,int x,int y)//判定点在右方，包含点在线上
{
	long long k=(long long)a*b;
	long long m=(long long)b*x;
	long long n=(long long)a*y;
    return(m+n>=k);//注意取等
} 
int main()
{
	setvbuf(stdin,new char[1<<20],_IOFBF,1<<20);
	setvbuf(stdout,new char[1<<20],_IOFBF,1<<20);

	int n,m;
	scanf("%d%d",&n,&m);
	int *a=new int[n+1];//线段的秩希望从1开始，故多开辟一个数组空间
	int *b=new int[n+1];
	int *x=new int[m];
	int *y=new int[m];
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(int i=0;i<m;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=0;i<m;i++)
	{
		//考虑点在边界直线之外的两种情况
		if(!atleft(a[n],b[n],x[i],y[i]))
			{
				printf("%d\n",n);
				continue;
			}
		if(atleft(a[1],b[1],x[i],y[i]))
			{
				printf("0\n");
				continue;
			}	
		int lo=1;
		int hi=n;
		int mi;
		while(lo+1<hi) //核心部分，report有详细解释
		{
		    mi=(lo+hi)>>1;
			if(atright(a[lo],b[lo],x[i],y[i])&&atleft(a[mi],b[mi],x[i],y[i]))
				hi=mi;
			else if(atright(a[mi],b[mi],x[i],y[i])&&atleft(a[hi],b[hi],x[i],y[i]))
				lo=mi;
		}
		printf("%d\n",lo);
	}
	return 0;
}