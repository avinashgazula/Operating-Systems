#include<iostream>
#include<cstring>
#include<fstream>
#include<dirent.h>
using namespace std;

int main(){
DIR* dir = NULL;
struct dirent* ent = NULL;
string path;
cout<<"Enter path :";
cin>>path;
 
if(dir = opendir(path.c_str())){
while((ent = readdir(dir))!=NULL){
cout<<ent->d_name<<endl;
}
}
}
