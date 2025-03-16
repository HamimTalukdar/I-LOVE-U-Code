#include <stdio.h> 
 
void slowDown(double d){ 
     for(double y=.1;y<100000;y=y+d){} 
} 
 
void I(int i, int l){ 
    int z; 
        for (int t = 0; t < l; t++) { 
                printf(" "); 
        } 
        for(z=0;z<8;z++){ 
         if((i<2 || i>10) && z>=0 && z<=7){ 
            printf("*"); 
         } 
         else if(i>1 && i<11 && z>=2 && z<=5){ 
            printf("*"); 
         } 
         else 
         printf(" "); 
      } 
} 
 
void Love(int i, int l){ 
    int j,k=i*2,n=10; 
        for (int t = 0; t < l; t++) { 
                printf(" "); 
        } 
        if(i>=5){  
          k=k-1; 
        } 
        for(j=0;j<31;j++){ 
            if(i<3 && ((j>=(n-7)-k && j<=(n-1)+k) || (j>=(2*n+1)-k && j<=(2*n+7)+k))){ 
              printf("*"); 
            } 
            else if((i==3 && j!=15) || (i>3 && (j>=k-7 && j<=37-k)) || (i==12 && j==15 )){ 
                printf("*"); 
            } 
            else  
                printf(" "); 
              
  } 
} 
 
void U(int i, int l){ 
    int z; 
        for (int t = 0; t < l; t++) { 
                printf(" "); 
        } 
      for(z=0;z<20;z++){ 
         if((i>=0 && i<=10) && (z>=0 && z<=3|| z>=16 && z<=19)){ 
            printf("*"); 
         } 
         else if(i==11 && (z>=0 && z<=19) || i==12 && (z>=1 && z<=18)){ 
            printf("*"); 
         } 
         else 
         printf(" "); 
      } 
} 
 
void I_L_U(){ 
    for(;;){ 
        printf("\033[H\033[2J"); 
        for(int i=0; i<13; i++){ 
        I(i, 4); 
        Love(i, 4);   
        U(i, 4);   
        printf("\n");  
        } 
        slowDown(.001); 
        printf("\033[H"); 
    } 
} 
 
int main() { 
    I_L_U(); 
}
