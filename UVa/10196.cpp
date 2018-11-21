#include<stdio.h>
#include<string.h>
int main()
{
	char k[12][12],x;
	int a,b,c,d,e,f,g,h,i,j;
	j=0;
	for(;;)
	{
		if(j!=0)
		{
			scanf("%c",&x);
		}
		for(b=2,g=0;b<10;b++)
		{
			for(a=2;a<10;a++)
			{
				scanf("%c",&k[a][b]);
				x=k[a][b];
				if(x=='k')
				{
					c=a;
					d=b;
				}
				else if(x=='K')
				{
					e=a;
					f=b;
				}
				if(x!='.')
				{
					g++;
				}
			}
			scanf("%c",&x);
		}
		if(g==0)
		{
			break;
		}
		j++;
		if(k[c-1][d+1]=='P')
		{
			printf("Game #%d: black king is in check.\n",j);
			continue;
		}
		else if(k[c+1][d+1]=='P')
		{
			printf("Game #%d: black king is in check.\n",j);
			continue;
		}
		else if(k[c-2][d-1]=='N')
		{
			printf("Game #%d: black king is in check.\n",j);
			continue;
		}
		else if(k[c-2][d+1]=='N')
		{
			printf("Game #%d: black king is in check.\n",j);
			continue;
		}
		else if(k[c-1][d+2]=='N')
		{
			printf("Game #%d: black king is in check.\n",j);
			continue;
		}
		else if(k[c-1][d-2]=='N')
		{
			printf("Game #%d: black king is in check.\n",j);
			continue;
		}
		else if(k[c+1][d+2]=='N')
		{
			printf("Game #%d: black king is in check.\n",j);
			continue;
		}
		else if(k[c+1][d-2]=='N')
		{
			printf("Game #%d: black king is in check.\n",j);
			continue;
		}
		else if(k[c+2][d-1]=='N')
		{
			printf("Game #%d: black king is in check.\n",j);
			continue;
		}
		else if(k[c+2][d+1]=='N')
		{
			printf("Game #%d: black king is in check.\n",j);
			continue;
		}
		else
		{
			for(a=c-1,b=d-1,i=0;a>1,b>1;a--,b--)
			{
				if(k[a][b]=='B')
				{
					printf("Game #%d: black king is in check.\n",j);
					i=1;
					break;
				}
				else if(k[a][b]=='Q')
				{
					printf("Game #%d: black king is in check.\n",j);
					i=1;
					break;
				}
				else if(k[a][b]!='.')
				{
					break;
				}
			}
			if(i==0)
			{
				for(a=c-1,b=d+1,i=0;a>1,b<10;a--,b++)
				{
					if(k[a][b]=='B')
					{
						printf("Game #%d: black king is in check.\n",j);
						i=1;
						break;
					}
					else if(k[a][b]=='Q')
					{
						printf("Game #%d: black king is in check.\n",j);
						i=1;
						break;
					}
					else if(k[a][b]!='.')
					{
						break;
					}
				}
				if(i==0)
    			{
    				for(a=c+1,b=d+1,i=0;a<10,b<10;a++,b++)
    				{
    					if(k[a][b]=='B')
    					{
    						printf("Game #%d: black king is in check.\n",j);
    						i=1;
    						break;
    					}
    					else if(k[a][b]=='Q')
    					{
    						printf("Game #%d: black king is in check.\n",j);
    						i=1;
    						break;
    					}
    					else if(k[a][b]!='.')
    					{
    						break;
    					}
    				}
					if(i==0)
        			{
        				for(a=c+1,b=d-1,i=0;a<10,b>1;a++,b--)
        				{
        					if(k[a][b]=='B')
        					{
        						printf("Game #%d: black king is in check.\n",j);
        						i=1;
        						break;
        					}
        					else if(k[a][b]=='Q')
        					{
        						printf("Game #%d: black king is in check.\n",j);
        						i=1;
        						break;
        					}
        					else if(k[a][b]!='.')
        					{
        						break;
        					}
        				}
						if(i==0)
            			{
            				for(a=c+1,b=d,i=0;a<10;a++)
            				{
            					if(k[a][b]=='R')
            					{
            						printf("Game #%d: black king is in check.\n",j);
            						i=1;
            						break;
            					}
            					else if(k[a][b]=='Q')
            					{
            						printf("Game #%d: black king is in check.\n",j);
            						i=1;
            						break;
            					}
            					else if(k[a][b]!='.')
            					{
            						break;
            					}
            				}
							if(i==0)
                			{
                				for(a=c,b=d+1,i=0;b<10;b++)
                				{
                					if(k[a][b]=='R')
                					{
                						printf("Game #%d: black king is in check.\n",j);
                						i=1;
                						break;
                					}
                					else if(k[a][b]=='Q')
                					{
                						printf("Game #%d: black king is in check.\n",j);
                						i=1;
                						break;
                					}
                					else if(k[a][b]!='.')
                					{
                						break;
                					}
                				}
								if(i==0)
                    			{
                    				for(a=c-1,b=d,i=0;a>1;a--)
                    				{
                    					if(k[a][b]=='R')
                    					{
                    						printf("Game #%d: black king is in check.\n",j);
                    						i=1;
                    						break;
                    					}
                    					else if(k[a][b]=='Q')
                    					{
                    						printf("Game #%d: black king is in check.\n",j);
                    						i=1;
                    						break;
                    					}
                    					else if(k[a][b]!='.')
                    					{
                    						break;
                    					}
                    				}
									if(i==0)
                        			{
                        				for(a=c,b=d-1,i=0;b>1;b--)
                        				{
                        					if(k[a][b]=='R')
                        					{
                        						printf("Game #%d: black king is in check.\n",j);
                        						i=1;
                        						break;
                        					}
                        					else if(k[a][b]=='Q')
                        					{
                        						printf("Game #%d: black king is in check.\n",j);
                        						i=1;
                        						break;
                        					}
                        					else if(k[a][b]!='.')
                        					{
                        						break;
                        					}
                        				}
                        			}
                    			}
                			}
            			}
        			}
    			}
			}
			if(i==0)
			{
				if(k[e-1][f-1]=='p')
				{
    				printf("Game #%d: white king is in check.\n",j);
    				continue;
    			}
        		else if(k[e+1][f-1]=='p')
        		{
        			printf("Game #%d: white king is in check.\n",j);
        			continue;
        		}
        		else if(k[e-2][f-1]=='n')
        		{
        			printf("Game #%d: white king is in check.\n",j);
        			continue;
        		}
        		else if(k[e-2][f+1]=='n')
        		{
        			printf("Game #%d: white king is in check.\n",j);
        			continue;
        		}
        		else if(k[e-1][f+2]=='n')
        		{
        			printf("Game #%d: white king is in check.\n",j);
        			continue;
        		}
        		else if(k[e-1][f-2]=='n')
        		{
        			printf("Game #%d: white king is in check.\n",j);
        			continue;
        		}
        		else if(k[e+1][f+2]=='n')
        		{
        			printf("Game #%d: white king is in check.\n",j);
        			continue;
        		}
        		else if(k[e+1][f-2]=='n')
        		{
        			printf("Game #%d: white king is in check.\n",j);
        			continue;
        		}
        		else if(k[e+2][f-1]=='n')
        		{
        			printf("Game #%d: white king is in check.\n",j);
        			continue;
        		}
        		else if(k[e+2][f+1]=='n')
        		{
        			printf("Game #%d: white king is in check.\n",j);
        			continue;
        		}
        		else
        		{
        			for(a=e-1,b=f-1,i=0;a>1,b>1;a--,b--)
        			{
        				if(k[a][b]=='b')
        				{
        					printf("Game #%d: white king is in check.\n",j);
        					i=1;
        					break;
        				}
        				else if(k[a][b]=='q')
        				{
        					printf("Game #%d: white king is in check.\n",j);
        					i=1;
        					break;
        				}
        				else if(k[a][b]!='.')
        				{
        					break;
        				}
        			}
        			if(i==0)
        			{
        				for(a=e-1,b=f+1,i=0;a>1,b<10;a--,b++)
        				{
        					if(k[a][b]=='b')
        					{
        						printf("Game #%d: white king is in check.\n",j);
        						i=1;
        						break;
        					}
        					else if(k[a][b]=='q')
        					{
        						printf("Game #%d: white king is in check.\n",j);
        						i=1;
        						break;
        					}
        					else if(k[a][b]!='.')
        					{
        						break;
        					}
        				}
        				if(i==0)
            			{
            				for(a=e+1,b=f+1,i=0;a<10,b<10;a++,b++)
            				{
            					if(k[a][b]=='b')
            					{
            						printf("Game #%d: white king is in check.\n",j);
            						i=1;
            						break;
            					}
            					else if(k[a][b]=='q')
            					{
            						printf("Game #%d: white king is in check.\n",j);
            						i=1;
            						break;
            					}
            					else if(k[a][b]!='.')
            					{
            						break;
            					}
            				}
        					if(i==0)
                			{
                				for(a=e+1,b=f-1,i=0;a<10,b>1;a++,b--)
                				{
                					if(k[a][b]=='b')
                					{
                						printf("Game #%d: white king is in check.\n",j);
                						i=1;
                						break;
                					}
                					else if(k[a][b]=='q')
                					{
                						printf("Game #%d: white king is in check.\n",j);
                						i=1;
                						break;
                					}
                					else if(k[a][b]!='.')
                					{
                						break;
                					}
                				}
        						if(i==0)
                    			{
                    				for(a=e+1,b=f,i=0;a<10;a++)
                    				{
                    					if(k[a][b]=='r')
                    					{
                    						printf("Game #%d: white king is in check.\n",j);
                    						i=1;
                    						break;
                    					}
                    					else if(k[a][b]=='q')
                    					{
                    						printf("Game #%d: white king is in check.\n",j);
                    						i=1;
                    						break;
                    					}
                    					else if(k[a][b]!='.')
                    					{
                    						break;
                    					}
                    				}
        							if(i==0)
                        			{
                        				for(a=e,b=f+1,i=0;b<10;b++)
                        				{
                        					if(k[a][b]=='r')
                        					{
                        						printf("Game #%d: white king is in check.\n",j);
                        						i=1;
                        						break;
                        					}
                        					else if(k[a][b]=='q')
                        					{
                        						printf("Game #%d: white king is in check.\n",j);
                        						i=1;
                        						break;
                        					}
                        					else if(k[a][b]!='.')
                        					{
                        						break;
                        					}
                        				}
        								if(i==0)
                            			{
                            				for(a=e-1,b=f,i=0;a>1;a--)
                            				{
                            					if(k[a][b]=='r')
                            					{
                            						printf("Game #%d: white king is in check.\n",j);
                            						i=1;
                            						break;
                            					}
                            					else if(k[a][b]=='q')
                            					{
                            						printf("Game #%d: white king is in check.\n",j);
                            						i=1;
                            						break;
                            					}
                            					else if(k[a][b]!='.')
                            					{
                            						break;
                            					}
                            				}
        									if(i==0)
                                			{
                                				for(a=e,b=f-1,i=0;b>1;b--)
                                				{
                                					if(k[a][b]=='r')
                                					{
                                						printf("Game #%d: white king is in check.\n",j);
                                						i=1;
                                						break;
                                					}
                                					else if(k[a][b]=='q')
                                					{
                                						printf("Game #%d: white king is in check.\n",j);
                                						i=1;
                                						break;
                                					}
                                					else if(k[a][b]!='.')
                                					{
                                						break;
                                					}
                                				}
                                			}
                            			}
                        			}
                    			}
                			}
            			}
        			}
    			}
			}
		}
		if(i==0)
		{
			printf("Game #%d: no king is in check.\n",j);
		}
	}
	return 0;
}