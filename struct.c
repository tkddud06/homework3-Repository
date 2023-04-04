#include <stdio.h>

struct student1 { // student1이라는 구조체의 정의
    char lastName;
    int studentId;
    char grade;
};

typedef struct { // student2라는 구조체의 정의. typedef를 통해 struct를 생략할 수 있게 함.
    char lastName;
    int studentId;
    char grade;
} student2;

int main() 
{
    struct student1 st1 = {'A', 100, 'A'}; // student1 구조체인 st1 선언 후, 값 초기화

    // st1에 초기화해둔 값들이 나올 것임.
    printf("st1.lastName = %c\n", st1.lastName); // A 출력
    printf("st1.studentId = %d\n", st1.studentId); // 100 출력
    printf("st1.grade = %c\n", st1.grade); // A 출력

    student2 st2 = {'B', 200, 'B'}; // student2 구조체인 st2 선언 후, 값 초기화

    // st1에 초기화해둔 값들이 나올 것임.
    printf("\nst2.lastName = %c\n", st2.lastName); // B 출력
    printf("st2.studentId = %d\n", st2.studentId); // 200 출력
    printf("st2.grade = %c\n", st2.grade); // B 출력

    student2 st3; // student2형 변수 st3 선언

    st3 = st2; // st3에 st2 대입. st2의 값들이 그대로 복사될 것임.

    // st3의 값들이 나올 것임. st2와 동일하게 나옴.
    printf("\nst3.lastName = %c\n", st3.lastName); // B 출력
    printf("st3.studentId = %d\n", st3.studentId); // 200 출력
    printf("st3.grade = %c\n", st3.grade); // B 출력

    /* 동일 여부 테스트 */
    // if(st3 == st2) // 작동 불능이다. 에러 나온다. 구조체는 해당 방식으로 비교하는게 아니라, 각 요소를 하나하나 비교해야한다.
    // {
    //     printf("equal\n");
    // }
    // else
    // {
    //     printf("not equal\n");
    // }

    // 아래는 위 기능을 실제로 작동 가능하도록 코딩한 부분이다.

    if(st3.lastName == st2.lastName && st3.grade == st2.grade && st3.studentId == st2.studentId) // 작동이 가능하게 하려면, 구조체의 각 멤버 변수를 불러와, 직접 비교해주어야 한다.
    {
        printf("equal\n");
    }
    else
    {
        printf("not equal\n");
    }

    printf("\n[----- [최상영]   [2022041062]  -----]\n");

    return 0;
}

// 프로그램 설명 : 구조체를 어떻게 정의할 수 있는지와 typedef의 사용에 대해 student1과 student2를 통해 보여주고 있고, 출력들을 통해 어떻게 구조체의 멤버 변수에 접근하는지 보여준다. 그리고 구조체를 구조체에 대입할 수 있음을 보여준다. 또, 구조체를 비교할때는 어떻게 해야하는지 보여준다.