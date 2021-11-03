#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Hiển thị bảng để chơi cờ caro và các số tương ứng với vị trí điền X hoặc O
void showTable(char a[][3]){
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
    if (yourChoice >= 0 && yourChoice <= 8){
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
    case 0:
        *player = '0';
        break;
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
    default:
        printf("-----Re-enter again-----\n");
        break;
    }
}

// Tìm vị trí để điền X và O
void ticTacToeGame(char a[][3], int *yourChoice, int *b, int *count, char *player){
    do{
        player_1(yourChoice);     // Nguoi choi so 1 chon vi tri dien X tuong ung vs cac so tu 1 - 8
        coords(*yourChoice, player);
        if (!valueNonExist(b, yourChoice, *count)){
            printf("-----Re-enter again-----\n");
        }
    }while(!check(*yourChoice) || !valueNonExist(b, yourChoice, *count)); // Neu nguoi choi chon sai thi chay lai vong lap de nguoi choi chon lai
    replaceValueX(a, *player);
    system("cls");
    showTable(a);
    b[(*count)++] = *yourChoice;  // Luu vi tri nguoi choi da chon

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
    } 
}

void checkWinning(){
    
}

int main(){
    system("cls");
    char a[3][3] = { // 3 hang` = 3 rows; 3 cot = 3 columns
        {48, 49, 50}, //row 1
        {51, 52, 53}, //row 2
        {54, 55, 56}  //row 3
    };
    char player;
    int yourChoice, b[10], footStep = 1, count = 1;

    //Cac ham` chinh' de? chay. chuong trinh
    showTable(a);  
    do{
        ticTacToeGame(a, &yourChoice, b, &count, &player);   
        footStep += 1;
    } while (footStep <= 5);

    getchar();
    return 0;
}
