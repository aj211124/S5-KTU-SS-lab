#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 11
char la[10];
struct symb
{
	int add;
	char label[10];
}sy[11];
void search();
void main()
{

	FILE *f1,*f2,*f3,*f4,*f5;
	int a[MAX],num,key,i,ch,locctr,start_addr,l,op1,o,len;
	char ans,opcode[20],label[20],op[20],otp[20];
	char addr[10];
	int create(char []);
	void lprob(int [],int,int);
	void display(int []);
	f1=fopen("input.txt","r");
	f3=fopen("SYMTAB.txt","w");
	fscanf(f1,"%s %s %x",label,opcode,&op1);
	if(strcmp(opcode,"START")==0)
	{
	 start_addr=op1;
	 locctr=start_addr;
	 }
	 else
	 locctr=0;
	fscanf(f1,"%s %s %s",label,opcode,op);
	while(!feof(f1))
	{
	 if(strcmp(label,"**")!=0)
	 {
	 fprintf(f3,"\n%x\t%s\n",locctr,label);
	 }
	 f2=fopen("OPTAB.txt","r");
	 fscanf(f2,"%s %x",otp,&o);
	 while(!feof(f2))
	 {
	  if(strcmp(opcode,otp)==0)
	  {
	    locctr=locctr+3;
	    break;
	  }
	  fscanf(f2,"%s %x",otp,&o);
	  }
	  fclose(f2);
	  if(strcmp(opcode,"WORD")==0)

	    {
	   locctr=locctr+3;
	   }
	   else if(strcmp(opcode,"RESW")==0)
	   {
	    op1=atoi(op);
	    locctr=locctr+(3*op1);
	    }
	    else if(strcmp(opcode,"BYTE")==0)
	    {
	    if(op[0]=='X')
	      locctr=locctr+1;
	      else
	      {
	      len=strlen(op)-3;
	      locctr=locctr+len;
	      }
	    }
	    else if(strcmp(opcode,"RESB")==0)
	    {
	     op1=atoi(op);
	     locctr=locctr+op1;
	     }
	    fscanf(f1,"%s%s%s",label,opcode,op);
	  }

	  fclose(f1);
	  fclose(f3);
	for(i=0;i<MAX;i++)
		a[i]=0;
	do
	{
		printf("\nenter your choice:\n 1.display the symbol table\n 2.search in the symbol table \n 3.exit\n");
		scanf("%d",&ch);
		f3=fopen("SYMTAB.txt","r");
		switch(ch)
		{
			case 1:
			fscanf(f3,"%s %s",addr,la);
			while(!feof(f3))
			{
				num=atoi(addr);
				key=create(la);
				lprob(a,key,num);
				fscanf(f3,"%s %s",addr,la);
			}
			fclose(f3);
			display(a);
			break;
			case 2:
			search();
			break;
			case 3:
			break;
		}
	}while(ch<=2);

}

int create(char label[10])
{
	int sum = 0, i, len;
	int key;

    len = strlen(label);
    for (i = 0; i < len; i++)
    {
        sum = sum + label[i];
    }
    key=sum%11;
    return key;
}

void lprob(int a[MAX],int key,int num)
{
	int flag,i,count=0;
	void display(int a[]);
	flag=0;
	if(a[key]==0)
	{
		a[key]=num;
		sy[key].add=num;
		strcpy(sy[key].label,la);
	}
	else
	{
		i=0;
		while(i<MAX)
		{
			if(a[i]!=0)
			count++;
			i++;
		}
		if(count==MAX)
		{
			printf("\nHash table is full");
			display(a);
			exit(1);
		}
		for(i=key+1;i<MAX;i++)
			if(a[i]==0)
			{
				a[i]=num;
				flag=1;
				sy[i].add=num;
				strcpy(sy[i].label,la);
				break;
			}
		for(i=0;i<key && flag==0;i++)
			if(a[i]==0)
			{
				a[i]=num;
				flag=1;
				sy[i].add=num;
				strcpy(sy[i].label,la);
				break;
			}
	}
}
void display(int a[MAX])
{
	int i;
	printf("\nThe Symbol Table is ");
	printf("\nhashvalues address label ");
	for(i=0;i<MAX;i++)
	{
			printf("\n%d\t %d\t %s\t",i,sy[i].add,sy[i].label);
	}
}

void search()
{
	char la[10];
	int set=0,s;
	int j,i,flag;
	printf("enter the label: \n");
	scanf("%s",la);
	int key=create(la);
	printf("%d",key);
	if(strcmp(la,sy[key].label)==0)
	{
		printf("\nThe label is present in the symbol table at address %d\n",sy[key].add);
	    set=1;
	}
	else
    {
		for(i=key+1;i<MAX;i++){

		    if(strcmp(la,sy[i].label)==0)
		    {
		    	printf("\nThe label is present in the symbol table at address %d\n",sy[i].add);
		        set=1;
		        flag=1;
		    }
		}
		for(i=0;i<key && flag==0;i++){
			if(strcmp(la,sy[i].label)==0){
		    	printf("\nThe label is present in the symbol table at address %d\n",sy[i].add);
		        set=1;
		    }
		}

		if(set==0)
			printf("\nThe label is not present in the symbol table");
	}

}
