#include <iostream>
#include <cmath>
using namespace std;

double A[3][3]={{3,2,3},{2,2,0},{3,0,12}};
double L[3][3]={0};

/** 
 *@name Resolve_by_square_root������ƽ�������ֽ����
 *@param1 A��ϵ������A
**/
void Resolve_by_square_root(double A[3][3])
{
	//ƽ�������ֽ����
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			if (i<j)
				continue;

			if (i==j)
			{
				L[i][j]=A[i][j];
				for (int k=0;k<i;k++)
				{
					L[i][j]-=L[i][k]*L[i][k];
				}
				L[i][j]=sqrt(L[i][j]);
			}
			else
			{
				L[i][j]=A[i][j];
				for (int k=0;k<j;k++)
				{
					L[i][j]-=L[i][k]*L[j][k];
				}
				L[i][j]/=L[j][j];
			}
		}
	}

	//��ӡ�ֽ���
	cout<<"ƽ�������ֽ��� LΪ"<<endl;
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<3;j++)
		{
			cout<<L[i][j]<<" ";
		}
		cout<<endl;
	}
}

void main()
{
	Resolve_by_square_root(A);
	system("pause");
}