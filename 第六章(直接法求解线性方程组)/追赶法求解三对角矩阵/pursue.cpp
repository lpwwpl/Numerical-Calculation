#include <iostream>
#include <cmath>
using namespace std;

double A[4][4]={{2,-1,0,0},{-1,3,-2,0},{0,-1,2,-1},{0,0,-3,5}};
double B[4]={6,1,0,1};
double L[4][4]={0};			//A�ֽ�õ��������Ǿ���
double U[4][4]={0};			//A�ֽ�õ��������Ǿ���
double a[4];		//����ϵ������A
double b[4];	//����ϵ������A
double c[3];		//����ϵ������A
double d[4];
double u[3];

/**
 *@name Resolve_matrix���ֽ����õ�A=LU 
**/
void Resolve_matrix()
{
	//������ϵ������
	for (int i=0;i<4;i++)
	{
		b[i]=A[i][i];
		if (i<3)
		{
			a[i+1]=A[i+1][i];
			c[i]=A[i][i+1];
		}
	}

	//���ݹ�ʽ����L��U�еĸ���ϵ��
	d[0]=b[0];
	for (int i=0;i<3;i++)
	{
		u[i]=c[i]/d[i];
		d[i+1]=b[i+1]-u[i]*a[i+1];
	}
	

	//�õ�U
	for (int i=0;i<4;i++)
	{
		U[i][i]=1;		//�Խ���Ԫ��ȫΪ1

		if(i<3)			//�Խ�����һ��Ϊu
		{
			U[i][i+1]=u[i];
		}
	}

	//�õ�L
	for (int i=0;i<4;i++)
	{
		L[i][i]=d[i];		//�Խ���Ԫ�ص�ֵ

		if (i<3)				//�Խ�����һ��Ϊa
		{
			L[i+1][i]=a[i+1];
		}
	}

	//��ӡU
	cout<<"it's U matrix "<<endl;
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			cout<<U[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;

	//��ӡL
	cout<<"it's L matrix "<<endl;
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			cout<<L[i][j]<<" ";
		}
		cout<<endl;
	}
}

/**
 *@name Solve_matrix�������� Ly=b Ux=y
**/
void Solve_matrix()
{
	double y[4];
	//�õ�y�����Ľ�
	y[0]=B[0]/d[0];
	for (int i=1;i<4;i++)
	{
		y[i]=(B[i]-a[i]*y[i-1])/d[i];
	}
	/*
	for (int i=0;i<4;i++)
	{
		cout<<y[i]<<" ";
	}
	cout<<endl;*/

	double x[4];
	//�õ�x������ֵ
	x[3]=y[3];
	for (int i=2;i>=0;i--)
	{
		x[i]=y[i]-u[i]*x[i+1];
	}
	
	//���������x
	cout<<"�������Ϊ"<<endl;
	for (int i=0;i<4;i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

void main()
{
	Resolve_matrix();
	cout<<endl;
	Solve_matrix();
	system("pause");
}