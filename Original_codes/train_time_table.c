#include<stdio.h>
#include<stdlib.h>
int conv(char temp[10])
{
	int i=0,t=0,j=0;
	char tmp1[3],tmp2[3];
	while(temp[i]!=':')
	{
		tmp1[j++]=temp[i++];
	}
	tmp1[j]='\0';
	i++;
	j=0;
	while(temp[i]!='\0')
	{
		tmp2[j++]=temp[i++];
	}
	tmp2[j]='\0';
	t=(atoi(tmp1)*60)+atoi(tmp2);
	return t;
}
void sort(int nd[100][2],int n)
{
	int i,j,k,t1,t2;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(nd[j][0]>nd[j+1][0])
			{
				t1=nd[j][0];
				t2=nd[j][1];
				nd[j][0]=nd[j+1][0];
				nd[j][1]=nd[j+1][1];
				nd[j+1][0]=t1;
				nd[j+1][1]=t2;
			}
		}
	}
}
int main()
{
	int n,t,na,nb,i,j,n1;
	int nad[100][2],nbd[100][2];
	int ca=0,cb=0;
	int tna=0,tnb=0;
	FILE *fp1,*fp2;
	char temp[10];
	fp1=fopen("abc.txt","r");
	fp2=fopen("abc.out","w");
	fscanf(fp1,"%d",&n);
	n1=n;
	while(n--)
	{       fscanf(fp1,"%d%d%d",&t,&na,&nb);
		i=0;
		while(i!=na)
		{
			fscanf(fp1,"%s",temp);
			nad[i][0]=conv(temp);
			fscanf(fp1,"%s",temp);
			nad[i][1]=conv(temp);
			i++;
		}
		i=0;
		while(i!=nb)
		{
			fscanf(fp1,"%s",temp);
			nbd[i][0]=conv(temp);
			fscanf(fp1,"%s",temp);
			nbd[i][1]=conv(temp);
			i++;
		}
		sort(nad,na);
		sort(nbd,nb);
		i=nad[0][0]<nbd[0][0]?nad[0][0]:nbd[0][0];
		ca=0;cb=0;tna=0;tnb=0;
		for(;i<24*60;i++)
		{
			for(j=0;j<na;j++)
			{
				if(nad[j][1]+t==i)
				cb++;
			}
			for(j=0;j<nb;j++)
			{
				if(nbd[j][1]+t==i)
				ca++;

			}

			for(j=0;j<na;j++)
			{
				if(nad[j][0]==i)
				if(ca>=1)
				ca--;
				else
				tna++;
			}
			for(j=0;j<nb;j++)
			{
				if(nbd[j][0]==i)
				if(cb>=1)
				cb--;
				else
				tnb++;
			}
		}
		fprintf(fp2,"Case #%d: %d %d\n",n1-n,tna,tnb);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}