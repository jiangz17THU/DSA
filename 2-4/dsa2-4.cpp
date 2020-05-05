#include <stdio.h>


void rebuild0(int* pre_order, int pre_header, int pre_trailer //先序遍历，标记首尾位置0~n-1
	, int* post_order, int post_header, int post_trailer //后序遍历，标记首尾位置0~n-1
	, int* in_order, int in_header, int in_trailer)     //中序遍历，标记首尾位置0~n-1
{
	if (pre_header == pre_trailer) //递归基
		in_order[in_header] = pre_order[pre_header];
	else
	{
		int boundary = 0; //将后序遍历根节点的左孩子所在位置标记为boundary
		while (post_order[post_header + boundary] != pre_order[pre_header + 1])
			boundary++;
		in_order[in_header+boundary + 1] = pre_order[pre_header];
		rebuild0(pre_order, pre_header + 1, pre_header + 1 + boundary,
			     post_order, post_header, post_header + boundary,
			     in_order, in_header, in_header + boundary);
		rebuild0(pre_order, pre_header + boundary + 2, pre_trailer,
				post_order, post_header + boundary + 1, post_trailer - 1,
				in_order, in_header + boundary + 2, in_trailer);
	}
}

void rebuild1(int* pre_order, int pre_header, int pre_trailer,
	int* in_order, int in_header, int in_trailer,
	int* post_order, int post_header, int post_trailer)
{
	if (pre_header == pre_trailer) //递归基
		post_order[post_header] = pre_order[pre_header];
	else
	{
		int boundary = 0;  //将中序遍历的根节点作为boundary
		while (in_order[in_header + boundary] != pre_order[pre_header])
			boundary++;
		post_order[post_trailer] = pre_order[pre_header];
		rebuild1(pre_order, pre_header + 1, pre_header + boundary,
			in_order, in_header, in_header + boundary - 1,
			post_order, post_header, post_header + boundary - 1);

		rebuild1(pre_order, pre_header + boundary + 1, pre_trailer,
			in_order, in_header + boundary + 1, in_trailer,
			post_order, post_header + boundary, post_trailer - 1);
	}
}

void rebuild2(int* in_order, int in_header, int in_trailer,
	int* post_order, int post_header, int post_trailer,
	int* pre_order, int pre_header, int pre_trailer)
{
	if (pre_header == pre_trailer) //递归基
		pre_order[pre_header] = post_order[post_trailer];
	else
	{
		int boundary = 0;  //将中序遍历的根节点作为boundary
		while (in_order[in_header + boundary] != post_order[post_trailer])
			boundary++;
		pre_order[pre_header] = post_order[post_trailer];
		rebuild2(in_order, in_header, in_header + boundary - 1,
			post_order, post_header, post_header + boundary - 1,
			pre_order, pre_header + 1, pre_header + boundary);

		rebuild2(in_order, in_header + boundary + 1, in_trailer,
			post_order, post_header + boundary, post_trailer - 1,
			pre_order, pre_header + boundary + 1, pre_trailer);
	}
}



int main()
{
	int n, k;
	scanf_s("%d%d", &n, &k);
	if (k == 0)
	{
		int* pre_order = new int[n];
		for (int i = 0; i < n; i++)  scanf_s("%d", &pre_order[i]);
		int* post_order = new int[n];
		for (int i = 0; i < n; i++)  scanf_s("%d", &post_order[i]);
		int* in_order = new int[n];
		rebuild0(pre_order, 0, n - 1, post_order, 0, n - 1, in_order, 0, n - 1);
		for (int i = 0; i < n; i++)  printf("%d ", in_order[i]);
		
	}

	if (k == 1)
	{
		int* pre_order = new int[n];
		for (int i = 0; i < n; i++)  scanf_s("%d", &pre_order[i]);
		int* in_order = new int[n];
		for (int i = 0; i < n; i++)  scanf_s("%d", &in_order[i]);
		int* post_order = new int[n];
		rebuild1(pre_order, 0, n - 1, in_order, 0, n - 1, post_order, 0, n - 1);
		for (int i = 0; i < n; i++)  printf("%d ", post_order[i]);
	}

	if (k == 2)
	{
		int* in_order = new int[n];
		for (int i = 0; i < n; i++)  scanf_s("%d", &in_order[i]);
		int* post_order = new int[n];
		for (int i = 0; i < n; i++)  scanf_s("%d", &post_order[i]);
		int* pre_order = new int[n];
		rebuild2(in_order, 0, n - 1, post_order, 0, n - 1, pre_order, 0, n - 1);
		for (int i = 0; i < n; i++)  printf("%d ", pre_order[i]);
	}

	if (k == 3)
	{
		 
	}
	return 0;
}


