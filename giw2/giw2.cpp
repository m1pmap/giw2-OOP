//Шаблон “Фабричный метод”. Проект “Фабрика смартфонов”.
//В проекте должно быть реализовано создание смартфонов 
//с различными характеристиками.

#include <iostream>
#include <string>

using namespace std;

class Smartphone
{
public:
	int weight;
	float diagonal;
	int battery;
	int camera;
	bool waterResistance;
	void virtual GetCharacteristics() = 0;

};

class BudjetSmartphone : public Smartphone
{
public:
	BudjetSmartphone()
	{
		weight = rand() % 60 + 160;  //160 - 220g
		diagonal = 5.5 + rand() % 7 / 10.;  //5.5 - 6.2d
		battery = 1800 + rand() % 12 * 100;  //1800 - 3000mAh
		camera = 18 + rand() % 18;  //18 - 32Mpx  
		waterResistance = rand() % 2;
	}
	void GetCharacteristics() override
	{
		cout << "Budjet smartphone characteristics: "
			<< "\nWeight: " << weight << "g"
			<< "\nDiagonal: " << diagonal << "d"
			<< "\nBattery: " << battery << "mAh"
			<< "\nCamera: " << camera << "Mpx"
			<< "\nWater resistance: ";
		if (waterResistance) { cout << "yes"; }
		else cout << "no";
	}
};

class ImageSmartphone : public Smartphone
{
public:
	ImageSmartphone()
	{
		weight = 120 + rand() % 60;  //120 - 180g
		diagonal = 5 + (rand() % 7 / 10.);  //5.0 - 5.7d
		battery = 2200 + rand() % 23 * 100;  //2200 - 4500mAh
		camera = 25 + rand() % 15;  //25 - 40Mpx
		waterResistance = rand() % 2;
	}
	void GetCharacteristics() override
	{
		cout << "Image smartphone characteristics: "
			<< "\nWeight: " << weight << "g"
			<< "\nDiagonal: " << diagonal << "d"
			<< "\nBattery: " << battery << "mAh"
			<< "\nCamera: " << camera << "Mpx"
			<< "\nWater resistance: ";
		if (waterResistance) { cout << "yes"; }
		else cout << "no";
	}
};

class FlagmanSmartphone : public Smartphone
{
public:
	FlagmanSmartphone()
	{
		weight = 100 + rand() % 90; //100 - 190g
		diagonal = 5 + rand() % 2 + (rand() % 10 / 10.); //5.0 - 7.0d
		battery = 4000 + rand() % 20 * 100; //4000 - 8000mAh
		camera = 50 + rand() % 20; //50 - 70Mpx
		waterResistance = true;
	}
	void GetCharacteristics() override
	{
		cout << "Flagman smartphone characteristics: "
			<< "\nWeight: " << weight << "g"
			<< "\nDiagonal: " << diagonal << "d"
			<< "\nBattery: " << battery << "mAh"
			<< "\nCamera: " << camera << "Mpx"
			<< "\nWater resistance: ";
		if (waterResistance) { cout << "yes"; }
		else cout << "no";
	}
};

class BusinessSmartphone : public Smartphone
{
public:
	BusinessSmartphone()
	{
		weight = 100 + rand() % 90;  //100 - 190g
		diagonal = 5 + rand() % 3 + (rand() % 10 / 10.);  //5.0 - 8.0d
		battery = 5000 + rand() % 50 * 100;  //5000 - 10000mAh
		camera = 40 + rand() % 20;  //40 - 60Mpx
		waterResistance = true;
	}
	void GetCharacteristics() override
	{
		cout << "Business smartphone characteristics: "
			<< "\nWeight: " << weight << "g"
			<< "\nDiagonal: " << diagonal << "d"
			<< "\nBattery: " << battery << "mAh"
			<< "\nCamera: " << camera << "Mpx"
			<< "\nWater resistance: ";
		if (waterResistance) { cout << "yes"; }
		else cout << "no";
	}
};



class Smartphonefactory
{
public:
	Smartphone* CreateSmartphone(string type)
	{
		if (type == "budjet")
		{
			return new BudjetSmartphone;
		}
		else
			if (type == "image")
			{
				return new ImageSmartphone;
			}
			else
				if (type == "flagman")
				{
					return new FlagmanSmartphone;
				}
				else
					if (type == "business")
					{
						return new BusinessSmartphone;
					}
					else
						return nullptr;
	}
};


int main()
{
	srand(time(0));

	Smartphonefactory factory;

	Smartphone* budjetPhone = factory.CreateSmartphone("budjet");
	Smartphone* imagePhone = factory.CreateSmartphone("image");
	Smartphone* flagmanPhone = factory.CreateSmartphone("flagman");
	Smartphone* businessPhone = factory.CreateSmartphone("business");

	budjetPhone->GetCharacteristics(); cout << "\n\n";
	imagePhone->GetCharacteristics(); cout << "\n\n";
	flagmanPhone->GetCharacteristics(); cout << "\n\n";
	businessPhone->GetCharacteristics();
}