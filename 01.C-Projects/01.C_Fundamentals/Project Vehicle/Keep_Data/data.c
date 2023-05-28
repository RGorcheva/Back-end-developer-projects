
typedef enum E_DrivingLicenseCategory { A1, A2, A, B, B1, C, D, BE, CE, DE, T } DrivingLicense;

typedef struct VehicleShopInfo
{
	unsigned vehicleID;
	char brand[10];
	char model[10];
	char VIN[20];
	unsigned yearOfМanufacture;
	DrivingLicense driveCatNeeded;
	float pricePerDay;
	unsigned isRented;
} VehicleInfo;

VehicleInfo vehicleShop[10] = {
	{
		.vehicleID = 1,
		.brand = "FIAT",
		.model = "Punto",
		.VIN = "HYGT45HYRGFT678",
		.yearOfМanufacture = 2003u,
		.driveCatNeeded = B,
		.pricePerDay = 50.0f,
		.isRented = 0u
	},
	{
		.vehicleID = 2,
		.brand = "FIAT",
		.model = "Punto",
		.VIN = "AHYBCDCDE79FHIF",
		.yearOfМanufacture = 2018U,
		.driveCatNeeded = B,
		.pricePerDay = 50.0f,
		.isRented = 0u
	},
	{
		.vehicleID = 3,
		.brand = "FIAT",
		.model = "Punto",
		.VIN = "DEGBFBAHF79FHIF",
		.yearOfМanufacture = 2018U,
		.driveCatNeeded = B,
		.pricePerDay = 50.0f,
		.isRented = 0u
	},
	{
		.vehicleID = 4,
		.brand = "MAZDA",
		.model = "2",
		.VIN = "DYGHSEPOVNNV678",
		.yearOfМanufacture = 2005U,
		.driveCatNeeded = B,
		.pricePerDay = 60.0f,
		.isRented = 0u
	},
	{
		.vehicleID = 5,
		.brand = "MAZDA",
		.model = "2",
		.VIN = "18HBVDHEE8JJIFBF",
		.yearOfМanufacture = 2015U,
		.driveCatNeeded = B,
		.pricePerDay = 60.0f,
		.isRented = 0u
	},
	{
		.vehicleID = 6,
		.brand = "FORD",
		.model = "Fiesta",
		.VIN = "QOMCBTRI5873JCB",
		.yearOfМanufacture = 2008U,
		.driveCatNeeded = B,
		.pricePerDay = 70.0f,
		.isRented = 0u
	},
	{
		.vehicleID = 7,
		.brand = "FORD",
		.model = "Fiesta",
		.VIN = "POIUNGSTU33799Q",
		.yearOfМanufacture = 2013U,
		.driveCatNeeded = B,
		.pricePerDay = 70.0f,
		.isRented = 0
	},
	{
		.vehicleID = 8,
		.brand = "FORD",
		.model = "Fiesta",
		.VIN = "MHGDUBFNOFGJ389",
		.yearOfМanufacture = 2021U,
		.driveCatNeeded = B,
		.pricePerDay = 70.0f,
		.isRented = 0u
	},
	{
		.vehicleID = 9,
		.brand = "TOYOTA",
		.model = "Yaris",
		.VIN = "FMBNDJKFNKD9457",
		.yearOfМanufacture = 2015U,
		.driveCatNeeded = B,
		.pricePerDay = 80.0f,
		.isRented = 0u
	},
	{
		.vehicleID = 10,
		.brand = "TOYOTA",
		.model = "Yaris",
		.VIN = "FJN579RUFUDHIDZ",
		.yearOfМanufacture = 2016U,
		.driveCatNeeded = B,
		.pricePerDay = 80.0f,
		.isRented = 0u
	}
};

typedef struct BrandDetails
{
	char brand[10];
	char brandDetails[1000];
	char model[10];
	char modelDetails[1000];
	float pricePerDay;
	unsigned isRentedCount;
} BrandDetails;

