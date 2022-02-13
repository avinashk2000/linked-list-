#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next,*prev;
};struct node *start;

int create()
{
	char ch;
	struct node *ptr,*cpt;
	ptr=(struct node *)malloc(sizeof(struct node));
	printf("\nENter The New Node Data = ");
	scanf("%d",&ptr->data);
	ptr->prev=NULL;
	start=ptr;
	do
	{
		cpt=(struct node *)malloc(sizeof(struct node));
		printf("\nENter Next New Node Data = ");
		scanf("%d",&cpt->data);
		ptr->next=cpt;
		cpt->prev=ptr;
		ptr=cpt;
		printf("\nPress y for More new Node otherwise press n = ");
		ch=getch();
	}while(ch=='y');
	ptr->next=NULL;
}

int display()
{
	struct node *ptr;
	printf("\nDisplay Linked List Data = ");
	ptr=start;
	while(ptr!=NULL)
	{
		printf(" %d ",ptr->data);
		ptr=ptr->next;
	}
}

int inserts()
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\nOVERFLOW");
		return;
	}
	printf("\nEnter Data Insert starting point = ");
	scanf("%d",&ptr->data);	
	ptr->next=start;
	start->prev=ptr;
	ptr->prev=NULL;
	start=ptr;
}

int insertl()
{
	struct node *ptr,*cpt;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)	
	{
		printf("\nOverFlow");
		return;
	}
	printf("\nEnter Data Insert last point = ");
	scanf("%d",&ptr->data);
	cpt=start;
	while(cpt->next!=NULL)
	{
		cpt=cpt->next;
	}
	cpt->next=ptr;
	ptr->prev=cpt;
	ptr->next=NULL;
}

int insertgiven()
{
	struct node *ptr,*cpt;
	int info;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\nOVERFLOW");
		return;	
	}	
	printf("\nEnter Information Where you want insert data = ");
	scanf("%d",&info);
	printf("\nEnter Data Which You want insert = ");
	scanf("%d",&ptr->data);
	cpt=start;
	while(cpt->data!=info)
	{
		cpt=cpt->next;
	}
	ptr->next=cpt->next;
	cpt->next=ptr;
	ptr->prev=cpt;
}

int deleteb()
{
	struct node *ptr;
	if(start==NULL)
	{
		printf("\nUnderFlow");
		return;
	}
	ptr=start;
	start=ptr->next;
	start->prev=NULL;
	free(ptr);
}

int deletel()
{
	struct node *ptr,*cpt;
	if(start==NULL)
	{
		printf("\nUnderFlow");
		return;	
	}	
	cpt=start;
	while(cpt->next!=NULL)
	{
		ptr=cpt;
		cpt=cpt->next;
	}
	ptr->next=NULL;
	free(cpt);
}

int deletegiven()
{
	struct node *ptr,*cpt;
	int info;
	if(start==NULL)
	{
		printf("\nUnderFlow");
		return;
	}
	ptr=start;
	printf("\nEnter Information Wgich Data want to delete = ");
	scanf("%d",&info);
	while(ptr->data!=info)
	{
		cpt=ptr;
		ptr=ptr->next;
	}
	cpt->next=ptr->next;
	free(ptr);
}
int main()
{
	int ch;
	while(1)
	{
		printf("\nPress 1 : Create Linked List");
		printf("\nPress 2 : Display Linked List");
		printf("\nPress 3 : Insert At Starting Point");
		printf("\nPress 4 : Insert At last Point");
		printf("\nPress 5 : Insert At Given information");
		printf("\nPress 6 : Delete Data From Starting point");
		printf("\nPress 7 : Delete Data From Last Point");
		printf("\nPress 8 : Delete Data From Given Information");
		printf("\nPress 9 : Exit From Programe");
		printf("\nENter The Choice = ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				inserts();
				display();
				break;
			case 4:
				insertl();
				display();
				break;
			case 5:
				insertgiven();
				display();
				break;
			case 6:
				deleteb();
				display();
				break;
			case 7:
				deletel();
				display();
				break;
			case 8:
				deletegiven();
				display();
				break;
			case 9:
				exit(1);
				break;
			default:
				printf("\nInvalid Choice");
		}
	}
}
