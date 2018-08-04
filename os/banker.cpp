#include <bits/stdc++.h>
using namespace std;
int p_num;
int r_num;
vector<int> res;
vector<int> d;
bool is_less(int**need,int*work,int ind)
{
	for(int i=0;i<r_num;i++)
	{
		if(need[ind][i] > work[i])
			return false;
	}
	return true;
}
bool is_less_(int**need,int*work,int ind)
{
	for(int i=0;i<r_num;i++)
	{
		if(need[ind][i] < work[i])
			return false;
	}
	return true;
}
bool is_less_than(int*r,int*avai)
{
	for(int i=0;i<r_num;i++)
	{
		if(r[i] > avai[i])
			return false;
	}
	return true;
}
bool get_safe_seq(int** alloc,int* avai,int** need)
{
	int* work;
	bool* finish;
	work=new int[r_num];
	finish=new bool[p_num];
	for(int i=0;i<r_num;i++)
	{
		work[i]=avai[i];
	}
	for(int i=0;i<p_num;i++)
	{
		finish[i]=false;
	}
	int x=0;
	res.clear();
	while(1)
	{
		int ind=-1;
		for(int i=0;i<p_num;i++)
		{
			if(!finish[i] && is_less(need,work,i))
			{
				ind=i;
				res.push_back(i);
				break;
			}
		}
		if(ind==-1)
		{
			break;
		}
		for(int i=0;i<r_num;i++)
		{
			work[i]+=alloc[ind][i];
		}
		finish[ind]=true;
	}
	for(int i=0;i<p_num;i++)
	{
		if(!finish[i])
		{
			d.push_back(i);
		}
	}
    if(d.size()!=0) return false;
	return true;
}
void check_request_grant(int*r,int**need,int*avai,int**alloc,int id)
{
	if(!is_less_(need,r,id))
	{
		cout<<"p"<<id<<" has extended max limit. ERROR\n";
		return;
	}
	if(!is_less_than(r,avai))
	{
		cout<<"p"<<id<<" must wait since resources are not avalilable\n";
		return;
	}
	for(int i=0;i<r_num;i++)
	{
		avai[i]-=r[i];
		alloc[id][i]+=r[i];
		need[id][i]-=r[i];
	}
	if(get_safe_seq(alloc,avai,need))
		cout<<"resources can be granted for p"<<id<<"\n";
	else
	{
		for(int i=0;i<r_num;i++)
		{
			avai[i]+=r[i];
			alloc[id][i]-=r[i];
			need[id][i]+=r[i];
		}
		cout<<"resources cannot be granted to p"<<id<<" as the resulting state is not safe\n";
		cout<<"deadlock between\n";
		for(int i=0;i<d.size();i++){
			cout<<d[i]<<" ";
		}
		d.clear();
	}
}
int main()
{
	ifstream fin;
	fin.open("proc.txt");
	if(!fin)
	{
		cout<<"error opening file\n";
		exit(0);
	}
	fin>>p_num;
	fin>>r_num;
	int **alloc;
	int **req;
	int *avai;
	avai=new int[r_num];
	for(int i=0;i<r_num;i++)
	{
		fin>>avai[i];
	}
	alloc=new int*[p_num];
	req=new int*[p_num];
	for(int i=0;i<p_num;i++)
	{
		alloc[i]=new int[r_num];
		req[i]=new int[r_num];
	}
	for(int i=0;i<p_num;i++)
	{
		int j=0;
		while(j<r_num)
		{
			fin>>alloc[i][j];
			j++;
		}
		fin>>j;
		j=0;
		while(j<r_num)
		{
			fin>>req[i][j];
			j++;
		}
		fin>>j;
	}
	fin.close();
	cout<<"avalilable : ";
	for(int i=0;i<r_num;i++)
	{
		cout<<avai[i]<<" ";
	}
	cout<<"\n";
	cout<<"Allocation : \n";
	for(int i=0;i<p_num;i++)
	{
		for(int j=0;j<r_num;j++)
		{
			cout<<alloc[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"max : \n";
	for(int i=0;i<p_num;i++)
	{
		for(int j=0;j<r_num;j++)
		{
			cout<<req[i][j]<<" ";
		}
		cout<<"\n";
	}
	int**need;
	need=new int*[p_num];
	for(int i=0;i<p_num;i++)
	{
		need[i]=new int[r_num];
	}
	for(int i=0;i<p_num;i++)
	{
		for(int j=0;j<r_num;j++)
		{
			need[i][j]=req[i][j]-alloc[i][j];
		}
	}
	if(get_safe_seq(alloc,avai,need))
	{
		cout<<"the safe sequence is :\n";
		for(int i=0;i<res.size();i++)
		{
			cout<<"p"<<res[i]<<" ";
		}
	}
	else
	{
		cout<<"there is no safe sequence ";
	}
	int id;
	cout<<"enter processid : ";
	cin>>id;
	while(id!=-1)
	{
		int *r;
		r=new int[r_num];
		cout<<"enter the resource request need :\n";
		for(int i=0;i<r_num;i++)
		{
			cin>>r[i];
		}
		check_request_grant(r,need,avai,alloc,id);
		cout<<"\n\n";
			cout<<"Allocation : \n";
			for(int i=0;i<p_num;i++)
			{
				for(int j=0;j<r_num;j++)
				{
					cout<<alloc[i][j]<<" ";
				}
				cout<<"\n";
			}
		cout<<"enter processid : ";
		cin>>id;
	}
	return 0;
}
