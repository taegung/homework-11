#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 10
#define TRUE 1
#define FALSE 0
short int visited[MAX_VERTEX];

typedef struct graphNode{
int vertex;//정점을 나타내는 데이터 
struct graphNode*link;//인접 정점을 연결하는 링크

}graphNode;

typedef struct graphType{
int n;//그래프의 정점의 개수
graphNode*adjlist[MAX_VERTEX];//정점에 대한 헤드 노드
}graphType;
 



void InitializeGraph(graphType*g);
void InsertVertex(graphType*g,int v);
int InsertEdge(graphType*g,int u,int v);
void print(graphType*g);
void dfs(graphType*g,int v);


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
      printf("[----- [윤태경] [2019038059] -----]\n");
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
        
         printf("삽입할 정점의 개수 입력");
         scanf("%d",&x);
         for(int i=0;i<x;i++){
         InsertVertex(g,x);
         } 
         break;
      case 'e': case 'E':
         printf("정점u를 입력하시오");
         scanf("%d",&u);
          printf("  정점u와 연결할 v를 입력하시오");
         scanf("%d",&v);
         InsertEdge(g,u,v); 
         break;
   
      case 'p': case 'P':
          print(g);
         break;

      case 'd': case 'D':
	  printf("탐색을 시작할 정점을 입력하시오");
           scanf("%d",&depth);
          dfs(g,depth);
          for(int i=0;i<MAX_VERTEX;i++)
            {
                visited[i] = 0;
            }
         break; 

      default:
         printf("\n       >>>>>   Concentration!!   <<<<<     \n");
         break;
      }

   }while(command != 'q' && command != 'Q');
    
   return 1;
}

void InitializeGraph(graphType*g){
   g->n=0;
   for(int x=0;x<MAX_VERTEX;x++){//입력받은 정점만큼 받복
      g->adjlist[x]=NULL;//그래프의 각헤더노드를 초기화
   }

}
void InsertVertex(graphType*g,int v){
      if(((g->n)+1)>MAX_VERTEX){//정점의 개수가 10보다 크다면 오류 문구

         printf("그래프 최대 정점 개수 초과 \n");
         return;
      }
      g->n++;//정점을 하나 증가시킴
}

int InsertEdge(graphType*g,int u,int v){
graphNode*node;
if((u>=g->n)||(v>=g->n)){
   printf("그래프:정점 번호 오류");
   return 0;
}
node=(graphNode*)malloc(sizeof(graphNode));//연결할노드 생성
node->vertex=v;//새로운 노드에 v값입력
node->link=NULL;//node->link를 NULL초기화
if(g->adjlist[u]==NULL){//정점노드에 연결된게 없으면
   g->adjlist[u]=node;//정점노드랑새로운노드 연결
   return 0 ;
}
graphNode*n=g->adjlist[u];//n은 정점이u와 연결된첫번쨰 노드
graphNode*trail=g->adjlist[u];//trial은 정점이u와 연결된첫번쨰 노드

while(n!=NULL){
   if(n->vertex>=v){//첫 정점노드 앞쪽에 삽입해야할 경우 인지 검사
      if(n==g->adjlist[u]){//n이 정점과 연결된 첫번쨰 노드인경우
         g->adjlist[u]=node;//입력받은 노드를 첫번째노드로 바꿈
         node->link=n;//노드의 링크를 n과 연결
      }
      else{//중간이거나 마지막인경우
         node->link=n;
         trail->link=node;
      }
         return 0;
      
   }
   //한칸씩 이동하면서 넣어줄 자리 찾음
   trail=n;
   n=n->link;

}
//마지막 노드까지 찾지 못한경우,마지막에 삽입
trail->link=node;
return 0;

}
void print(graphType*g){
  for(int i=0;i<g->n;i++){

graphNode*p=g->adjlist[i];
printf("정점%d의 인접리스트",i);
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
   if(!visited[w->vertex]){//방문하지 않았다면

      dfs(g,w->vertex);
   }
   //방문했다면
}
}





