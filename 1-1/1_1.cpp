#include <stdio.h>
#include <string.h> 

int main()
{
	setvbuf(stdin,new char[1<<20],_IOFBF,1<<20);
	setvbuf(stdout,new char[1<<20],_IOFBF,1<<20);
	
	int n,k;
	scanf("%d",&n);
	 
	int *a =new int[n];
	int *b =new int[n];
	int *c =new int[n];
	int *chosen=new int[n+1];//标记队员是否已经被选,注意比n多1
	 
	memset(chosen,0,sizeof(int) *(n+1));//清零，初始均未被选
	
	//输入三个优先级数组
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&c[i]);
	
	scanf("%d",&k);
	int num0,num1,num2;//设置优先级数组的下标变量
		num0=num1=num2=0;
	for(int i=0;i<n;i++)
	{
		 if(i%3==0&&chosen[a[num0]]==1)//i%3决定该由哪个教练选
		{
			num0++;
			i--;   //使得当下的i可以进入下一条件判断
			 
		}
		else if(i%3==0&&chosen[a[num0]]==0)
		{
			chosen[a[num0]]=1;
			num0++;
			if(a[num0-1]==k)  //找到k
			{printf("A");break;}
				 
		}
		else if(i%3==1&&chosen[b[num1]]==1)
		{
			num1++;
			i--;
			 
		}
		else if(i%3==1&&chosen[b[num1]]==0)
		{
			chosen[b[num1]]=1;
			num1++;
			if(b[num1-1]==k)
			{printf("B");break;}
			
		}
		else if(i%3==2&&chosen[c[num2]]==1)
		{
			num2++;
			i--;
			 
		}  
		else if(i%3==2&&chosen[c[num2]]==0)
		{
			chosen[c[num2]]=1;
			num2++;
			if(c[num2-1]==k)
			{printf("C");break;}
			
		}  
	}	
	return 0;
}
