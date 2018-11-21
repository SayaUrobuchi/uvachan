#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct bnum
{
	int len;
	int dig[1001];
}bnum;

bnum oo[11];

void output(bnum *t)
{
	int i;
	for(i=t->len-1; i>=0; i--)
	{
		printf("%d", t->dig[i]);
	}
	printf("\n");
}

int eql(bnum *p, bnum *q)
{
	int i;
	if(p->len != q->len)
	{
		return 0;
	}
	for(i=p->len-1; i>=0; i--)
	{
		if(p->dig[i] != q->dig[i])
		{
			return 0;
		}
	}
	return 1;
}

int nless(bnum *p, bnum *q)
{
	int i;
	if(p->len != q->len)
	{
		return p->len > q->len;
	}
	for(i=p->len-1; i>0; i--)
	{
		if(p->dig[i] != q->dig[i])
		{
			return p->dig[i] > q->dig[i];
		}
	}
	return p->dig[i] >= q->dig[i];
}

int more(bnum *p, bnum *q)
{
	int i;
	if(p->len != q->len)
	{
		return p->len > q->len;
	}
	for(i=p->len-1; i>0; i--)
	{
		if(p->dig[i] != q->dig[i])
		{
			return p->dig[i] > q->dig[i];
		}
	}
	return p->dig[i] > q->dig[i];
}

bnum *ass(bnum *p, char *s)
{
	int i, j;
	p->len = strlen(s);
	for(i=0, j=p->len-1; j>=0; i++, j--)
	{
		p->dig[i] = s[j] - '0';
	}
	return p;
}

bnum *add(bnum *p, bnum *q)
{
	int i;
	for(i=0; i<p->len&&i<q->len; i++)
	{
		p->dig[i] += q->dig[i];
	}
	if(p->len < q->len)
	{
		for(; i<q->len; i++)
		{
			p->dig[i] = q->dig[i];
		}
		p->len = q->len;
	}
	p->dig[p->len] = 0;
	for(i=0; i<p->len; i++)
	{
		if(p->dig[i] >= 10)
		{
			p->dig[i+1]++;
			p->dig[i] -= 10;
		}
	}
	if(p->dig[p->len])
	{
		p->len++;
	}
	return p;
}

bnum *sub(bnum *p, bnum *q)
{
	int i;
	for(i=0; i<q->len; i++)
	{
		p->dig[i] -= q->dig[i];
		if(p->dig[i] < 0)
		{
			p->dig[i] += 10;
			p->dig[i+1]--;
		}
	}
	for(; i<p->len; i++)
	{
		if(p->dig[i] < 0)
		{
			p->dig[i] += 10;
			p->dig[i+1]--;
		}
	}
	for(i=p->len-1; i>0; i--)
	{
		if(p->dig[i])
		{
			break;
		}
	}
	p->len = i + 1;
	return p;
}

bnum *mul(bnum *p, bnum *q)
{
	int i, j;
	int buf[1005];
	memset(buf, 0, sizeof(buf));
	for(i=0; i<p->len; i++)
	{
		for(j=0;j<q->len; j++)
		{
			buf[i+j] += p->dig[i] * q->dig[j];
		}
	}
	for(i=0, j=p->len+q->len-1; i<j; i++)
	{
		if(buf[i] >= 10)
		{
			buf[i+1] += buf[i] / 10;
			buf[i] %= 10;
		}
	}
	for(; ; i++)
	{
		if(buf[i] >= 10)
		{
			buf[i+1] += buf[i] / 10;
			buf[i] %= 10;
		}
		else if(buf[i] == 0)
		{
			break;
		}
	}
	for(i--; i>0; i--)
	{
		if(buf[i])
		{
			break;
		}
	}
	p->len = i+1;
	j = p->len;
	for(i=0; i<j; i++)
	{
		p->dig[i] = buf[i];
	}
	return p;
}

bnum *div(bnum *p, bnum *q)
{
	int i, j;
	int buf[1005];
	bnum t, r;
	for(i=0; i<q->len; i++)
	{
		t.dig[i] = p->dig[p->len-q->len+i];
	}
	t.len = q->len;
	for(i=(p->len)-(q->len); i>=0; i--)
	{
		r = *q;
		for(j=1; j<10; j++)
		{
			if(more(&r, &t))
			{
				break;
			}
			add(&r, q);
		}
		buf[i] = j-1;
		sub(&r, q);
		sub(&t, &r);
		if(i>0)
		{
			mul(&t, &oo[10]);
			add(&t, &oo[p->dig[i-1]]);
		}
	}
	for(i=0; i<=p->len-q->len; i++)
	{
		p->dig[i] = buf[i];
	}
	for(i--; i>0; i--)
	{
		if(p->dig[i])
		{
			break;
		}
	}
	p->len = i+1;
	if(p->len < 1)
	{
		p->len = 1;
	}
	return p;
}

bnum *mod(bnum *p, bnum *q)
{
	int i, j;
	int buf[1005];
	bnum t, r;
	if(more(q, p))
	{
		return p;
	}
	for(i=0; i<q->len; i++)
	{
		t.dig[i] = p->dig[p->len-q->len+i];
	}
	t.len = q->len;
	for(i=p->len-q->len; i>=0; i--)
	{
		r = *q;
		for(j=1; j<10; j++)
		{
			if(more(&r, &t))
			{
				break;
			}
			add(&r, q);
		}
		sub(&r, q);
		sub(&t, &r);
		if(i>0)
		{
			mul(&t, &oo[10]);
			add(&t, &oo[p->dig[i-1]]);
		}
	}
	*p = t;
	return p;
}

bnum *gcd(bnum *p, bnum *q)
{
	bnum r, *t;
	static bnum res;
	r = *p;
	t = mod(&r, q);
	if(eql(t, &oo[0]))
	{
		res = *q;
		return &res;
	}
	return gcd(q, &r);
}

char *get_n(bnum *p, char *s)
{
	int i, j;
	for(i=0, j=p->len-1; j>=0; i++, j--)
	{
		s[i] = p->dig[j] + '0';
	}
	s[i] = 0;
	return s;
}

int main()
{
	int ii, f;
	bnum p, q, i, t, tt, *gg;
	char buf[1001], buf2[1001];
	char s1[1001], s2[1001];
	for(ii=0; ii<=10; ii++)
	{
		sprintf(buf, "%d", ii);
		ass(&oo[ii], buf);
	}
	while(scanf("%s%s", s1, s2) == 2)
	{
		printf("%s/%s = ", s1, s2);
		ass(&p, s1);
		ass(&q, s2);
		gg = gcd(&p, &q);
		div(&p, gg);
		div(&q, gg);
		while(1)
		{
			t = q;
			f = 1;
			if(eql(mod(&t, &p), &oo[0]))
			{
				f = 0;
			}
			t = q;
			div(&t, &p);
			add(&t, &oo[f]);
			mul(&p, &t);
			sub(&p, &q);
			mul(&q, &t);
			gg = gcd(&p, &q);
			div(&p, gg);
			div(&q, gg);
			if(eql(&p, &oo[0]))
			{
				printf("(1/%s)\n", get_n(&t, buf));
				break;
			}
			else
			{
				printf("(1/%s)+", get_n(&t, buf));
			}
		}
	}
	return 0;
}
