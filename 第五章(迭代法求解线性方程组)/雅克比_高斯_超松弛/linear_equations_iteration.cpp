#include <iostream>
#include <cmath>
using namespace std;

//����ϵ������ͽ������
double A[2][2]={{3,1},{1,2}};
double b[2]={2,1};
double x[2]={10,10};
double x1[2];

//�ҵ��������е����ֵ
double Max(double* x)
{
	double temp=x[0];
	for(int i=1;i<2;i++)
	{
		if(temp<x[i])
			temp=x[i];
	}
	return temp;
}

//��ӡx����
void Print_vector(double* x)
{
	for(int i=0;i<2;i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

//��ʼ��x0
void Init_vector(double* x)
{
	for (int i=0;i<2;i++)
	{
		x[i]=10;
	}
}

/**
 *@name Jacobi_iteration���ſ˱ȵ��������������
 *@param1 x����ʼ������x
 *@param2 x1���������������
 *@param3 error������ֹͣ�ľ�����
**/
void Jacobi_iteration(double* x,double* x1,double error)
{
	double temp=0;
	double delta=100;
	while(fabs(delta)>error)
	{
		//���ݵ�����ʽ���м���
		for (int i=0;i<2;i++)
		{
			//ÿһ�������м����temp�洢�������
			temp=0;
			for (int j=0;j<2;j++)
			{
				if(i!=j)
					temp+=1/A[i][i]*(b[i]-A[i][j]*x[j]);
			}
			x1[i]=temp;
		}

		//��ӡ��һ�ֵĽ���������������
		Print_vector(x1);
		delta=Max(x1)-Max(x);

		//��x1����x��������һ�ֵ���
		for(int i=0;i<2;i++)
		{
			x[i]=x1[i];
		}
	}
}

/**
*@name Jacobi_iteration����˹���������������
*@param1 x����ʼ������x
*@param2 x1���������������
*@param3 error������ֹͣ�ľ�����
**/
void Gaussian_iteration(double* x,double* x1,double error)
{
	double temp=0;
	double delta=100;
	double max_x;
	while(fabs(delta)>error)
	{
		max_x=Max(x);
		//���ø�˹���������е���
		for(int i=0;i<2;i++)
		{
			temp=0;
			for(int j=0;j<2;j++)
			{
				if(i!=j)
					temp+=1/A[i][i]*(b[i]-A[i][j]*x[j]);
			}
			x1[i]=x[i]=temp;
		}

		//��ӡ��һ�ֵ����Ľ�����
		Print_vector(x1);
		delta=Max(x1)-max_x;

	}
}

void Super_loose(double* x,double* x1,double error,double w)
{
	double temp=0;
	double delta=100;
	double max_x;
	double temp_x[2];
	while(fabs(delta)>error)
	{
		//���仯ǰ��x������
		max_x=Max(x);
		for(int i=0;i<2;i++)
		{
			temp_x[i]=x[i];
		}

		//���ø�˹���������е���
		for(int i=0;i<2;i++)
		{
			temp=0;
			for(int j=0;j<2;j++)
			{
				if(i!=j)
					temp+=1/A[i][i]*(b[i]-A[i][j]*x[j]);
			}
			x1[i]=x[i]=temp;
		}

		//���ɳڼ�Ȩ
		for(int i=0;i<2;i++)
		{
			x1[i]=w*x1[i]+(1-w)*temp_x[i];
		}

		//��ӡ��һ�ֵ����Ľ�����
		Print_vector(x1);
		delta=Max(x1)-max_x;
	}
}

void main()
{
	cout<<"the Jacobi_iteration is "<<endl;
	Jacobi_iteration(x,x1,1e-4);
	Init_vector(x);
	cout<<"\nthe Gaussian_iteration is "<<endl;
	Gaussian_iteration(x,x1,1e-4);
	Init_vector(x);
	cout<<"\nthe Super_loose(w=1.5) is "<<endl;
	Super_loose(x,x1,1e-4,1.5);
	system("pause");
}