#include "Money.h"
#include <iostream>
#include <fstream>
int main() {
	std::ifstream inputFile("File.txt");  // Відкриваємо файл
	int arr[6];  // Масив для збереження чисел
    int index = 0;
    while (inputFile >> arr[index]) {  // Читаємо числа з файлу
        index++;
    }
	inputFile.close();
	money milk={arr[0],(short int)arr[1]};
	money bread={arr[3],(short int)arr[4]};
	int milk_quantity = arr[2];
	int bread_quantity = arr[5];

	//money milk(19, 89);
	//money bread(13, 29);
	//int milk_quantity = 3;
	//int bread_quantity = 1;	
	
	money total = (milk.multiply(milk_quantity)).add(bread.multiply(bread_quantity));

	// Тут виводимо підсумкову суму та округлену суму
	std::cout << "Zagalnya suma do oplati: "; total.print();
	total.round();
	std::cout << "Suma do oplati: "; total.print();

	return 0;
}