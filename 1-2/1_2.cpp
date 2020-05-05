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
	B=new long long int[n+1]; //存储code，注意B[0]不使用
	long long int Q;// 累计Q的结果
	int N;	// 累计N的结果
	Q=N=0;
	
	Bitmap bp(n); //创建Bitmap类对象
	 
	memset(B,-1,(n+1));//初始化code
	char  INSTRUCTION[5] ;//助教提示我用数组，见honor code，5为合理范围内任取
	
	for(;m>0;m--)
	{
     	scanf("%s",&INSTRUCTION);
		if(INSTRUCTION[0]=='I') //员工签到
		{
			 int a;
			scanf("%d",&a);
			  int c;
			scanf("%d",&c);
			bp.set(a);
			B[a]=c;
		}
		if(INSTRUCTION[0]=='O') //员工离开
		{
			  int a;
			scanf("%d",&a);
		    bp.clear(a);
		    B[a]=-1; 
		}
		if(INSTRUCTION[0]=='C') //清零
		{
			bp.reset();
		}
        if(INSTRUCTION[0]=='N') //累计N值
		{
			N+=bp.num();
		}
		if(INSTRUCTION[0]=='Q') //询问code
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