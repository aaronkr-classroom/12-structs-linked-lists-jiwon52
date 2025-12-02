//linked.c (slide 62)
#include<stdio.h>
#include<malloc.h>

typedef struct {
	int number;
	struct Node* p_next; // 다음 노드를 가리킬 포인터
} Node;

void AddNumber(Node **pp_head, Node **pp_tail, int data) {
	if (NULL != *pp_head) { //이미 노드가 있으면
		(*pp_tail)->p_next = (Node*)malloc(sizeof(Node));
		*pp_tail = (*pp_tail)->p_next; // 새 노드의 주소
	}
	else { //노드 데이터가 없다..!
		// *p_head 값이 NULL이라서 첫 노드가 추가함
		*pp_head = (Node*)malloc(sizeof(Node));
		*pp_tail = *pp_head;
	}
	(*pp_tail)->number = data; // 숫자 저장함
	(*pp_tail)->p_next = NULL; // 마지막 노드이어서
}

int main(void) {
	Node* p_head = NULL, * p_tail = NULL, * p;
	int sum = 0, temp;

	// ========= #1.숫자 입력 ===========
	//무한루프:중간에 9999를 누르면 종료
	while (1) {
		printf("숫자를 입력하세요 (9999를 누르면 종료):");
		scanf_s("%d", &temp);

		if (9999 == temp) break;

		//노드의 시작과 끝을 기억하는 포인터의 주소 값과 입력된 숫자를 전달
		AddNumber(&p_head, &p_tail, temp);
	}

	// ========= #2. 모든 입력 받은 숫자의 합 =========
	// 입력된 숫자를 출력하기 위해서 노드를 탐색할 포인터에 시작 노드의 주소 값을 대입합니다.
	p = p_head;
	while(NULL != p); {
		if (p != p_head) {
			printf(" + "); //숫자와 숫자 사이에 + 출력
		}
		printf("%d", p->number);

		sum = sum + p->number;
		p = p->p_next; //다음 노드로 이동
	}
	printf(" =%d\n", sum);

	// ========= #3. 메모리 해제 ============
	while (NULL != p_head) {
		p = p_head; //현재 노드를 삭제하기 위해 p변수에 노드 주소 값을 저장
		p_head = p_head->p_next; //시작 위치를 다음 노드로 이동
		free(p); //기억했던 주소를 사용하여 노드 삭제함
	}
	p_tail = p_tail; //반복문을 나오면 p_head값은 NULL. p_tail도 NULL로 변경.

	return 0;
}