#include <stdio.h>

#define MAX_TEST 100
//�׳� ��� 500 �ȾƼ� ������ �Ŷ�
//��ٷ��� �� ä��� �Ŷ� ���ؼ�
//��ٸ��� �ջ��� �� ������ win

int main(void)
{
	FILE *fp = fopen("B-small-attempt1.in", "r");
	FILE *wfp = fopen("B-small-attempt1.out", "w");

	int testcase, i;
	float c[MAX_TEST],f[MAX_TEST],x[MAX_TEST];
	float sum = 0.0, sec, xres, fnum, fnum2, xres2;
	int k;

	fscanf(fp,"%d", &testcase);
	for(i=0;i<testcase;i++){
		sum = 0.0;
		fscanf(fp,"%f %f %f", &c[i], &f[i], &x[i]);

		fprintf(wfp,"Case #%d: ", i+1);
		

		for(k=0;;k++){
			fnum = 2+f[i]*k;
			fnum2 = 2+f[i]*(k+1);
			sec = c[i]/fnum;
			xres = x[i]/fnum;
			xres2 = x[i]/fnum2;

 			if(xres+sum>sec+xres2+sum)
				sum+=sec;
			else{
				sum+=xres;
				fprintf(wfp,"%.7f\n", sum);
				break;
			}
		}
	}
	fclose(fp);
	fclose(wfp);
	return 0;
}