// Structure_study.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <time.h>
#include <stack>
#include <queue>
using namespace std;

void PrintN_1(int N)
{
	for (int i = 1; i <= N; i++)
	{
		printf("%d\n",i);
	}
	return ;
}
void PrintN_2(int N)
{
	if (N)
	{
		PrintN_2(N - 1);
		printf("%d\n", N);
	}
	return;
}
//Test PrintN
int main1()
{
	PrintN_1(100000);
	system("pause");
    return 0;
}

double f1(int n, double a[], double x)
{
	double p = a[0];
	for (int i = 1; i <= n; i++)
	{
		p += a[i] * (pow(x, i));
		return p;
	}
}
double f2(int n, double a[], double x)
{
	double p = a[n];
	for (int i = n-1; i >= 0; i--)
	{
		p = a[i] + x*p;
		return p;
	}
}
//Test clock()
int main2()
{
	cout << CLK_TCK << endl;
	system("pause");
	return 0;
}

//������к����� O(n^3)
int MaxSubseqSum1(int A[], int N)
{
	int MaxSum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			int ThisSum = 0;
			for (int k = i; k <= j; k++)
			{
				ThisSum += A[k];
			}
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}
//��ʵ ����Ҫѭ��3�� kѭ�����Խ�ʡ O(n^2)
int MaxSubseqSum2(int A[], int N)
{
	int MaxSum = 0;
	for (int i = 0; i < N; i++)
	{
		int ThisSum = 0;
		for (int j = i; j < N; j++)
		{
			ThisSum += A[j];
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}
//�ֶ���֮ O(n*log(n))
int MaxSubseqSum3(int A[], int N)
{
	if (N == 1)
	{
		return A[0];
	}
	else
	{
		int N1, N2;
		if (N % 2 == 0)
			N1 = N2 = N / 2;
		else
		{
			N1 = N / 2;
			N2 = N / 2 + 1;
		}
		int lMax = MaxSubseqSum3(A, N1);
		int* B = &A[N / 2];
		int rMax = MaxSubseqSum3(B, N2);

		int midMax;
		int midMax_l = 0;
		int midSum_l = 0;
		for (int i = N1 - 1; i >= 0; i--)
		{
			midSum_l += A[i];
			if (midSum_l > midMax_l)
				midMax_l = midSum_l;
		}
		int midMax_r = 0;
		int midSum_r = 0;
		for (int i = 0; i < N2; i++)
		{
			midSum_r += B[i];
			if (midSum_r > midMax_r)
				midMax_r = midSum_r;
		}
		midMax = midMax_l + midMax_r;
		int Max = rMax;
		if (lMax > Max)
			Max = lMax;
		if (midMax > Max)
			Max = midMax;
		return Max;
	}
}
//���и��õİ취���� 0(n) ���ߴ��� ���Ա߶��߼��� 
int MaxSubseqSum4(int A[], int N)
{
	int ThisSum, MaxSum;
	int i;
	ThisSum = MaxSum = 0;
	for (int i = 0; i < N; i++)
	{
		ThisSum += A[i];
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if (ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;
}
#define MAX 1000
int main3()
{
	int N = 0;
	int A[MAX];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	cout << MaxSubseqSum3(A, N) << endl;
	system("pause");
	return 0;
}

#define MAXSIZE 1000
#define ElementType int
typedef struct {
	ElementType Data[MAXSIZE];
	int Last;
}List;
//��ʼ��
List *MakeEmpty()
{
	List *PtrL;
	PtrL = (List*)malloc(sizeof(List));
	PtrL->Last = -1;
	return PtrL;
}

#include <stdio.h>
int main4()
{
	union number
	{ /* ����һ������ */
		int i;
		struct
		{ /* �������ж���һ���ṹ */
			char first;
			char second;
		}half;
	}num;
	num.i = 0x4241; /* ���ϳ�Ա��ֵ */
	printf("%c%c\n", num.half.first, num.half.second);
	num.half.first = 'a'; /* �����нṹ��Ա��ֵ */
	num.half.second = 'b';
	printf("%x\n", num.i);
	getchar();
	return 0;
}

//�����
typedef struct GNode {
	int Tag; //��־��0Ϊ��Ԫ�� 1Ϊ�����
	union { //�ӱ�ָ����Sublist�뵥Ԫ��������Data���ã������ô洢�ռ�
		ElementType Data;
		struct GNode *SubList;
	}URegion;
	struct GNode *Next;
}GList;

#define MAXSIZE 1000
struct DStack {
	ElementType Data[MAXSIZE];
	int Top1;
	int Top2;
}S;

//��׺���ʽ���� + - * / ����

#define ElementType int
#define MAXSIZE 10
#define ERROR -1
//ѭ�����м������
struct Queue {
	ElementType Data[MAXSIZE];
	int front;
	int rear;
};
void AddQ(Queue *PtrQ, ElementType item)
{
	if ((PtrQ->rear + 1) % MAXSIZE == PtrQ->front)
	{
		printf("������");
		return;
	}
	PtrQ->rear = (PtrQ->rear + 1) % MAXSIZE;
	PtrQ->Data[PtrQ->rear] = item;
}
ElementType DeleteQ(Queue *PtrQ)
{
	if (PtrQ->rear == PtrQ->front)
	{
		printf("���п�");
		return ERROR;
	}
	PtrQ->front = (PtrQ->front + 1) % MAXSIZE;
	return PtrQ->Data[PtrQ->front];
}

//���е���ʽ�洢ʵ��
typedef struct Node {
	ElementType Data;
	struct Node *Next;
}QNode;
typedef struct {
	QNode *rear;
	QNode *front;
}LinkQueue;
//����ͷ�ڵ����ʽ���г��Ӳ���
ElementType DeleteQ(LinkQueue *PtrQ)
{
	QNode *FrontCell;
	ElementType FrontElem;

	if (PtrQ->front == NULL)
	{
		printf("���п�");
		return ERROR;
	}
	FrontCell = PtrQ->front;
	if (PtrQ->front == PtrQ->rear)
		PtrQ->front = PtrQ->rear = NULL;
	else
		PtrQ->front = PtrQ->front->Next;
	FrontElem = FrontCell->Data;
	free(FrontCell);
	return FrontElem;
}

//������ ��dataΪchar��
typedef struct TNode {
	char Data;
	TNode* l_childern;
	TNode* r_childern;
}Tree;
Tree* CreateTree(char data)
{
	Tree* tree = (Tree*)malloc(sizeof(TNode));
	tree->Data = data;
	tree->l_childern = NULL;
	tree->r_childern = NULL;
	return tree;
}
//ǰ�� �ݹ�
void PreOrderTraversal(TNode* node)
{
	if (node)
	{
		cout << node->Data << " ";
		PreOrderTraversal(node->l_childern);
		PreOrderTraversal(node->r_childern);
	}
	return;
}
//���� �ݹ�
void InOrderTraversal(TNode* node)
{
	if (node)
	{
		InOrderTraversal(node->l_childern);
		cout << node->Data << " ";
		InOrderTraversal(node->r_childern);
	}
	return;
}
//���� �ݹ�
void PostOrderTraversal(TNode* node)
{
	if (node)
	{
		PostOrderTraversal(node->l_childern);
		PostOrderTraversal(node->r_childern);
		cout << node->Data << " ";
	}
	return;
}
//ǰ�� ��ջ
void PreOrderTraversal_2(TNode* tree)
{
	TNode* node = tree;
	stack<TNode*> temp;
	while (node != NULL || !temp.empty())
	{
		while (node)
		{
			temp.push(node);
			cout << node->Data << " ";
			node = node->l_childern;
		}
		if (!temp.empty())
		{
			node = temp.top();
			temp.pop();
			node = node->r_childern;
		}
	}
	cout << endl;
}
//���� ��ջ
void InOrderTraversal_2(TNode* tree)
{
	TNode* node = tree;
	stack<TNode*> temp;
	while (node != NULL || !temp.empty())
	{
		while (node)
		{
			temp.push(node);
			node = node->l_childern;
		}
		if (!temp.empty())
		{
			node = temp.top();
			temp.pop();
			cout << node->Data << " ";
			node = node->r_childern;
		}
	}
	cout << endl;
}
//���� ��ջ
typedef struct SType
{
	TNode *ptr;
	bool status;// ��ջ��־  
}SType;
void PostOrderTraversal_2(TNode* tree)
{
	stack<SType> S;
	TNode* p = tree;
	SType temp;
	while (p || !S.empty())
	{
		if (p)
		{
			temp.status = false;
			temp.ptr = p;
			S.push(temp);
			p = p->l_childern;
		}
		else
		{
			if (!S.empty())
			{
				temp = S.top();
				S.pop();
				p = temp.ptr;
				if (temp.status)
				{
					cout << p->Data << " ";
					p = NULL;
				}
				else
				{
					temp.status = true;
					S.push(temp);
					p = p->r_childern;
				}
			}
		}
	}
	cout << endl;
}
//��α��� ����
void LevelOrderTraversal(TNode* tree)
{
	if (!tree)
		return;
	queue<TNode*> q;
	TNode* p = tree;
	q.push(p);
	while (!q.empty())
	{
		p = q.front();
		cout << p->Data << " ";
		q.pop();
		if (p->l_childern)
			q.push(p->l_childern);
		if (p->r_childern)
			q.push(p->r_childern);
	}
	cout << endl;
}
void addTNode(char data, TNode* parent, int flag = 0)
{
	TNode* node = (TNode*)malloc(sizeof(TNode));
	node->Data = data;
	node->l_childern = NULL;
	node->r_childern = NULL;
	if (parent == NULL)
	{
		cout << "���ʧ��" << endl;
		return;
	}
	if (!flag)
		parent->l_childern = node;
	else
		parent->r_childern = node;
	return;
}

int main()
{
	//������
	Tree* tree = CreateTree('A');
	addTNode('B', tree, 0);
	addTNode('C', tree, 1);
	addTNode('D', tree->l_childern, 0);
	addTNode('F', tree->l_childern, 1);
	addTNode('E', tree->l_childern->r_childern, 0);
	addTNode('G', tree->r_childern, 0);
	addTNode('I', tree->r_childern, 1);
	addTNode('H', tree->r_childern->l_childern, 1);

	//����
	cout << "ǰ�򣨵ݹ飩: ";
	PreOrderTraversal(tree);
	cout << endl;
	cout << "���򣨵ݹ飩: ";
	InOrderTraversal(tree);
	cout << endl;
	cout << "���򣨵ݹ飩: ";
	PostOrderTraversal(tree);
	cout << endl;
	cout << "ǰ�򣨶�ջ��: ";
	PreOrderTraversal_2(tree);
	cout << "���򣨶�ջ��: ";
	InOrderTraversal_2(tree);
	cout << "���򣨶�ջ��: ";
	PostOrderTraversal_2(tree);
	cout << "��Σ����У�: ";
	LevelOrderTraversal(tree);
	system("pause");
	return 0;
}
























































































































































































































































































































