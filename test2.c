// #include <stdio.h>

// int main(){
//     int c;
//     TEST: while(scanf("%d", &c)){
//         if (c == -1) {
//             printf("Nhap sai!");
//             goto TEST;
//         }
//         printf("%d\n", c);
//     }
//     return 0;
// }
#include <stdio.h>

int main(void)
{
  char line[256];

  int arg1;
  int isint;

  while (1) {
    printf("Give attacking argument: ");
    fgets(line, sizeof line, stdin);
    isint = sscanf(line, "%d",&arg1);
    if (isint) break;

    printf("You did not enter a number.Please enter an argument's number\n");
  }

  printf("Thanks for entering %d", arg1);

  return 0;
}