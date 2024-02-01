#include <stdio.h>

void slowDown(double d){
     for(double y=.1;y<100000;y=y+d){}
}
void I(int l){
    int i, z;
    for(i=0;i<13;i++){
        for (int t = 0; t < l; t++) {
                printf(" ");
        }
        for(z=0;z<8;z++){
            slowDown(.02);
         if((i<2 || i>10) && z>=0 && z<=7){
            printf("*");
         }
         else if(i>1 && i<11 && z>=2 && z<=5){
            printf("*");
         }
         else
         printf(" ");
      }
      for(int t=1;t<65;t++){printf(" ");}
      printf("\n");
   }
}

void Love(int l){
    int i,j,k,n=10;
    for(i=0,k=0;i<13;i++,k=i*2){
        for (int t = 0; t < l; t++) {
            printf(" ");
        }
        if(i>=5){ 
          k=k-1;
        }
        for(j=0;j<31;j++){
            slowDown(.05);
            if(i<3 && ((j>=(n-7)-k && j<=(n-1)+k) || (j>=(2*n+1)-k && j<=(2*n+7)+k))){
              printf("*");
            }
            else if(i>2 && (j>=k-7 && j<=37-k) || (i==12 && j==15 )){
                printf("*");
            }
            else 
                printf(" ");
             
    }
    printf("\n");
  }
}

void U(int l){
    int i, z;
    for(i=0;i<13;i++){
        for (int t = 0; t < l; t++) {
                printf(" ");
        }
      for(z=0;z<20;z++){
        slowDown(.04);
        if((i>=0 && i<=10) && (z>=0 && z<=3|| z>=16 && z<=19)){
            printf("*");
         }
         else if(i==11 && (z>=0 && z<=19) || i==12 && (z>=1 && z<=18)){
            printf("*");
         }
         else
         printf(" ");
      }
      printf("\n");
   }
}

void I_L_U(){
    for(;;){
        printf("\033[H\033[2J");
        for (int i=1;i<=3;i++) {
            if(i==1){
                I(30);
            }else if(i==2){
                Love(30+12);
            }else if(i==3){
                U(30+12+39);
            }
            printf("\033[H");
            if(i==3){
                i=0;
                slowDown(.001);
                printf("\033[H");
                }
        } 
    }
}

int main() {
    I_L_U();
}