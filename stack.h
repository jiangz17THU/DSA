#ifndef STACK_H
#define STACK_H

class ArrayStack {
public:
	ArrayStack();
	~ArrayStack();
	void push(int t);//��ջ�����һ��tԪ��

	int pop();//��ջ��ɾ��һ��Ԫ��
	int size();//��С
	bool Empty();//�ж��Ƿ�Ϊ��
	int top();
	int flag;//�ж�ջ��Ԫ�صݼ�
private:
	int* arr;//����
	int count;
	int capacity;
	void expand();
};

// ������ջ����Ĭ�ϴ�С��10

ArrayStack::ArrayStack()
{
	arr = new int[10];
	capacity = 10;
	count = 0;
	flag = 1;
}
// ���١�ջ��

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

//��ջ�����һ��Ԫ��
void ArrayStack::push(int t)
{
	expand();
	arr[count] = t;
	if (count > 0 && t > arr[count - 1])
		flag = 0;
	count++;
}
// ���ء�ջ��Ԫ��ֵ��
int ArrayStack::top()
{
	return arr[count - 1];
}
// ���ء�ջ��Ԫ��ֵ������ɾ����ջ��Ԫ�ء�

int ArrayStack::pop()
{
	int ret = arr[count - 1];
	count--;
	return ret;
}
// ���ء�ջ���Ĵ�С

int ArrayStack::size()
{
	return count;
}
// ���ء�ջ���Ƿ�Ϊ��

bool ArrayStack::Empty()
{
	return size() == 0;
}

#endif 

