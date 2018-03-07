#include "../../StandardLibrary/public/headfile.hpp"

struct SPoint
{
	SPoint(double x, double y) :
		m_x(x), m_y(y)
	{
	}

	double m_x;
	double m_y;
};

class CPointAvg_ForEach
{
public:
	CPointAvg_ForEach():
		numPoints(0), xSum(0), ySum(0)
	{

	}

	void operator()(const SPoint& point)
	{
		++numPoints;
		xSum += point.m_x;
		ySum += point.m_y;
	}

	SPoint result() const
	{
		return SPoint(xSum / numPoints, ySum / numPoints);
	}
private:
	size_t numPoints;
	double xSum;
	double ySum;
};

//for_each
void test1()
{
	vector<SPoint> vtPoint;
	for (int i = 1; i < 11; ++i)
	{
		SPoint point(i, i + 2);
		vtPoint.push_back(point);
	}

	SPoint AvgPoint = for_each(vtPoint.begin(), vtPoint.end(), CPointAvg_ForEach()).result();
	cout << AvgPoint.m_x << " " << AvgPoint.m_y << endl;
}

class CPointAvg_Accumulate
{
public:
	CPointAvg_Accumulate() :
		numPoints(0), xSum(0), ySum(0)
	{

	}

	SPoint operator()(const SPoint& avgPoint, const SPoint& point)
	{
		++numPoints;
		xSum += point.m_x;
		ySum += point.m_y;
		return SPoint(xSum / numPoints, ySum / numPoints);
	}
private:
	size_t numPoints;
	double xSum;
	double ySum;
};

//accumulate
void test2()
{
	list<SPoint> lstPoint;
	for (int i = 1; i < 11; ++i)
	{
		lstPoint.push_back(SPoint(i, i + 2));
	}

	SPoint AvgPoint = accumulate(lstPoint.begin(), lstPoint.end(), SPoint(0, 0), CPointAvg_Accumulate());
	cout << AvgPoint.m_x << " " << AvgPoint.m_y << endl;
}

int main(int argc, char *argv[])
{
	test2();

	getchar();
	return 0;
}