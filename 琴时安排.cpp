#include<iostream>
#include<cmath>
#include<vector> 
using namespace std;

int Student_Num;
int type[101];
int Score;
int TimeTable[101];
vector<int> ArrangedTime[101]; // the i_th students' time
vector<int> FreeTime[101];

void Init()
{
	for(int i=0;i<101;i++)
	{
		TimeTable[i]=-1;
	}
}


int Arrange(int t) // Rearrange student of t, so that not conflict
{
	int x=TimeTable[t];
	
	if(type[x]==1) // Connect 2 hours
	{
		for(int i=0;i<FreeTime[x].size()-1;i++)
		{
			
		}
	} 
	else if(type[x]==2) // Separate 2 hours
	{
		
	}
	else if(type[x]==3) // 1 hour
	{
		
	}
	else 
	{
		return -1;
	}
}

int Find_AP(int x)
{	
	int First_time=-1,Second_time=-1,Third_time=-1,Forth_time=-1;
	
	if(type[x]==1) // Connected 2 hours 
	{
		for(int i=0;i<FreeTime[x].size()-1;i++)
		{
			First_time=FreeTime[x][i];
			Second_time=FreeTime[x][i+1];
			if(First_time!=Second_time-1) // is connected
				continue;
			else
			{
				if(TimeTable[First_time]==-1&&TimeTable[Second_time]==-1)
				{
					TimeTable[First_time]=TimeTable[Second_time]=x;
					ArrangedTime[x].push_back(First_time);
				}
				else
				{
					int f1=0,f2=0;
					if(TimeTable[First_time]!=-1) // have not been arranged
						f1=Arrange(TimeTable[First_time]);
					if(TimeTable[Second_time]!=-1)
						f2=Arrange(TimeTable[Second_time]);
					
					if(f1!=-1&&f2!=-1)
					{
						TimeTable[First_time]=x;
						TimeTable[Second_time]=x;
						ArrangedTime[x].push_back(First_time);
						
						return First_time;
					}
				}
			}
		}
		
	} 
	else if(type[x]==2) // Separate 2 hours
	{
		int LastArrangedTime=0;
		for(int i=0;i<FreeTime[x].size()-1;i++)
		{
			First_time=FreeTime[x][i];
			if(TimeTable[First_time]==-1) // Not Been Arranged
			{
				TimeTable[First_time]=x;
				ArrangedTime[x].push_back(First_time);
				
				if(LastArrangedTime==0) // First_time
				{
					LastArrangedTime=First_time;
					i++;
					continue;
				}
				else // Second_time
				{
					return First_time;
				}
			}
			else // Have Been Arranged, need to find AP 
			{
				int f1=0;
				f1=Arrange(TimeTable[First_time]);
				
				if(f1!=-1)  // Have AP
				{
					TimeTable[First_time]=x;
					ArrangedTime[x].push_back(First_time);
					
					if(LastArrangedTime==0) // First_time
					{
						LastArrangedTime=First_time;
						i++;
						continue;
					}
					else // Second_time
					{
						return First_time;				
					} 
				}
				
			}
		}
	}
	else if(type[x]==3) // 1 hour
	{
		for(int i=0;i<FreeTime[x].size()-1;i++)
		{
			First_time=FreeTime[x][i];
			if(TimeTable[First_time]==-1)
			{
				TimeTable[First_time]=x;
				ArrangedTime[x].push_back(First_time);
				
				return First_time;
			}
			else 
			{
				int f1=0;
				f1=Arrange(First_time);
				if(f1!=-1) // Have AP
				{
					TimeTable[First_time]=x;
					ArrangedTime[x].push_back(First_time);
					 
					return First_time;
				}
			}
		}
	}
	else
	{
		return -1;
	}
}



int main()
{
	cin>>Student_Num;
	for(int i=0;i<Student_Num;i++)
	{
		int type;cin>>type;
		int n;cin>>n;
		for(int j=0;j<n;j++)
		{			
			int m;cin>>m;
			FreeTime[i].push_back(m);
		}
	}
	Init();
	for(int i=0;i<Student_Num;i++)
	{
		Find_AP(i);
	}
	return 0;
}

