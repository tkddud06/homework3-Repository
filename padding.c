#include <stdio.h>

struct student { // student라는 구조체 정의
    char lastName[13]; // 13바이트
    int studentId; // 4바이트
    short grade; // 2바이트
}; // 원래대로라면, 다 합쳐서 13 + 4 + 2 = 19바이트가 나올 것이라고 추정할 수 있지만, gcc 컴파일러의 padding에 의하여, 16 + 4 + 4 가 되어, 실제로 student는 총 24바이트 크기의 구조체가 된다.

int main()
{
    struct student pst; // student 구조체인 pst 선언

    printf("size of student = %ld\n", sizeof(struct student)); // 위에서 설명한 이유에 따라, 24바이트 출력.
    printf("size of int = %ld\n", sizeof(int)); // int형 자료형은 4바이트이므로, 4바이트 출력.
    printf("size of short = %ld\n", sizeof(short)); // short형 자료형은 2바이트이므로, 2바이트 출력.
    
    printf("\n[----- [최상영]   [2022041062]  -----]\n");
    return 0;
}

// 프로그램 설명 : padding이 어떻게 작동하는지, 구조체의 크기가 어떻게 정해지는지 보여줌.