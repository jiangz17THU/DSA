#include<stdio.h>
#include "bintree.h"
  

#define node mutitreenode*
class mutitreenode
{
public:
	int data;
	int depth;  //深度
	
	mutitreenode* oldchild;//长子
	mutitreenode* nextsibling; //右兄弟
	//构造函数
	mutitreenode() 
	{
		data = 0; depth = 1; oldchild = NULL; nextsibling = NULL;
	}
	mutitreenode(int a,int b,node c,node d ):data(a),depth(b),oldchild(c),nextsibling(d) {} 
};
class mutitree
{
public:
	mutitreenode root;
	mutitree()
	{
		root.data = 1;   root.depth = 1;
		root.nextsibling = NULL;   root.oldchild = NULL;
	}
	node insertAsoc(node x, int e) //在x处插入长子e
	{
		node oc;
		return oc = new mutitreenode(e, x->depth + 1, NULL, NULL);
		x->oldchild = oc;
	}
	node insertAsnb(node x, int e) //在x处插入右兄弟e
	{
		node nb;
		return nb = new mutitreenode(e, x->depth, NULL, NULL);
		x->nextsibling = nb;
	}
	
};
int main()
{
	int N, M;
	scanf_s("%d%d", &N, &M);
	int* childnum = new int[N];
	mutitree tree;
	node p = &tree.root;
	node p0 = NULL;
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &childnum[i]);
		for(int j=0;j<childnum[i];j++)
		{
			int id;
			scanf_s("%d", &id);
			if (j == 0)
				p = tree.insertAsoc(p, id);
			else
				p=tree.insertAsnb(p, id);
			if (id == i + 2)
				p0 = p;
		}
		if (p0)
			p = p0;
		else
			p = new mutitreenode(i + 2, 1, NULL, NULL);
	}
	return 0;
}