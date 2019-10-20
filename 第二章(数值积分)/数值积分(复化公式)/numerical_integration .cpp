#include <iostream>
#include <cmath>
using namespace std;

//���غ���ֵ
/**
 *@name function��������ֵ���ֵĺ���
 *@param1 x�������xֵ
**/
double function(double x)
{
	return 1+exp(-x)*sin(4*x);
}

/**
 *@name Cotes���������ι�ʽ
 *@param1 below����������
 *@param2 upper����������
 *@param3 n������������ĸ���
**/
double trapezoid(double below,double upper,int n)
{
	double h=(upper-below)/n;
	double x=below;
	double S=0;
	for (int i=1;i<n;i++)
	{
		//�����ڲ����ڵ�ĺ���ֵ 1~(n-1)
		x+=h;
		S+=function(x);
	}
	return (h/2)*(2*S+function(below)+function(upper));
}

/**
 *@name Cotes��������������
 *@param1 below����������
 *@param2 upper����������
 *@param3 n������������ĸ���
**/
double Simpos(double below,double upper,int n)
{
	double h=(upper-below)/n;
	double S1=0;
	double S2=function(below+h/2);
	double x=below;
	for (int i=1;i<n;i++)
	{
		//������ڵ㴦�ĺ���ֵ 1~(n-1)
		x+=h;
		S1+=function(x);
	}
	x=below+h/2;
	for (int j=1;j<n;j++)
	{
		//����������е㴦�ĺ���ֵ 0.5~(n-0.5) ��n��
		x+=h;
		S2+=function(x);
	}

	return (h/6)*(function(below)+function(upper)+2*S1+4*S2);
}

/**
 *@name Cotes����������˹��ʽ
 *@param1 below����������
 *@param2 upper����������
 *@param3 n������������ĸ���
**/
double Cotes(double below,double upper,int n)
{
	double h=(upper-below)/n;
	double S1=0;
	double S2=0;
	double S3=0;
	double S4=0;
	double x=below;
	x=(below+h/4);
	for (int i=0;i<n;i++)
	{
		//���������1/4����ֵ 1/4~(n-3/4)��n��
		S1+=function(x);
		x+=h;
	}

	x=(below+h/2);
	for (int i=0;i<n;i++)
	{
		//���������1/2����ֵ 1/2~(n-1/2)��n��
		S2+=function(x);
		x+=h;
	}

	x=below+3*h/4;
	for (int i=0;i<n;i++)
	{
		//���������3/4����ֵ 3/4~(n-1/4)��n��
		S3+=function(x);
		x+=h;
	}

	x=below+h;
	for (int i=1;i<n;i++)
	{
		//���������3/4����ֵ 1~(n-1)��n-1��
		S4+=function(x);
		x+=h;
	}

	return (h/90)*(7*function(below)+32*S1+12*S2+32*S3+14*S4+7*function(upper));
}

void main()
{
	cout<<"�������ι�ʽ"<<trapezoid(0,1,4)<<endl;
	cout<<"������������ʽ"<<Simpos(0,1,2)<<endl;
	cout<<"��������˹��ʽ"<<Cotes(0,1,1)<<endl;
	system("pause");
}