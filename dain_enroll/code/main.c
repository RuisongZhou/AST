#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <io.h>


#define GR_H 32
#define GR_W 32  //默认的训练集和测试集的宽和高

#define VECTOR_H 2
#define VECTOR_W 2  //一块取特征值的区域的宽和高

typedef struct {
	int w, h;
	int a[GR_H][GR_W]; //原图分割成w*h的
} graph;

typedef struct {
	float v;
	int id;
} nd;

int Maxn;
graph train_data[10][2000];
nd dis[20000];
char tmp_init_s[GR_H][GR_W + 1];
int sum_of[10];     //代表每个数字
int right_ans_cnt;
int total_cnt;


void read_a_single_file(char *f_path, graph *g);
int min(int a, int b);
int min(int a, int b);
float cal_distance(graph *a, graph *b);
int read_file_list(char *path);
int MakeAnswer(graph *g);
void work(char *path);
void read_a_single_file(char *f_path, graph *g);
void init();
int cmp(const void *c, const void *d);


int min(int a, int b)
{
	return a < b ? a : b;
}


int cmp(const void *c, const void *d)
{
	nd *a, *b;
	a = (nd*)c; b = (nd*)d;
	return a->v - b->v;
}


float cal_distance(graph *a, graph *b)   //计算欧氏距离
{
	int sum = 0, r, c, t;
	for (r = 0; r < a->h; r++)
		for (c = 0; c < a->w; c++) {
			t = a->a[r][c] - b->a[r][c];
			sum += t * t;
		}
	return sqrt(sum);
}


int MakeAnswer(graph *g) //识别结果
{
	int i, j;
	int SumCount[10];
	int t1 = 0, t2 = 0;
	int p = 0;
	for (i = 0; i <= 9; i ++)
    {
		for (j = 0; j < sum_of[i]; j ++)
		{
			float temp = cal_distance(g, &train_data[i][j]);
			dis[p].id = i;
			dis[p].v = temp;
			p++;
		}
	}
	qsort(dis, p, sizeof(nd), cmp);
	memset(SumCount, 0, sizeof(SumCount));
	for (i = 0; i <= min(30,Maxn) ; i ++)
		SumCount[dis[i].id] ++;
	for (i = 0; i <= 9; i ++)
	{
		if (t2 < SumCount[i])
		{
			t1 = i;
			t2 = SumCount[i];
		}
	}
	printf("%d\n", t1);
	return t1;

}


int read_file_list(char *path)  //处理训练数据
{
	long Handle;
	int i = 0;
	char Spath[100];
	char *p = path + strlen(path) - 1 ,*q;
	if ((*p) != '\\') {
		strcat(p, "\\");
	}
	strcpy(Spath, path);
    q = Spath + strlen(Spath) - 1;
	strcat(p, "*.*");
	struct _finddata_t FileInfo;
	if ((Handle = _findfirst(path, &FileInfo)) == -1L)
		printf("ERROR\n");
	else
	{
		i++;
		int Num = FileInfo.name[0] - '0';
		*(q + 1) = '\0';
		strcat(q, FileInfo.name);
		if ( strcmp(FileInfo.name,".")!=0 && strcmp(FileInfo.name,"..") != 0 )
        {
			printf("%s\n", FileInfo.name);
			read_a_single_file(Spath, &train_data[Num][sum_of[Num] ++]);
		}
		while ( _findnext( Handle , &FileInfo ) == 0 )
		{
			*(q + 1) = '\0';
            strcat(q, FileInfo.name);
			if ( strcmp(FileInfo.name,".")==0 || strcmp(FileInfo.name,"..")==0 )
			   continue;
			printf("%s\n", FileInfo.name);
			Num = FileInfo.name[0] - '0';
			read_a_single_file(Spath, &train_data[Num][sum_of[Num] ++]);
			i++;
		}
		_findclose(Handle);
	}
	return i;
}


void work(char *path) //处理测试数据
{
	long Handle;
	//int i = 0;
	char Spath[100];
	char *p = path + strlen(path) - 1, *q;
	if ((*p) != '\\') {
		strcat(p, "\\");
	}
	strcpy(Spath, path);
    q = Spath + strlen(Spath) - 1;
	strcat(p, "*.*");
	struct _finddata_t FileInfo;
	if ((Handle = _findfirst(path, &FileInfo)) == -1L)
		printf("ERROR\n");
	else
	{
		graph Ques;
		//i++;
		*(q + 1) = '\0';
		strcat(q, FileInfo.name);
		if (strcmp(FileInfo.name,".")!=0 && strcmp(FileInfo.name,"..")!=0)
        {
			printf("%s\n", FileInfo.name);
			read_a_single_file(Spath, &Ques);
			total_cnt++;
			if ( MakeAnswer(&Ques)+ '0' == FileInfo.name[0])
                right_ans_cnt++;
		}
		while (_findnext(Handle, &FileInfo) == 0)
		{
			*(q + 1) = '\0';
            strcat(q, FileInfo.name);
			if (strcmp(FileInfo.name,".")==0 || strcmp(FileInfo.name,"..")==0)
			   continue;
			printf("%s\n", FileInfo.name);
			read_a_single_file(Spath, &Ques);
			total_cnt++;
			if ( MakeAnswer(&Ques)+ '0' == FileInfo.name[0])
                right_ans_cnt++;
			//i++;
		}
		_findclose(Handle);
	}

}


void read_a_single_file(char *f_path, graph *g)     //处理并保存数据
{
	FILE *f;
	int w, h, i, j, r, c, *p;
	f = fopen(f_path, "r");
	if (f == NULL)
        {
            printf("%s can not read,maybe %s is not exist\n", f_path, f_path);
            exit(0);
        }
	h = 0;
	while (fscanf(f, "%s", tmp_init_s[h++]) == 1); //读入每行数据
	w = strlen(tmp_init_s[0]);  //每行长度
	g->w = w / VECTOR_W;    //W是宽度
	g->h = h / VECTOR_H;    //h是高度
	for ( i = 0; i < h ; i += VECTOR_H )
		for ( j = 0; j < w; j += VECTOR_W )
        {
			p = &g->a[i / VECTOR_H][j / VECTOR_W];
			*p = 0;
			for (r = i; r < i + VECTOR_H; r++)
				for (c = j; c < j + VECTOR_W; c++)
					*p += tmp_init_s[r][c] - '0';
		}

	fclose(f);
}


void init()
{
	int i;
	for (i = 0; i <= 9; i ++)
		sum_of[i] = 0;
}


int main()
{
	total_cnt=0;
	right_ans_cnt=0;
	init();
	char Path_of_train[100];
	char Path_of_test[100];
	scanf("%s", Path_of_train);
	Maxn = read_file_list(Path_of_train);//Maxn is the num of trainData
	printf("%d data have been collected.\n",Maxn);
	printf("\n\nPlease enter the testDigits lujing\n");
	scanf("%s", Path_of_test);
	work(Path_of_test);
	float a1 = right_ans_cnt;
	float a2 = total_cnt;
	printf("%d right\n%d total\n",right_ans_cnt,total_cnt);
	printf("Accuracy : %.2f",a1/a2);
	return 0;
}
