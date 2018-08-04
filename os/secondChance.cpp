#include <bits/stdc++.h>
using namespace std;
int* sc;
int *ar;
int get_position(int* buffer,int size){
	int min=INT_MAX, pmin=size;
	for(int i=0;i<size;i++){
		if(ar[i]<min&&sc[i]==0){
			min=ar[i];
			pmin=i;
			//sc[i]=0;
		}
	}
	for(int i=0;i<size;i++){
		if(ar[i]<min) sc[i]=0;
	}
	return pmin;
}
void print_buffer(int* buffer,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<buffer[i]<<":"<<sc[i]<<"  ";
	}
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
void FIFO_page_replacement(ifstream &fin)
{
	int size;
	int* buffer;
	cout<<"enter buffer size : ";
	cin>>size;
	buffer=new int[size];
    sc = new int[size];
    ar = new int[size];
	for(int i=0;i<size;i++)
	{
		buffer[i]=-1;
        sc[i]=0;
        ar[i]=-1;
	}
	int n;
	for(int i=0;i<size;i++)
	{
		fin>>n;
		cout<<n<<" ";
		buffer[i]=n;
		ar[i]=i;
		cout<<"BUFFER : ";
		print_buffer(buffer,size);
		cout<<"\n";
	}
	int out=0;
	int i=size;
	while(fin>>n)
	{
		cout<<n<<" ";
		cout<<"BUFFER : ";
        if(!not_present(buffer,size,n)){

            for(int i=0;i<size;i++){
                if(buffer[i]==n){
                    sc[i]=1;
                    break;
                }
            }

        }
		if(not_present(buffer,size,n))
		{
            if(sc[out]==0){
                buffer[out]=n;
                ar[out]=i;
			    out=(out+1)%size;
            }
            else{
                /*/sc[out]--;
                /int temp = (out+1)%size;
                while(sc[temp]==1){
                    sc[temp]=0;
                    temp = (temp+1)%size;
                }
                sc[temp]=0;*/
                int temp = get_position(buffer,size);
                buffer[temp]=n;
                ar[temp]=i;
            }
			
		}
		print_buffer(buffer,size);
		cout<<"\n";
		i++;
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
	FIFO_page_replacement(fin);
	return 0;
}
