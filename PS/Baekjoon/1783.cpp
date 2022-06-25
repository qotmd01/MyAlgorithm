/*
https://velog.io/@qotmd01/PS-백준-1783-병든-나이트

*/

#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
   int n, m , move_cnt;
   cin >> n >> m;

   // 이동할수가 없다.
   if (n == 1){
       move_cnt = 0;
   }
   // 2번 3번을 번갈아 이동한다.
   else if (n == 2){
       move_cnt = min(3, (m-1) / 2);
   }
   else{
       // 1 ,4 번을 번갈아 이동한다.
       if (m < 7) {
           move_cnt = min(3, m - 1);
       }

       // 2, 3 번을 한번씩 사용하고 1, 4번을 사용하여 이동한다.
       else{
           move_cnt = 2 + m - 5;
       }
   }

   // 답은 '칸'을 출력해야 하므로 시작칸을 더한다.
   cout << move_cnt + 1 << "\n";
}
