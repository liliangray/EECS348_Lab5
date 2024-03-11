#include <stdio.h>
int main(){
    printf("\nEnter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    char input[100];
    //ask for user input
    fgets(input,sizeof(input),stdin);
    int score;
    sscanf(input, "%d",&score);
    //check that input meets minimum criteria (>=2 points)
    if(score<2){
        return 0;
    }
    int td = 6; int td1 = 8; int td2 = 7;
    int fg = 3; int saf = 2;
    printf("\nPossible combinations of scoring plays:\n");
    //nested loop to check for permutations
    for(int a=0;a<score;a++){
        for(int b=0;b<score;b++){
            for(int c=0;c<score;c++){
                for(int d=0;d<score;d++){
                    for(int e=0;e<score;e++){
                        if((a*td1+b*td2+c*td+d*fg+e*saf)==score){
                            printf("%d TD+2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", a,b,c,d,e);
                        }
                    }
                }
            }
        }
    }
}