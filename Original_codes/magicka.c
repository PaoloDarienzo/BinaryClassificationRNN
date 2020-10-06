#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

typedef unsigned char bool;

char list[1010];
int sizeList, occursList[256];
char combine[256][256];
char opposed[256][32];
int top[256];


bool checkCombine(char elem)
{
  if(sizeList == 0)
    return false;
  
  if(combine[ (int)list[sizeList-1] ][ (int)elem ] == '!')
    return false;
  
  occursList[ (int)list[sizeList-1] ]--;
  
  list[sizeList-1] = combine[ (int)list[sizeList-1] ][ (int)elem ];

  occursList[ (int)list[sizeList-1] ]++;

  return true;
}

bool checkOpposed(char elem)
{
  int i, k;

  if(sizeList == 0)
    return false;
  
  for(i = 0; i < top[ (int)elem ] ; i++)
    if(occursList[ (int)opposed[ (int)elem ][i] ] > 0)
    {
      sizeList = 0;
      for(k = (int)'A'; k <= (int)'Z'; k++)
        occursList[k] = 0;
      return true;
    }
      
  return false;
}

int main()
{
  int T, cont = 0;
  
  scanf("%d\n", &T);
  
  while(T--)
  {
    int c, d, n;
    int i, k;
    char tmp[10];
    
    for(i = (int)'A'; i <= (int)'Z'; i++)
    {
      top[i] = 0;
      occursList[i] = 0;
      for(k = (int)'A'; k <= (int)'Z'; k++)
        combine[i][k] = '!';
    }
    
    scanf("%d ", &c);
    for(i = 0; i < c; i++)
    {
      int id0, id1;
      scanf("%s ", tmp);
      
      id0 = (int)tmp[0], id1 = (int)tmp[1];
      
      #ifdef _DEBUG
        printf("\nCombine: %c %c -> %c", (char)id0, (char)id1, tmp[2]);
      #endif
      
      combine[id0][id1] = combine[id1][id0] = tmp[2];
    }
      
    scanf("%d ", &d);
    for(i = 0; i < d; i++)
    {
      int id0, id1;
      scanf("%s ", tmp);
      
      id0 = (int)tmp[0], id1 = (int)tmp[1];
      
      #ifdef _DEBUG
        printf("\nOpposed: %c %c", (char)id0, (char)id1);
      #endif
      
      opposed[id0][top[id0]++] = id1;
      opposed[id1][top[id1]++] = id0;
    }
      
    scanf("%d ", &n);
    sizeList = 0;
    for(i = 0; i < n; i++)
    {
      char elem;
      
      scanf("%c", &elem);
      
      #ifdef _DEBUG
        printf("\nElement: %c ", elem);
      #endif
      
      if(checkCombine(elem) == true)
        continue ;
      
      #ifdef _DEBUG
        printf("-- not combine ");
      #endif
      
      if(checkOpposed(elem) == true)
        continue; 
      
      #ifdef _DEBUG
        printf("-- not opposed ");
      #endif
      
      list[sizeList++] = elem;
      occursList[ (int) elem]++;
    }
    
    #ifdef _DEBUG
      printf("\n\n");
    #endif
    
    printf("Case #%d: [", ++cont);
    for(i = 0; i < sizeList-1; i++)
      printf("%c, ", list[i]);
    if(sizeList > 0)
      printf("%c", list[sizeList-1]);
    printf("]\n");
  }
  
return 0;
}
