//1 2 3 4 5 6 7 �ֱ����do re mi fa sol la si
// +��ʾ������-��ʾ������������ʾ����
// �ķ�������  ������������ ȫ���� �������� 
// �˷�����@   ʮ��������$ ����. (Ӣ��)
// 0��ֹ�� 
#include<iostream>
#include<cmath>
#include<windows.h> 
#include<time.h>
using namespace std;

char spectrum[100000]; 
int speed;

void press(int vk)
{
	keybd_event(vk,0,0,0);
	keybd_event(vk,0,KEYEVENTF_KEYUP,0);
}

int key(int x)
{
	if(x==1)return 90;
	else if(x==2)return 88;
	else if(x==3)return 67;
	else if(x==4)return 86;
	else if(x==5)return 66;
	else if(x==6)return 78;
	else if(x==7)return 77;
	else if(x==11)return 65;
	else if(x==12)return 83;
	else if(x==13)return 68;
	else if(x==14)return 70;
	else if(x==15)return 71;
	else if(x==16)return 72;
	else if(x==17)return 74;
	else if(x==21)return 81;
	else if(x==22)return 87;
	else if(x==23)return 69;
	else if(x==24)return 82;
	else if(x==25)return 84;
	else if(x==26)return 89;
	else if(x==27)return 85;
}

int main()
{
	cout<<"�����ٶ�����س�����������"<<endl; 
	cout<<"1 2 3 4 5 6 7 �ֱ����do re mi fa sol la si"<<endl;
	cout<<"+��ʾ������-��ʾ������������ʾ����"<<endl;
	cout<<"�ķ�������  ������������ ȫ���� ��������"<<endl;
	cout<<"�˷�����@   ʮ��������$ ����. (Ӣ��)"<<endl; 
	cout<<"0��ֹ��"<<endl;
	cin>>speed;
	cin>>spectrum;
	Sleep(5000);
	int i=0;
	while(spectrum[i]!='0')
	{ 
		int high=0;
		int time=0;
		int interval=250*60/speed;
		//��ȡ���ڳ��� 
		while(spectrum[i]=='!'||spectrum[i]=='@'||spectrum[i]=='$'||spectrum[i]=='.')
		{
			if(spectrum[i]=='!')time+=4,i++;
			if(spectrum[i]=='@')time+=2,i++;
			if(spectrum[i]=='$')time+=1,i++;
			if(spectrum[i]=='.')time=time+time/2,i++;	
		}
		//��ȡ������������ 
		int note[100]={0};
		int noteindex=0;
		int flag=1;
		while(flag==1) 
		{
			noteindex++;
			high=0;
			if(spectrum[i]=='+')high+=20,i++;
			else if(spectrum[i]=='-')i++;
			else high+=10;
			note[noteindex]=key((int)spectrum[i]-(int)'0'+high);
			i++;
			if(spectrum[i]=='!'||spectrum[i]=='@'||spectrum[i]=='$'||spectrum[i]=='.'||spectrum[i]=='0')flag=0;
		}
		//����
		noteindex=1;
		while(note[noteindex]!=0) 
		{
			press(note[noteindex]);
			noteindex++;
		}
		Sleep(time*interval);	
	}
	
	return 0;
}

