#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[30];
    char fathers_name[30];
    char mothers_name[30];
    char address[50];
    char number[30];
    char email[30];
    struct node *next;
};

struct node *head;


void insert()
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    printf("****  Add To Contact       *****\n");

    printf("Name : ");
    getchar();
    gets(temp->name);
    printf("Fathers Name : ");
    gets(temp->fathers_name);
    printf("Mothers Name : ");
    gets(temp->mothers_name);
    printf("Address : ");
    gets(temp->address);
    printf("Number : ");
    gets(temp->number);
    printf("Email : ");
    gets(temp->email);
    system("cls");
    printf("\n\n\tInformation add Successfully\n");
    temp->next = NULL;

    if(head==NULL){
        head = temp;
        return;
    }
    else{
        temp->next = head;
        head = temp;
        return;
    }

}

void deleteInfo()
{
    printf("****  Remove Information       *****\n");

    char name[30];
    printf("Enter your Name: ");
    getchar();
    gets(name);
    struct node *temp = head;
    struct node *pretemp;
    if(strcmp(temp->name, name)==0){
        head = temp->next;
        free(temp);
        system("cls");
        printf("Information Delete Successfully\n");

        return;
    }
    while(temp!=NULL){
        if(strcmp(temp->name, name)==0){
            break;
        }
        pretemp = temp;
        temp = temp->next;
    }
    pretemp->next = temp->next;
    free(temp);
    system("cls");
    printf("Information Delete Successfully\n");
    return;
}

void display()
{
    printf("**** Information  List        *****\n");
    struct node *temp = head;
    while(temp != NULL){
        printf("Name : %s\n", temp->name);
        printf("Fathers Name : %s\n", temp->fathers_name);
        printf("Mothers Name : %s\n", temp->mothers_name);
        printf("Address : %s\n", temp->address);
        printf("Number : %s\n", temp->number);
        printf("Email : %s\n", temp->email);
        printf("\n\n\n");
        temp = temp->next;
    }
}


void searchByName()
{
    printf("\n\t****  Search Information       *****\n");

    char name[30];
    printf("Enter your Name: ");
    getchar();
    gets(name);
    system("cls");
    printf("\n\t****  Search Result       *****\n");
    struct node *temp = head;
    while(temp!=NULL){
        if(strcmp(temp->name, name)==0){
        printf("Name : %s\n", temp->name);
        printf("Fathers Name : %s\n", temp->fathers_name);
        printf("Mothers Name : %s\n", temp->mothers_name);
        printf("Address : %s\n", temp->address);
        printf("Number : %s\n", temp->number);
        printf("Email : %s\n", temp->email);
        printf("\n\n\n");
        }
        temp = temp->next;
    }

    return;

}

void update()
{
    printf("\t****  Update Information       *****\n");

    char name[30];
    printf("Enter your Name: ");
    getchar();
    gets(name);
    struct node *temp = head;
    while(temp!=NULL){
        if(strcmp(temp->name, name)==0){
            break;
        }
        temp = temp->next;
    }
    printf("Old Information\n");
    printf("Name : %s\n", temp->name);
    printf("Fathers Name : %s\n", temp->fathers_name);
    printf("Mothers Name : %s\n", temp->mothers_name);
    printf("Address : %s\n", temp->address);
    printf("Number : %s\n", temp->number);
    printf("Email : %s\n", temp->email);
    printf("\n\n\n");
    printf("\n");
    printf("New Data\n");
    printf("Name : ");
    gets(temp->name);
    printf("Fathers Name : ");
    gets(temp->fathers_name);
    printf("Mothers Name : ");
    gets(temp->mothers_name);
    printf("Address : ");
    gets(temp->address);
    printf("Number : ");
    gets(temp->number);
    printf("Email : ");
    gets(temp->email);
    system("cls");
    printf("\n\n\tInformation Update successfully\n\n");
    return;
}

int main()
{
    system("color Cf");
    //system("color 5");
    while(1)
    {
        int n;
    printf("\n\n\n\t**************************************\n");
    printf("\t**** 1. Add Information          *****\n");
    printf("\t**** 2. Remove Information       *****\n");
    printf("\t**** 3. Search By Name           *****\n");
    printf("\t**** 4. Update Information       *****\n");
    printf("\t**** 5. View Information         *****\n");
    printf("\t**** 6. Exit                     *****\n");
    printf("\t**************************************\n");
    printf("\tReplay: ");
    scanf("%d", &n);

    switch(n)
    {
    case 1:
        system("cls");
        insert();
        break;

    case 2:
        system("cls");
        deleteInfo();
        break;

    case 3:
        system("cls");
        searchByName();
        break;

    case 4:
        system("cls");
        update();
        break;

    case 5:
        system("cls");
        display();
        break;

    case 6:
        return 0;
        break;

    default :
        system("cls");
        printf("\nInvalide Inpute\n");
        printf("You Must Input 1 to 6\n");
    }
    }

}

