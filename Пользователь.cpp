#include <iostream>

#include <conio.h>

#include <stdio.h>

#include <time.h>

#include <fstream>

#include <string>

using namespace std;

struct names

{string s1;

int l;

names *next,*prev;

};

struct surnames

{string s2;

int k;

surnames *next,*prev;

};

class Cname

{private:

ofstream f,sur,g;

string a;

names *nnew,*tec,*start;

surnames *nnew_s,*tec_s,*start_s;

int max_names,max_surnames;

public:

Cname(void);

void build_names(void);

void build_surnames(void);

void create(void);

};

Cname::Cname(void)

{max_names=1;

max_surnames=1;

build_names();

build_surnames();

create();

f.close();

sur.close();

g.close();

}

void Cname::build_names(void)

{string s; int i=0;

ifstream f("name.txt");

tec=new names;

tec->prev=NULL;

tec->next=NULL;

start=tec;

while(f.good())

{getline(f,s);

tec->s1=s;

tec->l=i;

i++;

max_names++;

nnew=new names;

nnew->prev=tec;

nnew->next=NULL;

tec->next=nnew;

tec=nnew;

//cout<<s<<"\n";

}

tec=start;

f.close();

}

void Cname::build_surnames(void)

{string s; int i=0;

ifstream sur("surname.txt");

tec_s=new surnames;

tec_s->prev=NULL;

tec_s->next=NULL;

start_s=tec_s;

while(sur.good())

{getline(sur,s);

tec_s->s2=s;

tec_s->k=i;

i++;

max_surnames++;

nnew_s=new surnames;

nnew_s->prev=tec_s;

nnew_s->next=NULL;

tec_s->next=nnew_s;

tec_s=nnew_s;

//cout<<tec_s->s2;

}

tec_s=start_s;

sur.close();

}

void Cname::create(void)

{int c=500,q,w,j,password;double q1,w1,p1;

srand(time(NULL));

ofstream g("zapros_500.txt");

for(int i=0;i<500;i++)

{q1=rand();

q=1+(q1/32767)*(max_names-1);

q1=q1/32767.0;

cout<<q1<<"\n";

w1=rand();

w=1+(w1/32767)*(max_surnames-1);

password=rand();

//cout<<q<<" "<<w<<" "<<password<<endl;

tec=start;

tec_s=start_s;

for(j=0;j<q;j++)

tec=tec->next;

for(j=0;j<w;j++)

tec_s=tec_s->next;

//cout<<"Insert into User SET User_name='"<<tec->s1<<"', User_surnames='"<<tec_s->s2<<"', Login='"<<i<<"', Password='"<<password<<"', User_ID="<<i+1<<";\n";

g<<"Insert into User SET User_name='"<<tec->s1<<"', User_surname='"<<tec_s->s2<<"', Login='"<<i<<"', Password='"<<password<<"', User_ID="<<i+1<<";\n";

}

g.close();

}

int main (void)

{setlocale(LC_ALL,"Russian");

Cname g;

_getch();

}
