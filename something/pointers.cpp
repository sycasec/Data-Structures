#include <stdio.h>
#include <stdlib.h>

void display_board();
int check_for_win();
int check_for_tie();

int main(){
    int x,row,col;
    int occ_flag=0,inp_flag=0,status_flag=0,resflag=0;
    int curr_ply = 1;
    int running=1;
    char res,buff;
    char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    while(running){
        system("cls");
        if(resflag==1){
            int m,n;for(m=0;m<3;m++){for(n=0;n<3;n++){board[m][n]=' ';}}
            resflag=0;status_flag=0;curr_ply = 1;
        }

        display_board(board);
        if(occ_flag==1){printf("\n\t\t\t\t(%d, %d)\n\t\t\t\tOccupied!\n", row,col);occ_flag=0;
        } else if(inp_flag==1){printf("\n\t\t\t\tInvalid\n\t\t\t\trow! (%d)\n", row);inp_flag=0;
        } else if(inp_flag==2){printf("\n\t\t\t\tInvalid\n\t\t\t\tcolumn! (%d)\n", col);inp_flag=0;}

        printf("\n\t\t\t\t%c's turn\n\n",(curr_ply==1)?'X':'O');
        printf("\t\t\t\tRow: ");scanf("%d", &row);
        printf("\t\t\t\tColumn: ");scanf("%d", &col);

        if(row<1||row>3){inp_flag=1; continue;}
        else if (col<1||col>3){inp_flag=2; continue;}

        if(board[row-1][col-1]==' '){board[row-1][col-1]=(curr_ply==1)?'X':'O';}
        else {occ_flag=1; continue;}

        if(check_for_win(board,curr_ply)>0){status_flag=1;}
        if(check_for_tie(board)==1){status_flag=2;}

        if(status_flag==0){
            if(curr_ply==1){curr_ply=0;}
            else if(curr_ply==0){curr_ply=1;}
            system("cls");
            continue;
        }
        system("cls");
        display_board(board);
        if(status_flag==1){printf("\n\t\t\t\t%c won the game!\n",(curr_ply==1)?'X':'O');}
        else if (status_flag==2){printf("\n\t\t\t\tIts a tie!");}

        printf("\n\t\t\t\trematch? (Y/N):");buff=getchar();res=getchar();
        if(res=='Y'){resflag=1;continue;}
        else{printf("\n\n\t\t\t\tThank you for playing!");running=0;}
    }
}


void display_board(char board[][3]){
    printf("\n\n\n");
    printf("\n\t\t\t  T i c  T a c  T o e  !\n\n");
    printf("\t\t\t     |`````````````|\n");
    printf("\t\t\t     |  %c | %c | %c  |\n",board[0][0],board[0][1],board[0][2]);
    printf("\t\t\t     | ---+---+--- |\n");
    printf("\t\t\t     |  %c | %c | %c  |\n",board[1][0],board[1][1],board[1][2]);
    printf("\t\t\t     | ---+---+--- |\n");
    printf("\t\t\t     |  %c | %c | %c  |\n",board[2][0],board[2][1],board[2][2]);
    printf("\t\t\t     |_____________|\n");
}

int check_for_tie(char board[][3]){
    int i,j,count=0;
    for(i=0;i<3;i++){for(j=0;j<3;j++){if(board[i][j]==' '){count++;}}}
    if(count==0){return 1;}
    else{return 0;}
}

int check_for_win(char board[][3], int player){
    int i,j;
    char player_ch;
    int row_count=0,col_count=0,diag1_count=0,diag2_count=0;
    if(player==1){player_ch='X';}else{player_ch='O';}
    for(i=0;i<3;++i){for(j=0;j<3;++j){
        if(board[i][j]==player_ch){row_count++;}
        if(board[j][i]==player_ch){col_count++;}}
        if(row_count>=3||col_count>=3){return 1;}
        row_count=0;col_count=0;
        if(board[i][i]==player_ch){diag1_count++;}
        if(board[i][2-i]==player_ch){diag2_count++;}
    }
    return diag1_count>=3||diag2_count>=3;
}
