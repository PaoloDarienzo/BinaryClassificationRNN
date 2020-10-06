#include<stdio.h>
int main()
{
  int t,n,covered[55],pos,i,j,k,k1,done[26],l,test;
  char s[55][55],rot[55][55];
  scanf("%d",&t);
  test=1;
  while(t--)
    {
      scanf("%d %d",&n,&k1);
      for(i=0;i<n;i++)
	scanf("%s",s[i]);
      for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	      rot[i][j]=s[j][i];
      /*
      printf("\n");
      for(i=0;i<n;i++)
	{
	  for(j=0;j<n;j++)
	    printf("%c",rot[i][j]);
	  printf("\n");
	}
      printf("\n");
      */
      for(i=0;i<n;i++)
	covered[i]=0;
      for(i=0;i<26;i++)
	done[i]=0;
      for(i=n-1;i>=0;i--)
	for(j=0;j<n;j++)
	  if(rot[i][j]=='.' && covered[j]==0)
	    {
	      pos=i  ;
	      for(k=i-1;k>=0;k--)
		if(rot[k][j]=='R' || rot[k][j]=='B')
		  {
		    rot[pos][j]=rot[k][j];
		    rot[k][j]='.';
		    pos--;
		  }
	      covered[j]=1;
	    }
      /*
      printf("\n");
      for(i=0;i<n;i++)
	{
	  for(j=0;j<n;j++)
	    printf("%c",rot[i][j]);
	  printf("\n");
	}
      printf("\n");
      */
      for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	  {
	    if(i<=(n-k1) && rot[i][j]!='.')
	      {
		for(l=0;l<k1 && rot[i+l][j]==rot[i][j];l++);
		if(l>=k1)
		  done[(int)rot[i][j]-65]=1;
	      }
	    if(j<=(n-k1) && rot[i][j]!='.')
	      {
		for(l=0;l<k1 && rot[i][j+l]==rot[i][j];l++);
		if(l>=k1)
		  done[(int)rot[i][j]-65]=1;
	      }
	    if(i<=(n-k1) && j<=(n-k1) && rot[i][j]!='.')
	      {
		for(l=0;l<k1 && rot[i+l][j+l]==rot[i][j];l++);
		if(l>=k1)
		  done[(int)rot[i][j]-65]=1;
	      }
	    if(i<=(n-k1) && j>=(k1-1) && rot[i][j]!='.')
	      {
		for(l=0;l<k1 && rot[i+l][j-l]==rot[i][j];l++);
		if(l>=k1)
		  done[(int)rot[i][j]-65]=1;
	      }
	  }
      if(done[17] && done[1])
	printf("Case #%d: Both\n",test++);
      else if(done[17])
	printf("Case #%d: Red\n",test++);
      else if(done[1])
	printf("Case #%d: Blue\n",test++);
      else
	printf("Case #%d: Neither\n",test++);
    }
  return 0;
}
