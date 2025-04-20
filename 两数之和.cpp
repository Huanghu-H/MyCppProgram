#include<iostream>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;

class Pair 
{
public:
    int index;
    int value;

    Pair(int idx, int val) : index(idx)
						   , value(val) {}
};

struct ComparePair 
{
    bool operator()(const Pair& p1, const Pair& p2) 
	{
        return p1.value > p2.value; // 注意这里是大于号，因为我们希望value越小越优先
    }
};
int main()
{
	vector<int> nums = {2,7,11,13};
	int target = 9; 
        vector<int> ans;
        priority_queue<Pair, vector<Pair>, ComparePair> num;
	    priority_queue<Pair, vector<Pair>, ComparePair> difnum;
        int index=0;

        for(auto x: nums)
        {
            num.push(Pair(index, x));
            difnum.push(Pair(index, target-x));
            index++;
        }    
        while(1)
        {
            if(num.top().value < difnum.top().value) num.pop();
            else if(num.top().value > difnum.top().value) difnum.pop();
            else if(num.top().value == difnum.top().value)
            {
                if(num.top().index == difnum.top().index) num.pop();
                else 
                {
                	cout<<num.top().index<<difnum.top().index<<endl;
                }
            }
        }
	
	return 0;
}

