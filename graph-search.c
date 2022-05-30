#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 10
#define TRUE 1
#define FALSE 0
short int visited[MAX_VERTEX];

typedef struct graphNode{
int vertex;//������ ��Ÿ���� ������ 
struct graphNode*link;//���� ������ �����ϴ� ��ũ

}graphNode;

typedef struct graphType{
int n;//�׷����� ������ ����
graphNode*adjlist[MAX_VERTEX];//������ ���� ��� ���
}graphType;
 

graphNode* queue[MAX_VERTEX];
int front = -1;
int rear = -1;

graphNode* deQueue();
void enQueue(graphNode* aNode);


void InitializeGraph(graphType*g);
void InsertVertex(graphType*g,int v);
int InsertEdge(graphType*g,int u,int v);
void print(graphType*g);
void dfs(graphType*g,int v);
void bfs(graphType*g,int v);
void freegraph(graphType*g,int v);
int main()
{
   char command;
   graphType*g;
   g=(graphType*)malloc(sizeof(graphType));
     int x;
     int v;
    int u;
    int depth;
    int num;

   do{
      printf("\n");
      printf("[----- [���°�] [2019038059] -----]\n");
      printf("\n\n");
      printf("----------------------------------------------------------------\n");
      printf("                   graph                        \n");
      printf("----------------------------------------------------------------\n");
      printf(" Initialize Graph     = z                                       \n");
      printf(" Insert Vertex        = v      Insert Edge                  = e \n");
      printf(" Depth First Search   = d      Breath First Search          = b \n");
      printf(" print Graph          = p      Quit                         = q \n");
      printf("----------------------------------------------------------------\n");

      printf("Command = ");
      scanf(" %c", &command);

      switch(command) {
      case 'z': case 'Z':
         InitializeGraph(g);
         break;
      case 'v': case 'V':
        
         printf("������ ������ ���� �Է�");
         scanf("%d",&x);
         for(int i=0;i<x;i++){
         InsertVertex(g,x);
         } 
         break;
      case 'e': case 'E':
         printf("����u�� �Է��Ͻÿ�");
         scanf("%d",&u);
          printf("  ����u�� ������ v�� �Է��Ͻÿ�");
         scanf("%d",&v);
         InsertEdge(g,u,v); 
         break;
   
      case 'p': case 'P':
          print(g);
         break;

      case 'd': case 'D':
     printf("Ž���� ������ ������ �Է��Ͻÿ�");
           scanf("%d",&depth);
          dfs(g,depth);
          for(int i=0;i<MAX_VERTEX;i++)
            {
                visited[i] = 0;
            }
         break;
      case 'b': case 'B':
          printf("Ž���� ������ ������ �Է��Ͻÿ�");
           scanf("%d",&num);
          bfs(g,num);
          for(int i=0;i<MAX_VERTEX;i++)
            {
                visited[i] = 0;
            }
         int rear=-1;
         int front=-1;
         break;   

      default:
         printf("\n       >>>>>   Concentration!!   <<<<<     \n");
         break;
      }

   }while(command != 'q' && command != 'Q');
    freegraph(g,x);
   return 1;
}

void InitializeGraph(graphType*g){
   g->n=0;
   for(int x=0;x<MAX_VERTEX;x++){//�Է¹��� ������ŭ �޺�
      g->adjlist[x]=NULL;//�׷����� �������带 �ʱ�ȭ
   }

}
void InsertVertex(graphType*g,int v){
      if(((g->n)+1)>MAX_VERTEX){//������ ������ 10���� ũ�ٸ� ���� ����

         printf("�׷��� �ִ� ���� ���� �ʰ� \n");
         return;
      }
      g->n++;//������ �ϳ� ������Ŵ
}

int InsertEdge(graphType*g,int u,int v){
graphNode*node;
if((u>=g->n)||(v>=g->n)){
   printf("�׷���:���� ��ȣ ����");
   return 0;
}
node=(graphNode*)malloc(sizeof(graphNode));//�����ҳ�� ����
node->vertex=v;//���ο� ��忡 v���Է�
node->link=NULL;//node->link�� NULL�ʱ�ȭ
if(g->adjlist[u]==NULL){//������忡 ����Ȱ� ������
   g->adjlist[u]=node;//�����������ο��� ����
   return 0 ;
}
graphNode*n=g->adjlist[u];//n�� ������u�� �����ù���� ���
graphNode*trail=g->adjlist[u];//trial�� ������u�� �����ù���� ���

while(n!=NULL){
   if(n->vertex>=v){//ù ������� ���ʿ� �����ؾ��� ��� ���� �˻�
      if(n==g->adjlist[u]){//n�� ������ ����� ù���� ����ΰ��
         g->adjlist[u]=node;//�Է¹��� ��带 ù��°���� �ٲ�
         node->link=n;//����� ��ũ�� n�� ����
      }
      else{//�߰��̰ų� �������ΰ��
         node->link=n;
         trail->link=node;
      }
         return 0;
      
   }
   //��ĭ�� �̵��ϸ鼭 �־��� �ڸ� ã��
   trail=n;
   n=n->link;

}
//������ ������ ã�� ���Ѱ��,�������� ����
trail->link=node;
return 0;

}
void print(graphType*g){
  for(int i=0;i<g->n;i++){

graphNode*p=g->adjlist[i];
printf("����%d�� ��������Ʈ",i);
while(p!=NULL){
   printf("->%d",p->vertex);
   p=p->link;
}
printf("\n");
  }
  
}

void dfs(graphType*g,int v){
graphNode* w;
visited[v]=TRUE;
printf("%5d",v);
for(w=g->adjlist[v];w;w=w->link){
   if(!visited[w->vertex]){//�湮���� �ʾҴٸ�

      dfs(g,w->vertex);
   }
   //�湮�ߴٸ�
}
}

graphNode*deQueue()
{
   if (front == rear) {
      // printf("\n....Now Queue is empty!!\n" );
      return NULL;
   }

   front = (front + 1) % MAX_VERTEX;
   return queue[front];//ť�迭�� front �ε��� ��ȣ ����

}

void enQueue(graphNode* aNode)
{
   rear = (rear + 1) % MAX_VERTEX;
   if (front == rear) {
      // printf("\n....Now Queue is full!!\n");
      return;
   }

   queue[rear] = aNode;//ť�� rear�� aNOde�Է�
}
void bfs(graphType*g,int v){

graphNode*w;
graphNode*node1;
node1=(graphNode*)malloc(sizeof(graphNode));//Ž���� ������ ������ ��带 ���� ����
node1->vertex=v;
node1->link=NULL;
printf("%5d",v);//Ž���� ������ ������ �� ���
visited[v]=TRUE;//�湮�� ���
enQueue(node1);//ó�� Ž���� ��� ť�� �Է�
while(front != rear){//ť�� ������ ������ ���� �ݺ�
     v=(deQueue()->vertex);//v=ť���� ���� ����� ������ �� 
for(w=g->adjlist[v];w;w=w->link){
if(!visited[w->vertex]){//�湮�� �����������
printf("%5d",w->vertex);
enQueue(w);
visited[w->vertex]=TRUE;
}
  }
}
free(node1);

}


void freegraph(graphType*g,int v){
   for(int i=0;i<v;i++){
      graphNode*h=g->adjlist[v];
      graphNode*next=NULL;
      while(h!=NULL){
      next=h;
      h=h->link;
      free(next);
      }
   }
       free(g);


}
