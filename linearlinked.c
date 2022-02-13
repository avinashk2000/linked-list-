#include<stdio.h>
#include<conio.h>
#include<ctype.h>
struct node
{
	int data;
	struct node *link;
};struct node *first;

//create

int create()
{
	char ch;
	struct node *ptr,*cpt;
	ptr=(struct node *)malloc(sizeof(struct node));
	printf("\n\tCreate New Node And Enter Data = ");
	scanf("%d",&ptr->data);
	first=ptr;
	do
	{
		cpt=(struct node *)malloc(sizeof(struct node));
		printf("\n\tCreate Next New Node And Enter Data = ");
		scanf("%d",&cpt->data);
		ptr->link=cpt;
		ptr=cpt;
		printf("\n\tPress Y For More Node Otherwise Press N = ");
		ch=getch();
	}while(ch=='y');
	ptr->link=NULL;
}

//traversal

int display()
{
	struct node *ptr;
	printf("\n\tDisplay Avilable Linked List = ");
	ptr=first;
	while(ptr!=NULL)
	{
		printf(" %d ",ptr->data);
		ptr=ptr->link;
	}
}

//insert begaining

int insertbeg()
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\n\tOverFlow");
		return;
	}
	printf("\n\tEnter Data For Insert At starting Of The List = ");
	scanf("%d",&ptr->data);
	ptr->link=first;
	first=ptr;	
}

//Insert last

int insertlast()
{
	struct node *ptr,*cpt;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\n\tOverFLow");
		return;
	}
	printf("\n\tEnter Data For Insert At Last Of The List = ");
	scanf("%d",&ptr->data);
	cpt=first;
	while(cpt->link!=NULL)
	{
		cpt=cpt->link;
	}
	cpt->link=ptr;
	ptr->link=NULL;
}

//Insert At given Value

int insertgiven()
{
	struct node *ptr,*cpt;
	int info;
	ptr=(struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\n\tOverflow");
		return;
	}
	printf("\n\tEnter Information Where You want Insert Data = ");
	scanf("%d",&info);
	printf("\n\tEnter Data Which Insert = ");
	scanf("%d",&ptr->data);
	cpt=first;
	while(cpt->data!=info)
	{
		cpt=cpt->link;
	}
	ptr->link=cpt->link;
	cpt->link=ptr;
}

//Delete at begaining

int deletebeg()
{
	struct node *ptr;
	if(first==NULL)
	{
		printf("\n\tUnderFlow");
		return;
	}
	ptr=first;
	first=ptr->link;
	free(ptr);
}

//delete at last

int deletelast()
{
	struct node *ptr,*cpt;
	if(first==NULL)
	{
		printf("\n\tUnderFlow");
		return;
	}
	ptr=first;
	while(ptr->link!=NULL)
	{
		cpt=ptr;
		ptr=ptr->link;
	}
	cpt->link=NULL;
	free(ptr);
}

//Delete at given info

int deletegiven()
{
	struct node *ptr,*cpt;
	int info;
	if(first==NULL)
	{
		printf("\n\tUnderFlow");
		return;
	}
	ptr=first;
	printf("\n\tEnter the information which data we deleted = ");
	scanf("%d",&info);
	while(ptr->data!=info)
	{
		cpt=ptr;
		ptr=ptr->link;
	}
	cpt->link=ptr->link;
	free(ptr);
}
int main()
{
	int ch;
	while(1)
	{
		printf("\n\tPress 1 :- Create Linked List");
		printf("\n\tPress 2 :- Display Linked List");
		printf("\n\tPress 3 :- Insert Data At Begaining");
		printf("\n\tPress 4 :- Insert Data At Last");
		printf("\n\tPress 5 :- Insert At Given Information");
		printf("\n\tPress 6 :- Delete At Begaining");
		printf("\n\tPress 7 :- Delete At Last");
		printf("\n\tPress 8 :- Delete At Given Information");
		printf("\n\tPress 9 :- Exit");
		printf("\n\tEnter Your Choice = ");
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
				insertbeg();
				display();
				break;
			case 4:
				insertlast();
				display();
				break;
			case 5:
				insertgiven();
				display();
				break;
			case 6:
				deletebeg();
				display();
				break;
			case 7:
				deletelast();
				display();
				break;
			case 8:
				deletegiven();
				display();
				break;
			case 9:
				exit(1);
				break;
		}
	}
}
