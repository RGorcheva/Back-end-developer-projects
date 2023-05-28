#ifndef ENUMS_H
#define ENUMS_H

enum E_productType
{
	E_productType_NA,
	E_productType_Book,
	E_productType_Serie,
	E_productType_Pen,
	E_productType_Notebook,
	E_productType_Greeting
};

enum E_BookGenre
{
	E_BookGenre_NA,
	E_BookGenre_Sci_Fi,
	E_BookGenre_Fantasy,
	E_BookGenre_Mystery,
	E_BookGenre_Romance
};

enum E_Color 
{
	E_Color_NA,
	E_Color_White,
	E_Color_Blue,
	E_Color_Red,
	E_Color_Black
};

enum Function
{
	e_Quit,
	e_Back,
	e_MainMenu,
	e_AddProduct,
	e_ChooseProduct,
	e_BuyProduct,
	e_VoteBook
};

#endif
