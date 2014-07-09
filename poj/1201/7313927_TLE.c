#include<stdio.h>
#include<stdlib.h>
#define maxe 160000
#define maxint 20000000
#define maxn 50100
#define NIL -1
typedef struct{
        int v,w,nxt;
}node;
node space[maxe];
node uv[maxn];
int sps,g[maxn];
int N,st;

void add(int u,int v,int w){
     space[sps].v = v; space[sps].w = w;
     space[sps].nxt = g[u]; g[u] = sps++;
}

void Read(){
     int i,n,ai,bi,ci;
     sps = N = 0; st = maxint;
     scanf("%d",&n);
     for(i=1;i<=n;++i){ 
         scanf("%d%d%d",&uv[i].v,&uv[i].w,&uv[i].nxt);
         uv[i].v +=2 , uv[i].w +=2;
         if(uv[i].w>N) N = uv[i].w ; 
         if(uv[i].v-1 <st) st = uv[i].v-1 ;
     }
     for(i=1;i<=N;++i) g[i]=NIL;
     for(i=2;i<=N;++i){
           add(i-1,i,0);  add(i,i-1,-1);
     }
     for(i=1;i<=n;++i){
           ai = uv[i].v , bi = uv[i].w, ci = uv[i].nxt;
           add(ai-1,bi,ci);
     }
}

int Q[maxn],vis[maxn],qf,qt;
int dist[maxn];
void InitQ()     {    qf = qt = 0 ;                 }
int EmpQ()       {  return qt == qf ? 1:0 ;         }
void EnQ(int x)  {  Q[qt]=x , qt=(qt+1)%maxn;       }
int DeQ()        {  int t = Q[qf] , qf=(qf+1)%maxn; return t; }   

int relax(int u,int v,int w){
    if(dist[v] > dist[u] + w){
       dist[v] = dist[u] + w ;
       return 1;
    }
    return 0;
}

int spfa(){
    int i,j,addr,cv,nv;
    InitQ();
    for(i=1;i<=N;++i){  vis[i]=0;  dist[i] = maxint; }
    EnQ(st);  dist[st]=0 ,vis[st]=1;
    while(!EmpQ()){
         cv = DeQ() , vis[cv]=0;
         //printf("current vertex:%d\n",cv);  system("pause");
         for(addr = g[cv] ; addr!=NIL ; addr = space[addr].nxt){
                  nv = space[addr].v ;
                  if(1==relax(cv,nv,space[addr].w ) && !vis[nv]){
                      EnQ(nv) ,  vis[nv] = 1;
                  }
         }
    }
    return dist[N];
}

int main(){
    int ans;
    Read();
    ans = spfa();
    printf("%d\n",&ans);
    return 0;
}
    
     
     