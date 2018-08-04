#include<iostream>
#include<fstream>
#include<string.h>
#include<dirent.h>
using namespace std;

int main(){
DIR *dir;
struct dirent *ent;
string s;
cout<<"Enter -a or -A :";
cin>>s;
bool test = false;
bool test2 = false;
if(s == "-a")
test = true;
if(s == "-A")
test2 = true;

if ((dir = opendir (".")) != NULL) {
  while ((ent = readdir (dir)) != NULL) {
   	 char* s = ent->d_name;
	   if(!test && !test2){
	   if(s[0] != '.')
	   cout<<s<<endl;
           }
	   else if(test2){
	    if((strcmp(s,".") && strcmp(s,"..")))
	    cout<<s<<endl;
           }
	   else
	   cout<<s<<endl;
	 
  }
  closedir (dir);
} else {
  cout<<"could not open directory";
}
}
