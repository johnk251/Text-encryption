#include <stdio.h>
#include <stdlib.h>
//#include <errorn.h>

int main(int arg ,char* argv[]){ 

if (arg<2){

printf("USAGE: cc text.txt 1 or 2  privatekey \n");
printf("1 for encrytion and 2 for decrytion");

return 1;
}

FILE * textfile ;
FILE * outfile;
char txt[20];
int privatekey= atoi(argv[4]);
int encryt= atoi(argv[3]);


textfile=fopen(argv[1],"r");

if(textfile==NULL){
perror("Error opening file");


}
outfile=fopen(argv[2],"a");

while(1)  {
int c =fgetc(textfile);

if(c==EOF)
 break;


if(encryt==1){
c=((c+privatekey)+122)%122;
//printf("after %c",c);
fputc(c,outfile);

}
if(encryt==2){
    

c=((c-privatekey)+122)%122;

fputc(c,outfile);
}



}






fclose(textfile);
fclose(outfile);


return 0;
}
