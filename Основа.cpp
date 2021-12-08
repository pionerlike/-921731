# include <stdio.h>
# include <string.h>
# include <stdlib.h>
int a,i,n,k, nr;
FILE *fp;
struct culinary
{
int number;
char name [25];
char ingridient [100];
int time;
int call;
int porcii;
char recept [500];
};
struct culinary book[100];
void find ();
void vivod ();
void dell ();
void add ();
void quick_struct( struct culinary book[], int count );
void qs_struct( struct culinary book[], int left, int right );


void main (void)
{
for (;
{
fp=fopen("book.det", "rb");

if (fp!=NULL)
{
for (i=0; i<100; i++)
{
int res;
res=fread (& book[i], sizeof (book[0]),1,fp);
if (res==0)
break;
}
nr=i;
}
fclose (fp);
printf ("Kolichestvo receptov v baze: %d\n",nr);

printf("\n Viberite deistvie:\n\n\n");
printf("1. Add culinary recept\n\n");
printf("2. Dell culinary recept\n\n");
printf("3. Find culinary recept\n\n");
printf("4. Vivod culinary book\n\n");
printf("5. Exit\n\n\n");
scanf ("%d",&a);

switch(a)
{
case 1: printf("Add culinary recept\n\n");
add ();
break;
case 2: printf("Dell culinary recept\n\n");
dell ();
break;
case 3: printf("Find culinary recept\n\n");
find ();
break;
case 4: printf("Vivod culinary book\n\n");
vivod ();
break;
case 5: exit(0);
default: printf("\n\nERROR!!! Please enter number 1-5...\n\n");
}
}
}
void add()
{
fopen("book.det","ab");
if (fp==NULL)
{
printf ("Error!\n");
exit(0);
}
i=nr;

book[i].number=nr;
printf ("Vvedite name recepta.\n");
fflush( stdin );
gets(book[i].name);


printf ("Vvedite ingridienti recepta.\n");
fflush( stdin );
gets(book[i].ingridient);

printf ("Vvedite vremia gotovki.\n");
scanf ("%d",&book[i].time);

printf ("Vvedite callorinost' bluda.\n");
scanf ("%d", &book[i].call);

printf ("Vvedite kol-vo porcii.\n");
scanf ("%d", &book[i].porcii);

printf ("Vvedite recept.\n");
fflush( stdin );
gets(book[i].recept);
printf ("\n\n");
nr++;
fwrite (&book[i],sizeof(book[0]),1,fp);
fclose (fp);
}
void dell()
{
fp=fopen("book.det","wb");
if (fp==NULL)
{
printf ("Spisok otsutstvyet!\n");
exit(0);
}
printf ("Vvedite number recepta dlia dell\n");
scanf ("%d", &n);
if (nr==0)
printf ("Spisok otsutstvyet");
for (k=0; k<n; k++)
{
fwrite (&book[k], sizeof(book[0]),1,fp);
}
for (k=n+1; k<nr; k++,n++)
{
book[k].number=n;
book[n]=book[k];
fwrite (&book[n], sizeof(book[0]),1,fp);
}
nr--;
printf ("\n\n");

fclose (fp);
}

void find()
{
int pos=1;
char ptr[40];
char *loc;
fp=fopen("book.det","rb");
if (fp==NULL)
{
printf ("Error!\n");
exit(0);
}
printf ("Vvedite stroky dlia poiska\n");
scanf ("%s", &ptr);
if (nr==0)
printf ("\nPoisk ne dal resultatov\n\n\n");
fread (&book[nr],sizeof(book[nr]),1,fp);// чтения файла
for (i=0; i<nr; i++)
{
loc=strstr(book[i].name,ptr);
if (loc==NULL)
{
loc=strstr(book[i].ingridient,ptr);
if (loc!=NULL)
{
printf (" %d.\n %s\n %s\n %s\n Vremia gotovki:%d minut\n Callorinost' bluda:%d call\n Kol-vo porcii: %d\n\n\n",book[i].number,book[i].name,book[i].ingridient,book[i].recept,book[i].time,book[i].call,book[i].porcii);
break;
}
else
pos=0;
}
else
{
printf (" %d.\n %s\n %s\n %s\n Vremia gotovki:%d minut\n Callorinost' bluda:%d call\n Kol-vo porcii: %d\n\n\n",book[i].number,book[i].name,book[i].ingridient,book[i].recept,book[i].time,book[i].call,book[i].porcii);
break;
}
}
if (pos==0)
printf ("\nPoisk ne dal resultatov\n\n");
fclose(fp);
}


void vivod()
{
int m;
struct culinary *ptr[25];
fp=fopen("book.det","rb");
if (fp==NULL)
{
printf ("pusto!\n");
exit(0);
}
ptr[0]=&book[0];

quick_struct( book, nr );


for (m=0; m<nr; m++)
{
printf (" %d.\n %s\n %s\n %s\n Vremia gotovki:%d minut\n Callorinost' bluda:%d call\n Kol-vo porcii: %d\n\n\n", book[m].number, book[m].name, book[m].ingridient, book[m].recept, book[m].time, book[m].call, book[m].porcii);
}
if (nr==0)
printf ("pusto\n\n\n");
fclose(fp);
}

void quick_struct( struct culinary items[], int count )
{
qs_struct( items, 0, count - 1 );
}

void qs_struct( struct culinary items[], int left, int right )
{
register int i, j;
char *x;
struct culinary tmp;
i = left;
j = right;
x = items[( left + right ) / 2].name;
do
{
while( ( strcmp( items[i].name, x ) < 0) && ( i < right) )
i++;
while( ( strcmp( items[j].name, x ) > 0) && ( j > left) )
j--;

if( i <= j)
{
tmp = items[i];
items[i] = items[j];
items[j] = tmp;
i++;
j--;
}
}while( i <= j );

if( left < j )
qs_struct( items, left, j );
if( i < right )
qs_struct( items, i, right );
}
