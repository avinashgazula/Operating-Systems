#include<bits/stdc++.h>
using namespace std;
vector<int> pages;
int ind=0;
void print_frame(int* frame,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<frame[i]<<" ";
	}
}
int get_position(int* frame,int size,int n)
{
	int *temp;
	temp=new int[size];
	for(int i=0;i<size;i++)
	{
		temp[i]=pages.size();
	}
	for(int i=0;i<size;i++)
	{
		for(int j=ind;j<pages.size();j++)
		{
			if(pages[j]==frame[i] && temp[i]>j)
			{
				temp[i]=j;
			}
		}
	}
	int max=temp[0],x=0;
	for(int i=1;i<size;i++)
	{
		if(temp[i]>max)
		{
			max=temp[i];
			x=i;
		}
	}
	return x;
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
void optimal_page_replacement()
{
	int*frame;
	int size;
	cout<<"enter frame size : ";
	cin>>size;
	frame=new int[size];
	for(int i=0;i<size;i++)
	{
		frame[i]=-1;
	}
	for(int i=0;i<size;i++)
	{
		cout<<pages[ind]<<" frame : ";
		frame[i]=pages[ind];
		print_frame(frame,size);
		ind++;
		cout<<"\n";
	}
	int n;
	while(ind<pages.size())
	{
		n=pages[ind];
		ind++;
		cout<<n<<" frame : ";
		if(not_present(frame,size,n))
		{
			int pos;
			pos=get_position(frame,size,n);
			frame[pos]=n;
			print_frame(frame,size);
		}
		cout<<"\n";
	}
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
	int n;
	while(fin>>n)
	{
		pages.push_back(n);
	}
	optimal_page_replacement();
	return 0;
}
