#pragma once
#define BinNodePosi(T) BinNode<T>* 
#define stature(p) ((p) ? (p)->height : -1) //�ڵ�߶ȣ��롰�����߶�Ϊ-1����Լ����ͳһ��
 
template <typename T> struct Cleaner {
	static void clean(T x) { 
	}
};

template <typename T> struct Cleaner<T*> {
	static void clean(T* x) {
		if (x) { delete x; } 
	}
};

template <typename T> void release(T x) { Cleaner<T>::clean(x); }

#define IsRoot(x) ( ! ( (x).parent ) )
#define IsLChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->lc ) )
#define IsRChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->rc ) )
#define HasParent(x) ( ! IsRoot(x) )
#define HasLChild(x) ( (x).lc )
#define HasRChild(x) ( (x).rc )
#define HasChild(x) ( HasLChild(x) || HasRChild(x) ) //����ӵ��һ������
#define HasBothChild(x) ( HasLChild(x) && HasRChild(x) ) //ͬʱӵ����������
#define IsLeaf(x) ( ! HasChild(x) )


#define sibling(p) /*�ֵ�*/ \
   ( IsLChild( * (p) ) ? (p)->parent->rc : (p)->parent->lc )

#define uncle(x) /*����*/ \
   ( IsLChild( * ( (x)->parent ) ) ? (x)->parent->parent->rc : (x)->parent->parent->lc )

#define FromParentTo(x) /*���Ը��׵�����*/ \
   ( IsRoot(x) ? _root : ( IsLChild(x) ? (x).parent->lc : (x).parent->rc ) )


template <typename T> struct BinNode { //�������ڵ�ģ����
// ��Ա��Ϊ���������ͳһ���ţ����߿ɸ�����Ҫ��һ����װ��
	T data; //��ֵ
	BinNodePosi(T) parent; BinNodePosi(T) lc; BinNodePosi(T) rc; //���ڵ㼰���Һ���
	int height; //�߶ȣ�ͨ�ã� 
 // ���캯��
	BinNode() :
		parent(NULL), lc(NULL), rc(NULL), height(0) { }
	BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL,
		int h = 0) :
		data(e), parent(p), lc(lc), rc(rc), height(h) { }
	// �����ӿ�
	BinNodePosi(T) insertAsLC(T const&); //��Ϊ��ǰ�ڵ�����Ӳ����½ڵ�
	BinNodePosi(T) insertAsRC(T const&); //��Ϊ��ǰ�ڵ���Һ��Ӳ����½ڵ�
};

template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const& e)
{
	return lc = new BinNode(e, this);
} //��e��Ϊ��ǰ�ڵ�����Ӳ��������

template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T const& e)
{
	return rc = new BinNode(e, this);
} //��e��Ϊ��ǰ�ڵ���Һ��Ӳ��������

template <typename T> class BinTree   //���յ���ʦ����
{
 protected:
	 int _size;  //��ģ
	 BinNodePosi(T) _root; //���ڵ�
	 virtual int updateHeight(BinNodePosi(T) x); //���½ڵ�x�ĸ߶�
	 void updateHeightAbove(BinNodePosi(T) x); //���½ڵ�x�������ȵĸ߶�

 public:
	 BinTree() : _size(0), _root(NULL) { } //���캯��
	 ~BinTree() { if (0 < _size) remove(_root); } //��������
	 int size() const { return _size; } //��ģ
     bool empty() const { return !_root; } //�п�
	 BinNodePosi(T) root() const { return _root; } //����

	 BinNodePosi(T) insertAsRoot(T const& e); //������ڵ�
	 BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e); //e��Ϊx�����ӣ�ԭ�ޣ�����
	 BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e); //e��Ϊx���Һ��ӣ�ԭ�ޣ�����
	 BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T> * &T); //T��Ϊx����������
	 BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T> * &T); //T��Ϊx����������
	 int remove(BinNodePosi(T) x); //����ɾ�������ظ�����ԭ�ȵĹ�ģ
	
};

template <typename T> int BinTree<T>::updateHeight(BinNodePosi(T) x) //���½ڵ�x�߶�
 { return x->height = 1 + max(stature(x->lc), stature(x->rc)); } //���������������
 
template <typename T> void BinTree<T>::updateHeightAbove(BinNodePosi(T) x) //���¸߶�
 { 
	while (x)
	{ 
		updateHeight(x); 
		x = x->parent; 
	} 
} //��x������������������

template <typename T> BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e)
{ _size = 1; return _root = new BinNode<T>(e); } //��e�������ڵ����յĶ�����

template <typename T> BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const& e)
{ _size++; x->insertAsRC(e); updateHeightAbove(x); return x->rc; } //e����Ϊx���Һ���

template <typename T> BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const& e)
{ 
	_size++; x->insertAsLC(e); updateHeightAbove(x); return x->lc;
} 

template <typename T> //ɾ����������λ��x���Ľڵ㼰���������ر�ɾ���ڵ����ֵ
int BinTree<T>::remove(BinNodePosi(T) x) { //assert: xΪ�������еĺϷ�λ��
	FromParentTo(*x) = NULL; //�ж����Ը��ڵ��ָ��
	updateHeightAbove(x->parent); //�������ȸ߶�
	int n = removeAt(x); _size -= n; return n; //ɾ������x�����¹�ģ������ɾ���ڵ�����
}
template <typename T> //ɾ����������λ��x���Ľڵ㼰���������ر�ɾ���ڵ����ֵ
static int removeAt(BinNodePosi(T) x) { //assert: xΪ�������еĺϷ�λ��
	if (!x) return 0; //�ݹ��������
	int n = 1 + removeAt(x->lc) + removeAt(x->rc); //�ݹ��ͷ���������
	release(x->data); release(x); return n; //�ͷű�ժ���ڵ㣬������ɾ���ڵ�����
}