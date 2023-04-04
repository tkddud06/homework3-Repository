#include <stdio.h>

void print_one(int *ptr, int rows); // print_one 함수의 선언부. 

int main()
{
    int one[] = {0, 1, 2, 3, 4}; // int형 배열 선언 후 초기화 (5 크기)

    printf("one = %p\n", one); // one의 주솟값 출력.
    printf("&one = %p\n", &one); // one의 주솟값 출력. 위와 동일.
    printf("&one[0] = %p\n", &one[0]); // one[0]의 주솟값 출력. 위와 동일. 다 같은 주소를 반환함. 단, one과 &one[0]는 표현법만 다르고 동일하다고 볼 수 있지만, one과 &one의 의미는 조금 다름.
    // &one은 배열 그 자체를 의미하도록 되있음. 이를 통해 얻는 자료형이 int(*)[5]라고 생각하면 됨. 그렇기 때문에, 배열 포인터에 대입해줄때 해당 방식으로 적게 되있음. 
    // 단순히 포인터에 배열의 주소를 넣을 때는, one으로 적어야 함. one으로는 얻는 자료형은 int *이라고 생각하면 됨 (&one[0]과 동일).
    printf("\n");
    printf("------------------------------------\n");
    printf(" print_one(&one[0], 5) \n");
    printf("------------------------------------\n");
    print_one(&one[0], 5); // print_one 함수에 one 배열의 주소와, 길이인 5 전달.

    printf("------------------------------------\n");
    printf(" print_one(one, 5) \n");
    printf("------------------------------------\n");
    print_one(one, 5); // print_one 함수에 one 배열의 주소와, 길이인 5 전달. 위와 동일한 결과값 출력될 것임. 결국 같은 주소를 전달했으니까. 
    // 만약 여기에 one 대신 &one으로 적어도, 실행이 정상적으로 됨.(print_one 함수 내에서는 어찌되었든 받은 주솟값을 바탕으로, 본래의 역할인 int*에 맞추어 동작하기 때문)
    // 하지만, 위에서 설명했듯, 적절한 자료형을 넘기지 않았기 때문에 컴파일 시에 경고가 나옴.
    // (&one을 적으면) warning: passing argument 1 of 'print_one' from incompatible pointer type [-Wincompatible-pointer-types]과, note: expected 'int *' but argument is of type 'int (*)[5]'

    
    printf("\n[----- [최상영]   [2022041062]  -----]\n");

    return 0;
}

void print_one(int *ptr, int rows) // print_one 함수의 정의부.
{ // 포인터를 이용해 일차원 배열을 출력하는 함수
    int i;

    printf ("Address \t Contents\n");

    for (i = 0; i < rows; i++) // row 수만큼 반복
    {
        printf("%p \t %5d\n", ptr + i, *(ptr + i)); // ptr + i의 주소와, 그 주소를 역참조한 것을 출력.
        // 아무것도 더하지 않은 상태부터 주소가 4씩 뒤로 가면서, 차례대로 해당하는 주소와, 해당 인덱스 위치의 원소가 출력될 것임. (row가 5라면, 0 인덱스 ~ 4 인덱스까지 출력될 것임.) 
        // 즉, 4씩 증가되는 주소와, 0, 1, 2, 3, 4 가 출력될 것임.
        // i를 더해주면 4i씩 뒤로 가는 이유는, int형 포인터로 받았기 때문임.
    }
    printf("\n");
}

// 프로그램 설명: 배열에서 첫 주소를 표현하는 방법들에 대해서 살펴봄. 포인터를 통해, 배열을 함수의 매개변수로서 넘겨 사용하는 방법을 확인함. 다시한번 포인터에 *과 +를 통해 배열의 주소와 원소에 접근하는 방법을 확인함.