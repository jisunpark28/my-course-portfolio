#include <stdio.h>
#include <string.h>

int main(){

	char question[100];
	char json_body[521];

	printf("Enter your question: ");
	fgets(question, sizeof(question), stdin);
	question[strcspn(question, "\n")]=0;
	sprintf(json_body,
		"{"
		"	\"contents\": [{"
		"	\"parts\": [{\"text\": \"%s\"}]"
		"	}]"
		"}", question);
	printf("%s\n", json_body);
return 0;
}