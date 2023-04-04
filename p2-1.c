#include <stdio.h>

#define MAX_SIZE 100 // max size�� 100���� ����

float sum1(float list[], int);

float sum2(float *list, int);

float sum3(int n, float *list);

// �� �� �Լ��� ����� ������. ����ο���, sum1�� sum2�� �迭�� �ѱ�� ǥ���� �ٸ� ��, ������. sum3�� �Ű������� ������ �ٸ�����, �Ű������� ������.

float input[MAX_SIZE], answer; // ũ�� 100�� float�� �迭 input, float�� ���� answer ����

int i; // �ε��� ǥ���� ���� int�� �������� i ����

void main(void)
{
    for(i=0; i < MAX_SIZE; i++)
    {
        input[i] = i; // input �迭�� �� �ε��� ��ġ��, �ش� �ε��� ��ȣ�� ������ �ϴ� ���� ����. �ڵ� ����ȯ�� ����, float������ �� ��. (0.0~99.0)
    }
    /* for checking call by reference */
    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");

    printf("input \t= %p\n", input); // input�� �ּ� ���
    answer = sum1(input, MAX_SIZE);
    printf("The sum is: %f\n\n", answer); // 0.0~99.0������ ���� 4950.0 ���.


    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");

    printf("input \t= %p\n", input); // input�� �ּ� ���. ���� ����
    answer = sum2(input, MAX_SIZE);
    printf("The sum is: %f\n\n", answer); // 0.0~99.0������ ���� 4950.0 ���. ���� ����.


    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");
    printf("--------------------------------------\n");

    printf("input \t= %p\n", input); // input�� �ּ� ���. ���� ����
    answer = sum3(MAX_SIZE, input);
    printf("The sum is: %f\n\n", answer); // 0.0~99.0������ ���� 4950.0 ���. ���� ����.

    printf("\n[----- [�ֻ�]   [2022041062]  -----]\n");

}

float sum1(float list[], int n)  // �����͸� ���� �迭�� �ּҸ� �ް�, �迭�� ���̸� n�� ���� ����.
{
    printf("list \t= %p\n", list); // �� ���� �ٸ���? ��! ���⼭ list�� ���� list�� �ƴ϶� �����ʹ�! �׷��� ��¥ �迭�� list�� &�����Ŷ��� �ٸ���. �������� �ּҰ� �����ϱ�.
    printf("&list \t= %p\n\n", &list);

    int i;
    float tempsum = 0;

    for(i = 0; i < n; i++)
    {
        tempsum += list[i]; // [] �����ڸ� ���� �迭�� �� ���ҿ� ����
    } // 0���� n-1�� �ε��� ��ġ�� ���ұ����� ���� ���ϴ� for��.

    return tempsum;
}

float sum2(float *list, int n) // �����͸� ���� �迭�� �ּҸ� �ް�, �迭�� ���̸� n�� ���� ����.
{
    printf("list \t= %p\n", list);
    printf("&list \t= %p\n\n", &list);

    int i;
    float tempsum = 0;

    for(i = 0; i < n; i++)
    {
        tempsum += *(list + i); // *�� +�� �̿��� �迭�� �� ���ҿ� ����. sum1�� ǥ���� �ٸ� ��, ����� ������.
    } // ����� sum1�� ������
    return tempsum;
}
/* stack variable reuse test */
float sum3(int n, float *list) // �Ű������� ������ �ٲٸ�, ������ ����ϴ� ��������� �ٲ�. 
// sum1, sum2������ ��������� �״�� �����Ͽ� &list�� ����������, �� ���� n�� ���� �����Ƿ�, 4����Ʈ �� ������ &list�� ����.
{
    printf("list \t= %p\n", list);
    printf("&list \t= %p\n\n", &list);

    int i;
    float tempsum = 0;

    for(i = 0; i < n; i++)
    {
        tempsum += *(list + i);
    } // sum2�� �Լ��� ����, ��� ��� ������.
    return tempsum;
}

// ���α׷� ���� : �Լ��� �Ű������μ� �迭�� �Ѱܹ޴� ���� ����� ���� ���캽. ������ ���� ������ ���� �Ǹ�, �Ű������� ������ ���� �ּҰ� ������ �޴� ���� Ȯ���� �� ����. �����Ϳ� *�� +�� ���� �迭�� �ּҿ� ���ҿ� �����ϴ� ����� Ȯ����.