#include<iostream>
#include<cmath>
#include<conio.h> 
#include<stdlib.h>
#include<windows.h>
using namespace std;
void check(int x,int y);
void eatchess(int x,int gridindex);
void sort(int x);
void wincheck();
int chess1[5],chess2[5],chess3[5],chess4[5],grid[23],win[5][5],chess[5][5],winer[5];
int dice,playpeople,winpeople;
void initialize()//��ʼ������ 
{
	cout<<"�������:"<<endl;
	playpeople=(int)getche()-(int)'0';
	while(playpeople<2||playpeople>4)
	{
		cout<<"�����������������"<<endl;
		playpeople=(int)getche()-(int)'0'; 
	}
}
void printmap()//��ӡ��ͼ 
{
	cout<<endl;
	//hang1 
	cout<<"��������                                                                                                ��������������������������������������"<<endl;
	//hang2
	if(chess1[3]==0)cout<<"��1 1 ��";
	else if(chess1[4]==0)cout<<"��1   ��";
	else cout<<"��    ��";
	cout<<"                                                                                                ";
	for(int i=16;i<=22;i++)
	{
		
		if(grid[i]%10==1)cout<<"��1   ";
		else if(grid[i]%10==2||grid[i]%10==3||grid[i]%10==4)cout<<"��1 1 ";
		else cout<<"��    ";
	}
	cout<<endl;
	//hang3
	if(chess1[1]==0)cout<<"��1 1 ��";
	else if(chess1[2]==0)cout<<"��1   ��";
	else cout<<"��    ��";
	cout<<"                                                                                                ";
	for(int i=16;i<=22;i++)
	{
		if(grid[i]%10==3)cout<<"��1   ";
		else if(grid[i]%10==4)cout<<"��1 1 ";
		else cout<<"��    ";
	}
	cout<<endl;
	//hang4
	cout<<"��������                                                                                                ��������������������������������������"<<endl;
	//hang5
	if(chess2[3]==0)cout<<"��2 2 ��";
	else if(chess2[4]==0)cout<<"��2   ��";
	else cout<<"��    ��";
	cout<<"                                                                                                ";
	for(int i=16;i<=22;i++)
	{
		
		if(grid[i]%100/10==1)cout<<"��2   ";
		else if(grid[i]%100/10>=2)cout<<"��2 2 ";
		else cout<<"��    ";
	}
	cout<<endl;
	//hang6
	if(chess2[1]==0)cout<<"��2 2 ��";
	else if(chess2[2]==0)cout<<"��2   ��";
	else cout<<"��    ��";
	cout<<"                                                                                                ";
	for(int i=16;i<=22;i++)
	{
		if(grid[i]%100/10==3)cout<<"��2   ";
		else if(grid[i]%100/10==4)cout<<"��2 2 ";
		else cout<<"��    ";
	}
	cout<<endl;
	//hang7
	cout<<"��������  ��������������������������������������������������������������������������������������������  ��������������������������������������"<<endl;
	//hang8
	cout<<"          ��";
	for(int i=1;i<=15;i++)
	{
		if(grid[i]==0)cout<<"    ��";
		else if(grid[i]==1)cout<<"1   ��";
		else if(grid[i]==2||grid[i]==3||grid[i]==4)cout<<"1 1 ��";
		else if(grid[i]==10)cout<<"2   ��";
		else if(grid[i]==20||grid[i]==30||grid[i]==40)cout<<"2 2 ��";
		else if(grid[i]==100)cout<<"3   ��";
		else if(grid[i]==200||grid[i]==300||grid[i]==400)cout<<"3 3 ��";
		else if(grid[i]==1000)cout<<"4   ��";
		else if(grid[i]>=2000)cout<<"4 4 ��";
		else cout<<grid[i]<<"A";
	}
	cout<<endl;
	//hang9
	cout<<"          ��";
	for(int i=1;i<=15;i++)
	{
		if(grid[i]==0)cout<<"    ��";
		else if(grid[i]==3)cout<<"1   ��";
		else if(grid[i]==4)cout<<"1 1 ��";
		else if(grid[i]==30)cout<<"2   ��";
		else if(grid[i]==40)cout<<"2 2 ��";
		else if(grid[i]==300)cout<<"3   ��";
		else if(grid[i]==400)cout<<"3 3 ��";
		else if(grid[i]==3000)cout<<"4   ��";
		else if(grid[i]==4000)cout<<"4 4 ��";
		else cout<<"    ��";
	}
	cout<<endl;
	if(playpeople>=3)
	{
		//hang10	
		cout<<"��������  ��������������������������������������������������������������������������������������������  ��������������������������������������"<<endl;
		//hang11
		if(chess3[3]==0)cout<<"��3 3 ��"; 
		else if(chess3[4]==0)cout<<"��3   ��";
		else cout<<"��    ��";
		cout<<"                                                                                                ";
		for(int i=16;i<=22;i++)
		{
			
			if(grid[i]%1000/100==1)cout<<"��3   ";
			else if(grid[i]%1000/100>=2)cout<<"��3 3 ";
			else cout<<"��    ";
		}
		cout<<endl;
		//hang12
		if(chess3[1]==0)cout<<"��3 3 ��";
		else if(chess3[2]==0)cout<<"��3   ��";
		else cout<<"��    ��";
		cout<<"                                                                                                ";
		for(int i=16;i<=22;i++)
		{
			if(grid[i]%1000/100==3)cout<<"��3   ";
			else if(grid[i]%1000/100==4)cout<<"��3 3 ";
			else cout<<"��    ";
		}
		cout<<endl;
		//hang13
		cout<<"��������                                                                                                ��������������������������������������"<<endl;
		if(playpeople==3)return;
		//hang14		
		if(chess4[3]==0)cout<<"��4 4 ��";
		else if(chess4[4]==0)cout<<"��4   ��";
		else cout<<"��    ��";
		cout<<"                                                                                                ";
		for(int i=16;i<=22;i++)
		{
		
			if(grid[i]/1000==1)cout<<"��4   ";
			else if(grid[i]/1000>=2)cout<<"��4 4 ";
			else cout<<"��    ";
		}
		cout<<endl;
		//hang15
		if(chess4[1]==0)cout<<"��4 4 ��";
		else if(chess4[2]==0)cout<<"��4   ��";
		else cout<<"��    ��";
		cout<<"                                                                                                ";
		for(int i=16;i<=22;i++)
		{
			if(grid[i]/1000==3)cout<<"��4   ";
			else if(grid[i]/1000==4)cout<<"��4 4 ";
			else cout<<"��    ";
		}
		cout<<endl;
		//hang16
		cout<<"��������                                                                                                ��������������������������������������"<<endl;
	}
	else cout<<"          ��������������������������������������������������������������������������������������������"<<endl;
	return ;
}
void sort(int x)//��ÿλ��ҵ��������� 
{
	//ѡ������ 
	if(x==1)
	{	
		for(int i=1;i<4;i++)
			for(int j=i+1;j<=4;j++)
				if(chess1[i]<chess1[j])
				{
					int t=chess1[j];
					chess1[j]=chess1[i];
					chess1[i]=t;
				}	
	}
	else if(x==2)
	{
		for(int i=1;i<4;i++)
			for(int j=i+1;j<=4;j++)
			if(chess2[i]<chess2[j])
			{
				int t=chess2[j];
				chess2[j]=chess2[i];
				chess2[i]=t;
			}
	}
	else if(x==3)
	{
		for(int i=1;i<4;i++)
			for(int j=i+1;j<=4;j++)
			if(chess3[i]<chess3[j])
			{
				int t=chess3[j];
				chess3[j]=chess3[i];
				chess3[i]=t;
			}
	}
	else if(x==4)
	{
		for(int i=1;i<4;i++)
			for(int j=i+1;j<=4;j++)
			if(chess4[i]<chess4[j])
			{
				int t=chess4[j];
				chess4[j]=chess4[i];
				chess4[i]=t;
			}
	}	
}
void calculate(int x)//���г��� 
{
	for(int i=1;i<=4;i++)
	{
		chess[1][i]=chess1[i];
		chess[2][i]=chess2[i];
		chess[3][i]=chess3[i];
		chess[4][i]=chess4[i];
	} 
	cout<<"�������Ͷ������"<<endl;
	getche(); 
	dice=1+rand()%(6);
	cout<<"���"<<x<<"Ͷ����"<<dice<<endl;
	if(x==1)//���1 
	{
		if(dice==6&&chess[1][1]==0)
		{
			cout<<"���������Ͷһ��ʹ��ķɻ����"<<endl;
			getche();
			dice=1+rand()%(6);
			cout<<"��Ͷ����"<<dice; 
			chess[1][1]+=dice;
			if(grid[chess[1][1]]<5)	grid[chess[1][1]]++;	
			else eatchess(1,chess[1][1]);
		}
		else if(dice==6&&chess[1][4]==0)
		{
			cout<<"��ɻ����ƶ����ӣ���ɰ�1�ƶ���2"<<endl;
			int b=(int)getche()-(int)'0';
			while(b!=1&&b!=2)
			{
				cout<<"����ѡ��!"<<endl;
				b=(int)getche()-(int)'0';
			}
			if(b==1)
			{
				cout<<"���������Ͷһ��ʹ��ķɻ����"<<endl;
				getche();
				dice=1+rand()%(6);
				cout<<"��Ͷ����"<<dice<<endl;
				int d=1;
				while(chess[1][d]!=0)d++;
				chess[1][d]+=dice;
				if(grid[chess[1][d]]<5)	grid[chess[1][d]]++;	
				else eatchess(1,chess[1][d]); 
			}
			if(b==2)
			{
				cout<<"�ƶ��ĸ����ӣ�1��ʾ���յ�����ģ�2��֮���Դ�����"<<endl;
				int c=(int)getche()-(int)'0';
				while(c<1||c>4)
				{
					cout<<"����ѡ��!"<<endl;
					c=(int)getche()-(int)'0';	
				}
				if(chess[1][c]<15)
				{
					chess[1][c]+=6;
					if(grid[chess[1][c]]<5)
					{
						grid[chess[1][c]]++;
						grid[chess[1][c]-dice]--;
					}
					else 
					{
						eatchess(1,chess[1][c]);
						grid[chess[1][c]-dice]--;
					}
				} 
				else if(chess[1][c]==15)
				{
					chess[1][c]=21;
					grid[15]--;
					grid[21]++;
					win[1][c]=1;
				}
				else if(chess[1][c]>15)
				{
					grid[chess[1][c]]--;
					chess[1][c]+=6;
					chess[1][c]=42-chess[1][c];
					grid[chess[1][c]]++;
				}
			} 
		}
		else
		{
			for(int a=1;a<=4;a++)
			{
				if(chess[1][a]==0||chess[1][a]==21)
				{
					if(a<4)continue;
					if(a==4)return;
				}
				else break;
			} 
			cout<<"�ƶ��ĸ����ӣ�1��ʾ���յ�����ģ�2��֮���Դ�����"<<endl;
			int b=(int)getche()-(int)'0';
			while(chess[1][b]==0||chess[1][b]==21||b<1||b>4)
			{
				cout<<"����ѡ��"<<endl;
				b=(int)getche()-(int)'0';
			}
			int c=b;
			if(chess[1][c]<15)
				{
					chess[1][c]+=dice;
					if(grid[chess[1][c]]<5)
					{
						grid[chess[1][c]]++;
						grid[chess[1][c]-dice]--;
					}
					else 
					{
						eatchess(1,chess[1][c]);
						grid[chess[1][c]-dice]--;
					}
				} 
			else if(chess[1][c]>=15)
				{
					grid[chess[1][c]]--;
					chess[1][c]+=dice;
					if(chess[1][c]>21)
					{
						chess[1][c]=42-chess[1][c];
						grid[chess[1][c]]++;
					}
					else if(chess[1][c]==21)
					{
						win[1][c]=1;grid[chess[1][c]]++;
					}
					else grid[chess[1][c]]++;
				}
			
		}
	}
	else//���234�� 
	{
		if(dice==6&&chess[x][4]==0)
		{
			cout<<"���"<<x<<"ѡ�����"<<endl; 
			int b=1;
			dice=1+rand()%(6);
			cout<<"���"<<x<<"Ͷ����"<<dice<<endl;
			while(chess[x][b]!=0)b++;
			chess[x][b]+=dice;
			if(grid[chess[x][b]]==0||grid[chess[x][b]]==1*(int)pow(10,x-1)||grid[chess[x][b]]==2*(int)pow(10,x-1)||grid[chess[x][b]]==3*(int)pow(10,x-1))	grid[chess[x][b]]+=(int)pow(10,x-1);
			else eatchess(x,chess[x][b]);
		}
		else
		{
			for(int a=1;a<=4;a++)
			{
				if(chess[x][a]==0||chess[x][a]==21)
				{
					if(a<4)continue;
					return;
				}
				else break;
			}
			cout<<"���"<<x<<"�ж����"<<endl;
			if(chess[x][1]==0)return;
			else
			{
				int b=1;
				while(chess[x][b]==21)b++;
				if(chess[x][b]==0)return;
				if(grid[chess[x][b]]>0)grid[chess[x][b]]-=(int)pow(10,x-1);
				chess[x][b]+=dice;
				if(chess[x][b]>21)chess[x][b]=42-chess[x][b];
				else if(chess[x][b]==21)
				{
					win[x][b]==1;grid[21]+=(int)pow(10,x-1);return;
				}
				if(grid[chess[x][b]]==0||grid[chess[x][b]]==1*(int)pow(10,x-1)||grid[chess[x][b]]==2*(int)pow(10,x-1)||grid[chess[x][b]]==3*(int)pow(10,x-1)&&chess[x][b]!=21)	grid[chess[x][b]]+=(int)pow(10,x-1);
				else if(chess[x][b]<=15)eatchess(x,chess[x][b]);
				else if(chess[x][b]!=21)grid[chess[x][b]]+=(int)pow(10,x-1);					
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		chess1[i]=chess[1][i];
		chess2[i]=chess[2][i];
		chess3[i]=chess[3][i];
		chess4[i]=chess[4][i];
	}
	sort(x);
	wincheck();
 
}
void eatchess(int x,int gridindex)//���� 
{
	for(int i=1;i<=4;i++)
	{
		for(int j=1;j<=4;j++)
		{
			if(i!=x&&chess[i][j]==gridindex)
			{
				chess[i][j]=0;
				grid[gridindex]=(int)pow(10,x-1);
			}
		}
	}
}
void wincheck()//����Ƿ�ʤ�� 
{
	for(int i=1;i<=playpeople;i++)
	{
		if(win[i][1]==21&&win[i][2]==21&&win[i][3]==21&&win[i][4]==21&&winer[i]==0)
		{
			cout<<"���"<<i<<"���ʤ������Ϸ����"<<endl;winer[i]=1;winpeople++; 
		}
		
	}
} 
int main()
{   

	initialize();
	while(winpeople<playpeople-1)
	{
		for(int i=1;i<=playpeople;i++)
		{
			//system("cls");
			if(winer[i]==0)
			{
				printmap();
				cout<<"�����������"<<endl;
				getche();system("cls");
				calculate(i);	
			}
		}
	}
	cout<<"��Ϸ����"<<endl; 
	return 0;
}

