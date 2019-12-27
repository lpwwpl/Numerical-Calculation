#include<iostream>
using namespace std;
const int len =5;													//���������ĳ���

double res[2]={0};											//��С���˷���õĻع�ϵ��
double A[2][2]={0};											//��С���˷���Ӧ��ϵ������
double b[2]={0};												//��С���˷���Ӧ���Ҷ�����
double x[5]={165,123,150,123,141};				//���ݵ�x����
double y[5]={187,126,172,125,148};				//���ݵ�y����


/**
 *@name Build_matrix��������С���˷���Ҫ�ľ���
**/
void Build_matrix()
{
	//������С���˷���Ӧ��ϵ������
	A[0][0]=len;

	for (int i=0;i<len;i++)
	{
		A[0][1]+=x[i];
		A[1][1]+=x[i]*x[i];
	}
	A[1][0]=A[0][1];

	//������С���˷���Ӧ���Ҷ�����
	for (int i=0;i<len;i++)
	{
		b[0]+=y[i];
		b[1]+=x[i]*y[i];
	}

	/*
	//��ӡϵ������A
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<2;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<endl;

	//��ӡ�Ҷ�����b
	for (int i=0;i<2;i++)
	{
		cout<<b[i]<<" ";
	}*/
}

/**
 *@name Least_square_method��������С���˷����ع�ϵ��
 *@param1 A����С���˷���Ӧ��ϵ������
**/
void  Least_square_method(double A[2][2],double b[2])
{
	res[0]=(A[0][1]*b[1]-b[0]*A[1][1])/(A[0][1]*A[1][0]-A[0][0]*A[1][1]);
	res[1]=(A[1][0]*b[0]-A[0][0]*b[1])/(A[0][1]*A[1][0]-A[0][0]*A[1][1]);
}

void main()
{
	Build_matrix();
	Least_square_method(A,b);
	cout<<"the line is y="<<res[0]<<"+"<<res[1]<<"x"<<endl;
	system("pause");
}