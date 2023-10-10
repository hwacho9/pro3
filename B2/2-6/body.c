#include <stdio.h>
#include <string.h>
#include <math.h>

#define NM_LEN 31
#define NM_FMT "%31s"

typedef struct {
  char name[NM_LEN+1];  /* 名前 */
  double stature;       /* 身長 [cm] */
  double weight;        /* 重量 [kg] */
  double bmi;           /* BMI値 */
} body_index_t;

void body_index_print(body_index_t x);
double bmi(body_index_t x);

int main(void) {
    body_index_t a, b; /* 二人　*/

    a.name[NM_LEN] = '\0';
    // strncpy(a.name, "Taro", NM_LEN);

    scanf(NM_FMT, a.name);
    scanf("%lf", &a.stature);
    scanf("%lf", &a.weight);
    

    scanf(NM_FMT, b.name);
    scanf("%lf", &b.stature);
    scanf("%lf", &b.weight);

    a.bmi = bmi(a);
    b.bmi = bmi(b);
    body_index_print(a);
    body_index_print(b);

}

void body_index_print(body_index_t x){
    printf("name: %s\n", x.name);
    printf("stature: %.1fcm\n", x.stature);
    printf("weight: %0.1fkg\n", x.weight);
    printf("BMI: %0.1f\n", x.bmi);
}

double bmi(body_index_t x)
{
    return x.weight / (x.stature/100 * x.stature/100);
}