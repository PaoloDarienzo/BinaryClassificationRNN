#include<stdio.h>

int posiciones[1001];
int vector[1010],vec2[1010];
int indice,indexy,ante;
long long venta[1001];
int n,k,r,tam;

long long plan()
{
 int i;
 long long cap;
 cap=0;
 tam=0;
 while(cap<k)
 {
  if((cap+vector[indice%n])<=k&&tam<n)
  {
   cap+=vector[indice%n];
   vec2[tam]=vector[indice%n];
   indice++;
   tam++;
  }
  else break;
 }
 return cap;
}

int buscar()
{
 int i;
 for(i=0;i<indexy;i++)
  if(posiciones[i]==(ante%n))return i;
 return -1;
}

main()
{
 int t,i,j,c,pos,x;
 long long total,tot,totAnt,totBloque;
 int aux,bloque;
 FILE *f=fopen("theme.in","r");
 while(fscanf(f,"%d",&t)==1)
 {
  c=1;
  for(i=0;i<t;i++)
  {
   tot=0;
   total=0;
   indice=0;
   indexy=0;
   x=0;
   fscanf(f,"%d %d %d",&r,&k,&n);
   for(j=0;j<n;j++)fscanf(f,"%d",&vector[j]);
   while(x<r)
   {
    ante=indice;
    tot=plan();
    pos=buscar();
    if(pos<0){total+=tot;posiciones[indexy]=ante%n;venta[indexy]=tot; indexy++;x++;}
    else break;   
   }
   if(x<r)
   {
    totAnt=0;
    totBloque=0;
    for(j=0;j<pos;j++)totAnt+=venta[j];
    for(j=pos;j<indexy;j++)totBloque+=venta[j];
    aux=r-pos;
    tot=totAnt;
    bloque=indexy-pos;
    tot+=(aux/bloque)*totBloque;
    for(j=0;j<(aux%bloque);j++)
    { tot+=venta[pos%indexy];pos++;}
    printf("Case #%d: %lld\n",c,tot);
   }
   else
    printf("Case #%d: %lld\n",c,total);
   c++;
  }
 }
 fclose(f);
}
