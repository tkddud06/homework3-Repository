#include <stdio.h>
#include <stdlib.h>

void main()
{
    int list[5]; // 5개 크기의 정수형 배열 선언
    int *plist[5] = {NULL,}; // 5개 크기의 정수형 포인터 배열 선언 및 초기화

    plist[0] = (int *)malloc(sizeof(int)); // 정수형 포인터의 1번째 인덱스 위치에 동적할당
    // (첫번째 인덱스는 해당 동적할당된 힙의 주소를 저장할 것임)

    list[0] = 1; // 정수형 배열의 0번째 인덱스 위치에 1 대입
    list[1] = 100; // 정수형 배열의 1번째 인덱스 위치에 100 대입

    *plist[0] = 200; // 정수형 포인터 배열의 첫번째 인덱스가 가리키고 있는 주소에 200 대입

    printf("list[0] = %d\n", list[0]); // 1 출력될 것임
    printf("&list[0] = %p\n", &list[0]); // list[0]의 주솟값 출력될 것임
    printf("list = %p\n", list); // list의 주솟값 출력될 것임(위와 동일)
    printf("&list = %p\n", &list); // list의 주솟값 출력될 것임(위와 동일)

    printf("----------------------------------------\n\n");

    printf("list[1] = %d\n", list[1]); // 100 출력될 것임
    printf("&list[1] = %p\n", &list[1]); // list[1]의 주솟값 출력될 것임
    printf("*(list+1) = %d\n", *(list + 1)); // *(list+1)을 역참조하여, 100 출력될 것임 (list[1]과 동일)
    printf("list+1 = %p\n", list+1); // list+1의 주솟값 출력될 것임. list[1]의 주소과 동일
    // list[1],list+1 의 주솟값은 list[0], list의 주솟값에서부터 4바이트 뒤에 있을 것임. (int가 4바이트니까, 배열은 연속적인 주소를 가지니까)
    printf("----------------------------------------\n\n");

    printf("*plist[0] = %d\n", *plist[0]); // 200 출력될 것임
    printf("&plist[0] = %p\n", &plist[0]); // plist[0]의 주솟값 출력될 것임.
    printf("&plist = %p\n", &plist); // plist의 주솟값 출력될 것임. plist[0]의 주솟값과 동일
    printf("plist = %p\n", plist); // plist의 주솟값 출력될 것임. 위와 동일
    printf("plist[0] = %p\n", plist[0]); // plist[0]이 가지고 있는 주솟값 출력될 것임. 200이라는 데이터를 가지고 있는 주소일 것임.
    printf("plist[1] = %p\n", plist[1]);
    printf("plist[2] = %p\n", plist[2]);
    printf("plist[3] = %p\n", plist[3]);
    printf("plist[4] = %p\n", plist[4]);
    // plist[1] ~ plist[4] 까지는 모두 0 출력. NULL을 원소로 가지고 있기 때문.
    free(plist[0]); // free.

    printf("\n[----- [최상영]   [2022041062]  -----]\n");

}

// 프로그램 설명 : 동적할당에 대해 확인하였으며, 배열에 어떻게 값을 대입하는지와, 배열의 주소를 표현하는 여러 방법들을 살펴봄. 배열이 메모리상에 어떻게 구성되어 있는지 살펴봄.
// 또, 포인터를 NULL로 초기화했을때의 결과를 확인함.