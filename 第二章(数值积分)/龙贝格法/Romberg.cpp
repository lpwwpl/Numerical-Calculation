#include <iostream>
#include <cmath>
using namespace std;

//������ֽ����
double integral_table[10][4];

/**
 *@name function����������
 *@param1 x���Ա���
**/
double function(double x)
{
	return 4/(1+pow(x,2));
}

/**
 *@name Romberg_arithmetic�������������㷨�������ֽ����
 *@param1 down����������
 *@param2 upper����������
**/
void Romberg_arithmetic(double down,double upper)
{
	double S=0;
	double n=0.5;
	double h=(upper-down);
	integral_table[0][0]=(function(down)+function(upper))*(h/2);
	//����˳��	��ѭ�����п�ʼ������1�� 2�� 3�У����е�0���ɱ䲽�����η���ã�
	//					��ѭ���е���

	//�䲽�����η����0�� Tn
	for (int i=0;i<10;i++)
	{
		n=n*2;
		h=(upper-down)/n;
		
		S=0;
		for (int j=0;j<n;j++)
		{
			S+=function(down+j*h+h/2);
		}

		integral_table[i+1][0]=integral_table[i][0]/2+S*(h/2);
	}

	//����Sn Cn Rn
	for (int i=1;i<4;i++)
	{
		for(int j=i;j<10;j++)
		{
			//���������������ʽ
			integral_table[j][i]=(pow(4.0,i)*integral_table[j][i-1]-integral_table[j-1][i-1])/(pow(4.0,i)-1);
		}
	}
}

void main()
{
	Romberg_arithmetic(0,1);
	//��ӡ��������
	for (int i=0;i<10;i++)
	{
		for (int j=0;j<4;j++)
		{
			if(integral_table[i][j]!=0)
			{
				cout<<integral_table[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	system("pause");
}