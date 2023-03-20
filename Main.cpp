#include <iostream>
#include <cstdlib>
#include <ctime>

void arr_add(int*& arr, int length, int num) {
	if (num <= 0)
		return;
	int* tmp = new int[length + num] {};
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = tmp;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Динамические переменные
	/*int* pointer = new int;	// Выделение динамической памяти размером 4 байта
	*pointer = 7;	// Запись значения в выделенную область памяти
	std::cout << "*pointer = " << *pointer << '\n';

	delete pointer;	// Освобождение выделенной памяти

	//*pointer = 100;	// ОШИБКА! Необходимо выполнить заново операцию выделения памяти

	pointer = new int;
	*pointer = 15;
	std::cout << "*pointer = " << *pointer << '\n';

	delete pointer;	// Освобождение выделенной памяти в конце программы - необязательно, но желательно*/

	// Динамические массивы
	/*int d_size;
	std::cout << "Введите длину массива -> ";
	std::cin >> d_size;
	int* d_arr = new int[d_size];

	std::cout << "Ввод данных в массив:\n";
	for (int i = 0; i < d_size; i++) {
		std::cout << "Введите " << i + 1 << "-й элемент -> ";
		std::cin >> d_arr[i];
	}
	std::cout << "Получившийся массив:\n[";
	for (int i = 0; i < d_size; i++)
		std::cout << d_arr[i] << ", ";
	std::cout << "\b\b]\n";

	delete[] d_arr;*/

	// Двумерные динамические массивы
	/*int rows, cols;
	std::cout << "Введите высоту массива ->";
	std::cin >> rows;
	std::cout << "Введите ширинуу массива ->";
	std::cin >> cols;
	//int* mx = new int[rows][cols];	// ОШИБКА!
	
	// Выделение памяти
	int** mx = new int* [rows];	// Выделяем память под массив указателей, каждый из к-рых указывает на нулевой элемент каждого ряда
	for (int i = 0; i < rows; i++)
		mx[i] = new int[cols];

	// Использование массива (так же, как и с обычным)
	mx[0][0];

	// Освобождение памяти
	for (int i = 0; i < rows; i++)	// Удаляем в обратном порядке
		delete[] mx[i];
	delete[] mx;*/


	// Задача 1. Увеличение размера массива
	std::cout << "Задача 1. \nВведите размер массива -> ";
	int size1;
	std::cin >> size1;
	int* arr1 = new int[size1];
	srand(time(NULL));
	std::cout << "Изначальный массив:\n";
	for (int i = 0; i < size1; i++) {
		arr1[i] = rand() % 10 + 1;	// [1..10]
		std::cout << arr1[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << "Введите кол-во дополнительных элементов -> ";
	std::cin >> n;
	arr_add(arr1, size1, n);
	size1 += n;
	std::cout << "Иттоговый массив:\n";
	for (int i = 0; i < size1; i++)
		std::cout << arr1[i] << ' ';
	std::cout << std::endl;


	return 0;
}