#include <stdio.h>

struct tabletop{
    int x;
    int y;
};

struct playerOne{
    int x;
    int y;
};

struct playerTwo{
    int x;
    int y;
};

int main(){

    int bSize = 6; //board size
    int i, j;
    struct tabletop board[bSize];

    for(i=1;i<=bSize;i++)
    {   

        for(j=1;j<=bSize;j++)
        {

            board[i].x = i;
            board[j].y = j;

            if((i+j)%2==0)
            {
                printf("[X]");

            }else{
            
                printf("[ ]");
            }
        }
        printf("\n");
    }
}

