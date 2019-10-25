#include <iostream>
#include <cmath>
using namespace std;

double Tn[20];	//�������������

/**
 *@name function����������
 *@param1 x��������Ա���
**/
double function(double x)
{
	if(x==0)
		return 1;
	else
		return sin(x)/x;
}

/**
 *@name Variable_step�����ñ䲽�����ι�ʽ���
 *@param1 down����������
 *@param2 upper����������
 *@param3 limit_error�������
**/
void Variable_step(double down,double upper,double limit_error)
{
	Tn[0]=(function(down)+function(upper))/2;

	double h;		//����С����ĳ���
	double n=0.5;		//���廮�ֵ�������
	double S=0;		//������

	//ע��ÿ��������֣������Լ�
	for (int i=0;i<19;i++)
	{
		//��ǰ�Ⱥ��� Tn[0]->Tn[1] ÿ�ζ�������ж���
		n=n*2;		
		//����С����ĳ���
		h=(upper-down)/n;	

		S=0;
		//����С�����������е�ĺ����� 
		for (int j=0;j<n;j++)
		{
			S+=function(down+j*h+h/2);
		}

		//��������һ��
		Tn[i+1]=Tn[i]/2+(h/2)*S;

		//�����⵽���С�����ƣ���ֱ�����
		if(abs(Tn[i+1]-Tn[i])/3<limit_error)
			break;
	}
}

void main()
{
	//���ñ䲽�����ι�ʽ���
	Variable_step(0,1,1e-10);

	//��ӡ������
	for (int i=0;i<20;i++)
	{
		cout<<"����"<<i<<" "<<Tn[i]<<endl; 
	}
	system("pause");
}