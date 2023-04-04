#include <stdio.h>
#include <stdlib.h>

void main()
{

    int list[5]; // 5개 크기의 정수형 배열 선언
    int *plist[5]; // 5개 크기의 정수형 포인터 배열 선언

    list[0] = 10; // 정수형 배열의 0번째 인덱스 위치에 10 대입
    list[1] = 11; // 정수형 배열의 1번째 인덱스 위치에 11 대입

    plist[0] = (int*)malloc(sizeof(int)); // 정수형 포인터 배열의 0번째 인덱스 위치에 동적할당

    printf("list[0] \t= %d\n", list[0]); // 10 출력
    printf("list \t\t= %p\n", list); // list의 주솟값 출력 
    printf("&list[0] \t= %p\n", &list[0]); // list[0]의 주솟값 출력. 위와 동일함. 표현이 다를 뿐임.
    printf("list + 0 \t= %p\n", list+0); // list의 주솟값 출력. 위와 동일
    printf("list + 1 \t= %p\n", list+1); // list+1의 주솟값 출력. 윗줄에 출력된 주솟값에서 4바이트 뒤로 간 주소가 출력됨 (int가 4바이트기 때문)
    printf("list + 2 \t= %p\n", list+2); // list+2의 주솟값 출력. 윗줄에 출력된 주솟값에서 4바이트 뒤로 간 주소 출력
    printf("list + 3 \t= %p\n", list+3); // list+3의 주솟값 출력. 윗줄에 출력된 주솟값에서 4바이트 뒤로 간 주소 출력
    printf("list + 4 \t= %p\n", list+4); // list+4의 주솟값 출력. 윗줄에 출력된 주솟값에서 4바이트 뒤로 간 주소 출력
    printf("&list[4] \t= %p\n", &list[4]); // list+4의 주솟값 출력. 윗줄의 주솟값(list+4의 주솟값)과 동일.

    free(plist[0]); // free.
}

// 프로그램 설명 : ap1.c에서, 배열의 메모리 구성에 더 집중하여 살펴보는 프로그램.
// 역시나 동적할당에 대해 확인하였고, 배열의 주소를 표현하는 여러 방법들을 살펴봄. 배열이 메모리상에 어떻게 구성되어 있는지 살펴봄.