#include <stdio.h>

#define MAX_ARR	101

int N;	/* �迭�� ũ�� */
int K;	/* ����� ���� */
int L;	/* ���� ��ȯ ���� */ 

int arr[MAX_ARR][MAX_ARR];
int step[MAX_ARR];
char dir[MAX_ARR];
int front;

int cnt;

typedef struct
{
	int x[MAX_ARR*MAX_ARR];
	int y[MAX_ARR*MAX_ARR];
	int dir;
	int cur_x, cur_y;
	int head;
	int rear;
}snake;

snake s;

void init(void)
{
	int x, y;
	int i, j;

	scanf("%d", &N);
	scanf("%d", &K);

	for (i = 0; i < K; i++)
	{
		scanf("%d %d", &y, &x);
		arr[y][x] = 4;	/* ��� ��ġ ǥ�� */
	}
	
	scanf("%d", &L);
	
	for (i = 0; i < L; i++)
	{
		/* step�� dir ���� */
		scanf("%d %c", &step[i], &dir[i]);
	}

	s.head = s.rear = 0;
	s.cur_x = s.cur_y = 1;
	
	/* ���� �Ӹ��� ��ǥ�� ������ �ְ�*/
	/* ���� �Ӹ����� �������� ��ǥ�� ������ �ִ´�*/
	s.x[s.head] = s.cur_x;	
	s.y[s.head] = s.cur_y;
		
	s.dir = 1;				/* 0��° ������ ����(1) */
}

void print(void)
{
	int i, j;

	printf("====================\n");
	for (i = 0; i <= N; i++)
	{
		for (j = 0; j <= N; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void print_snake(void)
{
	int i;

	printf("head : %d / rear : %d / dir : %d \n", s.head, s.rear, s.dir);

	for (i = s.head; i <= s.rear; i++)
	{
		printf("[%d] : %d %d \n", i, s.y[i], s.x[i]);
	}
}

int position_check(void)
{
	int ret;

	/* �� �Ӹ��� x or y�� ��ǥ�� ���� �ε����� ���� ���� */
	if (s.cur_y == 0 || s.cur_y == N+1 || s.cur_x == 0 || s.cur_x == N+1)
	{
		ret = 0;
//		printf("Err cur_y : %d / cur_x : %d \n",s.cur_y, s.cur_x);
	}
	else
	{
		/* �� �Ӹ��� �ڱ� ���̶� �ε������� Ž�� */
//		printf("position_ok \n");

		ret = 1;
	}

	return ret; 
}

int body_check(int y, int x)
{
	int ret = 1;
	int i;


	for (i = s.head + 1; i <= s.rear; i++)
	{
		if (y == s.y[i] && x == s.x[i])
		{
			ret = 0;
//			printf("body_err!! y : %d x : %d\n", y, x);
		}
	}

	return ret;
}


int move(void)
{
	int i;
	int head_y, head_x;
	int tail_y, tail_x;
	int temp_dir; 
	int remove_tail = 0;

	/* ���� �Ӹ��� ��ġ */
	head_y = s.y[s.head];
	head_x = s.x[s.head];

	temp_dir = s.dir;

	switch (temp_dir)	/* �� �Ӹ��� ������ */
	{
		case 0:	/* �� */
			s.cur_y--;
			break;

		case 1: /* ���� �̸� */
			s.cur_x++;		/* �Ӹ��� x��ǥ�� �����̰� */
			break;
		case 2: /* �� */
			s.cur_y++;

			break;
		case 3: /* �� */
			s.cur_x--;
			break;

		default:
			break;
	}

	if (position_check() == 0)	return 0; /* �� �Ӹ��� ��ġ�� ���̸� ����*/
	if (body_check(s.cur_y, s.cur_x) == 0)		return 0; /* �� �Ӹ��� �� ���� �ε����� ���� */

	if (arr[s.cur_y][s.cur_x] == 4) /* �Ӹ��� ������ ���� ����� ������ */
	{
		arr[s.cur_y][s.cur_x] = 0;
		s.rear++;				/* �� ���� ������ ������ �ø��� */
		for (i = s.rear; i > s.head; i--)	/* �迭�� ��Ӹ����� �������� ���� �о ���� */
		{
			s.y[i] = s.y[i - 1];
			s.x[i] = s.x[i - 1];
		}
		s.y[s.head] = s.cur_y;
		s.x[s.head] = s.cur_x;
	}
	else                     /* ����� ������ */
	{
		for (i = s.rear; i > s.head; i--)
		{
			s.y[i] = s.y[i - 1];
			s.x[i] = s.x[i - 1];
		}
		s.y[s.head] = s.cur_y;
		s.x[s.head] = s.cur_x;
	}

	return 1;

}

int change_dir(char dir, int prev_dir)
{
	int ret;

	switch (dir)
	{
		case 'L':	/* ���� */
			if (prev_dir == 0)	/* �� -> ��*/
				ret = 3;
			else if (prev_dir == 1)	/* �� -> ��*/
				ret = 0;
			else if (prev_dir == 2)	/* �� -> �� */
				ret = 1;
			else if (prev_dir == 3)	/* �� -> �� */
				ret = 2;
			else;

			break;

		case 'D':	/* ������ */
			if (prev_dir == 0)	/* �� -> ��*/
				ret = 1;
			else if (prev_dir == 1)	/* �� -> ��*/
				ret = 2;
			else if (prev_dir == 2)	/* �� -> �� */
				ret = 3;
			else if (prev_dir == 3)	/* �� -> �� */
				ret = 0;
			else;

			break;

		default:
			break;
	}

	return ret;
}

/* ��(0), ��(1), ��(2), ��(3) */
int prog(void)
{
	int cur_step;
	int prev_dir;
	int dummy;
	
	cur_step = step[front];

	while (1)
	{
//		print_snake();
//		scanf("%d", &dummy);
		
		cnt++;
		if (move() == 0) break;

		cur_step--;
//		printf("remain_step : %d \n", cur_step);
		if (cur_step == 0)
		{
			prev_dir = s.dir;
			s.dir = change_dir(dir[front],prev_dir);
			front++;
			step[front] -= cnt;
			cur_step = step[front];
//			printf("next step : %d \n", step[front]);
		}

	}

	return cnt;
}

int main(void)
{
	int time;

	init();
//	print();
	time = prog();

	printf("%d", time);

	return 0;
}