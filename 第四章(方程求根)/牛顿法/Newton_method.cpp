#include <iostream>
#include <math.h>
using namespace std;

double function(double x)
{
	return pow(x,3)+2*pow(x,2)+10*x-20;
}

double function_d(double x)
{
	return 3*pow(x,2)+4*x+10;
}

/**
 *@name Newton_method��ţ�ٷ�
 *@param1 x0�������ĳ�ʼֵ
 *@param2 e�������������
**/
double Newton_method(double x0,double e)
{
	double xk=x0;
	double xk1;
	double error=100;
	while(fabs(error)>e)
	{
		if(fabs(function_d(xk))>1e-3)
		{
			//ţ�ٷ���ʽ
			xk1=xk-function(xk)/function_d(xk);
			//�������
			error=xk1-xk;
			//������һ�ֵĵ���
			xk=xk1;

			cout<<"the xk1 is "<<xk1<<endl;
		}
		else
		{
			cout<<"error div number is 0"<<endl;
			return 0;
		}
	}
	return xk1;
}

double Newton_down_method(double x0,double e,double lamda_limit)
{
	double lamda=1;
	double xk=x0;
	double xk1;
	double error=100;
	unsigned char down_flag=0;
	while(fabs(error)>e)
	{
		if(fabs(function_d(xk))>1e-3)
		{
			//ţ�ٷ�����
			xk1=xk-lamda*function(xk)/function_d(xk);

			//����δ�ɹ���ɽ ���������ж�
			if(down_flag==0)
			{
				//�ж��Ƿ�ɹ���ɽ
				if(fabs(function(xk1))<fabs(function(xk)))
				{
					down_flag=1;
					cout<<"go down successful!"<<endl;
				}
			}

			if(down_flag==0)
			{
				//�ж�lamda�Ƿ�Խ��
				if(lamda<lamda_limit)
				{
					cout<<"please choose another x0 "<<endl;
					return 0;
				}
				else
					lamda=lamda/2;
			}

			//�ж���� ��������һ�ֵ���
			error=xk1-xk;
			xk=xk1;
			cout<<"the xk1 is "<<xk1<<" the lamda is "<<lamda<<endl;
		}
		else
		{
			cout<<"error div number is 0"<<endl;
			return 0;
		}
	}
	return xk1;
}

void main()
{
	cout<<"ţ�ٷ����"<<endl;
	Newton_method(1,1e-6);
	cout<<"ţ����ɽ�����"<<endl;
	Newton_down_method(1,1e-6,0.02);
	system("pause");
}