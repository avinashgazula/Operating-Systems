#include<bits/stdc++.h>

using namespace std;
map<string,int> m;
ifstream fin;
void *add(void *v)
{
string s;
long off=(*(long *)v);
fin.seekg(off,ios::beg);
getline(fin,s);
cout<<s<<endl;
string wd;
stringstream so;
so<<s;
while(so>>wd)
{
if(m.find(wd)==m.end())
m[wd]=1;
else
m[wd]++;
}
}
int main(int argc,char *argv[])
{
fin.open("abc.txt");
while(fin)
{
pthread_t t;
long pos=fin.tellg();
pthread_create(&t,NULL,&add,(void *)(&pos));
//pthread_join(t,NULL);
}
map<string,int>::iterator it;
for(it=m.begin();it!=m.end();it++)
{
cout<<it->first<<" "<<it->second<<endl;
}

	return 0;
}

