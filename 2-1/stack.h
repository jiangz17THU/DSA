#ifndef STACK_H
#define STACK_H

class ArrayStack {
public:
	ArrayStack();
	~ArrayStack();
	void push(int t);//向栈中添加一个t元素

	int pop();//在栈中删除一个元素
	int size();//大小
	bool Empty();//判断是否为空
	int top();
	int flag;//判断栈中元素递减
private:
	int* arr;//数组
	int count;
	int capacity;
	void expand();
};

// 创建“栈”，默认大小是10

ArrayStack::ArrayStack()
{
	arr = new int[10];
	capacity = 10;
	count = 0;
	flag = 1;
}
// 销毁“栈”

ArrayStack::~ArrayStack()
{
	if (arr)
	{
		delete[] arr;
		arr = nullptr;
	}
}

void ArrayStack::expand()
{
	if (count < capacity - 1)
		return;
	if (count == capacity - 1)
	{
		int* oldarr = arr;
		arr = new int[capacity <<= 1];
		for (int i = 0; i < count; i++)
			arr[i] = oldarr[i];
		delete[] oldarr;
	}

}

//向栈中添加一个元素
void ArrayStack::push(int t)
{
	expand();
	arr[count] = t;
	if (count > 0 && t > arr[count - 1])
		flag = 0;
	count++;
}
// 返回“栈顶元素值”
int ArrayStack::top()
{
	return arr[count - 1];
}
// 返回“栈顶元素值”，并删除“栈顶元素”

int ArrayStack::pop()
{
	int ret = arr[count - 1];
	count--;
	return ret;
}
// 返回“栈”的大小

int ArrayStack::size()
{
	return count;
}
// 返回“栈”是否为空

bool ArrayStack::Empty()
{
	return size() == 0;
}

#endif 

