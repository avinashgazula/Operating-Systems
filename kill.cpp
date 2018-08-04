#include<iostream>
#include<csignal>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main(){
system("ps");

int pid;
cout<<"Enter process id :";
cin>>pid;
if(kill(pid,SIGKILL))
cout<<"process killed";
else
cout<<"process can't be killed";
system("ps");
}
