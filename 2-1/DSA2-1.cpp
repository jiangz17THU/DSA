#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static int* action;
int count= 0;
//能够以1-n的次序驶出
bool ordered(int* a,int n,int m)
{
	ArrayStack S;
	int in = 0;
	int j = 1; //标记驶出的个数
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] == j)
		{
			j++;
			action[count] = a[i];
			count++;
			action[count] = 'P';
			count++;
		}
		else if (S.top()== j)
		{
			j++;
			action[count] = S.pop();
			count++;
			action[count] = 'O';
			count++;
			i--;
		}
		else
		{
			S.push(a[i]);
			action[count] = a[i];
			count++;
			action[count] = 'I';
			count++;
			in++;
			if (in > m)
				return false;
		}
	}
	
	if (S.size() <= m && S.flag == 1)
	{
		for (int i = S.size(); i > 0; i--)
		{
			action[count] = S.pop();
			count++;
			action[count] = 'O';
			count++;
		}
		return true;
	}
	else
		return false;
}


int main()
{
	int n, m;
	scanf_s("%d%d", &n, &m);
	int * a = new int[n];
	action = new int[(n + 2 * m)*2];
	
	for (int i = 0; i < n; i++)
		scanf_s("%d",&a[i]);
	if (!ordered(a, n, m))
		printf("No\n");
	else
	{
		for (int i = 0; i < count; i++)
		{
			printf("%d ", action[i]);
			i++;
			printf("%c\n", action[i]);
		}
	}
	
		return 0;
}