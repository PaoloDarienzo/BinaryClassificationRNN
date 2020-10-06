#include<stdio.h>
#include<string.h>
int queue1[105],queue2[105],pos[105];
char s[105][2];
int main()
{
  int T,N,i,j,head1,head2,tail1,tail2,position1,position2,time;
  scanf("%d",&T);
  for(i=1;i<=T;i++)
    {
      scanf("%d",&N);
      head1=0;
      tail1=0;
      head2=0;
      tail2=0;
      for(j=0;j<N;j++)
	{
	  scanf("%s %d",s[j],&pos[j]);
	  if(strcmp(s[j],"O")==0)
	    queue1[tail1++]=pos[j];
	  if(strcmp(s[j],"B")==0)
	    queue2[tail2++]=pos[j];
	}
      position1=1;
      position2=1;
      time=0;
      for(j=0;j<N;j++)
	{
	  if(strcmp(s[j],"O")==0)
	    {
	      while(position1!=pos[j])
		{
		  if(pos[j]<position1)
		    position1--;
		  if(pos[j]>position1)
		    position1++;
		  if(head2<tail2 && queue2[head2]<position2)
		    position2--;
		  if(head2<tail2 && queue2[head2]>position2)
		    position2++;
		  time++;
		}
	      head1++;
	      time++;
	      if(head2<tail2 && queue2[head2]<position2)
		position2--;
	      if(head2<tail2 && queue2[head2]>position2)
		position2++;	      
	    }
	  if(strcmp(s[j],"B")==0)
	    {
	      while(position2!=pos[j])
		{
		  if(pos[j]<position2)
		    position2--;
		  if(pos[j]>position2)
		    position2++;
		  if(head1<tail1 && queue1[head1]<position1)
		    position1--;
		  if(head1<tail1 && queue1[head1]>position1)
		    position1++;
		  time++;
		}
	      head2++;
	      time++;
	      if(head1<tail1 && queue1[head1]<position1)
		position1--;
	      if(head1<tail1 && queue1[head1]>position1)
		position1++;
	    }
	}
      printf("Case #%d: %d\n",i,time);
    }
  return 0;
}
