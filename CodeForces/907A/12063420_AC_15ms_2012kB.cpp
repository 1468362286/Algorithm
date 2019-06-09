#include <stdio.h>

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
int main() {
    int father, mother, son, masha;
    int car1, car2, car3;
    scanf("%d %d %d %d", &father, &mother, &son, &masha);
    bool flag = false;
    for (car3 = max(son,masha); car3 <= min(2*son,2*masha)&&flag==false; ++car3) {
        for (car2 =max(mother, max(car3+1,2*masha+1)); car2 <= 2*mother && flag == false; ++car2) {
            for (car1 =max(father, max(car2+1,2*masha+1)); car1 <= 2*father && flag == false; ++car1) {
                    flag = true;
                    printf("%d\n%d\n%d", car1, car2, car3);
            }
        }
    }
    if (flag == false)printf("-1");
}