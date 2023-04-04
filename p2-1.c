#include <stdio.h>

#define MAX_SIZE 100 // max size를 100으로 지정

float sum1(float list[], int);

float sum2(float *list, int);

float sum3(int n, float *list);

// 위 세 함수는 기능이 동일함. 선언부에서, sum1과 sum2는 배열을 넘기는 표현만 다를 뿐, 동일함. sum3는 매개변수의 순서가 다르지만, 매개변수는 동일함.

float input[MAX_SIZE], answer; // 크기 100의 float형 배열 input, float형 변수 answer 선언

int i; // 인덱스 표현을 위한 int형 전역변수 i 선언

void main(void)
{
    for(i=0; i < MAX_SIZE; i++)
    {
        input[i] = i; // input 배열의 각 인덱스 위치에, 해당 인덱스 번호를 값으로 하는 원소 대입. 자동 형변환을 통해, float형으로 들어갈 것. (0.0~99.0)
    }
    /* for checking call by reference */
    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");

    printf("input \t= %p\n", input); // input의 주소 출력
    answer = sum1(input, MAX_SIZE);
    printf("The sum is: %f\n\n", answer); // 0.0~99.0까지의 합인 4950.0 출력.


    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");

    printf("input \t= %p\n", input); // input의 주소 출력. 위와 동일
    answer = sum2(input, MAX_SIZE);
    printf("The sum is: %f\n\n", answer); // 0.0~99.0까지의 합인 4950.0 출력. 위와 동일.


    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");
    printf("--------------------------------------\n");

    printf("input \t= %p\n", input); // input의 주소 출력. 위와 동일
    answer = sum3(MAX_SIZE, input);
    printf("The sum is: %f\n\n", answer); // 0.0~99.0까지의 합인 4950.0 출력. 위와 동일.

    printf("\n[----- [최상영]   [2022041062]  -----]\n");

}

float sum1(float list[], int n)  // 포인터를 통해 배열의 주소를 받고, 배열의 길이를 n을 통해 받음.
{
    printf("list \t= %p\n", list); // 왜 둘이 다르지? 아! 여기서 list는 실제 list가 아니라 포인터다! 그러니 진짜 배열인 list에 &때린거랑은 다르지. 포인터의 주소가 나오니까.
    printf("&list \t= %p\n\n", &list);

    int i;
    float tempsum = 0;

    for(i = 0; i < n; i++)
    {
        tempsum += list[i]; // [] 연산자를 통해 배열의 각 원소에 접근
    } // 0부터 n-1번 인덱스 위치의 원소까지의 합을 구하는 for문.

    return tempsum;
}

float sum2(float *list, int n) // 포인터를 통해 배열의 주소를 받고, 배열의 길이를 n을 통해 받음.
{
    printf("list \t= %p\n", list);
    printf("&list \t= %p\n\n", &list);

    int i;
    float tempsum = 0;

    for(i = 0; i < n; i++)
    {
        tempsum += *(list + i); // *과 +를 이용해 배열의 각 원소에 접근. sum1과 표현이 다를 뿐, 기능은 동일함.
    } // 기능은 sum1과 동일함
    return tempsum;
}
/* stack variable reuse test */
float sum3(int n, float *list) // 매개변수의 순서를 바꾸면, 변수가 사용하는 저장공간도 바뀜. 
// sum1, sum2에서는 저장공간을 그대로 재사용하여 &list가 동일했지만, 이 경우는 n이 먼저 나오므로, 4바이트 뒤 값으로 &list가 나옴.
{
    printf("list \t= %p\n", list);
    printf("&list \t= %p\n\n", &list);

    int i;
    float tempsum = 0;

    for(i = 0; i < n; i++)
    {
        tempsum += *(list + i);
    } // sum2와 함수의 내용, 기능 모두 동일함.
    return tempsum;
}

// 프로그램 설명 : 함수의 매개변수로서 배열을 넘겨받는 여러 방법에 대해 살펴봄. 스택의 저장 공간은 재사용 되며, 매개변수의 순서에 따라 주소가 영향을 받는 것을 확인할 수 있음. 포인터에 *과 +를 통해 배열의 주소와 원소에 접근하는 방법을 확인함.