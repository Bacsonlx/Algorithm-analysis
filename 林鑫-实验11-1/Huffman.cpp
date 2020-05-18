#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define n 8           //Ҷ����Ŀ
#define m 2*n-1       //���н������
typedef struct {       //�������
	double weight;    //����Ȩֵ
	int parent, left, right;//˫��ָ�뼰���Һ���Node
}HuffMan_Node;
typedef HuffMan_Node HuffmanTree[m];//HuffmanTree����������

typedef struct {       //����SelectMin����������Ľ������
	int id;           //���������������е����
	double weight;    //���������Ȩֵ
}temp;

typedef struct {       //������
	char ch;          //�洢�ַ�
	char bits[n + 1];   //��ű���λ��
}CodeNode;
typedef CodeNode HuffmanCode[n];

void InitHuffmanTree(HuffmanTree T) {
	//��ʼ����������
	//��2n-1������������ָ�����Ϊ��(����Ϊ-1)��Ȩֵ��Ϊ0
	for (int i = 0; i < m; i++) {
		T[i].left = -1;
		T[i].right = -1;
		T[i].parent = -1;
		T[i].weight = 0;
	}
}

void InputWeight(HuffmanTree T) {
	//����Ҷ��Ȩֵ
	//����n��Ҷ�ӵ�Ȩֵ����������ǰn��������
	for (int i = 0; i < n; i++) {
		double x;
		scanf("%lf", &x);
		T[i].weight = x;
	}
}

bool cmp(temp a, temp b) {
	//��������ıȽϺ���
	return a.weight < b.weight;
}

void SelectMin(HuffmanTree T, int k, int *p1, int *p2) {
	//��ǰk�������ѡ��Ȩֵ��С�ʹ�С�ĸ���㣬����ŷֱ�Ϊp1��p2
	temp x[m];              //x����Ϊtemp���͵�����
	int i, j;
	for (i = 0, j = 0; i <= k; i++) {  //Ѱ����С�ʹ�С���ڵ�Ĺ���
		if (T[i].parent == -1) {//����Ǹ��ڵ�,��������²���
			x[j].id = i;      //���ø��ڵ����Ÿ�ֵ��x
			x[j].weight = T[i].weight;//���ø��ڵ��Ȩֵ��ֵ��x
			j++;            //x������ָ�����һλ
		}
	}
	sort(x, x + j, cmp);        //��x����Ȩֵ��С��������
	//������x�����ĵ�һ�͵ڶ���λ���д洢��id�����ҵĸ��ڵ�����ֵ
	*p1 = x[0].id;
	*p2 = x[1].id;
}

void CreateHuffmanTree(HuffmanTree T) {
	//�������������T[m-1]Ϊ������
	int i, p1, p2;
	InitHuffmanTree(T);    //��T��ʼ��
	InputWeight(T);        //����Ҷ��Ȩֵ
	for (i = n; i < m; i++) {
		//�ڵ�ǰɭ��T[0����i-1]�����н���У�ѡȡȨ��С�ʹ�С��
		//���������T[p1]��T[p2]��Ϊ�ϲ�����
		//������n-1�κϲ����½�����δ���T[i]��

		SelectMin(T, i - 1, &p1, &p2);//ѡ��Ȩֵ��С�ʹ�С�ĸ���㣬����ŷֱ�Ϊp1��p2

		//����ΪT[p1]��T[p2]����������Ϊ���������ϲ�Ϊһ���µ���
		//�����ĸ����½��T[i]
		T[p1].parent = T[p2].parent = i;//T[p1]��T[p2]���������ĸ����ָ��i
		T[i].left = p1;             //��СȨ�ĸ�������½�������
		T[i].right = p2;             //��СȨ�ĸ�������½����Һ���
		T[i].weight = T[p1].weight + T[p2].weight;//�½���Ȩֵ������������Ȩֵ֮��
	}
}

void CharSetHuffmanEncoding(HuffmanTree T, HuffmanCode H) {
	//���ݹ�������T������������H
	int c, p;//c��p�ֱ�ָʾT�к��Ӻ�˫�׵�λ��
	char cd[n + 1];//��ʱ��ű���
	int start;//ָʾ������cd�е���ʼλ��
	cd[n] = '\0';//���������
	getchar();
	for (int i = 0; i < n; i++) {//������Ҷ��T[i]�ı���
		H[i].ch = getchar();//����Ҷ��T[i]��Ӧ���ַ�
		start = n;//������ʼλ�õĳ�ֵ
		c = i;//��Ҷ��T[i]��ʼ����
		while ((p = T[c].parent) >= 0) {//ֱ�����ݵ�T[c]������Ϊֹ
			//��T[c]��T[p]�����ӣ������ɴ���0���������ɴ���1
			if (T[p].left == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
			c = p;//��������
		}
		strcpy(H[i].bits, &cd[start]);//���Ʊ���λ��
	}
}

//*************************���Ժ���**********************************
int main() {
	HuffmanTree T;
	HuffmanCode H;
	printf("������%d��Ҷ�ӽ���Ȩֵ����������������\n", n);
	CreateHuffmanTree(T);
	printf("������%d��Ҷ�ӽ����������ַ���\n", n);
	CharSetHuffmanEncoding(T, H);
	/*printf("���������Ѿ����ã������������Ѿ���ɣ�������£�\n");
	printf("����������\n");
	for (int i = 0; i < m; i++) {
		printf("id:%d  weight:%.1lf   parent:%d", i, T[i].weight, T[i].parent);
		printf("  left:%d right:%d\n", T[i].left, T[i].right);
	}*/
	printf("���������룺\n");
	double wpl = 0.0;
	for (int i = 0; i < n; i++) {
		printf("id:%d   ch:%c  code:%s\n", i, H[i].ch, H[i].bits);
		wpl += strlen(H[i].bits)*T[i].weight;
	}
	printf("ƽ���볤Ϊ��%.2lf\n", wpl);
	return 0;
}
