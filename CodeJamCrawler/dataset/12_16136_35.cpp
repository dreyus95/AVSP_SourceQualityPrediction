#include <stdio.h>
#include <string.h>

char mapping[27] = "yhesocvxduiglbkrztnwjpfmaq";

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	int T;
	scanf("%d", &T);
	getchar();

	char str[200];
	for (int i = 1; i <= T; ++i)
	{
		printf("Case #%d: ", i);

		gets(str);
		int len = strlen(str);
		for (int i = 0; i < len; ++i)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				printf("%c", mapping[str[i]-'a']);
			else
				printf("%c", str[i]);
		}
		printf("\n");
	}
	return 0;
}