BrandDetails Brand[4] = {
	{
		.brand = "FIAT",
		.brandDetails = "\n\tFiat Automobiles S.p.A. is an Italian automobile manufacturer, formerly part of Fiat Chrysler Automobiles, and since 2021 a subsidiary of Stellantis through its Italian division Stellantis Italy. Fiat Automobiles was formed in January 2007 when Fiat S.p.A. reorganized its automobile business, and traces its history back to 1899 when the first Fiat automobile, the Fiat 4 HP, was produced.\n",
		.model = "Punto",
		.modelDetails = "\n\tThe Fiat Punto has 1 Diesel Engine and 1 Petrol Engine on offer. The Diesel engine is 1248 cc while the Petrol engine is 1172 cc . It is available with Manual transmission.Depending upon the variant and fuel type the Punto has a mileage of 14.6 to 20.3 kmpl & Ground clearance of Punto is 195mm. The Punto is a 5 seater 4 cylinder car and has length of 3987mm, width of 1687mm and a wheelbase of 2510mm.\n",
		.pricePerDay = 50.0f,
		.isRentedCount = 0u
	},
	{
	.brand = "MAZDA",
	.brandDetails = "\n\tMazda Motor Corporation, commonly referred to as simply Mazda, is a Japanese multinational automotive manufacturer headquartered in Fuchū, Hiroshima, Japan. In 2015, Mazda produced 1.5 million vehicles for global sales, the majority of which(nearly one million) were produced in the company's Japanese plants, with the remainder coming from a variety of other plants worldwide. During this time, Mazda was the 15th-largest automaker in terms of production globally.\n",
	.model = "2",
	.modelDetails = "\n\tThe Mazda 2 is offered Petrol engine in the Indonesia. The new Hatchback from Mazda comes in a total of 2 variants. If we talk about Mazda 2 engine specs then the Petrol engine displacement is 1496 cc. 2 is available with Automatic transmission. The 2 is a 5 Seater Hatchback and has a length of 4060 mm the width of 1695 mm, and a wheelbase of 2570 mm. along with a ground clearance of 152 mm.\n",
	.pricePerDay = 60.0f,
	.isRentedCount = 0u
	},
	{
	.brand = "FORD",
	.brandDetails = "\n\tFord Motor Company (commonly known as Ford) is an American multinational automobile manufacturer headquartered in Dearborn, Michigan, United States. It was founded by Henry Ford and incorporated on June 16, 1903. The company sells nautomobiles and commercial vehicles under the Ford brand, and luxury cars under its Lincoln luxury brand. Ford also owns Brazilian SUV manufacturer Troller, an 8% stake in Aston Martin of the United Kingdom and a 32% stake in China's Jiangling Motors. It also has joint ventures in China (Changan Ford), Taiwan (Ford Lio Ho), Thailand (AutoAlliance Thailand), Turkey (Ford Otosan), and Russia (Ford Sollers).\n",
	.model = "Fiesta",
	.modelDetails = "\n\tThe Ford Fiesta has 1 Diesel Engine and 1 Petrol Engine on offer. The Diesel engine is 1498 cc while the Petrol engine is 1499 cc . It is available with Manual transmission.Depending upon the variant and fuel type the Fiesta has a mileage of 17.0 to 25.01 kmpl & Ground clearance of Fiesta is 153mm. The Fiesta is a 5 seater 4 cylinder car and has length of 4320mm, width of 1764mm and a wheelbase of 2489mm.\n",
	.pricePerDay = 60.0f,
	.isRentedCount = 0u
	},
	{
	.brand = "TOYOTA",
	.brandDetails = "\n\tToyota Motor Corporation (commonly known as simply Toyota) is a Japanese multinational automotive manufacturer headquartered in Toyota City, Aichi, Japan. It was founded by Kiichiro Toyoda and incorporated on August 28, 1937. Toyota is one of the largest automobile manufacturers in the world, producing about 10 million vehicles per year. As of 2009, Toyota officially lists approximately 70 different models sold under its namesake brand, including sedans, coupes, vans, trucks, hybrids, and crossovers. Many of these models are produced as passenger sedans, which range from the subcompact Toyota Yaris, compact Corolla, to mid-size Camry and full-size Avalon. Minivans include the Innova, Alphard/Vellfire, Sienna, and others. Several small cars, such as the xB and tC, were sold under the Scion brand.\n",
	.model = "Yaris",
	.modelDetails = "\n\tThe Toyota Yaris has 1 Petrol Engine on offer. The Petrol engine is 1496 cc. It is available with Manual & Automatic transmission. Depending upon the variant and fuel type the Yaris has a mileage of 17.1 to 17.8 kmpl. The Yaris is a 5 seater 4 cylinder car and has length of 4425mm, width of 1730mm and a wheelbase of 2550mm.\n",
	.pricePerDay = 80.0f,
	.isRentedCount = 0u
	}
}

