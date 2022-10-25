#include<stdio.h>
struct poly
{
    int coeff;
    int degree;
}p1[100],p2[100],p3[100];

int n1,n2,n,i,j,k,t;
void readPoly(struct poly[], int );
int addPoly(struct poly [],struct poly[],struct poly [],int,int);
void display(struct poly [],int k);

void main()
{
    printf("\nEnter the no of terms for polynomial 1 :");
    scanf("%d",&n1);
    readPoly(p1,n1);
    display(p1,n1);
    printf("\nEnter the no of terms for polynomial 2 :");
    scanf("%d",&n2);
    readPoly(p2,n2);
    display(p2,n2);
    t=addPoly(p1,p2,p3,n1,n1);
    printf("The sum is: \n");
    display(p3,t);

}

void readPoly(struct poly p[100],int n)
{
    printf("Enter Details in Decending order of degree\n");
    for(i=0;i<n;i++)
    {
        printf("Enter Coeff\n");
        scanf("%d",&p[i].coeff);
        printf("Enter Degree\n");
        scanf("%d",&p[i].degree);
    }
}

int addPoly(struct poly  p1[100],struct poly p2[100],struct poly p3[100],int n1,int n2)
{
    i=0;
    j=0;
    k=0;
    while(i<n1 && j<n2)
    {
        if(p1[i].degree==p2[j].degree)
        {
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            p3[k].degree=p1[i].degree;
            k++;i++;j++;
            
        }
        else if(p1[i].degree<p2[j].degree)
        {
            p3[k].degree=p2[j].degree;
            p3[k].coeff=p2[j].coeff;
            k++;j++;

        }
        else
        {
            p3[k].degree=p1[j].degree;
            p3[k].coeff=p1[j].coeff;
            k++;i++;
        }
    }
    while (i<n1)
    {
        p3[k].degree=p1[i].degree;
        p3[k].coeff=p1[i].coeff;
        k++;i++; 
    }
    while (j<n2)
    {
        p3[k].degree=p1[j].degree;
        p3[k].coeff=p1[j].coeff;
        k++;j++; 
    }
    return k;
}

void display(struct poly p[100],int k)
{
    for (i=0;i<k-1;i++)
        printf("%d(X^%d)+",p[i].coeff,p[i].degree);
    printf("%d(X^%d)",p[i].coeff,p[i].degree);
}




