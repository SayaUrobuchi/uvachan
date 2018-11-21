#include <stdio.h>
#include <stdlib.h>

int ary[36], check[36], ans[9], n, lim, num, sum;

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

char chkans()
{
	int i, j, k;
	for(i=1, k=0; i<n; i++)
	{
		if(ans[i] < ans[i-1])
		{
			return 0;
		}
		for(j=0; j<i; j++)
		{
			check[k++] = ans[i] + ans[j];
		}
	}
	qsort(check, num, sizeof(int), comp);
	for(i=0; i<num; i++)
	{
		if(check[i] != ary[i])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int i, j, k;
	/*for(i=2; i<10; i++)
	{
		for(j=1; j<i; j++)
		{
			printf("%d ", i + j);
		}
	}*/
	while(scanf("%d", &n) == 1)
	{
		num = n * (n-1) / 2;
		for(i=0, sum=0; i<num; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
		}
		if(sum % (n-1))
		{
			printf("Impossible\n");
		}
		else
		{
			qsort(ary, num, sizeof(int), comp);
			sum /= n - 1;
			for(i=2; i<n; i++)
			{
				ans[0] = ary[0] + ary[1] + ary[i];
				ans[0] /= 2;
				ans[1] = ans[0] - ary[1];
				ans[2] = ans[0] - ary[0];
				ans[0] -= ary[i];
				if(n > 3)
				{
					if(i != 2)
					{
						ans[3] = ary[2] - ans[0];
						if(ans[3] >= ans[2])
						{
							if(n == 4)
							{
								if(chkans())
								{
									break;
								}
							}
							else if(n == 5)
							{
								ans[4] = ary[num-1] - ans[3];
								if(chkans())
								{
									break;
								}
							}
							else if(n == 6)
							{
								ans[5] = ary[num-2] - ans[3];
								ans[4] = ary[num-1] - ans[5];
								if(chkans())
								{
									break;
								}
							}
							else
							{
								for(j=num-3, lim=num-n-1; j>lim; j--)
								{
                                    ans[n-1] = ary[num-1] + ary[num-2] + ary[j];
									ans[n-1] /= 2;
									ans[n-2] = ans[n-1] - ary[num-2];
									ans[n-3] = ans[n-1] - ary[num-1];
									ans[n-1] -= ary[j];
									if(n == 7)
									{
										if(chkans())
										{
											break;
										}
									}
									else
									{
										if(j != num - 3)
										{
											ans[n-4] = ary[num-3] - ans[n-1];
											if(n == 8)
											{
												if(chkans())
												{
													break;
												}
											}
											else
											{
												ans[4] = sum;
												for(k=0; k<n; k++)
												{
													if(k != 4)
													{
														ans[4] -= ans[k];
													}
												}
												if(chkans())
												{
													break;
												}
											}
										}
										ans[n-4] = ary[num-4] - ans[n-1];
										if(n == 8)
										{
											if(chkans())
											{
												break;
											}
										}
										else
										{
											ans[4] = sum;
											for(k=0; k<n; k++)
											{
												if(k != 4)
												{
													ans[4] -= ans[k];
												}
											}
											if(chkans())
											{
												break;
											}
										}
									}
								}
								if(j > lim)
								{
									break;
								}
							}
						}
					}
					ans[3] = ary[3] - ans[0];
					if(ans[3] < ans[2])
					{
						continue;
					}
					if(n == 4)
					{
						if(chkans())
						{
							break;
						}
					}
					else if(n == 5)
					{
						ans[4] = ary[num-1] - ans[3];
						if(chkans())
						{
							break;
						}
					}
					else if(n == 6)
					{
						ans[5] = ary[num-2] - ans[3];
						ans[4] = ary[num-1] - ans[5];
						if(chkans())
						{
							break;
						}
					}
					else
					{
						for(j=num-3, lim=num-n-1; j>lim; j--)
						{
                            ans[n-1] = ary[num-1] + ary[num-2] + ary[j];
							ans[n-1] /= 2;
							ans[n-2] = ans[n-1] - ary[num-2];
							ans[n-3] = ans[n-1] - ary[num-1];
							ans[n-1] -= ary[j];
							if(n == 7)
							{
								if(chkans())
								{
									break;
								}
							}
							else
							{
								if(j != num - 3)
								{
									ans[n-4] = ary[num-3] - ans[n-1];
									if(n == 8)
									{
										if(chkans())
										{
											break;
										}
									}
									else
									{
										ans[4] = sum;
										for(k=0; k<n; k++)
										{
											if(k != 4)
											{
												ans[4] -= ans[k];
											}
										}
										if(chkans())
										{
											break;
										}
									}
								}
								ans[n-4] = ary[num-4] - ans[n-1];
								if(n == 8)
								{
									if(chkans())
									{
										break;
									}
								}
								else
								{
									ans[4] = sum;
									for(k=0; k<n; k++)
									{
										if(k != 4)
										{
											ans[4] -= ans[k];
										}
									}
									if(chkans())
									{
										break;
									}
								}
							}
						}
						if(j > lim)
						{
							break;
						}
					}
				}
			}
			if(i == n && n != 3)
			{
				printf("Impossible\n");
			}
			else
			{
				printf("%d", ans[0]);
				for(i=1; i<n; i++)
				{
					printf(" %d", ans[i]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
