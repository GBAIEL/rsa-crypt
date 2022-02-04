#include <stdio.h>

int main(void)
{
	
	FILE *criptografia;
	char mensagem[2000];
	
	criptografia = fopen("equipex.txt", "w");

    scanf("%s", mensagem);

    fprintf(criptografia, "%s", mensagem);
	
	fclose(criptografia);
	
	printf("o arquivo foi criado com sucesso\n");
	
	return 0;
}
