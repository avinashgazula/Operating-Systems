# include <bits/stdc++.h>
using namespace std;

int init=53;
int last=199;
int first=0;
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
	int sum=0;
	sort(inp.begin(),inp.end());
	int x=0;
	while(inp[x]<init)
	{
		x++;
	}
	int y=x-1;
	cout<<"The order is : ";
    int i=y;
	while(i>=0)
	{
		cout<<init<<" ";
		sum+=abs(inp[i]-init);
		init=inp[i];
		i--;
	}
	while(x<inp.size())
	{
		cout<<init<<" ";
		sum+=abs(inp[x]-init);
		init=inp[x];
		x++;
	}
	cout<<init<<" ";
	cout<<"\nTotal Head movement is : "<<sum<<" Cylinders"<<"\n"; 
	return 0;
}