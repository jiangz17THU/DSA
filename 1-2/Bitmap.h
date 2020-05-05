# ifndef BITMAP_H
# define BITMAP_H

class Bitmap//沿用习题集【2-34】中可快速初始化Bitmap对象的思路，允许插入和删除,并加以扩充
{
private:
		 int top;
		 int num1; //这俩变量是用来记算N值的
		 int num2; //num1人数增加量，num2人数减少量
public:
	     int *F;
	     int *T;
	     
	//构造和析构函数    
	Bitmap(int n=8) 
	{
		F=new int[n];
		T=new int[n];
		top=0;
		num1=num2=0;
	}

	~Bitmap()
	{
		delete [] F;
		delete [] T;
	}

	 inline bool valid( int r) //当前秩有效
	{return ( r>=0)&&(r<top);}

	 inline bool erased(  int k)//判断[k]是否被标记过，且后来被移除
	{return valid(F[k])&& !(T[F[k]]+1+k);}//移除时约定T[F[k]]为-1-k

	inline bool test(int k)  //校验环判断
	{return (valid(F[k]))&&(k==T[F[k]]);}
	 
	inline void set( int k)//插入
	{
		if(test(k)) return;//忽略已经标记的位
		if(!erased(k)) 
			{
				F[k]=top;
				top++;
				num1++;
				T[F[k]]=k;
		}
		if(erased(k))
		{
			num1++;
            T[F[k]]=k;//若曾标记后被清除，则恢复原校验环
	}
	  }
	 

	 inline void clear(int k) //清除
	{
		if(test(k))
			{
				T[F[k]]=0-(1+k);//用不可能为Bitmap元素的秩的值赋值，同时便于检验
				num2++;
		}
	}

	 inline int num() //求取当下的N值
	 {
		 return (num1-num2);
	 }
	 inline void reset() //清零
	 {
		 top=0;
		 num1=0;
		 num2=0;
	 }
};

#endif
 
