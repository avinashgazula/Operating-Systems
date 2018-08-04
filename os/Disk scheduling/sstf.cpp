#include <bits/stdc++.h>
using namespace std;
int init=53;
vector<int> inp;
int main()
{
	ifstream fin;
	fin.open("input.txt");
	int n;
	while(fin>>n)
	{
		inp.push_back(n);
		cout<<n<<" ";
	}
	cout<<"\n";
	fin.close();
	sort(inp.begin(),inp.end());
	int x=0,y=0;
	while(inp[x]<=init)
		x++;
	y=x;
	x--;
	int sum=0;
	cout<<"The order is : ";
	while(x>=0 || y<inp.size())
	{
		cout<<init<<" ";
		if(x<0)
		{
			sum+=abs(init-inp[y]);
			init=inp[y];
			y++;
		}
		else if(y>=inp.size())
		{
			sum+=abs(init-inp[x]);
			init=inp[x];
			x--;
		}
		else
		{
			int a=abs(init-inp[y]);
			int b=abs(init-inp[x]);
			if(a<b)
			{
				sum+=a;
				init=inp[y];
				y++;
			}
			else
			{
				sum+=b;
				init=inp[x];
				x--;
			}
		}
	}
	cout<<init<<"\n";
	cout<<"Total Head movement is : "<<sum<<" Cylinders"<<"\n";
	return 0;
}