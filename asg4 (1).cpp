#include <bits/stdc++.h>
using namespace std;
struct process
{
	int pid;
	int arrival;
	int burst;
	int priority;
};
bool arrival(process a,process b)
{
	return a.arrival<b.arrival;
}
bool burst(process a,process b)
{
	return a.burst<b.burst;
}
bool pri(process a,process b)
{
	return a.priority<b.priority;
}
void FCFS(process* arr,int sz)
{
	cout<<"\n";
	cout<<"First come First serve scheduling : \n";
	sort(arr,arr+sz,arrival);
	int sum=0;
	int x=0;
	for(int i=0;i<sz;i++)
	{
		cout<<arr[i].pid<<"\t"<<arr[i].arrival<<"\t"<<arr[i].burst<<"\t"<<arr[i].priority<<"\t"<<sum<<endl;
		x+=sum;
		sum+=arr[i].burst;

	}
	double ans=(double)x/double(sz);
	cout<<"Avg waiting time is "<<ans<<endl;
}
void SJF(process* arr,int sz)
{
	cout<<"\n";
	cout<<"Shortest Job first Scheduling \n";
	sort(arr,arr+sz,burst);
	int sum=0,x=0;
	for(int i=0;i<sz;i++)
	{
		cout<<arr[i].pid<<"\t"<<arr[i].arrival<<"\t"<<arr[i].burst<<"\t"<<arr[i].priority<<"\t"<<sum<<endl;
		x+=sum;
		sum+=arr[i].burst;
	}
	double ans=(double)x/double(sz);
	cout<<"Avg waiting time is "<<ans<<endl;
}
void priority(process* arr,int sz)
{
	cout<<"\n";

	cout<<"Priority based Scheduling \n";
	sort(arr,arr+sz,pri);
	int sum=0,x=0;
	for(int i=0;i<sz;i++)
	{
		cout<<arr[i].pid<<"\t"<<arr[i].arrival<<"\t"<<arr[i].burst<<"\t"<<arr[i].priority<<"\t"<<sum<<endl;
		x+=sum;
		sum+=arr[i].burst;
	}
	double ans=(double)x/double(sz);
	cout<<"Avg waiting time is "<<ans<<endl;
}
int get_next(process* arr,int size,int &p)
{
	int x=p;
	int c=0;
	while(c<size)
	{
		if(arr[p].burst > 0)
		{
			int x=p;
			p=(p+1)%size;
			return x;
		}
		else
		{
			p=(p+1)%size;
			c+=1;
		}
	}
	return -1;
}
void round_robin(process *arr,int size)
{
	sort(arr,arr+size,arrival);
	cout<<"Round Robin Scheduling \n";
	int In;
	cout<<"Enter the Interval : ";
	cin>>In;
	int *prev_time;
	prev_time=new int[size];
	for(int i=0;i<size;i++)
	{
		prev_time[i]=0;
	}
	int x=0;
	int t=0;
	int p=0;
	while(1)
	{
		int ind=get_next(arr,size,p);
		if(ind==-1)
		{
			break;
		}
		cout<<arr[ind].pid<<"\t";
		cout<<t<<" to ";
		x+=t-prev_time[ind];
		if(arr[ind].burst < In)
		{
			t+=arr[ind].burst;
			arr[ind].burst=0;
		}
		else
		{
			t+=In;
			arr[ind].burst-=In;
		}
		prev_time[ind]=t;
		cout<<t<<endl;
	}
	double ans=(double)x/double(size);
	cout<<"Avg waiting  time is : "<<ans<<endl;
}
int main()
{
	process *arr;
	ifstream fin;
	cout<<"processid  arrival  burst  priority \n";
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
	for(int i=0;i<size;i++)
	{
		cout<<arr[i].pid<<"\t"<<arr[i].arrival<<"\t"<<arr[i].burst<<"\t"<<arr[i].priority<<endl;
	}
	FCFS(arr,size);
	SJF(arr,size);
	priority(arr,size);
	round_robin(arr,size);
	return 0;
}