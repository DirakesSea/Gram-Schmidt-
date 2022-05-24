#include <stdio.h>
#include <math.h>
#define EPS 1e-6

double mol(double a[],double b[],int n)
{
  int i;
  double sum=0;
  for(i=0;i<n;i++) sum=sum+a[i]*b[i];
  return sum;
}

int equal(double a[],int n)
{
   int flag=0,i;
   for(i=0;i<n;i++)
   {
       if(a[i]>=EPS||a[i]<=-EPS)  
	    return flag;
   }
    flag=1; 
	return flag;
}

int main()
{
   int n,m,i,j,flag=1,k;
   scanf("%d%d",&n,&m);
   double a[m][n],q[m][n];
   for(i=0;i<m;i++)
   {
       for(j=0;j<n;j++)
       {
           scanf("%lf",&a[i][j]);
       }
       
   }
   for(i=0;i<m;i++)
   {
     if(i==0)
	 {
	  for(j=0;j<n;j++) 
	   q[i][j]=a[i][j];
	  if(equal(q[i],n)==1)
	  { flag=0;
	    break;
	  }
	  else
	  {
	   for(j=0;j<n;j++) 
	   q[i][j]=q[i][j]/(sqrt(mol(q[i],q[i],n)));	
	  }	
	 }
	 else 
	{
	 for(j=0;j<n;j++) 
	   q[i][j]=a[i][j];
	 for(k=1;k<i;k++)
	 {
	   for(j=0;j<n;j++)
	   {
	   	q[i][j]=q[i][j]-mol(q[k],a[i],n)*q[k][j];
	   }
	   
     }
	 if(equal(q[i],n)==1)
	 {
	   flag=0;
	   break;	
	 }
	 else
	 {
	  for(j=0;j<n;j++) 
	   q[i][j]=q[i][j]/(sqrt(mol(q[i],q[i],n)));	
	 }  	
	}  
   }
   if(flag==1)
   {
   	printf("NO\n");
   	for(j=0;j<n;j++)
   	{
   	  if(j==0) printf("%.2lf",q[m-1][j]);
      else 	  printf(" %.2lf",q[m-1][j]);
	}
   }
   else printf("YES %d",i+1);
    
    
}