#include <iostream>
#include <cmath>
using namespace std;

#define error 1e-4

//�Ҷ˺���
double function(double x,double y)
{
	return 1/(1+x*x)-2*y*y;
}

//������
double solution(double x)
{
	return x/(1+x*x);
}

//��ʽŷ����ʽ�ĳ�ʼ��
void Euler_method1(float x0,float y0)
{
	float h=0.1;
	float x=x0;
	float y=y0;
	float yn;
	while(fabs(x-4)>=error)
	{
		//��ʽŷ����ʽ��ʼ��
		yn=y+h*function(x,y);
		//��ʽŷ����ʽ����
		y=y+h*function(x+h,yn);

		cout<<"the x is "<<x<<" the y is "<<y<<" the right y is "<<solution(x+h)<<endl;
		x=x+h;
	}
}

//����ŷ����ʽ��� ���θ�ʽ(��ʽ)
void Euler_method2(float x0,float y0)
{
	//���ò���
	float h=0.10;
	float x=x0;
	float y=y0;
	float yn;
	while (fabs(x-4.0)>=error)
	{
		//��ʽŷ����ʽ
		yn=y+h*function(x,y);				
		//��ʽŷ����ʽ
		y=y+h/2*(function(x,y)+function(x+h,yn));	

		cout<<"the x is "<<x<<" the y is "<<y<<" the right y is "<<solution(x+h)<<endl;
		x=x+h;
	}
}

void main()
{
	Euler_method1(0.0,0.0);
	system("pause");
}