# include <stdio.h>
# include <string.h>
# include <stdlib.h>
void convert(int bitmask,int*arr){
  int i=11;
     while(bitmask!=0){

          int x=bitmask%16;

          if(x!=0){
          while(x>0){
            int bit=x&1;
            arr[i]=bit;

            i--;
            x=x>>1;

          }}
          else{
            for(int j=0;j<4;j++){
              arr[i]=0;
              i--;
            }
          }
          bitmask=bitmask/16;

        }

}
int main(){

  FILE* f1;
  char input[2], rec[2], w[7];
  char name[10];
  f1=fopen("record.txt","r");
   FILE* f2=fopen("output.txt","w");
   fscanf(f1,"%s",rec);
   int saG;
   int lenG;
   int start;
   unsigned int addd,newadr;
   printf("enter correct add where prgm is laoded:\t");
   scanf("%x",&start);
   addd=start;
   fprintf(f2,"ADDRESS\t\tCONTENT\n");
   if(strcmp(rec,"H")==0){

      fscanf(f1,"%s",name);
       printf("%s\n",name);
      fscanf(f1,"%x",&saG);
      printf("%x",saG);
      fscanf(f1,"%x",&lenG);
      printf("%x\n",lenG);

}
   int addr;
   int len;
  int arr[12];
   int bitmask;
   fscanf(f1,"%s",rec);
   printf("%s\n",rec);
   while(!feof(f1) && strcmp(rec,"T")==0&& strcmp(rec,"E")!=0){
      fscanf(f1,"%x",&addr);
      printf("%x\n",addr);
       fscanf(f1,"%x",&len);
       printf("%x\n",len);
        fscanf(f1,"%x",&bitmask);
        printf("%x\n",bitmask);
        addd=start;
        addd+=addr;
        bitmask+=start;
        printf("%x\t%x\n\n",addd,bitmask);
        fprintf(f2,"%x\t\t\t%x\n",addd,bitmask);
        addd=addd+3;
      convert(bitmask,arr);

        unsigned int val1;
        int k=0;
        unsigned int val2=0;
   while(len>0){

  fscanf(f1,"%x",&val1);
 if((val1==val2)||(val1==14))
  {
    break;
  }
  printf("%x\n",val1);
  val2=val1;
  printf("%x\t%x\n\n",addd,val1+start);
  fprintf(f2,"%x\t\t\t%x\n",addd,val1+start);
  int l=1;
  int temp=val1;
  addd+=3;
  while(temp>0){
    temp=temp/0x16;
    l+=1;
  }
  if(arr[k]==1){
   newadr=(start-addr)+addd;
  }else{
    //addd+3;
  }

  len=len-(l/2);
  k++;
  printf("Next line\n");
}
 fscanf(f1,"%s",rec);
}
return 0;
}
