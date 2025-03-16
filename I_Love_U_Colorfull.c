#include <stdio.h>

void slowDown(double d){
     for(double y=.1;y<100000;y=y+d){}
} 

void I(int left_space, int right_space){
    int i, z;
    for(i=0;i<13;i++){
        for (int t = 0; t < left_space; t++) {printf(" ");}
        for(z=0;z<8;z++){
            slowDown(.02);
         if((i<2 || i>10) && z>=0 && z<=7){
            printf("\033[1;34m*\033[0m");
         }
         else if(i>1 && i<11 && z>=2 && z<=5){
            printf("\033[1;34m*\033[0m");
         }
         else
         printf(" ");
      }
      for(int t=0;t<right_space;t++){printf(" ");}
      printf("\n");
   }
}

void Love(int left_space, int right_space){
    int i,j,k,n=10;
    for(i=0,k=0;i<13;i++,k=i*2){
        for (int t = 0; t < left_space; t++) {printf(" ");}
        if(i>=5){ 
          k=k-1;
        }
        for(j=0;j<31;j++){
            slowDown(.05);
            if(i<3 && ((j>=(n-7)-k && j<=(n-1)+k) || (j>=(2*n+1)-k && j<=(2*n+7)+k))){
              printf("\033[1;31m*\033[0m");
            }
            else if(i>2 && (j>=k-7 && j<=37-k) || (i==12 && j==15 )){
              printf("\033[1;31m*\033[0m");
            }
            else 
              printf(" ");  
    }
    for(int t=0;t<right_space;t++){printf(" ");}
    printf("\n");
  }
}

void O_U(int left_space, int right_space, char letter){
  int i, z;
  for(i=0;i<13;i++){
    for (int t = 0; t < left_space; t++) {printf(" ");}
    for(z=0;z<20;z++){
      slowDown(.04);
      if(letter=='U'){
        if((i>=0 && i<=10) && (z>=0 && z<=3|| z>=16 && z<=19)){
          printf("\033[1;34m*\033[0m");
        }
        else if(i==10 && (z>=0 && z<=19) || i==11 && (z>=1 && z<=18) || i==12 && (z>=3 && z<=16)){
          printf("\033[1;34m*\033[0m");
        }else
        printf(" ");
      }else if(letter=='O'){
        if((i>=3 && i<=10) && (z>=0 && z<=3|| z>=16 && z<=19)){
          printf("\033[1;31m*\033[0m");
        }else if((i==10||i==2) && (z>=0 && z<=19) || (i==11||i==1) && (z>=1 && z<=18) || (i==12||i==0) && (z>=3 && z<=16)){
          printf("\033[1;31m*\033[0m");
        }else
        printf(" ");
      }
    }
    for(int t=0;t<right_space;t++){printf(" ");}
    printf("\n");
 }
}

void two(int left_space, int right_space){
  int i, z, p=3;
  for(i=0; i<8; i++){
      for (int t = 0; t < left_space; t++) {printf(" ");}
      for(z=0; z<9; z++){
        slowDown(.04);
          if(i==1 || i==6 || i==7){
              printf("\033[1;34m*\033[0m");
          }else if((i==0 && z>=2 && z<=6) || (i==2 && z>=6)){
              printf("\033[1;34m*\033[0m");
          }else if((i>=3 && i<=5) && (z>=i+p && z<=i+p+2)){
              printf("\033[1;34m*\033[0m\033[1;34m*\033[0m\033[1;34m*\033[0m");
              p-=3;
          }
          else
              printf(" ");
    } 
    for(int t=0;t<right_space;t++){printf(" ");}
    printf("\n");
  }
}


void I_L_U(){
    for(;;){
        printf("\033[H\033[2J");
        for (int i=0;i<=3;i++) {
          printf("\n\n\n\n");
            if(i==0){
              I(30, 60);
            }else if(i==1){
              Love(30+12, 60);
            }else if(i==2){
              O_U(30+12+39, 0, 'U');
            }else if(i==3){
              O_U(30+12, 60, 'O');
              two(30+12+20, 0);
            }
            printf("\033[H");
            if(i==3){
                slowDown(.001);
                printf("\033[H");
            }
            
        } 
    }
}

int main() {
    I_L_U();
}
