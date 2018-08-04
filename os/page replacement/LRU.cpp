#include<bits/stdc++.h>
using namespace std;
void print_buffer(int* buffer,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<buffer[i]<<" ";
	}
}
int get_position(int *count,int size)
{
	int ind=0;
	int max=count[0];
	for(int i=1;i<size;i++)
	{
		if(count[i] > max)
		{
			ind=i;
			max=count[i];
		}
	}
	return ind;
}
bool not_present(int* buffer,int size,int n)
{
	for(int i=0;i<size;i++)
	{
		if(buffer[i]==n)
			return false;
	}
	return true;
}
void LRU_page_replacement(ifstream &fin)
{
	int size;
	cout<<"Enter frame size : ";
	cin>>size;
	int *buffer;
	buffer=new int[size];
	int *count;
	count=new int[size];
	for(int i=0;i<size;i++)
	{
		buffer[i]=-1;
		count[i]=0;
	}
	for(int i=0;i<size;i++)
	{
		fin>>buffer[i];
		cout<<buffer[i]<<" FRAME : ";
		for(int j=0;j<=i;j++)
		{
			count[j]++;
		}
		print_buffer(buffer,size);
		cout<<"\n";
	}
	int n;
	while(fin>>n)
	{
		cout<<n<<" FRAME : ";
		if(not_present(buffer,size,n))
		{
			int ind;
			ind=get_position(count,size);
			buffer[ind]=n;
			count[ind]=0;
			for(int i=0;i<size;i++)
			{
				count[i]++;
			}
			print_buffer(buffer,size);
		}
		else
		{
			for(int i=0;i<size;i++)
			{
				if(buffer[i]==n)
				{
					count[i]=0;
					break;
				}
			}
			for(int i=0;i<size;i++)
			{
				count[i]++;
			}
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
	LRU_page_replacement(fin);
	return 0;
}
