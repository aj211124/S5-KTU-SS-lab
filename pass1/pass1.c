#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
  unsigned int st,locctr,len,opt1;
  char opcode[100],op[100],label[100],opt[100];
  FILE *f1,*f2,*f3,*f4,*f5;
  f1=fopen("input.txt","r");
  f2=fopen("optab.txt","r");
  f3=fopen("symtab.txt","w");
  f4=fopen("intermediate.txt","w");
  f5=fopen("prolen.txt","w");
  fscanf(f1,"%s\t%s\t%X",label,opcode,&st);
  if(strcmp(opcode,"START")==0)
  {
    locctr=st;
    fprintf(f4,"\t%s\t%s\t%X\n",label,opcode,st);
    printf("\t%s\t%s\t%X\n",label,opcode,st);
    fscanf(f1,"%s\t%s\t%s",label,opcode,op);
  }
  else
  {
    locctr=0;
    st=0;
  }
  while(strcmp(opcode,"END")!=0)
  {
    fprintf(f4,"%X\t%s\t%s\t%s\n",locctr,label,opcode,op);
    printf("%X\t%s\t%s\t%s\n",locctr,label,opcode,op);
    if(strcmp(label,"**")!=0)
    {
      fprintf(f3,"%s\t%x\n",label,locctr);
    }
    fscanf(f2,"%s\t%x",opt,&opt1);
    while(!feof(f2))
    {
      if(strcmp(opcode,opt)==0)
      {
        break;
      }
      fscanf(f2,"%s\t%d",opt,&opt1);
    }
      if(strcmp(opcode,"WORD")==0)
      {
        locctr+=3;
      }
      else if(strcmp(opcode,"RESW")==0)
      {
        locctr+=(3*atoi(op));
      }
      else if(strcmp(opcode,"RESB")==0)
      {
        locctr+=atoi(op);
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
      else
      {
        locctr+=3;
      }
    fscanf(f1,"%s\t%s\t%s",label,opcode,op);
  }
  fprintf(f4,"%X\t%s\t%s\t%s",locctr,label,opcode,op);
  printf("%X\t%s\t%s\t%s\n",locctr,label,opcode,op);
  len=locctr-st;
  fprintf(f5,"%x",len);
  fclose(f1);
  fclose(f2);
  fclose(f3);
  fclose(f4);
  fclose(f5);
  printf("The length of the program is %x",len);
}
