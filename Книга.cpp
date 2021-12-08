#include "stdafx.h"

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

ofstream g;

public:

Cname(void);

void create(void);

};

Cname::Cname(void)

{create();

}

void Cname::create(void)

{float c1,h1,t1;

string book_name, author, descr;char c,h,t;

srand(time(NULL));

ofstream g("book.txt");

for(int i=0;i<50;i++)

{author.clear();

book_name.clear();

descr.clear();

c1=rand();

h1=rand();

t1=rand();

c=192+(c1/32767)*31;

h=192+(h1/32767)*31;

t=192+(t1/32767)*31;

author.push_back(c);

book_name.push_back(h);

descr.push_back(t);

for(int j=0; j < 7; j++)

{c1=rand();

h1=rand();

t1=rand();

c=224+(c1/32767)*31;

h=224+(h1/32767)*31;

t=224+(t1/32767)*31;

author.push_back(c);

book_name.push_back(h);

descr.push_back(t);

}

cout<<"Insert into Book SET Book_ID='"<<i+1<<"', Title='"<< book_name<<"', Author='"<<author<<"', Description='"<<descr<<"';\n";

g<<"Insert into Book SET Book_ID='"<<i+1<<"', Title='"<< book_name<<"', Author='"<<author<<"', Description='"<<descr<<"';\n";}

g.close();

}

int main (void)

{setlocale(LC_ALL,"Russian");

Cname g;

_getch();

}
