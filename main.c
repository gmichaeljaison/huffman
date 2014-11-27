#include<iostream.h>
#include <stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#define max 200
#include"freqency.c"

struct tree
{
	char a[max];
	int s;
	struct tree *left,*right;
}*root=NULL,*tt[max]={NULL},*temp,*temp2,*t2,*ri,*le;

struct pqu
{
	int info;
	char a[max];
	struct pqu *ptr;
}*front=NULL,*t,*par,*t1,*p1,*p2;

struct pqu* fp(int info)
{
	struct pqu *p=NULL;
	for(t1=front;t1->info<info&&t1!=NULL;t1=t1->ptr)
	{
		p=t1;
	}
	return (p);
}

void enqu(char a[max],int p)
{
	t=(struct pqu*)malloc(sizeof(struct pqu));
	strcpy(t->a,a);
	t->info=p;
	t->ptr=NULL;
	if(front==NULL)
	{
		front=t;
	}
	else
	{
		par=fp(p);
		if(par==NULL)
		{
			t->ptr=front;
			front=t;
		}
		else
		{
			t->ptr=par->ptr;
			par->ptr=t;
		}
	}
}

struct pqu* dequ()
{
	t1=front;
	front=front->ptr;
	return t1;
}

void info(char c[2])
{
	int m=0,i;
	temp2=root;
	while(strcmp(c,temp2->a)!=0)
	{
		t2=temp2->left;
		for(i=0;i<strlen(t2->a);i++)
		{
			if(t2->a[i]==c[0])
			{
				temp2=temp2->left;
				m=1;
				cout<<"0";
				break;
			}
		}
		if(m!=1)
		{
			temp2=temp2->right;
			cout<<1;
		}
		m=0;
	}
}

void insert()
{
	char a1[max],b1[max],v1[max];
	int i,j,z=0,l;
	while(front!=NULL)
	{
		p1=dequ();
		strcpy(a1,p1->a);
		l=p1->info;
		p2=dequ();
		if(p2==NULL)
			break;
		strcpy(b1,p2->a);
		strcpy(v1,a1);
		temp=(struct tree*)malloc(sizeof(struct tree));
		strcpy(temp->a,strcat(v1,b1));
		temp->s=l+p2->info;
		temp->left=NULL;
		temp->right=NULL;
		temp2=temp;
		root=temp;
		for(i=0;i<z;)
		{
			if(strcmp(tt[i]->a,a1)==0)
			{
				temp->left=tt[i];
				for(l=i;l<z;l++)
				{
					tt[l]=tt[l+1];
				}
				i=0;
				continue;
			}
			else if(strcmp(tt[i]->a,b1)==0)
			{
				temp->right=tt[i];
				for(l=i;l<z;l++)
				{

					tt[l]=tt[l+1];
				}
				i=0;
				continue;
			}
			i++;
		}
		if(temp->left==NULL)
		{
			le=(struct tree*)malloc(sizeof(struct tree));
			strcpy(le->a,a1);
			le->left=NULL;
			le->right=NULL;
			temp2->left=le;
		}
		if(temp->right==NULL)
		{
			ri=(struct tree*)malloc(sizeof(struct tree));
			strcpy(ri->a,b1);
			ri->left=NULL;
			ri->right=NULL;
			temp2->right=ri;
		}
		if(front!=NULL)
			enqu(temp2->a,temp2->s);
		tt[z++]=temp2;
	}
}

void disp(struct tree *rt)
{
	if(rt!=NULL)
	{
		disp(rt->left);
		cout<<"	"<<rt->a;
		disp(rt->right);
	}
}

void main()
{
	int i=0,g,h,p,y,n;
	char m[max],b[max][2],re;
	clrscr();
	stat();
	for(i=0;i<ndat;i++)
	{
		m[0]=dat[i];
		m[1]= '\0';
		strcpy(b[i],m);
		if (freq[i] == 0)
			g = freq[i];
		enqu(m,g);
	}
	insert();
	disp(root);
	clrscr();
	cout<<"The corresponding codes are....."<<endl;

	for(i=0;i<ndat;i++)
	{
		cout<<"	"<<b[i]<<" : ";
		info(b[i]);
		cout<<endl;
	}
	getch();
}
