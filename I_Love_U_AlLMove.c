#include <stdio.h>
#include <stdbool.h>

void slowDown(double d){
     for(double y=.1;y<100000;y=y+d){}
} 

void I(int left_space, int right_space, float time, int color, bool raw, int r_no){
    int i, z;
    if(raw==true){
      i=r_no;
    }else{
      i=0;
    }
    for(;i<13;i++){
        for (int t = 0; t < left_space; t++) {printf(" ");}
        for(z=0;z<8;z++){
            slowDown(time);
         if((i<2 || i>10) && z>=0 && z<=7){
            printf("\033[1;%dm*\033[0m", color);
         }
         else if(i>1 && i<11 && z>=2 && z<=5){
            printf("\033[1;%dm*\033[0m", color);
         }
         else
         printf(" ");
      }
      for(int t=0;t<right_space;t++){printf(" ");}
      if(raw==true){
        break;
      }
      printf("\n");
   }
}

void Love(int left_space, int right_space, float time, int color, bool raw, int r_no){
    int i,j,k,n=10;
    if(raw==true){
      i=r_no;
      k=i*2;
    }else{
      i=0;
      k=0;
    }
    for(;i<13;i++,k=i*2){
        for (int t = 0; t < left_space; t++) {printf(" ");}
        if(i>=5){ 
          k=k-1;
        }
        for(j=0;j<31;j++){
            slowDown(time);
            if(i<3 && ((j>=(n-7)-k && j<=(n-1)+k) || (j>=(2*n+1)-k && j<=(2*n+7)+k))){
              printf("\033[1;%dm*\033[0m", color);
            }
            else if(i>2 && (j>=k-7 && j<=37-k) || (i==12 && j==15 )){
              printf("\033[1;%dm*\033[0m", color);
            }
            else 
              printf(" ");  
    }
    for(int t=0;t<right_space;t++){printf(" ");}
    if(raw==true){
      break;
    }
    printf("\n");
  }
}

void O_U(int left_space, int right_space, float time, int color, char letter, bool raw, int r_no){
  int i, z;
  if(raw==true){
    i=r_no;
  }else{
    i=0;
  }
  for(;i<13;i++){
    for (int t = 0; t < left_space; t++) {printf(" ");}
    for(z=0;z<20;z++){
      slowDown(time);
      if(letter=='U'){
        if((i>=0 && i<=10) && (z>=0 && z<=3|| z>=16 && z<=19)){
          printf("\033[1;%dm*\033[0m", color);
        }
        else if(i==10 && (z>=0 && z<=19) || i==11 && (z>=1 && z<=18) || i==12 && (z>=3 && z<=16)){
          printf("\033[1;%dm*\033[0m", color);
        }else
        printf(" ");
      }else if(letter=='O'){
        if((i>=3 && i<=10) && (z>=0 && z<=3|| z>=16 && z<=19)){
          printf("\033[1;%dm*\033[0m", color);
        }else if((i==10||i==2) && (z>=0 && z<=19) || (i==11||i==1) && (z>=1 && z<=18) || (i==12||i==0) && (z>=3 && z<=16)){
          printf("\033[1;%dm*\033[0m", color);
        }else
        printf(" ");
      }
    }
    for(int t=0;t<right_space;t++){printf(" ");}
    if(raw==true){
      break;
    }
    printf("\n");
 }
}

void two(int left_space, int right_space, float time, int color, bool raw, int r_no){
  int i, z, p=3;
  if(raw==true){
    i=r_no;
  }else{
    i=0;
  }
  for(; i<8; i++){
      for (int t = 0; t < left_space; t++) {printf(" ");}
      for(z=0; z<9; z++){
          slowDown(time);
          if(i==1 || i==6 || i==7){
              printf("\033[1;%dm*\033[0m", color);
          }else if((i==0 && z>=2 && z<=6) || (i==2 && z>=6)){
              printf("\033[1;%dm*\033[0m", color);
          }else if((i>=3 && i<=5) && (z>=i+p && z<=i+p+2)){
              printf("\033[1;%dm*\033[0m\033[1;%dm*\033[0m\033[1;%dm*\033[0m", color, color, color);
              p-=3;
          }
          else
              printf(" ");
    } 
    for(int t=0;t<right_space;t++){printf(" ");}
    if(raw==true){
      break;
    }
    printf("\n");
  }
}

void I_L_U(int c1, int c2){
  printf("\033[H\033[2J");
  for (int i=0;i<=3;i++) {
    printf("\n\n\n\n");
      if(i==0){
        I(30, 60, 0.05, c1, false, 0);
      }else if(i==1){
        Love(30+12, 60, 0.05, c2, false, 0);
      }else if(i==2){
        O_U(30+12+39, 0, 0.05, c1, 'U', false, 0);
      }else if(i==3){
        O_U(30+12, 60, 0.05, c2, 'O', false, 0);
        two(30+12+20, 0, 0.05, c1, false, 0);
      }
      printf("\033[H");
      if(i==3){
          slowDown(.001);
          printf("\033[H");
      } 
  } 
}

void proLove(int c1, int c2){
  printf("\033[H\033[2J");
  for (int i=0;i<=3;i++) {
    printf("\n\n\n\n");
      if(i==0){
        for(int t=0;t<=13;t++){
          I(30, 10, 0.05, c1, true, t);
          printf("\n");
        }
      }else if(i==1){
        for(int t=0;t<=13;t++){
          I(30, 10, 0.05, c1, true, t);
          Love(0, 10, 0.05, c2, true, t);
          printf("\n");
        }
      }else if(i==2){
        for(int t=0;t<=13;t++){
          I(30, 10, 0.05, c1, true, t);
          Love(0, 10, 0.05, c2, true, t);
          O_U(0, 0, 0.3, c1, 'U', true, t);
          printf("\n");
        }
      }else if(i==3){
        O_U(30+10+12, 60, 0.05, c2, 'O', false, 0);
        two(30+10+12+20, 0, 0.05, c1, false, 0);
      }
      printf("\033[H");
      if(i==3){
          slowDown(.001);
          printf("\033[H");
      }
  } 
}

void connectLove(int c1, int c2){
  printf("\033[H\033[2J");
  printf("\n\n\n\n");
  for (int i=0;i<=13;i++) {
      I(30, 10, 0.05, c1, true, i);
      Love(0, 10, 0.05, c2, true, i); 
      O_U(0, 0, 0.05, c1, 'U', true, i);
      printf("\n");
  } 
  printf("\033[H\n\n\n\n");
  O_U(30+10+12, 60, 0.05, c2, 'O', false, 0);
  two(30+10+12+20, 0, 0.05, c1, false, 0);
  slowDown(.001);
  printf("\033[H");
}

int main() {
  // Red: 31, Green: 32, Yellow: 33, Blue: 34, Magenta: 35, Cyan: 36
  for(;;){
    for(int i=0; i<3; i++){
      if(i==0){
        I_L_U(34, 31);
      }else if(i==1){
        proLove(32, 33);
      }else{
        connectLove(35, 36);
      }
    }
  }
}

