#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

int used[250];
double px[250], py[250];

typedef struct data
{
    int n;
    int a[4];
    double len;
}data;

data pool[3500000], *ptt;

double get_dis(int p, int q)
{
    double x, y;
    x = px[p]-px[q];
    y = py[p]-py[q];
    return sqrt(x*x+y*y);
}

bool cmp(int p, int q)
{
    return px[p]<px[q];
}

bool comp(data *p, data *q)
{
    int i;
    int a[4], b[4];
    if(fabs(p->len-q->len) > 1e-7)
    {
        return p->len > q->len;
    }
    for(i=0; i<4; i++)
    {
        a[i] = p->a[i];
        b[i] = q->a[i];
    }
    sort(a, a+p->n, cmp);
    sort(b, b+p->n, cmp);
    for(i=0; i<4; i++)
    {
        if(a[i] != b[i])
        {
            return px[a[i]] > px[b[i]];
        }
    }
    return 0;
}

double cross(int p, int q, int r)  // p, q, r are index of px and py
{
    double pqx = px[q] - px[p];
    double pqy = py[q] - py[p];
    double qrx = px[r] - px[q];
    double qry = py[r] - py[q];
    return pqx*qry - pqy*qrx;
}

data* heap[4000000]; int hpn;
void heap_push(data* d)
{
    heap[hpn++] = d;
    push_heap(heap,heap+hpn,comp);
}

data* heap_pop()
{
    if(hpn==0) return NULL;
    data* tmp;
    tmp = heap[0];
    pop_heap(heap,heap+hpn,comp); hpn--;
    return tmp;
    
}


int main()
{
    int count, n, m, i, j, k;
    double ans;
    data *ptr, *t;
    scanf("%d", &count);
    while(count--)
    {
        scanf("%d", &n);
        m = ((n<<2));
        for(i=0; i<m; i++)
        {
            scanf("%lf%lf", &px[i], &py[i]);
        }
        hpn=0;
        memset(used, 0, sizeof(used));
        ptt = pool;
        for(i=0; i<m; i++)
        {
            for(j=i+1; j<m; j++)
            {
                ptr = ptt++;
                ptr->a[0] = i;
                ptr->a[1] = j;
                ptr->n = 2;
                ptr->len = get_dis(i, j);
                heap_push(ptr);
            }
        }
        ans = 0;
        for(i=0; i<n; i++)
        {
            while(1)
            {
                ptr = heap_pop();
                for(j=0; j<ptr->n; j++)
                {
                    if(used[ptr->a[j]])
                    {
                        break;
                    }
                }
                if(j < ptr->n)
                {
                    continue;
                }
                if(ptr->n == 4)
                {
                    ans += ptr->len;
                    for(j=0; j<4; j++)
                    {
                        used[ptr->a[j]] = 1;
                    }
                    break;
                }
                for(j=0; j<m; j++)
                {
                    if(used[j] == 0 && cross(ptr->a[ptr->n-2], ptr->a[ptr->n-1], j) < 0)
                    {
						for(k=0; k<ptr->n; k++)
						{
							if(ptr->a[k] == j)
							{
								break;
							}
						}
						if(k < ptr->n)
						{
							continue;
						}
                        t = ptt++;
                        *t = *ptr;
                        t->a[t->n++] = j;
                        t->len += get_dis(t->a[t->n-1], t->a[t->n-2]);
                        if(t->n == 4)
                        {
                            t->len += get_dis(t->a[t->n-1], t->a[0]);
                        }
                        heap_push(t);
                    }
                }
            }
        }
        printf("%.4lf\n", ans);
    }
    return 0;
}
