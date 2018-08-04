#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main(){
fstream file;
string fileName;
string option;
cout<<"Enter fileName : ";
cin>>fileName;
cout<<"Enter -l or -w : ";
cin>>option;
file.open(fileName.c_str());
int word=0, line=0;
string s;
getline(file, s);
while(file){
line++;
word++;
for(int i=0; i<strlen(s.c_str()); i++){
  if(s[i] == ' ')
   word++;
   while(s[i]==' '){
     i++;
   }
   }
file>>s;
}
if(option == "-w")
cout<<"Words :"<<word;
else if(option == "-l")
cout<<" Lines :"<<line<<endl;

}
