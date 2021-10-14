#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
COORD coord = { 0, 0 };

void gotoxy(int x, int y) {
    coord.X = x; coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void password()
{
    char buffer[256] = {0};
    char password[] = "case_mngmt@123";
    char c;
    int pos=0;
    int trials=1;
    do{
        if(trials==6)
        {
            printf("\n\n\t\t\t\t\t\t\t\t\tYOU HAVE MADE 5 INCORRECT ATTEMPTS.... PLEASE WAIT FOR 15 SECONDS TILL THE NEXT ATTEMPT!!!");
            Sleep(15000);
            trials++;
        }
        else
        {
            system("cls");
            printf("\n\n\n\n\n\t\t\t\t\t\t\t\t\t                                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n");
            printf("\t\t\t\t\t\t\t\t\t                                 |  * * * * * * * * * * * * * * * * | \n");
            printf("\t\t\t\t\t\t\t\t\t                                 |  *    COURT CASE MANAGEMENT    * |     \n");
            printf("\t\t\t\t\t\t\t\t\t                                 |  *    ---------------------    * |        \n");
            printf("\t\t\t\t\t\t\t\t\t                                 |  * * * * * * * * * * * * * * * * |         \n");
            printf("\t\t\t\t\t\t\t\t\t                                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     \n");
            printf("\n\t\t\t\t\t\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
            pos=0;
            printf("\n\n\t\t\t\t\t\t\t\t\tENTER THE PASSWORD FOR LOGIN: ");
            do
            {
                c = getch();
                if( isprint(c) )
                {
                    buffer[ pos++ ] = c;
                    printf("%c", '*');
                }
                else if( c == 8 && pos )
                {
                    buffer[ pos-- ] = '\0';
                    printf("%s", "\b \b");
            }
            } while( c != 13 );

            if( !strcmp(buffer, password) )
            {
                printf("\n\n\t\t\t\t\t\t\t\t\tLOGGED IN SUCCESSFULLY!");
                Sleep(500);
                return(0);
            }

            else
            {
                printf("\n\n\t\t\t\t\t\t\t\t\tINCORRECT LOGIN!");
                Sleep(500);
                trials++;

            }
            printf("\n\n\t\t\t\t\t\t\t\t\tYOU WILL HAVE TO ENTER THE PASSWORD AGAIN!!");
            Sleep(1000);
        }

    }while(trials<11);
    printf("\n\n\t\t\t\t\t\t\t\t\tSORRY... NO MORE TRIALS ALLOWED. ABORTING!!!!");
    exit(0);

}

typedef struct COURT_CASE
{
    int Sno;
    char name[50];
    int age;
    char category[50];
    char description[100];
    int ID;
    struct hearing_date
    {
        int dd;
        int mm;
        int yyyy;
    }hearing_date;
    struct COURT_CASE *next;
}court_case;

court_case *head1=NULL;
court_case *head2=NULL;
court_case *head3=NULL;
court_case *head4=NULL;
court_case *head;


court_case *new_case(char category[])
{

    if(strcmpi(category,"civil")==0)
    {
        return head1;
    }
    else if(strcmpi(category,"criminal")==0)
    {
        return head2;

    }
    else if(strcmpi(category,"Corporate")==0)
    {
        return head3;
    }
    else
    {
        return head4;
    }
}

void make_list(char category[],court_case *h)
{
    if(strcmpi(category,"civil")==0)
    {
        head1=h;
    }
    else if(strcmpi(category,"criminal")==0)
    {
        head2=h;

    }
    else if(strcmpi(category,"Corporate")==0)
    {
        head3=h;
    }
    else
    {
        head4=h;
    }
}

int check_date(int date,int month, int year)
{

    //check year
    if(year>=2020 && year<=2050)
    {
        //check month
        if(month>=1 && month<=12)
        {
            //check days
            if((date>=1 && date<=31) && (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12))
                printf("\n\t\t\t\t\t\t\t\t\t\tDATE IS VALID. YOU CAN CONTINUE...\n");

            else if((date>=1 && date<=30) && (month==4 || month==6 || month==9 || month==11))
                printf("\n\t\t\t\t\t\t\t\t\t\tDATE IS VALID. YOU CAN CONTINUE...\n");

            else if((date>=1 && date<=28) && (month==2))
                printf("\n\t\t\t\t\t\t\t\t\t\tDATE IS VALID. YOU CAN CONTINUE...\n");

            else if(date==29 && month==2 && (year%400==0 ||(year%4==0 && year%100!=0)))
                printf("\n\t\t\t\t\t\t\t\t\t\tDATE IS VALID. YOU CAN CONTINUE...\n");

            else
                {printf("\n\t\t\t\t\t\t\t\t\t\tDAY IS INVALID. ENTER THE DATE AGAIN.\n\t\t\t\t\t\t\t\t\t\t");
                return 2;}
        }
        else
        {
            printf("\n\t\t\t\t\t\t\t\t\t\tMONTH IS INVALID. ENTER THE MONTH AGAIN.\n\t\t\t\t\t\t\t\t\t\t");
            return 2;
        }
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t\t\t\tYEAR IS INVALID. ENTER THE DATE AGAIN.\n\t\t\t\t\t\t\t\t\t\t");
        return 2;
    }
return 0;
}

void insert()
{
    int ch;
court_case *temp=(court_case*)malloc(sizeof(court_case));

printf("\n\n\t\t\t\t\t\t\t\t\t\tENTER NAME :");
fgets(temp->name,50,stdin);

printf("\n\t\t\t\t\t\t\t\t\t\tENTER AGE  :");
scanf("%d",&temp->age);


srand(time(0));
temp->ID= (rand() % (900)) + 100;
//flag is used to check if the loop has to be executed again
int flag=0;
do
{
    flag=0;
    char c[50];
printf("\n\t\t\t\t\t\t\t\t\t\tCHOOSE CATEGORY \n\t\t\t\t\t\t\t\t\t\t 1)CIVIL \n\t\t\t\t\t\t\t\t\t\t 2)CRIMINAL \n\t\t\t\t\t\t\t\t\t\t 3)CORPORATE \n\t\t\t\t\t\t\t\t\t\t 4)OTHER\n\t\t\t\t\t\t\t\t\t\t YOUR CHOICE:");
scanf("%d",&ch);
switch(ch)
{
    case 1:strcpy(temp->category,"Civil");
         temp->ID=temp->ID+1000;
        break;

    case 2:strcpy(temp->category,"Criminal");
    temp->ID=temp->ID+2000;
        break;

    case 3:strcpy(temp->category,"Corporate");
    temp->ID=temp->ID+3000;
        break;

    case 4:

        printf("\n\t\t\t\t\t\t\t\t\t\tENTER CATEGORY : ");
        getchar();
        temp->ID=temp->ID+4000;
        fgets(c,sizeof(c),stdin);
        strcpy(temp->category,c);
        break;

     default:printf("\n\t\t\t\t\t\t\t\t\t\tINVALID OPTION. ENTER AGAIN. \n");
                 flag=1;
}}while(flag==1);
printf("\n\t\t\t\t\t\t\t\t\t\tYOUR CASE ID IS %d .",temp->ID);
//Calling the function to get the pointer to the category list to which the record has to be added
court_case *head=new_case(temp->category);

printf("\n\n\t\t\t\t\t\t\t\t\t\tENTER A SHORT DESCRIPTION OF THE CASE: ");
if(ch!=4)
getchar();
fgets(temp->description,100,stdin);

printf("\n\t\t\t\t\t\t\t\t\t\tENTER THE DATE OF HEARING (DD/MM/YYYY): ");
int flag2;
do
{
scanf("%d/%d/%d",&temp->hearing_date.dd,&temp->hearing_date.mm,&temp->hearing_date.yyyy);
flag2=check_date(temp->hearing_date.dd,temp->hearing_date.mm,temp->hearing_date.yyyy);
}while(flag2==2);


if(head==NULL)
 {
     head=temp;
     head->next=NULL;
     make_list(temp->category,temp);
 }
 else
 {
     court_case *crt=head;
     while(crt->next!=NULL)
        crt=crt->next;
     crt->next=temp;
     temp->next=NULL;
 }
}

void del()
{
    int id;
    int choice;
    court_case *tmp;
    int flag3=0;
    court_case *head;
    do
    {
        flag3=0;
    printf("\n\t\t\t\t\t\t\t\t\t\tCHOOSE CATEGORY FROM WHICH THE CASE IS TO BE DELETED.:\n\t\t\t\t\t\t\t\t\t\t 1)CIVIL \n\t\t\t\t\t\t\t\t\t\t 2)CRIMINAL \n\t\t\t\t\t\t\t\t\t\t 3)CORPORATE \n\t\t\t\t\t\t\t\t\t\t 4)OTHER\n\t\t\t\t\t\t\t\t\t\t YOUR CHOICE: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:head=new_case("Civil");
            break;

        case 2:head=new_case("Criminal");
            break;

        case 3:head=new_case("Corporate");
            break;

        case 4:head=new_case("Other");
            break;

        default:printf("\n\t\t\t\t\t\t\t\t\t\tINVALID OPTION. ENTER AGAIN: ");
                     flag3=1;
    }}while(flag3==1);

    printf("\n\t\t\t\t\t\t\t\t\t\tENTER THE CASE ID: ");
    scanf("%d",&id);
     tmp = head;
     if (tmp == NULL)
    {
        printf("\n\t\t\t\t\t\t\t\t\t\tTHE LIST IS EMPTY.");
        return;
    }
    //if only one case in the category
    else if((tmp->next==NULL && tmp->ID==id)|| (tmp->ID==id && tmp->next!=NULL))
    {
        //tmp=tmp->next;
        if(new_case(tmp->category)==head1)
        {
            tmp=tmp->next;
            free(head1);
            head1=tmp;
        }
        else if(new_case(tmp->category)==head2)
        {
            tmp=tmp->next;
            free(head2);
            head2=tmp;
        }
        else if(new_case(tmp->category)==head3)
        {
            tmp=tmp->next;
            free(head3);
            head3=tmp;
        }
        else if(new_case(tmp->category)==head4)
        {
            tmp=tmp->next;
            free(head4);
            head4=tmp;
        }
        printf("\n\t\t\t\t\t\t\t\t\t\tTHE RECORD HAS BEEN DELETED. \n");
        return;
    }
    // delete from a specified position other than head
    else if(tmp->next!=NULL)
    {
        while(tmp->next!=NULL && tmp->next->ID!=id)
        {
            tmp=tmp->next;
        }
        if(tmp->next==NULL)
        {
            printf("\n\t\t\t\t\t\t\t\t\t\tTHE ID ENTERED IS INVALID...");
        }
        else
        {
            if(tmp->next->ID==id)
            {
                court_case *rec= tmp->next->next;
                tmp->next =rec;
                free(tmp->next);
                printf("\n\t\t\t\t\t\t\t\t\t\tTHE RECORD HAS BEEN DELETED. \n");
            }
        }


    }
    else
            printf("THE ID ENTERED IS INVALID...");


}



void edit()
{
int ch,s,i,t;
int flag=0,flag5,r,check;
court_case *head=NULL;
do
{
    do
{
    flag=0;
    char c[20];
    printf("\n\t\t\t\t\t\t\t\t\t\tCHOOSE CATEGORY FROM WHICH THE CASE IS TO BE EDITED.:\n\t\t\t\t\t\t\t\t\t\t 1)CIVIL \n\t\t\t\t\t\t\t\t\t\t 2)CRIMINAL \n\t\t\t\t\t\t\t\t\t\t 3)CORPORATE \n\t\t\t\t\t\t\t\t\t\t 4)OTHER\n\t\t\t\t\t\t\t\t\t\t YOUR CHOICE: ");
scanf("%d",&ch);
switch(ch)
{
    case 1:head=head1;
        break;

    case 2:head=head2;
        break;

    case 3:head=head3;
        break;

    case 4:head=head4;
        break;

     default:printf("\n\t\t\t\t\t\t\t\t\t\tINVALID OPTION. ENTER AGAIN :");
                 flag=1;
}}while(flag==1);
printf("\n\t\t\t\t\t\t\t\t\t\tENTER CASE ID OF CASE TO BE EDITED :");
scanf("%d",&s);
 flag5=0;
if(head==NULL)
{
    printf("\n\t\t\t\t\t\t\t\t\t\tTHE LIST IS EMPTY.");
    Sleep(250);
    return;
}
 check=0;

 r=0;
 if(head->next==NULL && head->ID!=s)
  r=1;
if((head->next==NULL && head->ID==s)|| (head->ID==s && head->next!=NULL))
    {
        int check=1;
    }

while(head->ID!=s && head->next!=NULL)
{
head=head->next;
r=1;
}
if(head->ID==s && head->next==NULL)
    r=0;
if( head->next==NULL && r==1)
{
printf("\n\t\t\t\t\t\t\t\t\t\tINVALID ID. TRY AGAIN...");
flag5=1;
}
}while(flag5==1);


//print function to be added
printf("\n\t\t\t\t\t\t\t\t\t\tCHOOSE THE FIELD YOU WISH TO EDIT- \n\t\t\t\t\t\t\t\t\t\t 1)NAME \n\t\t\t\t\t\t\t\t\t\t 2)AGE \n\t\t\t\t\t\t\t\t\t\t 3)DESCRIPTION \n\t\t\t\t\t\t\t\t\t\t 4)HEARING DATE \n\t\t\t\t\t\t\t\t\t\t YOUR CHOICE :");
scanf("%d",&i);
switch(i)
{
case 1:printf("\n\t\t\t\t\t\t\t\t\t\tENTER THE NEW NAME :");
getchar();
    fgets(head->name,50,stdin);
    break;

case 2:printf("\n\t\t\t\t\t\t\t\t\t\tENTER THE NEW AGE:");
scanf("%d",&head->age);
break;

    case 3:printf("\n\t\t\t\t\t\t\t\t\t\tENTER THE NEW DESCRIPTION OF THE CASE ");
           if(t!=4)
           getchar();
           fgets(head->description,100,stdin);
           break;

    case 4:printf("\n\t\t\t\t\t\t\t\t\t\tENTER THE NEW DATE OF HEARING (dd/mm/yyyy)-");
    int flag2;
    do
    {
    scanf("%d%d%d",&head->hearing_date.dd,&head->hearing_date.mm,&head->hearing_date.yyyy);
    flag2=check_date(head->hearing_date.dd,head->hearing_date.mm,head->hearing_date.yyyy);
    }while(flag2==2);
    break;

    default:printf("\n\t\t\t\t\t\t\t\t\t\tINVALID CHOICE");

}
if(check==1)
{

     if(new_case(head->category)==head1)
        {
            free(head1);
            head1=head;
        }
        else if(new_case(head->category)==head2)
        {
            free(head2);
            head2=head;
        }
        else if(new_case(head->category)==head3)
        {
            free(head3);
            head3=head;
        }
        else if(new_case(head->category)==head1)
        {
            free(head4);
            head4=head;
        }

        return;
}}

void display()

{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t----------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t----------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t|                                                                                                  |\n");
	printf("\t\t\t\t\t\t|     ********   *********   *********    *********   *                  *          *       *      |\n");
	printf("\t\t\t\t\t\t|       *     *      *       *            *       *   *                 *  *         *     *       |\n");
	printf("\t\t\t\t\t\t|       *     *      *       *            *       *   *                *    *         *   *        |\n");
	printf("\t\t\t\t\t\t|       *     *      *       *            *       *   *               *      *         * *         |\n");
	printf("\t\t\t\t\t\t|       *     *      *       *********    *********   *              *        *         *          |\n");
	printf("\t\t\t\t\t\t|       *     *      *               *    *           *             ************        *          |\n");
	printf("\t\t\t\t\t\t|       *     *      *               *    *           *            *            *       *          |\n");
	printf("\t\t\t\t\t\t|       *     *      *               *    *           *           *              *      *          |\n");
	printf("\t\t\t\t\t\t|     ********   **********  *********    *           *********  *                *     *          |\n");
	printf("\t\t\t\t\t\t|                                                                                                  |\n");
	printf("\t\t\t\t\t\t----------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t\t----------------------------------------------------------------------------------------------------\n");
    Sleep(1000);
    int choice,flag4;
    int select;
    court_case *ptr=(court_case*)malloc(sizeof(court_case));
    do
    {
        system("cls");
        flag4=0;
        printf("\n\n\n\n\n\t\t\t\t\t\t                                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~             \n");
        printf("\t\t\t\t\t\t                                 |  * * * * * * * * * * * * * * * * | \n");
        printf("\t\t\t\t\t\t                                 |  *    COURT CASE MANAGEMENT    * |     \n");
        printf("\t\t\t\t\t\t                                 |  *    ---------------------    * |        \n");
        printf("\t\t\t\t\t\t                                 |  * * * * * * * * * * * * * * * * |         \n");
        printf("\t\t\t\t\t\t                                 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     \n");
        printf("\n\t\t\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t-----------------------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\tDISPLAY MENU ");
        printf("\n\t\t\t\t\t\t\t\t\t\t-----------------------------------------------");
        printf("\n\n\t\t\t\t\t\t\t\t\t\t1.DISPLAY ALL RECORDS");
        printf("\n\t\t\t\t\t\t\t\t\t\t2.DISPLAY ALL RECORDS OF A PARTICULAR CATEGORY");
        printf("\n\t\t\t\t\t\t\t\t\t\t3.DISPLAY A PARTICULAR RECORD");
        printf("\n\t\t\t\t\t\t\t\t\t\t4.EXIT");
        printf("\n\n\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE OF VIEWING : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:system("cls");
                   printf("\t\t\t\t\t\t\t\t\t\t||  ALL RECORDS  ||");
                                gotoxy(3,2);
                               printf("S.NO");
                                gotoxy(15,2);
                               printf("NAME");
                                gotoxy(35,2);
                               printf("AGE");
                                gotoxy(50,2);
                               printf("ID NO.");
                                gotoxy(70,2);
                               printf("CATEGORY");
                                gotoxy(90,2);
                                printf("DESCRIPTION");
                                gotoxy(140,2);
                               printf("DATE");
                                printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n");

                   int a =1;
                   int y = 1;
                   int x = 4;
                   while(a<5)
                   {
                       if(a==1)
                        ptr = head1;
                       else if(a==2)
                        ptr = head2;
                       else if(a==3)
                        ptr = head3;
                       else
                        ptr = head4;

                   while(ptr!=NULL)
                   {
                                gotoxy(3,x);
                               printf("%d)",y);
                                gotoxy(12,x);
                               printf("%s",ptr->name);
                                gotoxy(35,x);
                               printf("%d",ptr->age);
                                gotoxy(50,x);
                               printf("%d",ptr->ID);
                                gotoxy(70,x);
                               printf("%s",ptr->category);
                                gotoxy(90,x);
                               printf("%s",ptr->description);
                                gotoxy(140,x);
                               printf("%d/%d/%d",ptr->hearing_date.dd,ptr->hearing_date.mm,ptr->hearing_date.yyyy);
                               printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                               x+=2;
                               y++;
                        ptr=ptr->next;
                   }
                   a++;
                   }

                   break;
            case 2: printf("\n\n\t\t\t\t\t\t\t\t\t\tCHOOSE CATEGORY: \n\t\t\t\t\t\t\t\t\t\t1)CIVIL \n\t\t\t\t\t\t\t\t\t\t2)CRIMINAL \n\t\t\t\t\t\t\t\t\t\t3)CORPORATE \n\t\t\t\t\t\t\t\t\t\t4)OTHER \n\t\t\t\t\t\t\t\t\t\tENTER: ");
                    scanf("%d",&select);
                    switch(select)
                    {
                     case 1:   system("cls");
                               printf("\n\t\t\t\t\t|| CIVIL RECORDS || \n\n\n");
                               gotoxy(3,2);
                               printf("S.NO");
                               gotoxy(15,2);
                               printf("NAME");
                                gotoxy(35,2);
                               printf("AGE");
                                gotoxy(50,2);
                               printf("ID NO.");
                                gotoxy(70,2);
                                printf("DESCRIPTION");
                                gotoxy(120,2);
                               printf("DATE");
                               ptr=head1;
                               printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
                               int x=4;
                               int y =1;
                               while(ptr!=NULL)
                              {
                                gotoxy(3,x);
                               printf("%d)",y);
                                gotoxy(12,x);
                               printf("%s",ptr->name);
                                gotoxy(35,x);
                               printf("%d",ptr->age);
                                gotoxy(50,x);
                               printf("%d",ptr->ID);
                                gotoxy(70,x);
                               printf("%s",ptr->description);
                                gotoxy(120,x);
                               printf("%d/%d/%d",ptr->hearing_date.dd,ptr->hearing_date.mm,ptr->hearing_date.yyyy);
                               printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
                               x+=2;
                               y++;


                                ptr=ptr->next;
                              }
                               break;

                    case 2:   system("cls");
                               printf("\n\t\t\t\t\t|| CRIMINAL RECORDS || \n\n\n");
                               gotoxy(3,2);
                               printf("S.NO");
                               gotoxy(15,2);
                               printf("NAME");
                                gotoxy(35,2);
                               printf("AGE");
                                gotoxy(50,2);
                               printf("ID NO.");
                                gotoxy(70,2);
                                printf("DESCRIPTION");
                                gotoxy(120,2);
                               printf("DATE");
                               ptr=head2;
                               printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
                               int x2=4;
                               int y2=1;
                               while(ptr!=NULL)
                              {
                                gotoxy(3,x2);
                               printf("%d)",y2);
                                gotoxy(12,x2);
                               printf("%s",ptr->name);
                                gotoxy(35,x2);
                               printf("%d",ptr->age);
                                gotoxy(50,x2);
                               printf("%d",ptr->ID);
                                gotoxy(70,x2);
                               printf("%s",ptr->description);
                                gotoxy(120,x2);
                               printf("%d/%d/%d",ptr->hearing_date.dd,ptr->hearing_date.mm,ptr->hearing_date.yyyy);
                               printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
                               x2+=2;
                               y2++;

                              ptr=ptr->next;
                             }
                             break;

                   case 3:   system("cls");
                               printf("\n\t\t\t\t\t|| CORPORATE RECORDS || \n\n\n");
                              gotoxy(3,2);
                               printf("S.NO");
                               gotoxy(15,2);
                               printf("NAME");
                                gotoxy(35,2);
                               printf("AGE");
                                gotoxy(50,2);
                               printf("ID NO.");
                                gotoxy(70,2);
                                printf("DESCRIPTION");
                                gotoxy(120,2);
                               printf("DATE");
                               ptr=head3;
                               printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
                               int x3=4;
                               int y3 =1;
                               while(ptr!=NULL)
                              {
                                gotoxy(3,x3);
                               printf("%d)",y3);
                                gotoxy(12,x3);
                               printf("%s",ptr->name);
                                gotoxy(35,x3);
                               printf("%d",ptr->age);
                                gotoxy(50,x3);
                               printf("%d",ptr->ID);
                                gotoxy(70,x3);
                               printf("%s",ptr->description);
                                gotoxy(120,x3);
                               printf("%d/%d/%d",ptr->hearing_date.dd,ptr->hearing_date.mm,ptr->hearing_date.yyyy);
                               printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
                               x3+=2;
                               y3++;

                             ptr=ptr->next;
                            }
                            break;

                   case 4:  system("cls");
                               printf("\n\t\t\t\t\t|| OTHER RECORDS || \n\n\n");
                               gotoxy(3,2);
                               printf("S.NO");
                               gotoxy(15,2);
                               printf("NAME");
                                gotoxy(35,2);
                               printf("AGE");
                                gotoxy(50,2);
                               printf("ID NO.");
                                gotoxy(70,2);
                                printf("DESCRIPTION");
                                gotoxy(120,2);
                               printf("DATE");
                               ptr=head4;
                               printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
                               int x4=4;
                               int y4=1;
                               while(ptr!=NULL)
                              {
                                gotoxy(3,x4);
                               printf("%d)",y4);
                                gotoxy(12,x4);
                               printf("%s",ptr->name);
                                gotoxy(35,x4);
                               printf("%d",ptr->age);
                                gotoxy(50,x4);
                               printf("%d",ptr->ID);
                                gotoxy(70,x4);
                               printf("%s",ptr->description);
                                gotoxy(120,x4);
                               printf("%d/%d/%d",ptr->hearing_date.dd,ptr->hearing_date.mm,ptr->hearing_date.yyyy);
                               printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
                               x4+=2;
                               y4++;

                            ptr=ptr->next;
                            }
                            break;

                 default:   printf("\n\t\t\t\t\t\t\t\t\t\tINVALID OPTION. ENTER AGAIN. ");

            }
            break;

            case 3:system("cls");
                int id, first_digit;
                printf("\n\t\t\t\t\t\tRECORD DIRECTORY  \n");
                printf("***********************************************************************************************************************");
                printf("\n\t\t\tENTER REGISTRATION ID OF THE CASE RECORD YOU WANT TO DISPLAY: ");
                scanf("%d",&id);
                first_digit=id/1000;

                if(first_digit==1)
                {
                    ptr=head1;
                }
                else if(first_digit==2)
                {
                    ptr=head2;
                }
                else if(first_digit==3)
                {
                    ptr=head3;
                }
                else if(first_digit==4)
                {
                    ptr=head4;
                }
                else
                {
                    printf("\n\n\t\t\tTHE ID THAT YOU ENTERED IS INVALID. ABORTING!!");
                    break;
                }
                gotoxy(35,7);
                printf("***************RECORD TABLE***************");
                gotoxy(10,9);
                printf("NAME");
                gotoxy(25,9);
                printf("AGE");
                gotoxy(50,9);
                printf("DESCRIPTION");
                gotoxy(100,9);
                printf("DATE");
                printf("\n------------------------------------------------------------------------------------------------------------------------\n");
                x=11;
                while(ptr->ID!=id)
                    ptr=ptr->next;
                gotoxy(8,x);
                printf("%s",ptr->name);
                gotoxy(25,x);
                printf("%d",ptr->age);
                gotoxy(40,x);
                printf("%s",ptr->description);
                gotoxy(97,x);
                printf("%d/%d/%d",ptr->hearing_date.dd,ptr->hearing_date.mm,ptr->hearing_date.yyyy);
                printf("\n------------------------------------------------------------------------------------------------------------------------\n");
                x+=2;
                break;



            case 4: return;
            default:printf("\n\t\t\t\t\t\t\t\t\t\tTHE CHOICE ENTERED IS WRONG. ENTER AGAIN!");

            flag4=1;
        }
        if(flag4==0)
        {
            printf("\n\n\t\t\t\t\t\t\t\t\t\tWANT TO CONTINUE DISPLAYING THE RECORDS.?? 1.YES 2.NO ");
            printf("\n\t\t\t\t\t\t\t\t\t\tPLEASE ENTER YOUR CHOICE: ");
            scanf("%d",&flag4);
        }
        if(flag4!=1 && flag4!=2)
        {
            printf("\n\t\t\t\t\t\t\t\t\t\tINCORRECT OPTION. PLEASE ENTER YOUR CHOICE AGAIN: ");
            scanf("%d",&flag4);
        }
    }while(flag4==1);
}


void main()
{
    password();
	int h;

	//CASE 1
    court_case *temp1=(court_case*)malloc(sizeof(court_case));
    temp1->ID=1224;
    strcpy(temp1->name,"Ayaan Kapoor.");
    temp1->age = 20;
    strcpy(temp1->category,"Civil");
    strcpy(temp1->description,"Involved in medical malpractices.");
    temp1->hearing_date.dd= 12;
    temp1->hearing_date.mm = 10;
    temp1->hearing_date.yyyy = 2027;
    temp1->next=NULL;
	head1=temp1;

	 //CASE2
    court_case *temp2 = (court_case*)malloc(sizeof(court_case));
    temp2->ID=2112;
    strcpy(temp2->name,"Anirudh Roy");
    temp2->age = 27;
    strcpy(temp2->category ,"Criminal");
    strcpy(temp2->description,"Charges of murder .");
    temp2->hearing_date.dd= 07;
    temp2->hearing_date.mm = 06;
    temp2->hearing_date.yyyy = 2026;
    temp2->next=NULL;
    //head2->next=temp2;
    head2=temp2;

    //CASE3
    court_case *temp3 = (court_case*)malloc(sizeof(court_case));
    temp3->ID=3178;
    strcpy(temp3->name,"Pawan Kumar");
    temp3->age = 36;
    strcpy(temp3->category,"Corporate");
    strcpy(temp3->description,"Illegal capture of land.");
    temp3->hearing_date.dd= 01;
    temp3->hearing_date.mm = 04;
    temp3->hearing_date.yyyy = 2024;
    temp3->next=NULL;
    head3=temp3;

     //CASE4
      court_case *temp4 = (court_case*)malloc(sizeof(court_case));
    temp4->ID=4444;
    strcpy(temp4->name,"Sejal Wadhawan");
    temp4->age = 33;
    strcpy(temp4->category,"Others");
    strcpy(temp4->description,"Divorce case");
    temp4->hearing_date.dd= 12;
    temp4->hearing_date.mm =05;
    temp4->hearing_date.yyyy = 2021;
    temp4->next=NULL;
    head4=temp4;

    //CASE5
    court_case *temp5 = (court_case*)malloc(sizeof(court_case));
    temp5->ID=1152;
    strcpy(temp5->name,"Suchit Singh Rajput");
    temp5->age = 28;
    strcpy(temp5->category,"Civil");
    strcpy(temp5->description,"involved in theft.");
    temp5->hearing_date.dd= 10;
    temp5->hearing_date.mm = 07;
    temp5->hearing_date.yyyy = 2020;
    temp5->next=NULL;
    head1->next=temp5;

    int t=0;
        do
    {
    t=0;
    system("cls");
    printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t---------------");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t---------------");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t| | | | | | | |");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t| | | | | | | |");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t| | | ___ | | |");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t| | |/   \\| | |");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t| | |\\___/| | |");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t| | |  |  | | |");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t| | |\\/|\\/| | |");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t| | |  |  | | |");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t| | | /|\\ | | | ");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t| | |/ | \\| | | ");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t---------------");
    printf("\n\t\t\t\t\t\t\t\t\t\t\t\t---------------");
    printf("\n\n\n\t\t\t\t\t\t\tCHOOSE THE FUNCTION YOU WANT TO OPERATE ON CASE RECORDS, FROM THE OPTIONS BELOW--\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t1) INSERT A NEW RECORD IN THE CASE MANAGEMENT SYSTEM \n");
    printf("\n\t\t\t\t\t\t\t\t\t\t2) MODIFY A RECORD OF THE DATABASE\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t3) DISPLAY RECORDS OF CURRENT CASES\n");
    printf("\n\t\t\t\t\t\t\t\t\t\t4) DELETE A PARTICULAR RECORD FROM THE DATABASE\n");
    printf("\n\t\t\t\t\t\t\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d",&h);
    printf("\n\t\t\t\t\t\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
    switch(h)
    {
    	case 1:  getchar();
    	         insert();
    	break;

    	case 2:  edit();
    	break;

    	case 3:  display();
    	break;

    	case 4:  del();
    	break;


    	default: printf("\n\t\t\t\t\t\t\t\t\t\tINVALID OPTION. CHOOSE AGAIN.\n");
    	t=1;
    }
    if(t==0)
    {
        printf("\n\n\t\t\t\t\t\t\t\t\t\tWANT TO CONTINUE WITH MAIN?? 1.YES  2.NO ");
        printf("\n\t\t\t\t\t\t\t\t\t\tPLEASE ENTER YOUR CHOICE: ");
        scanf("%d",&t);
    }
    if(t!=1 && t!=2)
    {
        printf("\n\t\t\t\t\t\t\t\t\t\tINCORRECT OPTION. PLEASE ENTER YOUR CHOICE AGAIN: ");
        scanf("%d",&t);
    }

}while(t==1);

