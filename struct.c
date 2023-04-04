#include <stdio.h>

struct student1 { // student1�̶�� ����ü�� ����
    char lastName;
    int studentId;
    char grade;
};

typedef struct { // student2��� ����ü�� ����. typedef�� ���� struct�� ������ �� �ְ� ��.
    char lastName;
    int studentId;
    char grade;
} student2;

int main() 
{
    struct student1 st1 = {'A', 100, 'A'}; // student1 ����ü�� st1 ���� ��, �� �ʱ�ȭ

    // st1�� �ʱ�ȭ�ص� ������ ���� ����.
    printf("st1.lastName = %c\n", st1.lastName); // A ���
    printf("st1.studentId = %d\n", st1.studentId); // 100 ���
    printf("st1.grade = %c\n", st1.grade); // A ���

    student2 st2 = {'B', 200, 'B'}; // student2 ����ü�� st2 ���� ��, �� �ʱ�ȭ

    // st1�� �ʱ�ȭ�ص� ������ ���� ����.
    printf("\nst2.lastName = %c\n", st2.lastName); // B ���
    printf("st2.studentId = %d\n", st2.studentId); // 200 ���
    printf("st2.grade = %c\n", st2.grade); // B ���

    student2 st3; // student2�� ���� st3 ����

    st3 = st2; // st3�� st2 ����. st2�� ������ �״�� ����� ����.

    // st3�� ������ ���� ����. st2�� �����ϰ� ����.
    printf("\nst3.lastName = %c\n", st3.lastName); // B ���
    printf("st3.studentId = %d\n", st3.studentId); // 200 ���
    printf("st3.grade = %c\n", st3.grade); // B ���

    /* ���� ���� �׽�Ʈ */
    // if(st3 == st2) // �۵� �Ҵ��̴�. ���� ���´�. ����ü�� �ش� ������� ���ϴ°� �ƴ϶�, �� ��Ҹ� �ϳ��ϳ� ���ؾ��Ѵ�.
    // {
    //     printf("equal\n");
    // }
    // else
    // {
    //     printf("not equal\n");
    // }

    // �Ʒ��� �� ����� ������ �۵� �����ϵ��� �ڵ��� �κ��̴�.

    if(st3.lastName == st2.lastName && st3.grade == st2.grade && st3.studentId == st2.studentId) // �۵��� �����ϰ� �Ϸ���, ����ü�� �� ��Ҹ� �ҷ���, ���� �����־�� �Ѵ�.
    {
        printf("equal\n");
    }
    else
    {
        printf("not equal\n");
    }

    printf("\n[----- [�ֻ�]   [2022041062]  -----]\n");

    return 0;
}

// ���α׷� ���� : ����ü�� ��� ������ �� �ִ����� typedef�� ��뿡 ���� student1�� student2�� ���� �����ְ� �ְ�, ��µ��� ���� ��� ����ü�� ��ҿ� �����ϴ��� �����ش�. �׸��� ����ü�� ����ü�� ������ �� ������ �����ش�. ��, ����ü�� ���Ҷ��� ��� �ؾ��ϴ��� �����ش�.