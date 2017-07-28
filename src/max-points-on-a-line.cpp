// max-points-on-a-line.cpp : 定义控制台应用程序的入口点。
// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
// 注：假设有A B C D E F G H，8个点，其中A B重合，若直接判断三点共线，当取前两个点是A、B时，会得到ABC ABD ABE ABF ABG ABH满足三点共线，但实际上C D E F G H可能不共线
//     因此，当取到的前两个点重合时，必须再取另一个点来确定一条直线，之后再统计三点共线
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;


struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution
{
public:
	bool on_a_line(Point A, Point B, Point C)
	{
		return (A.y-B.y)*(A.x-C.x) == (A.x-B.x)*(A.y-C.y);
	}
	int maxPoints(vector<Point> &point)  //求落在一条直线上的点的个数，返回最大值
	{
		if(point.size()<2)
			return point.size();
		int max = 0;
		for(int i=0;i<point.size();i++)
		{
			Point A = point[i];
			int dup = 0;  //重复点计数
			for(int j=i+1;j<point.size();j++)
			{
				Point B = point[j];
				int cnt = 1;
				if((A.x-B.x==0)&&(A.y-B.y==0))
					dup++; //A B重合
				else
				{
					cnt++; //在同一直线上点计数
					for(int k=j+1;k<point.size();k++)
					{
						Point C = point[k];
						if(on_a_line(A,B,C))
							cnt++;
					}
				}
				if(max < cnt+dup)
					max = cnt+dup;
			}
		}
		return max;
	}
};

