#include <iostream>

#include <conio.h>

#include <stdio.h>

#include <time.h>

#include <fstream>

#include <string>

#include <math.h>

using namespace std;

class Ccomp

{private:

ofstream g;

public:

Ccomp(void);

void create(void);

};

Ccomp::Ccomp(void)

{create();

};

void Ccomp::create(void)

{double num,ingr,cond,measure,quant;

int comp_ingr, comp_num, comp_unit, comp_cond,quantity;

srand(time(NULL));

ofstream g("6_composition.sql");

for(int i=0;i<1000;i++)

{num=(rand()/double(32767));

comp_num=1+num*10;

for(int j=0;j<comp_num;j++)

{ingr=rand();

comp_ingr=1+(ingr/double(32767))*452;

cond=rand();

comp_cond=1+(cond/double(32767))*56;

measure=rand();

comp_unit=1+(measure/double(32767))*14;

quant=rand();

quantity=1+(quant/double(32767))*20;

g<<"Insert into Composition SET Comp_Ingredient_ID="<<comp_ingr<<", Comp_Recipe_ID="<<i+1<<", Comp_Unit_measure_ID="<<comp_unit<<", Comp_Condition_ID="<<comp_cond<<", Quantity="<<quantity<<";\n";

}

}

g.close();

}

int main (void)

{setlocale(LC_ALL,"Russian");

Ccomp g;

_getch();

}
