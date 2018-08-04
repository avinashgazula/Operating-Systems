#include <bits/stdc++.h>
using namespace std;
void print_frame(int* frame,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<frame[i]<<" ";
	}
}
bool not_present(int* frame,int size,int n)
{
	for(int i=0;i<size;i++)
	{
		if(frame[i]==n)
			return false;
	}
	return true;
}
void FIFO_page_replacement(ifstream &fin)
{
	int size;
	int* frame;
	int pf=0;
	cout<<"enter frame size : ";
	cin>>size;
	frame=new int[size];
	for(int i=0;i<size;i++)
	{
		frame[i]=-1;
	}
	int n;
	for(int i=0;i<size;i++)
	{
		fin>>n;
		cout<<n<<" ";
		frame[i]=n;
		pf++;
		cout<<"frame : ";
		print_frame(frame,size);
		cout<<"\n";
	}
	int out=0;
	while(fin>>n)
	{
		cout<<n<<" ";
		cout<<"frame : ";
		if(not_present(frame,size,n))
		{
			frame[out]=n;
			pf++;
			out=(out+1)%size;
			print_frame(frame,size);
		}
		cout<<"\n";
	}
	cout<<"\nNo. of page faults: "<<pf;
}
int main()
{
	ifstream fin;
	fin.open("pages.txt");
	if(!fin)
	{
		cout<<"error opening file\n";
		exit(0);
	}
	FIFO_page_replacement(fin);
	return 0;
}
