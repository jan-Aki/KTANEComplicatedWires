#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
srand(time(NULL));
int red,blue,star,led;
int shouldcut;
int usercut;
int pport,batteries,serialnumber;

while (1){
shouldcut=1;
red=rand()%2;
blue=rand()%2;
star=rand()%2;
led=rand()%2;
pport=rand()%2;
batteries=rand()%7;
serialnumber=rand()%10;

if(red==1 && star==0 && led==0){//red, blue, red and blue
    if(serialnumber%2==1){
        shouldcut=0;
    }
}
if(red==1 && blue==1 && star==0 && led==1){//red blue led
    if(serialnumber%2==1){
        shouldcut=0;
    }
}
if(red==1 && blue==1 && star==1 && led==0){//red blue star
    if (pport==0){
        shouldcut=0;
    }
}
if(red==1 && blue==1 && star==1 && led==1){//all
    shouldcut=0;
}
if(red==1 && blue==0 && led==1){//red led
    if (batteries<2){
        shouldcut=0;
    }
}
if(red==0 && blue==1 && star==0 && led==1){//blue led
    if(pport==0){
        shouldcut=0;
    }
}
if(red==0 && blue==1 && star==1 && led==0){//blue star
    shouldcut=0;
}
if(red==0 && blue==1 && star==1 && led==1){//blue star led
    if(pport==0){
        shouldcut=0;
    }
}
if(red==0 && blue==0 && star==0 && led==1){//led
    shouldcut=0;
}
if(red==0 && blue==0 && star==1 && led==1){//star led
    if(batteries<2){
        shouldcut=0;
    }
}
if(red==0 && blue==1 && star==0 && led==0){
    if(serialnumber%2==1){
        shouldcut=0;
    }
}

printf("Parallel port:%d\nBatteries:%d\nSerial number:%d\n",pport,batteries,serialnumber);
if(red==1){
    printf("red ");
}
if(blue==1){
    printf("blue ");
}
if(red==0 && blue==0){
    printf("white ");
}
if(star==1){
    printf("star ");
}
if(led==1){
    printf("led");
}
printf("\nDo you cut the wire? (1 for cut, 0 for don't cut)\n");
scanf("%d",&usercut);
if (usercut!=shouldcut){
    printf("haha bomb go boom\n\n\n");
}else{
    printf(":)\n\n\n");
}
}
return 0;
}