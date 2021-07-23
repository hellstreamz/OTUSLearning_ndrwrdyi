
//#include "random_value.h" РАЗККОМЕНТИТЬ ЕСЛИ СБОРКА ИДЕТ БЕК CMAKE 
//#include "check_value.h" РАЗККОМЕНТИТЬ ЕСЛИ СБОРКА ИДЕТ БЕК CMAKE 
//#include "high_scores.h" РАЗККОМЕНТИТЬ ЕСЛИ СБОРКА ИДЕТ БЕК CMAKE 
#include "check_value.cpp"
#include "high_scores.cpp"
#include "random_value.cpp"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    int guess_value=0;
	int trycounts=0;
	bool table=false;
	// argc - it is a count of arguments
	// But there is some detail - OS always pass one system argument - the name of the executable
	// So, is the application was executed without arguments at all, argc will be still == 1

	// Let's print this argument 
	//argc = всегда как минимум равен 1
	if (argc ==1 ){
		int level;
		int standart_value;
		std::cout << "Game started without parameters" << std::endl;
		std::cout << "Please select your level" << std::endl;
		std::cout << "enter 1 to guess numbers from 0 to 9" << std::endl;
		std::cout << "enter 2 to guess numbers from 0 to 49" << std::endl;
		std::cout << "enter 3 to guess numbers from 0 to 99" << std::endl;
		std::cout << "OVERHARDCORE LEVEL enter 4 to guess numbers from 0 to 999" << std::endl;
		std::cin>>level ;
		if (level==1){
			standart_value=10;
		}
		if (level==2){
			standart_value=50;
		}
		if (level==3){
			standart_value=100;
		}
		if (level==4){
			standart_value=1000;
		}
		
	    guess_value=random_val(standart_value);
	    trycounts=val_check(guess_value);
		main_high(trycounts,table); 
    	//  std::cout << "argv[0] = " << argv[0] << std::endl;  // вывод приложения.exe/путя к нему 
	}

	// To check - does use print some other argument we should check if the argc >= 2
	if (argc >= 2) {
		//std::cout << "We have one more argument!" << std::endl;
		//std::cout << "argv[1] = " << argv[1] << std::endl;
      
		std::string arg1_value{ argv[1] };  //сняли сам аргумент
		if(arg1_value== "-table"){
			table=true;
			main_high(trycounts,table);
		}
		if (arg1_value == "-max") {
			//std::cout << "-max argument was detected!" << std::endl;

			// We've detected the '-max' argument. And we extect that after this argument there is a value:
			int parameter_value = 0;
			if (argc < 3) {
				std::cout << "Wrong usage! The argument '-max' requires some value!" << std::endl;
				return -1;
			}
			// We need to parse the string to the int value
			std::cout<<" "<< std::endl;
			parameter_value = std::stoi(argv[2]); //сняли значение аргумента. видимо эта функция еще
			// делает вывод как cout хотя если до этого вывести в cout пробел и после пробел то не отображает
			// этот параметр :/
			std::cout<<" "<< std::endl;
			guess_value=random_val(parameter_value);  //рандомное число исходя из указанного максимума
			trycounts=val_check(guess_value);    ///угадываем число+получаем в ответ кол-во попыток
			main_high(trycounts,table);   /// запись в табло рекордов
			// std::cout << "The '-max' value = " << parameter_value << std::endl;
		}
	}

	return 0;

}