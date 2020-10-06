#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp1,*fp2;
	int s,q,qname[1000],i,j,n,se[100]={0},ans=0,nz=0,n1,k;
	char sname[100][100],qnm[100];
	fp1=fopen("abc.in","r");
	fp2=fopen("abc.out","w");
	fscanf(fp1,"%d",&n);
	n1=n;
	while(n--)
	{
		ans=0;
	   fscanf(fp1,"%d",&s);
	   for(i=0;i<s;i++)
	   {
		fgets(sname[i],100,fp1);
		if(strcmp(sname[i],"\n")==0)i--;
	   }
	   fscanf(fp1,"%d",&q);
	   for(i=0;i<q;i++)
	   {
		fgets(qnm,100,fp1);
		if(strcmp(qnm,"\n")==0){i--;continue;}
		for(j=0;j<s;j++)
		if(strcmp(qnm,sname[j])==0)
		{
			qname[i]=j;
			break;
		}
	   }
	   for(i=0;i<s;i++)
	   se[i]=0;
	   for(i=0;i<q;i++)
	   {
		se[qname[i]]=1;
		nz=0;
		for(j=0;j<s;j++)
		if(se[j]==0){nz++;}
		if(nz==0)
		{
			ans++;
			for(k=0;k<s;k++)
			se[k]=0;
			i--;
		}
	   }
	   fprintf(fp2,"Case #%d: %d\n",n1-n,ans);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}