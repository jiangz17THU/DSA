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
	int *chosen=new int[n+1];//��Ƕ�Ա�Ƿ��Ѿ���ѡ,ע���n��1
	 
	memset(chosen,0,sizeof(int) *(n+1));//���㣬��ʼ��δ��ѡ
	
	//�����������ȼ�����
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&c[i]);
	
	scanf("%d",&k);
	int num0,num1,num2;//�������ȼ�������±����
		num0=num1=num2=0;
	for(int i=0;i<n;i++)
	{
		 if(i%3==0&&chosen[a[num0]]==1)//i%3���������ĸ�����ѡ
		{
			num0++;
			i--;   //ʹ�õ��µ�i���Խ�����һ�����ж�
			 
		}
		else if(i%3==0&&chosen[a[num0]]==0)
		{
			chosen[a[num0]]=1;
			num0++;
			if(a[num0-1]==k)  //�ҵ�k
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
