#include <bits/stdc++.h>
using namespace std;
struct process
{
	int pid;
	int arrival;
	int burst;
	int priority;
};
bool mycomp(process a,process b)
{
	return a.arrival<b.arrival;
}
void sjf_premp(process *arr,int size)
{
	int totalburst=0;
	for(int i=0;i<size;i++)
	{
		totalburst+=arr[i].burst;
	}
	int i,j,total=0,prev=0;
	int finish[size],min,nextprocess,waittime=0;
	int previous[size],prevproc,prevproctime=0;
	for(j=0;j<size;j++)
	{
		finish[j]=0;
		previous[j]=0;
	}
	for(i=0;i<=totalburst;i++)
	{
		min=INT_MAX;
		nextprocess=INT_MIN;
		for(j=0;j<size;j++)
		{
			if(finish[j]==0 && min>arr[j].burst && arr[j].arrival<=i)
			{
				min=arr[j].burst;
				nextprocess=j;
			}
		}
		if(nextprocess==INT_MIN)
			break;
		if(prev==nextprocess)
		{
			arr[nextprocess].burst=arr[nextprocess].burst-1;
			if(arr[nextprocess].burst==0)
			{
				finish[nextprocess]=1;
			}
			continue;
		}
		else
		{
			waittime+=i-max(arr[nextprocess].arrival,previous[nextprocess]);
			arr[nextprocess].burst--;
			previous[prev]=i;
			prev=nextprocess;
		}
	}
	double avg=(double)waittime/(double)size;
	cout<<"The average waiting time is "<<avg<<endl;
}

void realtime(process *arr,int size){

}

int main()
{
	process *arr;
	ifstream fin;
	fin.open("processes.txt");
	int size;
	fin>>size;
	arr=new process[size];
	for(int i=0;i<size;i++)
	{
		fin>>arr[i].pid;
		fin>>arr[i].arrival;
		fin>>arr[i].burst;
		fin>>arr[i].priority;
	}
	sjf_premp(arr,size);
	fin.close();
	return 0;
}
