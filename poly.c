#include <stdio.h>
#include <stdlib.h>
#include<math.h>
struct Node
{
	int coef,xe,ye,ze;
	struct Node *link;
};
typedef struct Node *n;
n a,b,c;

void read(n Pol)
{
	int i,coeff,xe,ye,ze,n;
	printf("Enter the no of elements\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	
		scanf("%d %d %d %d",&coeff,&xe,&ye,&ze);
		insertrear(Pol,coeff,xe,ye,ze);
	}
}

void insertrear(n pol1,int c,int xe1,int ye1,int ze1)
{
	n t,temp;
	t=(n)malloc(sizeof(struct Node));
	t->coef=c;
	t->xe=xe1;
	t->ye=ye1;
	t->ze=ze1;
	if(pol1->link==pol1)
	{
		t->link=pol1;
		pol1->link=t;
		return;
	}
	temp=pol1;
	while(temp->link!=pol1)
	{
		temp=temp->link;
	}

	t->link=pol1;
		temp->link=t;
}

void add()
{
	int sum;
	n a1,b1;
	a1=a->link;
	b1=b->link;
	while(a1!=a && b1!=b)
	{
		switch(compare(a1,b1))
		{
			case 1: insertrear(c,a1->coef,a1->xe,a1->ye,a1->ze);
			        a1=a1->link;
			        break;
			case -1: insertrear(c,b1->coef,b1->xe,b1->ye,b1->ze);
			         b1=b1->link;
					 break;
			case 0: sum=a1->coef+b1->coef;
			if(sum!=0)
			{
			  insertrear(c,a1->coef,a1->xe,a1->ye,a1->ze);
			 	
			}
			a1=a1->link;
			b1=b1->link;
			break;		         
		}
	}
	while(a1!=a)
	{
		insertrear(c,a1->coef,a1->xe,a1->ye,a1->ze);
		a1=a1->link;
	}
	while(b1!=b)
	{
		insertrear(c,b1->coef,b1->xe,b1->ye,b1->ze);
		b1=b1->link;
	}
	display(c);
	
}

int compare(n u,n v)
{
	int maxu,maxv;
	if(u->xe==v->xe && u->ye==v->ye && u->ze==v->ze)
	{
		return 0;
	}
	else
	{
		maxu=maximum(u);
		maxv=maximum(v);
		if(maxu>maxv)
		{
			return 1;
		}
		else 
	        {
	    	  return -1;
	        }
		
	}
}

int maximum(n p)
{
	int m=p->xe;
	if(m<p->ye)
	{
	   m=p->ye;
	}
	if(m<p->ze)
	{
	   m=p->ze;
	}
	return m;
}

void display(n c)
{
	n cur;
	if(c->link==c)
	{
		printf("Empty Polynomial\n");
		return;
	}
	cur=c->link;
	while(cur->link!=c)
	{
		printf("%dx^%dy^%dz^%d+\n",cur->coef,cur->xe,cur->ye,cur->ze);
		cur=cur->link;
	}
	printf("%dx^%dy^%dz^%d+\n",cur->coef,cur->xe,cur->ye,cur->ze);
}

void evaluate()
{
	int sum=0,i,n,x,y,z,cc,ex,ey,ez;
	printf("Enter the x,y,z value\n");
	scanf("%d %d %d",&x,&y,&z);
	printf("Enter the no. of terms\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the %dth term\n",(i+1));
		scanf("%d %d %d %d",&cc,&ex,&ey,&ez);
		sum=sum+cc*pow(x,ex)*pow(y,ey)*pow(z,ez);
		
		
	}
	printf("Evaluated value is %d",sum);
}

void main()
{  
    a=(n)malloc(sizeof(struct Node));
    b=(n)malloc(sizeof(struct Node));
    c=(n)malloc(sizeof(struct Node));
    a->link=a;
    b->link=b;
    c->link=c;
    read(a);
    read(b);
    add();
    evaluate();
}


// Polynomial Addition Using C
/*
// Adding two Polynomials

#include<stdio.h>
#include<stdlib.h>

struct node{
    int cof;
    int exp;
    struct node *next;
};

void create(struct node **h)
{
    struct node *curr, *ptr;
    int n, i;
    printf("\nEnter the number of terms in your Polynomial : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        curr = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter Coefficient and Exponent of Term %d : \n",i+1);
        scanf("%d%d",&curr->cof,&curr->exp);
        curr->next = NULL;

        if(*h == NULL){
            *h = curr;
            ptr = curr;
        }else{
            ptr->next = curr;
            ptr = curr;
        }
    }
}

void display(struct node *h)
{
    struct node *curr;
    for(curr = h; curr != NULL; curr = curr->next){
        printf("%dx^%d",curr->cof,curr->exp);
        if(curr->next != NULL){
            printf(" + ");
        }
    }
}

void join(struct node **h1, struct node *h2)
{
    struct node *ptr;
    
    if(*h1 == NULL){
        *h1 = h2;
        return;
    }
    for(ptr= *h1; ptr->next != NULL; ptr=ptr->next);
    ptr->next = h2;
}

void simplify(struct node **h)
{
    struct node *ptr, *ptr1, *prev;
    
    for(ptr = *h; ptr != NULL; ptr=ptr->next)
    {
        prev = ptr;
        for(ptr1 = ptr->next; ptr1 != NULL; prev = ptr1, ptr1 = ptr1->next)
        {
            if(ptr1->exp == ptr->exp)
            {
                ptr->cof += ptr1->cof;
                prev->next = ptr1->next;
                free(ptr1);
                ptr1=prev;
            }
        }
    }
}

int main()
{
    struct node *h1 = NULL, *h2 = NULL;

    create(&h1);
    printf("\nPolynomial 1 : ");
    display(h1);
    create(&h2);
    printf("\nPolynomial 1 : ");
    display(h1);
    printf("\nPolynomial 2 : ");
    display(h2);
    join(&h1,h2);
    printf("\nPolynomial after addition : ");
    display(h1);
    simplify(&h1);
    printf("\nPolynomial after simplification : ");
    display(h1);
    printf("\n");
    return 0;
}
*/
