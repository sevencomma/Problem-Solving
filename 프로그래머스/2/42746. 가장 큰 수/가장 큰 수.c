#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const char* a, const char* b) {
    char ab[20], ba[20];
    sprintf(ab, "%s%s", *(char**)a, *(char**)b);
    sprintf(ba, "%s%s", *(char**)b, *(char**)a);
    return strcmp(ba, ab);
}
//두 문자열을 합쳐서 비교함 -> 합쳤을 때 어떤 수가 더 큰 수인지 비교   
//각 문자열은 비교 하기 힘듬

void MergeTwoArea(char* arr[], int left, int mid, int right) {
    int fIdx = left;
    int rIdx = mid + 1;
    int i;

    char** sortArr = (char**)malloc(sizeof(char*) * (right - left + 1));
    if (sortArr == NULL) {
        printf("동적할당 실패");
        exit(1);
    }

    int sIdx = 0;
    while (fIdx <= mid && rIdx <= right) {
        if (compare(&arr[fIdx], &arr[rIdx]) >= 0) { // compare 함수 사용하여 정렬 순서 결정
            /// 0 큰 수가 나왔을 경우 뒷수가 더 크기 때문에 배열 앞부분에 작은 수를 먼저 정렬한다.
            sortArr[sIdx++] = arr[fIdx++];
        }
        else {
            sortArr[sIdx++] = arr[rIdx++];
        }
    }

    while (fIdx <= mid) {
        sortArr[sIdx++] = arr[fIdx++];
    }

    while (rIdx <= right) {
        sortArr[sIdx++] = arr[rIdx++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = sortArr[i - left];
    }

    free(sortArr);
}

void MergeSort(char* arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        MergeTwoArea(arr, left, mid, right);
    }
}

char* solution(int numbers[], size_t numbers_len) {
    // 필요한 총 길이를 계산 (각 숫자가 최대 4자리, 추가로 '\0'을 위한 1자리)
    size_t total_length = numbers_len * 4 + 1;
    char* answer = (char*)malloc(total_length);
    if (answer == NULL) {
        printf("동적할당 실패");
        exit(1);
    }
    answer[0] = '\0'; // 빈 문자열로 초기화

    char** stringArray = (char**)malloc(numbers_len * sizeof(char*));
    if (stringArray == NULL) {
        printf("동적할당 실패");
        exit(1);
    }

    for (int i = 0; i < numbers_len; i++) {
        stringArray[i] = (char*)malloc(5 * sizeof(char)); // 각 문자열을 위한 메모리 할당 (최대 4자리 + '\0')
        if (stringArray[i] == NULL) {
            printf("동적할당 실패");
            exit(1);
        }
        snprintf(stringArray[i], 5, "%d", numbers[i]); // 숫자를 문자열로 변환
    }

    // 병합 정렬 사용
    MergeSort(stringArray, 0, numbers_len - 1);

    // 뒤에서부터 문자열을 합치면서 메모리 해제 
    for (int i = numbers_len - 1; i >= 0; i--) {
        strcat(answer, stringArray[i]);
        free(stringArray[i]); 
    }
    free(stringArray); // 배열 메모리 해제
    if (answer[0] == '0') // 맨 앞에 숫자가 0인 경우 뒤에 숫자도 모두 0이기 때문에 예외 처리 시켜준다.
    {
        strcpy(answer, "0");

    }

    return answer;
}

int main() {
    int numbers[] = { 0, 0, 0 };
    size_t numbers_len = sizeof(numbers) / sizeof(numbers[0]);

    char* result = solution(numbers, numbers_len);
    if (result != NULL) {
        printf("%s\n", result);
        free(result);
    }

    return 0;
}