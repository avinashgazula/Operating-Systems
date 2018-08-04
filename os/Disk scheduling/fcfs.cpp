# include <bits/stdc++.h>
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
	int sum=0;
	cout<<"The Order is : ";
	for(int i=0;i<inp.size();i++)
	{
		cout<<init<<" ";
		sum+=abs(inp[i]-init);
		init=inp[i];
	}
	cout<<init<<"\n";
	cout<<"Total Head movement is : "<<sum<<" Cylinders"<<"\n"; 
	return 0;
}