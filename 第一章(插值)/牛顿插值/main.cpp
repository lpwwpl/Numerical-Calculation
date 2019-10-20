#include <iostream>
#include <stdlib.h>
using namespace std;

int count;
float quotient_table[10][10];
float node[10];
float product_factor[10];

void Load_Data()
{
	cout<<"please input the count ";
	cin>>count;
	cout<<"\nplease input the node and zero order of quotient"<<endl;
	for (int i=0;i<count;i++)
	{
		cin>>node[i]>>quotient_table[0][i];
		cout<<endl;
	}
}

void Print_quotient_table()
{
	for (int i=0;i<count;i++)
	{
		for (int j=0;j<count;j++)
		{
			cout<<quotient_table[i][j]<<" ";
		}
		cout<<endl;
	}
}

/*
 *@name Build_quotient_table���������̱�
 *@return none
*/
void Build_quotient_table()
{
	for (int i=1;i<count;i++)
	{
		for (int j=i;j<count;j++)
		{
			//��ά����ÿһ��i��Ӧ����i�ײ��̣�ÿһ��j��Ӧ�����ڸýײ����еĲ�ͬ��֮��Ĳ���
			quotient_table[i][j]=(quotient_table[i-1][j]-quotient_table[i-1][j-1])/(node[j]-node[j-i]);
		}
	}
}

/*
 *@name Newton_interpolation������ţ�ٲ�ֵ���м���
 *@param x������x
 *@return��ţ�ٲ�ֵ�õ��Ľ��
*/
float Newton_interpolation(float x)
{
	float sum=0;
	float temp_x=1;
	for (int i=0;i<count;i++)
	{
		sum+=temp_x*quotient_table[i][i];
		temp_x*=(x-node[i]);
	}
	return sum;
}

void main()
{
	Load_Data();
	Build_quotient_table();
	Print_quotient_table();
	cout<<"the result is "<<Newton_interpolation(0.596)<<endl;
	system("pause");
}