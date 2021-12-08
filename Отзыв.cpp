#include <iostream>

#include <conio.h>

#include <stdio.h>

#include <time.h>

#include <fstream>

#include <string>

using namespace std;

class Cref

{private:

ofstream g;

public:

Cref(void);

void create(void);

};

Cref::Cref(void)

{create();

}

void Cref::create(void)

{double num,user,simv;

int ref_num,user_id,y,m,d,h,min,s;

char c;

string message;

srand(time(NULL));

ofstream g("8_reference.sql");

for(int i=0;i<1000;i++)

{num=rand();

ref_num=1+(num/32767)*5;

for(int j=0;j<ref_num;j++)

{user=rand();

user_id=1+(user/double(32767))*500;

simv=rand();

c=192+(simv/double(32767.0))*31;

message.clear();

message.push_back(c);

for(int k=0;k<20;k++)

{simv=rand();

c=224+(simv/double(32767.0))*31;

message.push_back(c);

}

y=2008+rand()/(32767.0)*3;m=rand()/(double(32767))*12;d=1+rand()/(double(32767))*30;h=rand()/(double(32767))*24;min=rand()/(32767.0)*60;s=rand()/(double(32767))*60;

g<<"Insert into Reference SET Ref_User_ID="<<user_id<<", Ref_Recipe_ID="<<i+1<<", Message='"<<message<<"', Date='"<<y<<"-"<<m<<"-"<<d<<" "<<h<<":"<<min<<":"<<s<<"';\n";

}

}

g.close();

}

int main (void)

{setlocale(LC_ALL,"Russian");

Cref g;

_getch();

}
