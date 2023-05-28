#define ACCOUNT(X,Y) (printf("\n---------------------------------------\
					  \nYour current account is %.2f\
					  \nYour Final account is %.2f", X, Y))

int main(void)
{
	float iCurrentPrice = 0;
	iCurrentPrice = 150.00f;
	float iFinalPrice = 200.00f;
	ACCOUNT(iCurrentPrice, iFinalPrice);
	//printf("\n---------------------------------------");
	//printf("\nYour current account is %.2f", iCurrentPrice);
	//printf("\nYour Final account is %.2f", iFinalPrice);
	return 0;
}
