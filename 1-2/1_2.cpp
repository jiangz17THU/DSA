# include <stdio.h>
# include <string.h>
# include "Bitmap.h"

int main()
{
	setvbuf(stdin,new char[1<<20],_IOFBF,1<<20);
	setvbuf(stdout,new char[1<<20],_IOFBF,1<<20);

	int n,m;
	scanf("%d%d",&n,&m);
	long long int *B; 
	B=new long long int[n+1]; //�洢code��ע��B[0]��ʹ��
	long long int Q;// �ۼ�Q�Ľ��
	int N;	// �ۼ�N�Ľ��
	Q=N=0;
	
	Bitmap bp(n); //����Bitmap�����
	 
	memset(B,-1,(n+1));//��ʼ��code
	char  INSTRUCTION[5] ;//������ʾ�������飬��honor code��5Ϊ����Χ����ȡ
	
	for(;m>0;m--)
	{
     	scanf("%s",&INSTRUCTION);
		if(INSTRUCTION[0]=='I') //Ա��ǩ��
		{
			 int a;
			scanf("%d",&a);
			  int c;
			scanf("%d",&c);
			bp.set(a);
			B[a]=c;
		}
		if(INSTRUCTION[0]=='O') //Ա���뿪
		{
			  int a;
			scanf("%d",&a);
		    bp.clear(a);
		    B[a]=-1; 
		}
		if(INSTRUCTION[0]=='C') //����
		{
			bp.reset();
		}
        if(INSTRUCTION[0]=='N') //�ۼ�Nֵ
		{
			N+=bp.num();
		}
		if(INSTRUCTION[0]=='Q') //ѯ��code
		{
			  int a;
			scanf("%d",&a);
		 if(bp.test(a))
			Q+=B[a];
		 else
			Q+=-1;
		}
	}
	printf("%lld\n",N+Q);
	delete[] B;
	return 0;
}