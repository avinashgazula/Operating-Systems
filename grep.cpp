#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main(){
ifstream file;
char pattern[30]; string fileName;
char option[5];
cout<<"Enter -n or -x : ";
cin>>option;
bool X= false;
bool N =false;
if(!strcmp(option,"-x")) X=true; 
 if(!strcmp(option, "-n")) N=true;
cout<<"Enter Pattern :";
cin>>pattern;
cout<<"Enter FileName :";
cin>>fileName;
file.open(fileName.c_str());
bool present = false;
string s;
getline(file,s);int l =0;
 while(!file.eof())
{ l++;
 if(X){
   if(s == pattern) cout<<s<<endl;
}else{
  for(int i=0; i<=strlen(s.c_str())-strlen(pattern); i++){
   if(s.substr(i,strlen(pattern)) == pattern){
   present = true;break;}
  }
  if(present){
   if(N)
   cout<<l<<". ";
   cout<<s<<endl;
   present = false;
  }}
  file>>s;
 }
 file.close();
}
