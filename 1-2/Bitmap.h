# ifndef BITMAP_H
# define BITMAP_H

class Bitmap//����ϰ�⼯��2-34���пɿ��ٳ�ʼ��Bitmap�����˼·����������ɾ��,����������
{
private:
		 int top;
		 int num1; //������������������Nֵ��
		 int num2; //num1������������num2����������
public:
	     int *F;
	     int *T;
	     
	//�������������    
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

	 inline bool valid( int r) //��ǰ����Ч
	{return ( r>=0)&&(r<top);}

	 inline bool erased(  int k)//�ж�[k]�Ƿ񱻱�ǹ����Һ������Ƴ�
	{return valid(F[k])&& !(T[F[k]]+1+k);}//�Ƴ�ʱԼ��T[F[k]]Ϊ-1-k

	inline bool test(int k)  //У�黷�ж�
	{return (valid(F[k]))&&(k==T[F[k]]);}
	 
	inline void set( int k)//����
	{
		if(test(k)) return;//�����Ѿ���ǵ�λ
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
            T[F[k]]=k;//������Ǻ��������ָ�ԭУ�黷
	}
	  }
	 

	 inline void clear(int k) //���
	{
		if(test(k))
			{
				T[F[k]]=0-(1+k);//�ò�����ΪBitmapԪ�ص��ȵ�ֵ��ֵ��ͬʱ���ڼ���
				num2++;
		}
	}

	 inline int num() //��ȡ���µ�Nֵ
	 {
		 return (num1-num2);
	 }
	 inline void reset() //����
	 {
		 top=0;
		 num1=0;
		 num2=0;
	 }
};

#endif
 
