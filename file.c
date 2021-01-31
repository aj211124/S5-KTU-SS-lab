#include<stdio.h>
#include<string.h>
#include<math.h>
#define MAX 100
struct node
{
    char name[MAX];
    struct node *next;
}*head=NULL,*tail=NULL,*newnode,*temp,*temp1,*temp2;
int n[MAX];
void search_file()
{
    int ys=1;
    temp=head;
    char str[MAX];
    printf("Enter the name of file to be search\n");
    getchar();
    scanf("%s",str);
    while(temp!=NULL&&ys!=0)
    {
        ys=strcmp(str,temp->name);
        temp=temp->next;
    }
    if(ys==0)
    {
        printf("File exists\n");
    }
    else
    {
        printf("There is no such file\n");
    }
}
void create_file()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    char str[MAX];
    int a=1;
    if(head==NULL)
    {
        printf("Enter the name of the file\n");
        getchar();
        scanf("%s",newnode->name);
        head=newnode;
        tail=newnode;
        newnode->next=NULL;
    }
    else
    {
        printf("Enter the name of the file\n");
        getchar();
        scanf("%s",str);
        temp=head;
        while(temp!=NULL&&a!=0)
        {
            a=strcmp(str,temp->name);
            temp=temp->next;
        }
        if(a==0)
        {
            printf("The file name already exist, enter different file name\n");
            create_file();
        }
        else
        {
            strcpy(newnode->name,str);
            tail->next=newnode;
            tail=newnode;
            newnode->next=NULL;
        }
    }
}
void delete_file()
{
    char str[MAX];
    int a=1;
    printf("Enter the name of the file\n");
    getchar();
    scanf("%s",str);
    temp=head;
    temp1=head;
    temp2=head;
    while(temp!=NULL&&a!=0)
    {
        a=strcmp(str,temp->name);
        temp2=temp1;
        temp1=temp;
        temp=temp->next;
    }
    if(a==0)
    {
        if(temp1==head)
        {
            head=head->next;
            printf("The file is deleted\n");
        }
        else if(temp1==tail)
        {
            tail=temp2;
            tail->next=NULL;
            printf("The file is deleted\n");
        }
        else
        {
            temp2->next=temp;
            printf("The file is deleted\n");
        }
    }
    else
    {
        printf("There is no such file\n");
    }
}
void display_file()
{
    temp=head;
    while(temp!=NULL)
    {
        puts(temp->name);
        temp=temp->next;
    }
}
void single_level()
{
    int y,w;
    do
    {
        printf("Enter the choice\nFor searching a file press 1\nFor creating a file Enter 2\nFor deleting a file press 3\nTo display the files press 4\n");
        scanf("%d",&y);
            switch(y)
            {
            case 1:
                if(head==NULL)
                {
                    printf("The directory has no file, create a file\n");
                    create_file();
                }
                else
                {
                    search_file();
                }
                break;

            case 2:
                create_file();
                break;

            case 3:
                if(head==NULL)
                {
                    printf("The directory has no file\n");
                }
                else
                {
                    delete_file();
                }
                break;

            case 4:
                if(head==NULL)
                {
                    printf("The directory has no file\n");
                }
                else
                {
                    display_file();
                }
                break;

            default:
                printf("Wrong choice\n");
                break;
            }
        printf("To continue with other operation in single directory press 1, else press any other number\n");
        scanf("%d",&w);
    }while(w==1);
}
struct node1
{
    char directory[MAX];
    char file[MAX];
    struct node1* d;
    struct node1* f;
}*headd=NULL,*tempd,*taild=NULL,*files,*direct,*h=NULL,*t=NULL,*tempd1,*tempd2,*tempf,*tempf1,*tempf2;
void search()
{
    printf("\n");
    char dic[MAX],foz[MAX];
    printf("Enter the directory in which the file has to be search\n");
    getchar();
    scanf("%s",dic);
    int a=1,b=1;
    tempd=headd;
    while(tempd!=NULL&&a!=0)
    {
        a=strcmp(tempd->directory,dic);
        tempd1=tempd;
        tempd=tempd->d;
    }
    if(a==0)
    {
        printf("Enter the name of the file\n");
        getchar();
        scanf("%s",foz);
        tempf=tempd1;
        while(tempf!=NULL&&b!=0)
        {
            b=strcmp(foz,tempf->file);
            tempf=tempf->f;
        }
        if(b==0)
        {
            printf("File found\n");
        }
        else
        {
            printf("No such file found\n");
        }
    }
    else
    {
        printf("No such directory\n");
    }
    printf("\n");
}
void create()
{
    printf("\n");
    files=(struct node1*)malloc(sizeof(struct node1));
    char dic[MAX],fiz[MAX];
    if(headd==NULL)
    {
        printf("There is no directory, Create a directory first\n");
        add_directory();
    }
    else
    {
        printf("Enter the directory in which the file has to be stored\n");
        getchar();
        scanf("%s",dic);
        tempd=headd;
        int a=1,b=1;
        while(tempd!=NULL&&a!=0)
        {
            a=strcmp(tempd->directory,dic);
            tempd1=tempd;
            tempd=tempd->d;
        }
        if(a==0)
        {
            printf("Enter the name of the file to be stored\n");
            getchar();
            scanf("%s",fiz);
            if(tempd1->f==NULL)
            {
                strcpy(files->file,fiz);
                files->f=NULL;
                tempd1->f=files;
            }
            else
            {
                tempf=tempd1->f;
                h=tempf;
                while(tempf!=NULL&&b!=0)
                {
                    b=strcmp(tempf->file,fiz);
                    tempf1=tempf;
                    tempf=tempf->f;
                }
                if(b==0)
                {
                    printf("Already the file name exists. Try at other directory or try other file name\n");
                    create();
                }
                else
                {
                    t=tempf1;
                    strcpy(files->file,fiz);
                    while(t->f!=NULL)
                    {
                        t=t->f;
                    }
                    t->f=files;
                    files->f=NULL;
                }
            }
        }
        else
        {
            printf("No such directory found, try again\n");
            create();
        }
    }
    printf("\n");
}
void remove_file()
{
    printf("\n");
    char dir[MAX],foz[MAX];
    printf("Enter the directory name in which the file has to be deleted\n");
    getchar();
    scanf("%s",dir);
    tempd=headd;
    tempd1=headd;
    int a=1,b=1;
    if(headd==NULL)
    {
        printf("There is no directory made\n");
    }
    else
    {
        while(tempd!=NULL&&a!=0)
        {
            a=strcmp(tempd->directory,dir);
            tempd2=tempd1;
            tempd1=tempd;
            tempd=tempd->d;
        }
        if(a==0)
        {
            printf("Enter the file name to be deleted\n");
            getchar();
            scanf("%s",foz);
            tempf=tempd2->f;
            h=tempf;
            if(tempf==NULL)
            {
                printf("The directory has no files\n");
            }
            else
            {
                while(tempf!=NULL&&b!=0)
                {
                    b=strcmp(tempf->file,foz);
                    tempf2=tempf1;
                    tempf1=tempf;
                    tempf=tempf->f;
                }
                if(b==0)
                {
                    if(h==tempf1)
                    {
                        tempd2->f=tempf;
                        printf("The file has been deleted\n");
                    }
                    else
                    {
                        tempf2->f=tempf;
                        printf("The file has been deleted\n");
                    }
                }
                else
                {
                    printf("There is no such file\n");
                }
            }
        }
        else
        {
            printf("No such directory found\n");
        }
    }
    printf("\n");
}
void remove_directory()
{
    printf("\n");
    char dir[MAX];
    int a=1;
    tempd=headd;
    tempd1=headd;
    if(headd==NULL)
    {
        printf("There is no directory\n");
    }
    else
    {
        printf("Enter the directory name that has to be deleted\n");
        getchar();
        scanf("%s",dir);
        while(tempd!=NULL&&a!=0)
        {
            a=strcmp(tempd->directory,dir);
            tempd2=tempd1;
            tempd1=tempd;
            tempd=tempd->d;
        }
        if(a==0)
        {
            if(tempd1==headd)
            {
                headd=headd->d;
                printf("The directory has been deleted\n");
            }
            else if(tempd1==taild)
            {
                taild=tempd2;
                taild->d=NULL;
                printf("The directory has been deleted\n");
            }
            else
            {
                tempd2->d=tempd;
                printf("The directory has been deleted\n");
            }
        }
        else
        {
            printf("No such directory\n");
        }
    }
    printf("\n");
}
void display()
{
    printf("\n");
    char dic[MAX],foz[MAX];
    printf("Enter the directory in which the file has to be search\n");
    getchar();
    scanf("%s",dic);
    int a=1,b=1;
    tempd=headd;
    tempd1=headd;
    while(tempd!=NULL&&a!=0)
    {
        a=strcmp(tempd->directory,dic);
        tempd2=tempd1;
        tempd1=tempd;
        tempd=tempd->d;
    }
    if(a==0)
    {
        tempf=tempd2->f;
        if(tempf==NULL)
        {
            printf("The directory has no files");
        }
        else
        {
            printf("\n");
            while(tempf!=NULL)
            {
                puts(tempf->file);
                tempf=tempf->f;
            }
        }
    }
    else
    {
        printf("No such directory\n");
    }
    printf("\n");
}
void display_directory()
{
    printf("\n");
    if(headd==NULL)
    {
        printf("Their is no directory\n");
    }
    else
    {
        printf("\n");
        tempd=headd;
        while(tempd!=NULL)
        {
            puts(tempd->directory);
            tempd=tempd->d;
        }
    }
    printf("\n");
}
void add_directory()
{
    printf("\n");
    direct=(struct node1*)malloc(sizeof(struct node1));
    char dic[MAX];
    printf("Enter the directory name\n");
    getchar();
    scanf("%s",dic);
    if(headd==NULL)
    {
        strcpy(direct->directory,dic);
        headd=direct;
        taild=direct;
        direct->d=NULL;
        direct->f=NULL;
    }
    else
    {
        int a=1;
        tempd=headd;
        while(tempd!=NULL&&a!=0)
        {
            a=strcmp(dic,tempd->directory);
            tempd=tempd->d;
        }
        if(a==0)
        {
            printf("Name already exist, try again\n");
            add_directory();
        }
        else
        {
            strcpy(direct->directory,dic);
            taild->d=direct;
            direct->d=NULL;
            taild=direct;
            direct->f=NULL;
        }
    }
    printf("\n");
}
void search_directory()
{
    printf("\n");
    char dic[MAX];
    if(headd==NULL)
    {
        printf("No directory exists\n");
    }
    else
    {
        int b=1;
        printf("Enter directory name\n");
        getchar();
        scanf("%s",dic);
        tempd=headd;
        while(tempd!=NULL&&b!=0)
        {
            b=strcmp(tempd->directory,dic);
            tempd=tempd->d;
        }
        if(b==0)
        {
            printf("Directory exists\n");
        }
        else
        {
            printf("No such directory exists\n");
        }
    }
    printf("\n");
}
void two_level()
{
    int y,w;
    do
    {
        printf("Enter the choice\nFor searching a file press 1\nFor creating a file Enter 2\nFor deleting a file press 3\nTo display the files press 4\nTo add directory press 5\nTo display directories press 6\nFor searching a directory press 7\nTo remove the entire directory press 8\n");
        scanf("%d",&y);
        switch(y)
            {
            case 1:
                search();
                break;

            case 2:
                create();
                break;

            case 3:
                remove_file();
                break;

            case 4:
                display();
                break;

            case 5:
                add_directory();
                break;

            case 6:
                display_directory();
                break;

            case 7:
                search_directory();
                break;

            case 8:
                remove_directory();
                break;

            default:
                printf("Wrong choice\n");
                break;
            }
        printf("To continue with other operation in two level directory press 1, else press any other number\n");
        scanf("%d",&w);
    }while(w==1);
}
void main()
{
    int ch,w=1;
    while(w==1)
    {
    printf("Select the type of directory\nFor single level directory press 1\nFor two level directory press 2\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        single_level();
        break;

    case 2:
        two_level();
        break;

    default:
        printf("Wrong choice\n");
        break;
    }
    head=NULL;
    headd=NULL;
    printf("To continue with the program press 1,else press any other number\n");
    scanf("%d",&w);
    printf("\n");
    }
}

