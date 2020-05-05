#include <stdio.h>
#include "List.h"
#include "Listnode.h"

int main()
{
	setvbuf(stdin,new char[1<<20],_IOFBF,1<<20);
	setvbuf(stdout,new char[1<<20],_IOFBF,1<<20);

	List interview; //链表对象interview
	int n,m;
	scanf("%d%d",&n,&m);
	int *id=new int[n];
	for(int i=0;i<n;i++)
		scanf("%d",&id[i]);

	Listnode *p= interview.trailer;
	p=interview.insertaspre(p,id[0]);//第一个面试者坐下
	for(int i=1;i<n;i++)//后续面试者依次按规则坐下
	{
		p=interview.insertaspre_m(id[i],m,p);
	}

	int r=interview.rank(p);
	for(int i=0;i<n-r;i++)  //面试者顺时针出场
	{
		printf("%d ",p->data);
		p=p->next;
	}
	Listnode *t= interview.header;
	for(int i=0;i<r;i++)
	{
		t=t->next;
		printf("%d ",t->data);
	}

	return 0;
}