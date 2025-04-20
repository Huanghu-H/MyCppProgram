#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAX 99999

int n,ans1,ans2;
class Point 
{
public:
    int x,y;
    Point()
    {
    	x=y=0;
	}
};

int manhattan_distance(Point& a,Point& b) 
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}
bool compare(Point& a,Point& b)
{
	if (a.x == b.x) 
	{
       return a.y < b.y;
    }
    return a.x < b.x;
}
int main() 
{
	cin>>n;
    vector<Point> points(n),noorder_points(n);
    for (int i=0;i<n;i++) 
	{
		int x,y;
        cin>>x>>y;     
        noorder_points[i].x=points[i].x=x;
        noorder_points[i].y=points[i].y=y;
    }

    std::sort(points.begin(),points.end(),compare);

    int min_distance=MAX;
    Point point1,point2;

    for (int i = 0; i < n - 1; ++i) 
	{
        int distance = manhattan_distance(points[i], points[i + 1]);
        if (distance < min_distance) 
		{
            min_distance = distance;
            point1 = points[i];
            point2 = points[i + 1];
        }
    }

	int i=0;
	for(auto &p:noorder_points)
	{
		i++;
		if(p.x==point1.x&&p.y==point1.y) ans1=i;
		if(p.x==point2.x&&p.y==point2.y) ans2=i;
	}
	cout<<endl<<min_distance<<endl;
	if(ans1<ans2)cout<<ans1<<" "<<ans2<<endl;
	else cout<<ans2<<" "<<ans1<<endl; 

    return 0;
}

