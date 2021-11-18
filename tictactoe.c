#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Hiển thị bảng để chơi cờ caro và các số tương ứng với vị trí điền X hoặc O
void showTable(char a[][3]){
    printf("\tTIC TAC TOE GAME\n");
    printf("Player 1 - X\tPlayer 2 - 0\n");
    printf("----------------------");
    printf("\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%3c   |", a[i][j]);
        }
        printf("\n");
        printf("----------------------");
        printf("\n");
    } 
}

// Kiểm tra vị trí của người chơi chọn có phù hợp hay không?
int check(int yourChoice){
    if (yourChoice >= 1 && yourChoice <= 9){
        return true;
    }
    return false;
}

// value non-exist = Gia' tri. khong ton` tai.
// hàm này kiểm tra xem vị trí của người chơi chọn đã tồn tại hay chưa?
bool valueNonExist(int *b, int *yourChoice, int count){
    for (int i = 1; i < count; i++){
        if (*yourChoice == b[i]){
            return false;
        }
    }
    return true;
}

// Người chơi thứ 1 điền X
void player_1(int *yourChoiceX){
    printf("Nhap vi tri dien X: ");
    scanf("%d", yourChoiceX);
}

// Người chơi thứ 2 điền O
void player_2(int *yourChoiceO){
    printf("Nhap vi tri dien O: ");
    scanf("%d", yourChoiceO);
}


// Thay thế vị trí người chơi số 1 chọn thành X
void replaceValueX(char a[][3], char player){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (player == a[i][j]){
                a[i][j] = 'X';
            }
        }
    }
}

// Thay thế người chơi số 2 chọn là O
void replaceValueO(char a[][3], char player){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (player == a[i][j]){
                a[i][j] = 'O';
            }
        }
    }
}

void coords(int yourChoice, char *player){
    switch (yourChoice)
    {
    case 1:
        *player = '1';
        break;
    case 2:
        *player = '2';
        break;
    case 3:
        *player = '3';
        break;
    case 4:
        *player = '4';
        break;
    case 5:
        *player = '5';
        break;
    case 6:
        *player = '6';
        break;
    case 7:
        *player = '7';
        break;
    case 8:
        *player = '8';
        break;
    case 9:
        *player = '9';
        break;
    default:
        printf("-----Re-enter again-----\n");
        break;
    }
}

int checkWinning(char a[][3]){
    // i == row; j == column
    // Check row
    for (int i = 0; i < 3;i++){
        for (int j = 0; j < 3;){
            if (a[i][j] == a[i][j+1] && a[i][j+1] == a[i][j+2]){
                if (a[i][j] == 'X'){
                    printf("Player 1 - X - Win");
                    return 1;
                }
                else{
                    printf("Player 2 - 0 - Win");
                    return 1;
                }
            }
            else{
                break;
            }
        }
    }
    // Check column
    for (int j = 0; j < 3;j++){
        for (int i = 0; i < 3;){
            if (a[i][j] == a[i+1][j] && a[i+1][j] == a[i+2][j]){
                if (a[i][j] == 'X'){
                    printf("Player 1 - X - Win");
                    return 1;
                }
                else{
                    printf("Player 2 - 0 - Win");
                    return 1;
                }
            }
            else{
                break;
            }
        }
    }
    // Check circle
    if(a[0][0] == a[1][1] && a[1][1] == a[2][2] || a[0][2] == a[1][1] && a[1][1] == a[2][0]){
        if (a[1][1] == 'X'){
            printf("Player 1 - X - Win");
            return 1;
        }
        else{
            printf("Player 2 - O - Win");
            return 1;
        }
    }
}

bool checkDraw(char a[][3]){
    if (a[0][0] != 49 && a[0][1] != 50 && a[0][2] != 51 &&
        a[1][0] != 52 && a[1][1] != 53 && a[1][2] != 54 &&
        a[2][0] != 55 && a[2][1] != 56 && a[2][2] != 57){
            return true;
    }
}

// Tìm vị trí để điền X và O
int ticTacToeGame(char a[][3], int *yourChoice, int *b, int *count, char *player){
    do{
        player_1(yourChoice);     // Nguoi choi so 1 chon vi tri dien X tuong ung vs cac so tu 1 - 9
        coords(*yourChoice, player);
        if (!valueNonExist(b, yourChoice, *count)){
            printf("-----Re-enter again-----\n");
        }
    }while(!check(*yourChoice) || !valueNonExist(b, yourChoice, *count)); // Neu nguoi choi chon sai thi chay lai vong lap de nguoi choi chon lai
    replaceValueX(a, *player);
    system("cls");
    showTable(a);
    b[(*count)++] = *yourChoice;  // Luu vi tri nguoi choi da chon
    if(checkWinning(a) == 1){
        // exit(0);
        return 1;
    }

    if ((*count) < 10){ // Neu so lan chon be hon 10 thi cho nguoi choi so 2 chon
        do{ // Phan nay tuong tu nhu nguoi choi so 1.
            player_2(yourChoice);
            coords(*yourChoice, player);
            if (!valueNonExist(b, yourChoice, *count)){
                printf("-----Re-enter again-----\n");
            }
        }while(!check(*yourChoice) || !valueNonExist(b, yourChoice, *count));
        replaceValueO(a, *player);
        system("cls");
        showTable(a);
        b[(*count)++] = *yourChoice;
        if(checkWinning(a) == 1){
            // exit(0);
            return 1;
        }
    }
    else{
        if (checkDraw(a)){
            printf("Draw");
            exit(0);
        }
    }
}

int main(){
    system("cls");
    char a[3][3] = { // 3 hang` = 3 rows; 3 cot = 3 columns
        {49, 50, 51}, //row 1
        {52, 53, 54}, //row 2
        {55, 56, 57}  //row 3
    };
    char player;
    int yourChoice, b[10], footStep = 1, count = 1;

    //Cac ham` chinh' de? chay. chuong trinh
    showTable(a);  
    do{
        if (ticTacToeGame(a, &yourChoice, b, &count, &player) == 1){
            break;
        }
        ticTacToeGame(a, &yourChoice, b, &count, &player);   
        if (ticTacToeGame(a, &yourChoice, b, &count, &player) == 1){
            break;
        }
        footStep += 1;
        if (ticTacToeGame(a, &yourChoice, b, &count, &player) == 1){
            break;
        }
    } while (footStep <= 5);
    return 0;
}
