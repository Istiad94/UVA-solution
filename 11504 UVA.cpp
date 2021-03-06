#include<bits/stdc++.h>
using namespace std;

/// M A C R O Starts Here
#define pf printf
#define sf scanf
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define pi acos(-1.0)
#define get_stl(s) getline(cin,s)
#define sif(a) scanf("%d",&a)
#define pif(a) printf("%d\n",a)
#define puf(a) printf("%llu\n",a)
#define pii pair<int, int>
#define mem(name, value) memset(name, value, sizeof(name))
#define all(name) name.begin(),name.end()

typedef long long ll;
typedef unsigned long long ull;

int dx[]={0,0,1,-1,-1,1,-1,1};
int dy[]={-1,1,0,0,1,1,-1,-1};
int dz[]={0,0,+1,-1,-1,+1,-1,+1};

int isLeft(double a, double b, double c, double d, double e, double f)
{
    double r = 0.5*((a*(d-f))+(b*(e-c))+((c*f)-(d*e)));
    if(r==0.00) return 0;
    if(r<0)     return -1;
    return 1;
}

vector<int>g[100001];
bool v[100001];
vector<int>top;

void reset(int n)
{
    top.clear();
    for(int i=1;i<=n;i++)
    {
        g[i].clear();
        v[i] = false;
    }
}

void edge(int m)
{
    int u,v;
    while(m--)
    {
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
    }
}

void DFS(int s,bool f)
{
    v[s] = true;
    for(int i=0;i<g[s].size();i++)
        if(!v[g[s][i]])
            DFS(g[s][i],f);
    if(f)   top.push_back(s);
}

void topsort(int n)
{
    for(int i=1;i<=n;i++)
        if(!v[i])
            DFS(i,true);
}

int DFS2(int n)
{
    for(int i=1;i<=n;i++)
        v[i] = false;
    int ans = 0;
    reverse(top.begin(),top.end());
    for(int i=0;i<top.size();i++)
        if(!v[top[i]])
        {
            DFS(top[i],false);
            ans++;
        }
    return ans;
}

int main()
{
    //freopen("in.txt","r", stdin);
    //freopen("out.txt","w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test,n,m;
    scanf("%d",&test);

    while(test--)
    {
        scanf("%d%d",&n,&m);
        reset(n);
        edge(m);
        topsort(n);
        int ans = DFS2(n);
        printf("%d\n",ans);
    }

    return 0;
}