BrandDetails Brand1 = {
	.brand = "FIAT",
	.brandDetails = "\n\tFiat Automobiles S.p.A. is an Italian automobile manufacturer, formerly part of Fiat Chrysler Automobiles, and since 2021 a subsidiary of Stellantis through its Italian division Stellantis Italy. Fiat Automobiles was formed in January 2007 when Fiat S.p.A. reorganized its automobile business, and traces its history back to 1899 when the first Fiat automobile, the Fiat 4 HP, was produced.\n",
	.model = "Punto",
	.modelDetails = "\n\tThe Fiat Punto has 1 Diesel Engine and 1 Petrol Engine on offer. The Diesel engine is 1248 cc while the Petrol engine is 1172 cc . It is available with Manual transmission.Depending upon the variant and fuel type the Punto has a mileage of 14.6 to 20.3 kmpl & Ground clearance of Punto is 195mm. The Punto is a 5 seater 4 cylinder car and has length of 3987mm, width of 1687mm and a wheelbase of 2510mm.\n",
	.pricePerDay = 50.0f,
	.isRentedCount = 0u
};
BrandDetails Brand2 = {
	.brand = "MAZDA",
	.brandDetails = "\n\tMazda Motor Corporation, commonly referred to as simply Mazda, is a Japanese multinational automotive manufacturer headquartered in Fuchū, Hiroshima, Japan. In 2015, Mazda produced 1.5 million vehicles for global sales, the majority of which(nearly one million) were produced in the company's Japanese plants, with the remainder coming from a variety of other plants worldwide. During this time, Mazda was the 15th-largest automaker in terms of production globally.\n",
	.model = "2",
	.modelDetails = "\n\tThe Mazda 2 is offered Petrol engine in the Indonesia. The new Hatchback from Mazda comes in a total of 2 variants. If we talk about Mazda 2 engine specs then the Petrol engine displacement is 1496 cc. 2 is available with Automatic transmission. The 2 is a 5 Seater Hatchback and has a length of 4060 mm the width of 1695 mm, and a wheelbase of 2570 mm. along with a ground clearance of 152 mm.\n",
	.pricePerDay = 60.0f,
	.isRentedCount = 0u
};
BrandDetails Brand3 = {
	.brand = "FORD",
	.brandDetails = "\n\tFord Motor Company (commonly known as Ford) is an American multinational automobile manufacturer headquartered in Dearborn, Michigan, United States. It was founded by Henry Ford and incorporated on June 16, 1903. The company sells nautomobiles and commercial vehicles under the Ford brand, and luxury cars under its Lincoln luxury brand. Ford also owns Brazilian SUV manufacturer Troller, an 8% stake in Aston Martin of the United Kingdom and a 32% stake in China's Jiangling Motors. It also has joint ventures in China (Changan Ford), Taiwan (Ford Lio Ho), Thailand (AutoAlliance Thailand), Turkey (Ford Otosan), and Russia (Ford Sollers).\n",
	.model = "Fiesta",
	.modelDetails = "\n\tThe Ford Fiesta has 1 Diesel Engine and 1 Petrol Engine on offer. The Diesel engine is 1498 cc while the Petrol engine is 1499 cc . It is available with Manual transmission.Depending upon the variant and fuel type the Fiesta has a mileage of 17.0 to 25.01 kmpl & Ground clearance of Fiesta is 153mm. The Fiesta is a 5 seater 4 cylinder car and has length of 4320mm, width of 1764mm and a wheelbase of 2489mm.\n",
	.pricePerDay = 60.0f,
	.isRentedCount = 0u
};
BrandDetails Brand4 = {
	.brand = "TOYOTA",
	.brandDetails = "\n\tToyota Motor Corporation (commonly known as simply Toyota) is a Japanese multinational automotive manufacturer headquartered in Toyota City, Aichi, Japan. It was founded by Kiichiro Toyoda and incorporated on August 28, 1937. Toyota is one of the largest automobile manufacturers in the world, producing about 10 million vehicles per year. As of 2009, Toyota officially lists approximately 70 different models sold under its namesake brand, including sedans, coupes, vans, trucks, hybrids, and crossovers. Many of these models are produced as passenger sedans, which range from the subcompact Toyota Yaris, compact Corolla, to mid-size Camry and full-size Avalon. Minivans include the Innova, Alphard/Vellfire, Sienna, and others. Several small cars, such as the xB and tC, were sold under the Scion brand.\n",
	.model = "Yaris",
	.modelDetails = "\n\tThe Toyota Yaris has 1 Petrol Engine on offer. The Petrol engine is 1496 cc. It is available with Manual & Automatic transmission. Depending upon the variant and fuel type the Yaris has a mileage of 17.1 to 17.8 kmpl. The Yaris is a 5 seater 4 cylinder car and has length of 4425mm, width of 1730mm and a wheelbase of 2550mm.\n",
	.pricePerDay = 80.0f,
	.isRentedCount = 0u
};