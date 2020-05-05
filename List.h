# ifndef LIST_H
# define LIST_H
# include "Listnode.h"

class List//˫��������header��trailer���涨header��trailerΪ˳ʱ��
{
private:
	int size;
	
protected:
	void init();//�б��ʼ��
public:
	post(T) header;
    post(T) trailer;//����ͷβ�ڱ�
    //�������������
	List()
	{ init();}
	~List(){};

	//ֻ���ӿ�
	 int getsize() { return size;} 
	 int rank(post(T) node);

	 //��д�ӿ�
	 post(T) insertaspre(post(T) node,int &e);//��e��Ϊǰ������
     post(T) insertaspre_m(int &e,int m,post(T) node);//��e�ӵ�ǰ�ڵ����m���ڵ���루��List����ɻ���
};

 int List::rank(post(T) node)
{
	int r=0; //r��ʾ��ǰ�ڵ���ȣ���0��
	post(T) p=node->pre;
	while(p!=header)
	{
		p=p->pre;
		r++;
	}
	return r;
}

 void List::init()
{
	 header=new Listnode;
	 trailer=new Listnode;
	 size=0;
	 header->next=trailer; header->pre=NULL;
	 trailer->next=NULL;   trailer->pre=header;
}

 post(T) List::insertaspre_m(int &e,int m,post(T) node)//��ǰһӦƸ�߳���������ʱ�뷽��ΧԲ���߹�m ��
{
  post(T) p=node;
  int t=this->getsize();
  m=m%t;   //��sizeȡģ��������
  if(t==1)
	{
		List::insertaspre(p,e);
		return p->pre;
  }
  else
  {
	if(m==0)
	{
		if(p->next==trailer)
		{
			p=this->header->next;
			List::insertaspre(p,e);
			return p->pre;
		}
		else
		{
			p=p->next;
			List::insertaspre(p,e);
			return p->pre;
		}
	}

	else
	{
		while(p->pre!=this->header&&m>1)
		{
			m--;
			p=p->pre;
		}
		if(m==1)
			List::insertaspre(p,e);
		else
		{   p=this->trailer;
			while(m-1>0)
			{
				m--;
				p=p->pre;
			}
			List::insertaspre(p,e);
		}
		return p->pre;
	}
  }
 }
 post(T) List :: insertaspre(post(T) node,int &e)//ǰ��ڵ�
	 {
		 post(T) prenode=new Listnode(e,node->pre,node) ;
		 node->pre->next=prenode;
		 node->pre=prenode;
		 size++;
		 return prenode;
	 }

# endif