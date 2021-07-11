#ifndef LOADING_H
#define LOADING_H

void loading(void){
	std::cout << '-' << std::flush;
    for(int i = 0; i <= 5; i++){
        usleep(9000);
        std::cout << "\b\\" << std::flush;
        usleep(9000);
        std::cout << "\b|" << std::flush;
        usleep(9000);
        std::cout << "\b/" << std::flush;
        usleep(9000);
    	std::cout << "\b-" << std::flush;
    }
}

#endif