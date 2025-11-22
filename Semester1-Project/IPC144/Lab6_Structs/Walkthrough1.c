#include <stdio.h>

struct Demo
{
	int apple;
	int banana;
	int orange;
	char grapes[6];

};

int main(void)
{
	struct Demo first = {2,4, 2, "lgwrd"};
	char temp;
	int i;
	printf("%s\n", first.grapes);
	temp = first.grapes[first.apple];
	first.grapes[first.apple] = first.grapes[first.banana];
	first.grapes[first.banana] = temp;
	printf("%s\n", first.grapes);
	for(i = 0; first.grapes[i]!='\0';i++){
		first.grapes[i]+=first.orange;
	}
	printf("%s\n", first.grapes);
	return 0;
}