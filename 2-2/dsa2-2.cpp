#include<stdio.h>
#include"stack.h"

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	int n, m,max1,max2,count=0;
	
	scanf_s("%d%d", &n, &m);
	int** num = new int* [m];
	for (int i = 0; i < m; i++)
		num[i] = new int[n];
	scanf_s("%d%d", &max1, &max2);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			scanf_s("%d", &num[i][j]);	
	}
	
	int** s1 = new int* [m];
	for (int i = 0; i < m; i++)
		s1[i] = new int[n];
	for (int i = 0; i < m; i++)
	{
		ArrayStack S1;
		for (int j = 0; j < n; j++)
		{
			while (!S1.Empty() && num[i][S1.top()] == 1&&num[i][j]==1)
				S1.pop();
			if(num[i][j]==0)
			{
				S1.push(j);
				s1[i][j] = -1;
				continue;
			}
			if (S1.Empty())
				s1[i][j] = 0;
			else
			{
				if (num[i][j - 1] == 1)
					s1[i][j] = s1[i][j - 1];
				
				else 
				{
					S1.push(j);
					s1[i][j] = S1.top();
				}
			}
			S1.push(j);

			if (s1[i][j] != -1)
			{
				int temp = j+1-s1[i][j];
				for (int k = i; i-k<max2&&k>=0; k--)
				{
					if (s1[k][j] == -1)
						break;
					else if (j + 1 - s1[k][j] > max1)
						temp = max1;	
					temp = min(j+1-s1[k][j], temp);
					count += temp;
				}
			}
		}
	}
	printf("%d", count%10007);
	return 0;
}