#include <stdio.h>

struct student { // student��� ����ü ����
    char lastName[13]; // 13����Ʈ
    int studentId; // 4����Ʈ
    short grade; // 2����Ʈ
}; // ������ζ��, �� ���ļ� 13 + 4 + 2 = 19����Ʈ�� ���� ���̶�� ������ �� ������, gcc �����Ϸ��� padding�� ���Ͽ�, 16 + 4 + 4 �� �Ǿ�, ������ student�� �� 24����Ʈ ũ���� ����ü�� �ȴ�.

int main()
{
    struct student pst; // student ����ü�� pst ����

    printf("size of student = %ld\n", sizeof(struct student)); // ������ ������ ������ ����, 24����Ʈ ���.
    printf("size of int = %ld\n", sizeof(int)); // int�� �ڷ����� 4����Ʈ�̹Ƿ�, 4����Ʈ ���.
    printf("size of short = %ld\n", sizeof(short)); // short�� �ڷ����� 2����Ʈ�̹Ƿ�, 2����Ʈ ���.
    
    printf("\n[----- [�ֻ�]   [2022041062]  -----]\n");
    return 0;
}

// ���α׷� ���� : padding�� ��� �۵��ϴ���, ����ü�� ũ�Ⱑ ��� ���������� ������.