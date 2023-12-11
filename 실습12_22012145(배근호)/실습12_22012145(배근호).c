#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SWAP(x,y,t) ( (t) = (x), (x) = (y), (y) = (t))
#pragma warning(disable:4996)

//함수구현
void copy(int* A, int* B, int n) {
    for (int i = 0; i < n; i++)
        B[i] = A[i];
}

void is_sorted(int* B, int n) {
    int isTrue = 1;
    for (int i = 0; i < n - 1; i++) {
        if (B[i] > B[i + 1]) {
            printf("정렬오류\n");
            isTrue = 0;
            break;
        }
    }
    if (isTrue == 1)
        printf("정렬성공\n");
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

//main 함수
void main() {
    //12.1
    printf("12.1 랜덤 생성 데이터의 정렬\n");
    int n, * A; //원소 수, 데이터 원본 배열
    int* B; //데이터 복사본 배열
    while (1) {
        A = NULL;
        B = NULL;
        printf("원소 수: ");
        scanf("%d", &n);
        if (n < 0)
            break;
        A = (int*)malloc(sizeof(int) * n);
        B = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            A[i] = (rand() / (0x7fff * 1.0)) * 100000000;
            B[i] = A[i];
        }
        //정렬 시작
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
    printf("오름차순 정렬된 데이터의 정렬\n");
    while (1) {
        A = NULL;
        B = NULL;
        printf("원소 수: ");
        scanf("%d", &n);
        if (n < 0)
            break;
        A = (int*)malloc(sizeof(int) * n);
        B = (int*)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            A[i] = i;
            B[i] = A[i];
        }
        //정렬 시작
        selection_sort(B, n);
        is_sorted(B, n);
        copy(A, B, n);

        insertion_sort(B, n);
        is_sorted(B, n);
        copy(A, B, n);

        /*오름차순 quick sort(error로 인한 주석처리)
        clock_t before = clock();
        quick_sort(B, 0, n - 1);
        clock_t after = clock();
        printf("quick sort: %f\n", (double)(after - before) / CLOCKS_PER_SEC);
        is_sorted(B, n);*/

        free(A);
        free(B);
        printf("\n");
    }

    printf("\n내림차순 정렬된 데이터의 정렬\n");
    while (1) {
        A = NULL;
        B = NULL;
        printf("원소 수: ");
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
        //정렬 시작
        selection_sort(B, n);
        is_sorted(B, n);
        copy(A, B, n);

        insertion_sort(B, n);
        is_sorted(B, n);
        copy(A, B, n);

        /*내림차순 quick sort(error로 인한 주석처리)
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