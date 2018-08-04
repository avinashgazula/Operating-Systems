#include <bits/stdc++.h>
using namespace std;
int* sc;
int *ar;
int get_position(int* frame,int size){
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
void print_frame(int* frame,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<frame[i]<<":"<<sc[i]<<"  ";
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
	cout<<"enter frame size : ";
	cin>>size;
	frame=new int[size];
    sc = new int[size];
    ar = new int[size];
	for(int i=0;i<size;i++)
	{
		frame[i]=-1;
        sc[i]=0;
        ar[i]=-1;
	}
	int n;
	for(int i=0;i<size;i++)
	{
		fin>>n;
		cout<<n<<" ";
		frame[i]=n;
		ar[i]=i;
		cout<<"frame : ";
		print_frame(frame,size);
		cout<<"\n";
	}
	int out=0;
	int i=size;
	while(fin>>n)
	{
		cout<<n<<" ";
		cout<<"frame : ";
        if(!not_present(frame,size,n)){

            for(int i=0;i<size;i++){
                if(frame[i]==n){
                    sc[i]=1;
                    break;
                }
            }

        }
		if(not_present(frame,size,n))
		{
            if(sc[out]==0){
                frame[out]=n;
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
                int temp = get_position(frame,size);
                frame[temp]=n;
                ar[temp]=i;
            }
			
		}
		print_frame(frame,size);
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
