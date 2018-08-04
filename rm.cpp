#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<dirent.h>
using namespace std;

int main(){
string name;
string option;
cout<<"Enter -i or -d\n";
cin>>option;
if(option == "-i"){
cout<<"Enter filename\n";
cin>>name;
char ch;
cout<<"Are you sure you want to delete? :";
cin>>ch;
if(ch == 'y'){
if(remove(name.c_str())==0)
cout<<"file deleted\n";
else
cout<<"file either doesn't exist or can't be deleted\n";
}}
else if(option == "-d"){
 cout<<"Enter directory Name :";
	cin>>name;
 DIR *pdir = NULL;
struct dirent* sdir = NULL;
char s2[]="./";
pdir= opendir(strcat(s2,name.c_str()));
if(pdir == NULL) cout<<"Directory not found";
else{
int n=0;
while (sdir=readdir(pdir)){
if(sdir!=NULL) n++;
if(n==2){
remove(name.c_str());
cout<<"directory deleted";
}
}
}

}
}