system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t  **********   **      **         **         **       **    **      **          \n");
	printf("\t\t\t\t\t\t\t      **       **      **        *  *        ***      **    **    **                                         \n");
    printf("\t\t\t\t\t\t\t      **       **      **       **  **       ** *     **    **  **                                         \n");
    printf("\t\t\t\t\t\t\t      **       **********      ********      **  *    **    ***                                          \n");
	printf("\t\t\t\t\t\t\t      **       **********     **********     **   *   **    ***                                           \n");
	printf("\t\t\t\t\t\t\t      **       **      **    **        **    **    *  **    **  **                                          \n");
	printf("\t\t\t\t\t\t\t      **       **      **   **          **   **     * **    **    **                                        \n");
	printf("\t\t\t\t\t\t\t      **       **      **   **          **   **      ***    **      **                                     \n");
	printf("\n\n");



	printf("\t\t\t\t\t\t\t               **      **    **********    **       **                                                        \n");
	printf("\t\t\t\t\t\t\t               **      **    **      **    **       **                                                        \n");
	printf("\t\t\t\t\t\t\t                **    **     **      **    **       **                                                        \n");
	printf("\t\t\t\t\t\t\t                 **  **      **      **    **       **                                                        \n");
	printf("\t\t\t\t\t\t\t                   **        **      **    **       **                                                        \n");
	printf("\t\t\t\t\t\t\t                   **        **      **    **       **                                                        \n");
	printf("\t\t\t\t\t\t\t                   **        **      **    **       **                                                        \n");
	printf("\t\t\t\t\t\t\t                   **        **      **    **       **                                                        \n");
	printf("\t\t\t\t\t\t\t                   **        **********    ***********                                                        \n");

    Sleep(1000);

}


