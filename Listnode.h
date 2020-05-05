# ifndef LISTNODE_H
# define LISTNODE_H
# define post(T) Listnode *

  struct Listnode
 {
	 post(T) pre;
   	 post(T) next;
	 int data;
	 //¹¹Ôìº¯Êý
	 Listnode(){}
	 Listnode(int e,post(T) s=NULL,post(T)p=NULL):data(e),pre(s),next(p){}
  };
# endif
   