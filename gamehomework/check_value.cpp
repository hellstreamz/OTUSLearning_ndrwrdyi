#include <iostream>

int val_check(int target_value) {

	 //const int target_value = 54; 
	int my_value = 0;
	bool not_win = true;
	int trycount=0;   //количество попыток угадывания

	std::cout << "Enter your guess:" << std::endl;

	do {
		std::cin >> my_value;
		trycount=trycount+1;
		if (my_value < target_value) {
			std::cout << "greater than " << my_value << std::endl; //неправильно less ,нужно greater
		}
		else if (my_value > target_value) {
			std::cout << "less than " << my_value << std::endl;        //неправильно пишется greater по факту 
			// тут less
		}
		else {
			std::cout << "you win!" << std::endl;
			break;
		}

	} while(true);

	return trycount;  //забираем обратно количество попыток угадать число
}