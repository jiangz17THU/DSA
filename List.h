# ifndef LIST_H
# define LIST_H
# include "Listnode.h"

class List//双向链表，含header，trailer，规定header到trailer为顺时针
{
private:
	int size;
	
protected:
	void init();//列表初始化
public:
	post(T) header;
    post(T) trailer;//设置头尾哨兵
    //构造和析构函数
	List()
	{ init();}
	~List(){};

	//只读接口
	 int getsize() { return size;} 
	 int rank(post(T) node);

	 //可写接口
	 post(T) insertaspre(post(T) node,int &e);//将e作为前驱插入
     post(T) insertaspre_m(int &e,int m,post(T) node);//将e从当前节点回溯m个节点插入（将List假想成环）
};

 int List::rank(post(T) node)
{
	int r=0; //r表示当前节点的秩，从0计
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

 post(T) List::insertaspre_m(int &e,int m,post(T) node)//从前一应聘者出发，沿逆时针方向围圆桌走过m 人
{
  post(T) p=node;
  int t=this->getsize();
  m=m%t;   //对size取模，简化讨论
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
 post(T) List :: insertaspre(post(T) node,int &e)//前插节点
	 {
		 post(T) prenode=new Listnode(e,node->pre,node) ;
		 node->pre->next=prenode;
		 node->pre=prenode;
		 size++;
		 return prenode;
	 }

# endif