#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point
{
	double x;
	double y;
	
	Point(double x_p, double y_p) : x(x_p), y(y_p) {}
	
	~Point() {}
};

void readPoints(vector<Point> &points);
bool compareX(Point p1, Point p2);
bool compareY(Point p1, Point p2);
double distance(const Point &p1, const Point &p2);
double stripClosest(vector<Point> &strip_points);
double bruteForce(vector<Point> &points, int left, int right);
double closestPair(vector<Point> &points, int left, int right);
double minVal(double x, double y);

void readPoints(vector<Point> &points, const string file_name)
{
	ifstream inf{file_name};
	
	double x, y;
	
	while(inf)
	{
		inf >> x >> y;
// 		cout << x << "\t" << y << "\n";
		points.push_back(Point(x, y));
	}
}

bool compareX(Point p1, Point p2)
{
	return p1.x < p2.x ;
}

bool compareY(Point p1, Point p2)
{
	return p1.y < p2.y ;
}

double distance(const Point &p1, const Point &p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

double minVal(double x, double y)
{
	return (x<=y)? x : y;
}

double stripClosest(vector<Point> &strip_points)
{
	int n = strip_points.size();
	
	double min_d = distance(strip_points[0], strip_points[n-1]);
	for(int i=0; i<n; ++i)
	{
		for(int j=i+1; j<n && (strip_points[j].y - strip_points[i].y) < min_d; ++j)
		{
			min_d = minVal(min_d, distance(strip_points[i], strip_points[j]));
		}
	}
	
	return min_d;
}

double bruteForce(vector<Point> &points, int left, int right)
{
	double min_d = distance(points[left], points[right]);
	
	for(int i=left; i<=right; ++i)
	{
		for(int j=i+1; j<=right; ++j)
		{
			min_d = minVal(min_d, distance(points[i], points[j]));
		}
		
	}
	return min_d;
}

double closestPair(vector<Point> &points, int left, int right)
{
	if((right-left) <= 2)
		return bruteForce(points, left, right);
	
	int mid = (left + right)/2;
	
	
	
	double d = minVal(closestPair(points, left, mid),  closestPair(points, mid+1, right));
	
	vector<Point> strip_points{};
	
	for(int i=left; i<=right; ++i)
	{
		if(fabs(points[i].x - points[mid].x) < d)
		strip_points.push_back(points[i]);
	}

	if(strip_points.size() < 2)
	{
		return d;
	}
	
	sort(strip_points.begin(), strip_points.end(), compareY);

	// 	cout << "check\t" << left << "\t" << right <<"\n";
	
	return minVal(d, stripClosest(strip_points));
}

int main()
{	
	vector<Point> points{};
	
	readPoints(points, "N_10.dat");
	
	points.pop_back(); // because file reading is adding th last point to the vector twice
	
	sort(points.begin(), points.end(), compareX);
	
	double ans = closestPair(points, 0, points.size()-1);
	
	cout << ans << "\n";
	return 0;
}