#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct birth{
                int day;
                int month;
                int year;};
 struct student{
                    char name[50];
                    int id_number;
                     struct birth date;
                    int score;};

struct Node {
  struct student data;
  struct Node * next;
};

struct student get_data_from_user()
{
    struct student new_student;
    printf("\n");
    printf("Add name of student\n");
    scanf("%s",&(new_student).name);
    printf("Add id of student\n");
    scanf("%d",&(new_student).id_number);
    printf("Add date of birth of student\n");
    scanf("%d",&(new_student).date.day);
    scanf("%d",&(new_student).date.month);
    scanf("%d",&(new_student).date.year);
    printf("Add score of student\n");
    scanf("%d",&(new_student).score);
    return new_student;
}

void LinkedL_insert_at_middle(struct Node** head_ref,struct Node** tail_ref,struct student new_student)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    /* 2. put in the data  */

    strcpy(new_node->data.name,new_student.name);
    new_node->data.id_number=new_student.id_number;
    new_node->data.date.day=new_student.date.day;
    new_node->data.date.month=new_student.date.month;
    new_node->data.date.year=new_student.date.year;
    new_node->data.score=new_student.score;

     if (*head_ref == NULL)
     {
        new_node->next = NULL;
        (*head_ref) = new_node;
        (*tail_ref) = new_node;
        return;
     }
    /* 3. Find middle node*/
    struct Node* single_step_traverse =*head_ref;
    struct Node* double_step_traverse =(*head_ref)->next;

        while(double_step_traverse != NULL && double_step_traverse->next != NULL)
        {
            single_step_traverse=single_step_traverse->next;
            double_step_traverse=double_step_traverse->next->next;
        }

        /4. insert at middle/
        new_node->next = single_step_traverse->next;
        single_step_traverse->next = new_node;

}
void LinkedL_insert_at_beggining(struct Node** head_ref,struct Node** tail_ref,struct student new_student)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    /* 2. put in the data  */

     strcpy(new_node->data.name,new_student.name);
    new_node->data.id_number=new_student.id_number;
    new_node->data.date.day=new_student.date.day;
    new_node->data.date.month=new_student.date.month;
    new_node->data.date.year=new_student.date.year;
    new_node->data.score=new_student.score;

     /* 3. If the Linked List is not empty, then insert normally*/
    if (*head_ref != NULL)
    {
        new_node->next = (*head_ref);
        (*head_ref)    = new_node;
    }
    else     /* 4. If the Linked List is empty*/
    {
        new_node->next = NULL;
        (*head_ref) = new_node;
        (*tail_ref) = new_node;

    }
}

void LinkedL_insert_at_end(struct Node** head_ref,struct Node** tail_ref,struct student new_student)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));


    /* 2. put in the data  */

    strcpy(new_node->data.name,new_student.name);
    new_node->data.id_number=new_student.id_number;
    new_node->data.date.day=new_student.date.day;
    new_node->data.date.month=new_student.date.month;
    new_node->data.date.year=new_student.date.year;
    new_node->data.score=new_student.score;

    /* 3. This new node is going to be the last node, so make next
          of it as NULL*/
    new_node->next = NULL;
    /* 4. If the Linked List is empty, then make the new node as head */

    if (*head_ref == NULL)
    {
       *head_ref = new_node;

    }
 /* 6. Change the next of last node */
    if (*tail_ref != NULL)
    (*tail_ref)->next=new_node;

        *tail_ref=new_node;

}

void show(struct Node*head_ref)
{
    struct Node* current=head_ref;
     while(current)
     {
    printf("---------------------------------------\n");

    printf("%s  ",(current)->data.name);

    printf("%d  ",(current)->data.id_number);

    printf("%d/",(current)->data.date.day);
    printf("%d/",(current)->data.date.month);
    printf("%d  ",(current)->data.date.year);
    printf("%d  ",(current)->data.score);
        current=current->next;
        printf("\n");
     }
    printf("---------------------------------------\n\n");


}
















































































































struct Node* head=NULL;
    struct Node* tail=NULL;
  for(int i=0;i<N;i++)
  {
   struct student new_student=get_data_from_user();
    LinkedL_insert_at_beggining(&head,&tail,new_student);
}
    show (head);
    printf("\n The size taken by the structure in the memory %d\n",sizeof(struct student));
    printf("\n The size taken by one node of the linked list %d\n\n",sizeof(struct Node));
    int k;
    int exit_program=1;
while (exit_program)
  {
  printf("where do you want to insert the new data\n");
  printf("enter 1 to insert in the beginning\n");
  printf("enter 2 to insert in the middle\n");
  printf("enter 3 to insert in the end\n");
  scanf("%d",&k);
  switch (k)
  {
      case 1:
       {
        struct student new_student=get_data_from_user();
        LinkedL_insert_at_beggining(&head,&tail,new_student);
        break;
       }
      case 2:
       {
         struct student new_student=get_data_from_user();
      LinkedL_insert_at_middle(&head,&tail,new_student);
        break;
       }
      case 3:
          {
        struct student new_student=get_data_from_user();
       LinkedL_insert_at_end(&head,&tail,new_student);
       break;
          }
       default: {printf("Please enter a valid choice");}
  }
  show (head);
  printf("if you finished enter 0 if not enter 1\n ");
  scanf("%d",&exit_program);
  }

free(head);
free(tail);

































































































































 int main()
{
  printf("Welcome to our project\n");
  printf("Kareem Ahmed Thabet\n");
  printf("Kerollos nashaat nageeb\n");
  printf("Romany sobhy sadek\n");
  printf("Enter number of students\n");
  int N;   //Number of students
    scanf("%d",&N);
    printf("enter 1 to use linked list or 2 for arrays");
  scanf("%d",&h);
  switch(h)
  case 1:{
















































      break;}
  case 2:{}






















































  break;}
  return 0;
  }

