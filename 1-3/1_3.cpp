#include <stdio.h>
#include "List.h"
#include "Listnode.h"

int main()
{
	setvbuf(stdin,new char[1<<20],_IOFBF,1<<20);
	setvbuf(stdout,new char[1<<20],_IOFBF,1<<20);

	List interview; //�������interview
	int n,m;
	scanf("%d%d",&n,&m);
	int *id=new int[n];
	for(int i=0;i<n;i++)
		scanf("%d",&id[i]);

	Listnode *p= interview.trailer;
	p=interview.insertaspre(p,id[0]);//��һ������������
	for(int i=1;i<n;i++)//�������������ΰ���������
	{
		p=interview.insertaspre_m(id[i],m,p);
	}

	int r=interview.rank(p);
	for(int i=0;i<n-r;i++)  //������˳ʱ�����
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