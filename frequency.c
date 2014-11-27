
int ndat;
char dat[max];
int freq[max];

void stat()
{
	int i;
	int flag;
	char temp;
	FILE *fp;
	clrscr();
	ndat = 0;
	fp = fopen("rajaram.txt","r+");
//	fp2 = fopen("freqkey.dat","w");
/*	for (i=1;i<25;i++)
	{
		dat[i] = '\0';
		freq[i] = 0;
	}                    */
	flushall();
	while (feof(fp) == 0)
	{
		temp = getc(fp);
		flag = 0;
		for (i=0;i<ndat;i++)
		{
			if (dat[i] == temp)
			{
				freq[i]++;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			dat[ndat] = temp;
			ndat++;
			freq[ndat] = 1;
		}
	}

	fclose(fp);
//	for (i=0;i<n2;i++)
//	{
//		fprintf(fp2,"%c %d \n",a[i],n[i]);
//	}

}
