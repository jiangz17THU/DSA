#pragma once
#define BinNodePosi(T) BinNode<T>* 
#define stature(p) ((p) ? (p)->height : -1) //节点高度（与“空树高度为-1”的约定相统一）
 
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
#define HasChild(x) ( HasLChild(x) || HasRChild(x) ) //至少拥有一个孩子
#define HasBothChild(x) ( HasLChild(x) && HasRChild(x) ) //同时拥有两个孩子
#define IsLeaf(x) ( ! HasChild(x) )


#define sibling(p) /*兄弟*/ \
   ( IsLChild( * (p) ) ? (p)->parent->rc : (p)->parent->lc )

#define uncle(x) /*叔叔*/ \
   ( IsLChild( * ( (x)->parent ) ) ? (x)->parent->parent->rc : (x)->parent->parent->lc )

#define FromParentTo(x) /*来自父亲的引用*/ \
   ( IsRoot(x) ? _root : ( IsLChild(x) ? (x).parent->lc : (x).parent->rc ) )


template <typename T> struct BinNode { //二叉树节点模板类
// 成员（为简化描述起见统一开放，读者可根据需要进一步封装）
	T data; //数值
	BinNodePosi(T) parent; BinNodePosi(T) lc; BinNodePosi(T) rc; //父节点及左、右孩子
	int height; //高度（通用） 
 // 构造函数
	BinNode() :
		parent(NULL), lc(NULL), rc(NULL), height(0) { }
	BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL,
		int h = 0) :
		data(e), parent(p), lc(lc), rc(rc), height(h) { }
	// 操作接口
	BinNodePosi(T) insertAsLC(T const&); //作为当前节点的左孩子插入新节点
	BinNodePosi(T) insertAsRC(T const&); //作为当前节点的右孩子插入新节点
};

template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const& e)
{
	return lc = new BinNode(e, this);
} //将e作为当前节点的左孩子插入二叉树

template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T const& e)
{
	return rc = new BinNode(e, this);
} //将e作为当前节点的右孩子插入二叉树

template <typename T> class BinTree   //仿照邓老师讲义
{
 protected:
	 int _size;  //规模
	 BinNodePosi(T) _root; //根节点
	 virtual int updateHeight(BinNodePosi(T) x); //更新节点x的高度
	 void updateHeightAbove(BinNodePosi(T) x); //更新节点x及其祖先的高度

 public:
	 BinTree() : _size(0), _root(NULL) { } //构造函数
	 ~BinTree() { if (0 < _size) remove(_root); } //析构函数
	 int size() const { return _size; } //规模
     bool empty() const { return !_root; } //判空
	 BinNodePosi(T) root() const { return _root; } //树根

	 BinNodePosi(T) insertAsRoot(T const& e); //插入根节点
	 BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e); //e作为x的左孩子（原无）插入
	 BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e); //e作为x的右孩子（原无）插入
	 BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T> * &T); //T作为x左子树接入
	 BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T> * &T); //T作为x右子树接入
	 int remove(BinNodePosi(T) x); //子树删除，返回该子树原先的规模
	
};

template <typename T> int BinTree<T>::updateHeight(BinNodePosi(T) x) //更新节点x高度
 { return x->height = 1 + max(stature(x->lc), stature(x->rc)); } //具体规则，因树而异
 
template <typename T> void BinTree<T>::updateHeightAbove(BinNodePosi(T) x) //更新高度
 { 
	while (x)
	{ 
		updateHeight(x); 
		x = x->parent; 
	} 
} //从x出发，覆盖历代祖先

template <typename T> BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e)
{ _size = 1; return _root = new BinNode<T>(e); } //将e当作根节点插入空的二叉树

template <typename T> BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const& e)
{ _size++; x->insertAsRC(e); updateHeightAbove(x); return x->rc; } //e插入为x的右孩子

template <typename T> BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const& e)
{ 
	_size++; x->insertAsLC(e); updateHeightAbove(x); return x->lc;
} 

template <typename T> //删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
int BinTree<T>::remove(BinNodePosi(T) x) { //assert: x为二叉树中的合法位置
	FromParentTo(*x) = NULL; //切断来自父节点的指针
	updateHeightAbove(x->parent); //更新祖先高度
	int n = removeAt(x); _size -= n; return n; //删除子树x，更新规模，返回删除节点总数
}
template <typename T> //删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
static int removeAt(BinNodePosi(T) x) { //assert: x为二叉树中的合法位置
	if (!x) return 0; //递归基：空树
	int n = 1 + removeAt(x->lc) + removeAt(x->rc); //递归释放左、右子树
	release(x->data); release(x); return n; //释放被摘除节点，并返回删除节点总数
}