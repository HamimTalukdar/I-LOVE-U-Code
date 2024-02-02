#include <stdio.h> 
#include<string.h>
 
void I(int i, int l){ 
    for (int t = 0; t < l; t++) { 
            printf(" "); 
    } 
    for(int z=0;z<8;z++){ 
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
 
void Love(int i, int l, char Lover_name[], char Your_name[], char special_character){ 
    int j,k=i*2,n=10; 
    int c,m,s1,s2;
    s1=strlen(Lover_name);
    s2=strlen(Your_name);
    c=15-(s1/2)-1;
    m=15-(s2/2)-1;

    for (int t = 0; t < l; t++) { 
        printf(" "); 
    } 
    if(i>=5){  
      k=k-1; 
    } 
    for(j=0;j<31;j++){ 
        if(i==4 && j==c ){
            printf(" ");
            while(Lover_name[j-c]!='\0'){
               printf("%c", Lover_name[j-c]);
               j++;
            }
            printf(" ");
            j++;
         }
         else if(i==6 && j==m){
            printf(" ");
            while(Your_name[j-m]!='\0'){
               printf("%c", Your_name[j-m]);
               j++;
            }
            printf(" ");
            j++;
         }
         else if(i<3 && ((j>=(n-7)-k && j<=(n-1)+k) || (j>=(2*n+1)-k && j<=(2*n+7)+k))){
            printf("%c", special_character);
         }
         else if(i>2 && j>=k-7 && j<=37-k || i==12 && j==15 ){
            if(i==5 && j==14){
               printf(" + ");
               j=16;
            }
            else
               printf("%c", special_character);
         }
      else
         printf(" ");
              
    } 
} 
 
void U(int i, int l){ 
    for (int t = 0; t < l; t++) { 
        printf(" "); 
    } 
    for(int z=0;z<20;z++){ 
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
 
void I_L_U(char Lover_name[], char Your_name[], char special_character){ 
    for(int i=0; i<13; i++){ 
        I(i, 4); 
        Love(i, 4, Lover_name, Your_name, special_character);   
        U(i, 4);   
        printf("\n");  
    } 
} 
 
int main() { 
    char special_character, Lover_name[20], Your_name[20];
    printf("Enter your crush name : ");
    gets(Lover_name);
    printf("Enter your name : ");
    gets(Your_name);
    printf("Enter your special letter/digit : ");
    scanf("%c",&special_character);
    printf("\n\n");

    I_L_U(Lover_name, Your_name, special_character);
}