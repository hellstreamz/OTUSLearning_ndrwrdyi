#include <iostream>

#include <cstdlib>
#include <ctime>

int random_val(int max_value) {
     //в мейне проверку если не выбран уровень/макс значение- сделать проверку и ввести стандартный макс-100
	 //через мейн
	/// const int max_value = 100; непонятно зачем,нигде не используется

	std::srand(std::time(nullptr)); // use current time as seed for random generator

	const int random_value = std::rand() % max_value;

	// std::cout << random_value << std::endl; вывод рандомного числа в консольку

	return random_value;  //забираем обратно случайное число
}