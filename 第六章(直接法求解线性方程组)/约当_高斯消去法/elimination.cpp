#include <iostream>
#include <cmath>
using namespace std;

const int row_len=3;
const int col_len=3;
double A[row_len][col_len]={{3,-1,2},{1,1,1},{2,1,-1}};
double b[row_len]={-3,-4,-3};

/**
 *@name Jordan_elimination��Լ����Ԫ
 *@param1 A��ϵ������
 *@param2 b���Ҷ�����
**/
void Jordan_elimination(double A[row_len][col_len],double b[row_len])
{
	for (int i=0;i<row_len;i++)
	{
		//��һ��Ԫ��
		//���Ƚ��й�һ�� A��Ԫ��
		double A_temp=A[i][i];
		for (int j=0;j<col_len;j++)
		{
			A[i][j]=A[i][j]/A_temp;
		}
		//��һ��b��Ԫ��
		b[i]=b[i]/A_temp;

		//�������м�ȥ���еĹ�һ��Ԫ
		for (int k=0;k<row_len;k++)
		{
			if(k==i)
				continue;
			else
			{
				//��ȥ���еĵ�i�е�Ԫ��
				double A_temp2=A[k][i];
				for (int p=0;p<row_len;p++)
				{
					A[k][p]=A[k][p]-A_temp2*A[i][p];
				}
				//��b�����ڸ��е�ֵ������
				b[k]=b[k]-A_temp2*b[i];
			}
		}
	}

	//��ʾ���󾭹�Լ����Ԫ��Ľ�� �Խ�
	for (int i=0;i<row_len;i++)
	{
		for (int j=0;j<col_len;j++)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<b[i]<<endl;
	}
}


/**
 *@name Jordan_elimination����˹��ȥ��
 *@param1 A��ϵ������
 *@param2 b���Ҷ�����
**/
void Gaussian_elimination(double A[row_len][col_len],double b[row_len])
{
	for (int i=0;i<row_len;i++)
	{
		//�����Խǹ�һ��
		double A_temp=A[i][i];
		for (int j=0;j<col_len;j++)
		{
			A[i][j]=A[i][j]/A_temp;
		}
		b[i]=b[i]/A_temp;

		//�Ը��к�����н�����Ԫ
		for (int k=i+1;k<row_len;k++)
		{
			double A_temp2=A[k][i];
			for (int p=0;p<col_len;p++)
			{
				A[k][p]=A[k][p]-A_temp2*A[i][p];
			}
			b[k]=b[k]-A_temp2*b[i];
		}
	}

	//��ʾ������ ������
	for (int i=0;i<row_len;i++)
	{
		for (int j=0;j<col_len;j++)
		{
			cout<<A[i][j]<<" "; 
		}
		cout<<b[i]<<endl;
	}

	//�ش�
	cout<<"\nthe result is"<<endl;
	
	//x����Ϊ������ �Ӻ���ǰ�ش�
	double x[row_len];
	for (int i=row_len-1;i>=0;i--)
	{
		x[i]=b[i];
		for (int j=i+1;j<row_len;j++)
		{
			x[i]+=(-A[i][j]*x[j]);
		}
	}

	//��ʾ������
	for (int i=0;i<row_len;i++)
	{
		cout<<x[i]<<endl;
	}
}


void main()
{
	//cout<<"Լ����ȥ��"<<endl;
	//Jordan_elimination(A,b);
	//cout<<endl;
	cout<<"��˹��ȥ��"<<endl;
	Gaussian_elimination(A,b);
	system("pause");
}