#include<iostream>
#include<fstream>
using namespace std;

int main(){
string name;
string option;
cout<<"Enter fileName : ";
cin>>name;
cout<<"Enter -E or -n :";
cin>>option;
bool E = false;
bool N = false;
if(option == "-E")
E = true;
else if(option == "-n")
N = true;
fstream file;
file.open(name.c_str());
if(!file)
cout<<"No such file or directory";
else{
int i=1;
string s;
getline(file,s);
while(file){
if(N)
cout<<i<<". ";
i++;
cout<<s;
if(E) cout<<"$";
cout<<endl;
getline(file,s);
}
}
}
