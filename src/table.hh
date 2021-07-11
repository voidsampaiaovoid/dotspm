#ifndef TABLE_HH
#define TABLE_HH

#include <iostream>

void table(std::string strname, std::string strcomment, std::string strversion){
	for(int i = 1; i <= 1; i++){
		std::cout << "┌─";
		for(int j = 1; j <= strname.length(); j++){
			std::cout << "─";
		}
		std::cout << "─┬─";
		for(int m = 1; m <= strcomment.length(); m++){
			std::cout << "─";
		}
		std::cout << "─┬─";
		for(int n = 1; n <= strversion.length(); n++){
			std::cout << "─";
		}
		std::cout << "─┐" << "\n";
		std::cout << "│ ";
		std::cout << strname;
		std::cout << " │ ";
		std::cout << strcomment;
		std::cout << " │ ";
		std::cout << strversion;  
		std::cout << " │" << "\n";
		std::cout << "└─";
		for(int k = 1; k <= strname.length(); k++){
			std::cout << "─";
		}
		std::cout << "─┴─";
		for(int l = 1; l <= strcomment.length(); l++){
			std::cout << "─";
		}
		std::cout << "─┴─";
		for(int o = 1; o <= strversion.length(); o++){
			std::cout << "─";
		}
		std::cout << "─┘" << "\n";
	}
}

#endif