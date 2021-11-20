#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct AEIOU {
   int symbol;
   int cnt;
   int arr[100];
}alpha;

int main(void) {
   
   //각 모음 집합
   alpha A;
   alpha E;
   alpha I;
   alpha O;
   alpha U;
   int symbol[5]; // 각 모음의 대응 수
   char* plaintext;
   int msg_cnt;

   // 초기화
   memset(symbol, 0, 5);
   plaintext = (char*)malloc(sizeof(char) * 1000);
//   freopen("input.txt", "r", stdin);
   // 전체 메세지 수
   msg_cnt = 0;
   scanf("%d", &msg_cnt);

   for (int i = 0; i < msg_cnt; i++) {

      // 초기화
      A.cnt = 0;
      E.cnt = 0;
      I.cnt = 0;
      O.cnt = 0;
      U.cnt = 0;
      memset(A.arr, 0, 200);
      memset(E.arr, 0, 200);
      memset(I.arr, 0, 200);
      memset(O.arr, 0, 200);
      memset(U.arr, 0, 200);

      for (int j = 0; j < 5; j++) {
         scanf("%d", &symbol[j]);
      }

      // 모음 대응 값 초기화
      A.symbol = symbol[0];
      E.symbol = symbol[1];
      I.symbol = symbol[2];
      O.symbol = symbol[3];
      U.symbol = symbol[4];
      getchar();
      fgets(plaintext, 1000, stdin);
      
      // 모음 정보 채우기
      for (int j = 0; j < strlen(plaintext); j++) {

         if (plaintext[j] == 'A')
         {
            A.arr[A.cnt] = j;
            A.cnt++;
            plaintext[j] = '?';
            continue;
         }
         if (plaintext[j] == 'E')
         {
            E.arr[E.cnt] = j;
            E.cnt++;
            plaintext[j] = '?';
            continue;
         }
         if (plaintext[j] == 'I')
         {
            I.arr[I.cnt] = j;
            I.cnt++;
            plaintext[j] = '?';
            continue;
         }
         if (plaintext[j] == 'O')
         {
            O.arr[O.cnt] = j;
            O.cnt++;
            plaintext[j] = '?';
            continue;
         }
         if (plaintext[j] == 'U')
         {
            U.arr[U.cnt] = j;
            U.cnt++;
            plaintext[j] = '?';
            continue;
         }
      }

      // 모음 Dic 출력
      if (A.cnt != 0) {
         printf("%d%d", A.symbol, A.cnt);
         for (int j = 0; j < A.cnt; j++)
            printf("%d", A.arr[j]);
      }
      if (E.cnt != 0) {
         printf("%d%d", E.symbol, E.cnt);
         for (int j = 0; j < E.cnt; j++)
            printf("%d", E.arr[j]);
      }
      if (I.cnt != 0) {
         printf("%d%d", I.symbol, I.cnt);
         for (int j = 0; j < I.cnt; j++)
            printf("%d", I.arr[j]);
      }
      if (O.cnt != 0) {
         printf("%d%d", O.symbol, O.cnt);
         for (int j = 0; j < O.cnt; j++)
            printf("%d", O.arr[j]);
      }
      if (U.cnt != 0) {
         printf("%d%d", U.symbol, U.cnt);
         for (int j = 0; j < U.cnt; j++)
            printf("%d", U.arr[j]);
      }

      // enc 배열 출력
      for (int j = 0; j < strlen(plaintext)-1; j++) {
         printf("%d", plaintext[j]);
      }

      printf("\n");
      memset(plaintext, 0, 1000);
   }

   free(plaintext);
   return 0;
}
