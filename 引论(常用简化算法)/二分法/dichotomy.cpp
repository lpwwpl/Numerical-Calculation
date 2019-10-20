#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

float Equation_function(float x)
{
	return pow(x,3)-x-1;
}

float Dichotomy_solution(float error_range,float down,float upper)
{
	float error=(upper-down)/2;
	float x;
	float y,y0,y1;										//������¼x,upper,down�ĺ���ֵ
	int count=0;

	while(error>=error_range)
	{
		//�ҵ���ǰ�����޶�Ӧ�Ľ��Լ����
		x=(upper+down)/2;
		error=(upper-down)/2;

		//�����ʱ��x,upper,down��Ӧ�ĺ���ֵ
		y=Equation_function(x);
		y0=Equation_function(down);
		y1=Equation_function(upper);

		if((y*y1)<0)
		{
			down=x;
		}
		else if((y*y1)==0)
		{
			return x;
		}
		else
		{
			upper=x;
		}
	}
	return x;
}

void main()
{
	float x;
	x=Dichotomy_solution(1e-3,1,2);
	cout<<"x is "<<x<<endl;
	system("pause");
}