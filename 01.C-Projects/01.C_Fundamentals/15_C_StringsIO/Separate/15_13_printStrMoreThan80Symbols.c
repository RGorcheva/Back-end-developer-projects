/*
 Използвайте функцията getchar(), с която въвеждате текст от
клавиатурата, докато не подадете ЕОF(Ctrl+Z). Текстът да отпечатва
само входни редове, които са по дълги от 80 символа.
*/

int main(void)
{
	char buff[256] = { 0 };
	char temp[256] = { 0 };
	int countSymbol = 0;
	io_strEnterMultilineEOF(buff);
	int lenght = strlen(buff);
	int j = 0;
	for (int i = 0; i <= lenght; ++i)
	{

		if (buff[i] != '\n')
		{
			temp[j] = buff[i];
			j++;
		}
		if ((buff[i] == '\n') || (buff[i] == '\0'))
		{
			temp[j] = '\0';
			if (strlen(temp) >= 80)
			{
				printf(temp);
				printf("\n");
			}
			j = 0;
		}

	}
	return 0;
}