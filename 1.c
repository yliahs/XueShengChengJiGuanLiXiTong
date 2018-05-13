#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define m 30
#define n 10
#define s 6
void input(int *id, int score[m][s], int *tscore, int *tscores, char name[m][n],  int *people, int *subject)
{
	int i,j;
	printf("Input how number people\n");
	scanf("%d", &people);
	printf("Input how number subject\n");
	scanf("%d", &subject);
	for (i = 0; i <= *people - 1; i++)
	{
		printf("Input your number and name\n");
		scanf("%d%s", &id[i], &name[i]);
		printf("Input your score record\n");
		for (j = 0; j <= *subject - 1; j++)
			scanf("%d", &score[i][j]);
	}
	for (i = 0; i <= *people - 1; i++)
	{
		for (j = 0; j <= *subject - 1; j++)
			tscore[i] = tscore[i] + score[i][j];
	}
	printf("\n");
}
void copy(int *id, int *ids, int score[m][s], int scores[m][s], int *tscore, int *tscores, char name[m][n], char names[m][n], int *people, int *subject)
{
	int i, j;
	for (i = 0; i <= *people - 1; i++)
	{
		for (j = 0; j <= *subject - 1; j++)
			scores[i][j] = score[i][j];
		ids[i] = id[i];
		tscores[i] = tscore[i];
		strcpy(names[i], name[i]);
	}
}
void calscore(int score[m][s], int *people, int *subject)
{
	int i, j, total = 0;
	for (j = 0; j <= *subject - 1; j++)
	{
		for (i = 0; i <= *people - 1; i++)
			total = total + score[i][j];
		printf("%d subject total score:%d average score:%.2f\n", j + 1, total, (float)total / *people);
		total = 0;
	}
}
void calstu(int score[m][s], int *people, int *subject)
{
	int i, j, total = 0;
	for (i = 0; i <= *people - 1; i++)
	{
		for (j = 0; j <= *subject - 1; j++)
			total = total + score[i][j];
		printf("student %d total score:%d average score:%.2f\n", i + 1, total, (float)total / *subject);
		total = 0;
	}
}
void sortscoreup(int *score, int *people)
{
	int a, i, j, temp;
	printf("score up rank:\n");
	for (j = 0; j <= *people - 1; j++)
		for (i = 0; i<*people - 1 - j; i++)
			if (score[i]>score[i + 1])
			{
				temp = score[i];
				score[i] = score[i + 1];
				score[i + 1] = temp;
			}
	for (a = 0; a <= *people - 1; a++)
		printf("%d\n", score[a]);
}
void sortscoredown(int *score, int *people)
{
	int a, i, j, temp;
	printf("score down rank:\n");
	for (j = 0; j <= *people - 1; j++)
		for (i = 0; i<*people - 1 - j; i++)
			if (score[i]<score[i + 1])
			{
				temp = score[i];
				score[i] = score[i + 1];
				score[i + 1] = temp;
			}
	for (a = 0; a <= *people - 1; a++)
		printf("%d\n", score[a]);
}
void sortdy(int *id, int *score, int *people, char name[m][n])
{
	int a, i, j;
	char temp[m];
	printf("according to the order of the dictionary:\n");
	for (j = 0; j <= *people - 1; j++)
		for (i = 0; i<*people - 1 - j; i++)
			if (strcmp(name[i], name[i + 1])>0)
			{
				strcpy(temp, name[i]);
				strcpy(name[i], name[i + 1]);
				strcpy(name[i + 1], temp);
			}
	for (a = 0; a <= *people - 1; a++)
		printf("name:%s total score:%d\n", name[a], score[a]);
}
void sortid(int *id, int *score, int *people)
{
	int a, i, j, temp1, temp2;
	for (j = 0; j <= *people - 1; j++)
		for (i = 0; i<*people - 1 - j; i++)
			if (id[i]>id[i + 1])
			{
				temp1 = id[i];
				id[i] = id[i + 1];
				id[i + 1] = temp1;
				temp2 = score[i];
				score[i] = score[i + 1];
				score[i + 1] = temp2;
			}
	printf("sort id and score:\n");
	for (a = 0; a <= *people - 1; a++)
		printf("%d\n", score[a]);
}
void idsearch(int *id, int *score, int *people, int scores[m][s], int *subject)
{
	int a, b, c, i, j, k, temp1, temp2;
	printf("please input your id:\n");
	scanf("%d", &a);
	for (b = 0; b <= *people - 1; b++)
	{
		if (id[b] == a)
		{
			c = b;
		}
	}
	for (j = 0; j <= *people - 1; j++)
		for (i = 0; i<*people - 1 - j; i++)
			if (score[i]<score[i + 1])
			{
				temp1 = id[i];
				id[i] = id[i + 1];
				id[i + 1] = temp1;
				temp2 = score[i];
				score[i] = score[i + 1];
				score[i + 1] = temp2;
			}
	for (b = 0; b <= *people - 1; b++)
	{
		if (id[b] == a)
			printf("rank:%d score: ", b + 1);
	}
	for (k = 0; k <= *subject - 1; k++)
		printf("%d ", scores[c][k]);
}
void namesearch(int *id, int *score, int *people, char name[m][n], int scores[m][s], int *subject)
{
	char a[m];
	int b, c, d, i, j, k, temp1, temp2;
	printf("please input your name:\n");
	scanf("%s", &a);
	for (b = 0; b <= *people - 1; b++)
	{
		if (strcmp(a, name[b]) == 0)
		{
			c = id[b];
			d = b;
		}
	}
	for (j = 0; j <= *people - 1; j++)
		for (i = 0; i<*people - 1 - j; i++)
			if (score[i]<score[i + 1])
			{
				temp1 = id[i];
				id[i] = id[i + 1];
				id[i + 1] = temp1;
				temp2 = score[i];
				score[i] = score[i + 1];
				score[i + 1] = temp2;
			}
	for (b = 0; b <= *people - 1; b++)
	{
		if (id[b] == c)
			printf("rank:%d score: ", b + 1);
	}
	for (k = 0; k <= *subject - 1; k++)
		printf("%d ", scores[d][k]);
}
void statistic(int *id, int score[m][s], int *people, int *subject)
{
	int g1 = 0, g2 = 0, g3 = 0, g4 = 0, g5 = 0;
	int a, b;
	for (a = 0; a <= *subject - 1; a++)
	{
		for (b = 0; b <= *people - 1; b++)
		{
			if (score[b][a] >= 90 && score[b][a] <= 100)
				g1++;
			else if (score[b][a] >= 80 && score[b][a] <= 89)
				g2++;
			else if (score[b][a] >= 70 && score[b][a] <= 79)
				g3++;
			else if (score[b][a] >= 60 && score[b][a] <= 69)
				g4++;
			else if (score[b][a] >= 0 && score[b][a] <= 59)
				g5++;
		}
		printf("subject %d:\n", a + 1);
		printf("excellent number:%d percentage:%.2f%%\n", g1, ((float)g1 / *people) * 100);
		printf("well number:%d percentage:%.2f%%\n", g2, ((float)g2 / *people) * 100);
		printf("medium number:%d percentage:%.2f%%\n", g3, ((float)g3 / *people) * 100);
		printf("pass number:%d percentage:%.2f%%\n", g4, ((float)g4 / *people) * 100);
		printf("fail number:%d percentage:%.2f%%\n", g5, ((float)g5 / *people) * 100);
		printf("\n");
		g1 = g2 = g3 = g4 = g5 = 0;
	}
}
void list(int *id, int score[m][s], int *people, char name[m][n], int *subject)
{
	int i, j, total = 0;
	for (i = 0; i <= *people - 1; i++)
	{
		printf("id:%d name:%s\n", id[i], name[i]);
		for (j = 0; j <= *subject - 1; j++)
		{
			printf("%d ", score[i][j]);
			total = total + score[i][j];
		}
		printf("\n");
		printf("total score:%d average score:%.2f\n", total, (float)total / *subject);
		total = 0;
	}
}
main()
{
	int id[m], ids[m], score[m][s], scores[m][s], tscore[m] = { 0 }, tscores[m] = { 0 };
	char name[m][n], names[m][n];
	int people, subject, choice;
	printf("Student score manage program\n");
	printf("Powered by Hehong Wu   Version:4.0\n");
	for (;;)
	{
		printf("1.Input record\n");
		printf("2.Caculate totel and average score of every course\n");
		printf("3.Caculate totel and average score of every student\n");
		printf("4.Sort in descending order by total score of every student\n");
		printf("5.Sort in ascending order by total score of every student\n");
		printf("6.Sort in ascending order by number\n");
		printf("7.Sort in dictionory order by name\n");
		printf("8.Search by number\n");
		printf("9.Search by name\n");
		printf("10.Statistic analysis\n");
		printf("11.List record\n");
		printf("0.Exit\n");
		printf("Please enter your choice:\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			input(&id, score, &tscore, &tscores, name, &people, &subject);
			break;
		case 2:
			copy(&id, &ids, score, scores, &tscore, &tscores, name, names, &people, &subject);
			calscore(scores, &people, &subject);
			printf("\n");
			break;
		case 3:
			copy(&id, &ids, score, scores, &tscore, &tscores, name, names, &people, &subject);
			calstu(scores, &people, &subject);
			printf("\n");
			break;
		case 4:
			copy(&id, &ids, score, scores, &tscore, &tscores, name, names, &people, &subject);
			sortscoredown(&tscores, &people);
			printf("\n");
			break;
		case 5:
			copy(&id, &ids, score, scores, &tscore, &tscores, name, names, &people, &subject);
			sortscoreup(&tscores, &people);
			printf("\n");
			break;
		case 6:
			copy(&id, &ids, score, scores, &tscore, &tscores, name, names, &people, &subject);
			sortid(&ids, &tscores, &people);
			printf("\n");
			break;
		case 7:
			copy(&id, &ids, score, scores, &tscore, &tscores, name, names, &people, &subject);
			sortdy(&ids, &tscores, &people, names);
			printf("\n");
			break;
		case 8:
			copy(&id, &ids, score, scores, &tscore, &tscores, name, names, &people, &subject);
			idsearch(&ids, &tscores, &people, scores, &subject);
			printf("\n");
			break;
		case 9:
			copy(&id, &ids, score, scores, &tscore, &tscores, name, names, &people, &subject);
			namesearch(&ids, &tscores, &people, names, scores, &subject);
			printf("\n");
			break;
		case 10:
			copy(&id, &ids, score, scores, &tscore, &tscores, name, names, &people, &subject);
			statistic(&ids, scores, &people, &subject);
			printf("\n");
			break;
		case 11:
			copy(&id, &ids, score, scores, &tscore, &tscores, name, names, &people, &subject);
			list(&ids, scores, &people, names, &subject);
			calscore(scores, &people, &subject);
			printf("\n");
			break;
		case 0:
			exit(0);
			break;
		}
	}
}