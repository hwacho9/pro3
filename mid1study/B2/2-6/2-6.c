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

void body_index_print(body_index_t);
double bmi(body_index_t );

int main (void) {
    body_index_t a, b;
    
    a.name[NM_LEN] = '\0';
    scanf(NM_FMT, a.name);
    scanf("%lf", & a.stature);
    scanf("%lf", & a.weight);

    a.bmi = bmi(a);
    body_index_print(a);

    return 0;
}


void body_index_print(body_index_t x) {
    printf("name: %s\n", x.name);
    printf("BMI: %0.1f\n", x.bmi);
}

double bmi(body_index_t x) {
    return x.bmi = x.weight / pow(( x.stature / 100 ), 2);
}
