#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct slots
{
    int id  ;
    float time;
    int avail ; //1 ya3ne fadee
}slots;
typedef struct node
    {
    int id ,age;
    char gender;
    char name[20];
    struct node* next;
    }node;

node*head;
slots arr[5];

int exist (int x)
{ //law mogod return 1
    node* temp =head;
    if (temp==NULL)
        return 0;
    else
    {
     while (temp!=NULL)
     {
         if (x==temp->id)
            return 1;
         temp=temp->next;
     }
     return 0;
    }
}
void reserv (void)
{
    int flag=0;
    printf ("the available slots are\n");

    int i;
          for (i=0 ; i<5 ; i++)
  {

    if (  arr[i].avail==0) // law m7goz skip

        {

            continue;
        }

     else if (arr[i].avail==1)
        {
         printf ("%f\n",arr[i].time);
         flag=1;

       }
  }

  if (flag ==0)
  {
        printf("there are no available slots\n");
        return;
  }

      int x; i=0;
      float s;
      printf("         Enter the id to reserve an appointment\n");
      scanf("%d",&x);
      while(exist(x)==0)
      {
        printf("incorrect id please enter the right one\n");
        scanf("%d",&x);
      }
      printf("         Enter the desired slot\n");
      scanf("%f",&s);

      for (i=0 ; i<5 ;i++)
      {
        if (arr[i].avail==1&&arr[i].time==s)
            break;
        else if(i==4)
        {
            printf("this slot dose not exist pleas enter the correct one\n\n");
            scanf("%f",&s);
            i=-1;
        }
      }


      if (i==-1) i++;
       arr[i].id = x;
       arr[i].avail= 0;

        printf("      the reservation accepted\n\n");


}

void edit (void)
{
    int x; int y; char z;
     char s[20];
    printf("please enter the id to edit information\n");
    scanf("%d",&x);
    node*newnode=head;
    if (exist(x)==0)
    {
        printf("the id %d is incorrect\n",x);
        return;
    }

    else
    {
         while (x!=newnode->id)
           newnode= newnode->next;

      printf("please enter the name\n");
     scanf(" %s",s);


      printf("please enter age\n");
      scanf(" %d",&y);

      printf("please enter gender\n");
      scanf(" %c",&z);

      for(int i=0;i<20;i++)
     {
         newnode->name[i]=s[i];
     }
      newnode->age=y;

      newnode->gender=z;
    }

}
 void append()
 {
     int x;
     int y;
     char z;
     char s[20];
     node * newnode;
     newnode = (node*)malloc(sizeof(node));
    do
        {
            printf("enter a new id please\n");
            scanf("%d",&x);

        }while(exist(x) || x==0);
     newnode->id=x;

     printf("please enter the name\n");
     scanf(" %s",s);

     printf("please enter age\n");
     scanf(" %d",&y);

     printf("please enter gender\n");
     scanf(" %c",&z);
     for(int i=0;i<20;i++)
     {
         newnode->name[i]=s[i];
     }

     newnode->age=y;

     newnode->gender=z;
     newnode->next=NULL;
     if(head==NULL)
        {
     head=newnode;
     return;
	    }
      else
	  {
     node* temp;
     temp=head;

            while(temp->next!=NULL)
			{ temp=temp->next;}
            temp->next=newnode;
	  }
 }
 
void showreserv()
 {
     int flag=1;
	 for (int i=0 ; i<5;i++)
     {
         if (arr[i].avail==0)
         {

                printf("id %d has areservation at %f\n",arr[i].id,arr[i].time);
                flag=0;
         }

     }
      if (flag==1)
         {
             printf("there are no reservation today\n");
         }
 }
 void show(int x)
 {
	 if (head==NULL)
		 {
		     printf("there are no patients\n");
		     return;
		 }
	 else
	 {
		 node*temp=head;
	   while(temp != NULL&&temp->id!=x)
	   {

		 temp=temp->next;
	   }
	   if(temp==NULL)
       {
           printf("this id dosen't exist\n ");
       }
       else
       printf("id =%d \nname is %s\nage=%d\ngender is %c\n ",temp->id,temp->name,temp->age,temp->gender);

     }
 }

void cancel (void)
{
    int x,i=0;
    printf ("enter the id to cancle the reservation\n");
    scanf("%d",&x);
    while (arr[i].id !=x || x==0)
    {
        i++;
        if (i>4)
            {
            printf("this id dose not have a reservation\n");
            return;
            }
    }
    arr[i].id=0;
    arr[i].avail=1;
    printf("                you canceld the reservation\n");
}

 void main(void)
{


{

 head=NULL;
 for(int i=0 ;i<5;i++) //default id =0 
	 arr[i].avail=1;
 arr[0].time=2;
arr[1].time=2.3;
arr[2].time=3;
arr[3].time=4;
arr[4].time=4.3;


}
 
int a,p;
do
{

    printf("for user mode enter 1:\nfor admin mode enter 2:\n");
	scanf("%d",&a);
	if(a==1)
	{
	    do
    {
	    int y,z;
	printf("to view a patient record 1:\nto view today's reservation enter 2:\n");
		scanf("%d",&y);
	    switch (y)
		{
			case 1:
			    printf("Enter the id to view the record\n");
		     	scanf("%d",&z);
		     	show(z);
		        break;
			case 2:
                showreserv();
			    break;
	        default :
			break;

		}
        printf ("to back to the menu enter 1:\nto close enter 0:\n");
		scanf("%d",&p);
	}while(p);
	}
	else if(a==2)
	{
		for(int i=0 ; i<3;i++)
		{
			printf("please enter the password\n");
	        scanf("%d",&p);
			if(p==1234)
			{
				printf("loged in\n");
				break;
			}
			else
			{
				printf("wrong passowrd ");
				if (i==2) return;
		    }

		}
		do //momken do while
		{
		printf("to add a new patient enter 1:\nto edit record enter 2:\nto reserve enter 3:\nto cancel enter 4:\n");
		scanf("%d",&a);

		switch (a)
		{
			case 1:
		     	append();
		        break;
			case 2:
			    edit();
			    break;
			case 3:
			    reserv();
			    break;
			case 4:
			    cancel();
			    break;
	        default :
			break;

		}
		printf ("to go back to the menu enter 1:\nto close enter 0:\n");
		scanf("%d",&p);

		}while (p) ;

	}
	else
	printf("Erorr\n");

printf ("to go back to the main menu enter 1:\nto close the system enter 0:\n");
		scanf("%d",&p);
}while(p);
}

