#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,t) ( (t) = (x), (x) = (y), (y) = (t))
#pragma warning(disable:4996)

//�Լ�����
void copy(int* A, int* B, int n) {
    for (int i = 0; i < n; i++)
        B[i] = A[i];
}

void is_sorted(int* B, int n) {
    int isTrue = 1;
    for (int i = 0; i < n - 1; i++) {
        if (B[i] > B[i + 1]) {
            printf("���Ŀ���\n");
            isTrue = 0;
            break;
        }
    }
    if (isTrue == 1)
        printf("���ļ���\n");
}

void selection_sort(int* B, int n) {
    clock_t before = clock();
    int min, temp;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i; j < n; j++) 
            if (B[min] > B[j])
                min = j;
            SWAP(B[i], B[min], temp);
    }
    clock_t after = clock();
    printf("selection sort: %f\n", (double)(after - before) / CLOCKS_PER_SEC);
}

void insertion_sort(int* B, int n) {
    clock_t before = clock();
    int i, j;
    int next;
    for (i = 1; i < n; i++) {
        next = B[i];
        for (j = i - 1; j >= 0 && next < B[j]; j--)
            B[j + 1] = B[j];
        B[j + 1] = next;
    }
    clock_t after = clock();
    printf("insertion sort: %f\n", (double)(after - before) / CLOCKS_PER_SEC);
}

void quick_sort(int* B, int left, int right) {
    int pivot, i, j;
    int temp;
    if (left < right) {
        i = left; j = right + 1;
        pivot = B[left];
        do {
            do
                i++;
            while (B[i] < pivot);
            do
                j--;
            while (B[j] > pivot);
            if (i < j)
                SWAP(B[i], B[j], temp);
        } while (i < j);
        SWAP(B[left], B[j], temp);
        quick_sort(B, left, j - 1);
        quick_sort(B, j + 1, right);
    }
}

//main �Լ�
void main() {
    //12.1
    printf("12.1 ���� ���� �������� ����\n");
    int n, * A; //���� ��, ������ ���� �迭
    int* B; //������ ���纻 �迭
    while (1) {
        A = NULL;
        B = NULL;
        printf("���� ��: ");
        scanf("%d", &n);
        if (n < 0)
            break;
        A = (int*)malloc(sizeof(int) * n);
        B = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            A[i] = (rand() / (0x7fff * 1.0)) * 100000000;
            B[i] = A[i];
        }
        //���� ����
        selection_sort(B, n);
        is_sorted(B, n);
        copy(A, B, n);

        insertion_sort(B, n);
        is_sorted(B, n);
        copy(A, B, n);

        clock_t before = clock();
        quick_sort(B, 0, n-1);
        clock_t after = clock();
        printf("quick sort: %f\n", (double)(after - before) / CLOCKS_PER_SEC);
        is_sorted(B, n);

        free(A);
        free(B);
        printf("\n");
    }

    //12.2
    printf("\n12.2\n");
    printf("�������� ���ĵ� �������� ����\n");
    while (1) {
        A = NULL;
        B = NULL;
        printf("���� ��: ");
        scanf("%d", &n);
        if (n < 0)
            break;
        A = (int*)malloc(sizeof(int) * n);
        B = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            A[i] = i;
            B[i] = A[i];
        }
        //���� ����
        selection_sort(B, n);
        is_sorted(B, n);
        copy(A, B, n);

        insertion_sort(B, n);
        is_sorted(B, n);
        copy(A, B, n);

        /*�������� quick sort(error�� ���� �ּ�ó��)
        clock_t before = clock();
        quick_sort(B, 0, n - 1);
        clock_t after = clock();
        printf("quick sort: %f\n", (double)(after - before) / CLOCKS_PER_SEC);
        is_sorted(B, n);*/

        free(A);
        free(B);
        printf("\n");
    }

    printf("\n�������� ���ĵ� �������� ����\n");
    while (1) {
        A = NULL;
        B = NULL;
        printf("���� ��: ");
        scanf("%d", &n);
        if (n < 0)
            break;
        A = (int*)malloc(sizeof(int) * n);
        B = (int*)malloc(sizeof(int) * n);
        for (int i = n - 1, index = 0; i >= 0; i--) {
            A[index] = i;
            B[index] = A[i];
            index++;
        }
        //���� ����
        selection_sort(B, n);
        is_sorted(B, n);
        copy(A, B, n);

        insertion_sort(B, n);
        is_sorted(B, n);
        copy(A, B, n);

        /*�������� quick sort(error�� ���� �ּ�ó��)
        clock_t before = clock();
        quick_sort(B, 0, n - 1);
        clock_t after = clock();
        printf("quick sort: %f\n", (double)(after - before) / CLOCKS_PER_SEC);
        is_sorted(B, n);
        */

        free(A);
        free(B);
        printf("\n");
    }
}