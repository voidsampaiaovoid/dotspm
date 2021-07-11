/*
*
* Author: Nicolas Sampaio
*
* Github: http://github.com/voidsampaiaovoid
*
*/
#include <iostream>
#include <cstring>
#include <stdlib.h>

#include "Args.hh"

int main(int argc, char* argv[]){
	Args *argvs=new Args();

	if(argc == 1 || strcmp(argv[1], "--help")==0 || strcmp(argv[1], "help")==0 || strcmp(argv[1], "-h")==0){
		argvs->helpArgv();
	}

	if(argc >= 3 && strcmp(argv[1], "--install")==0 || strcmp(argv[1], "install")==0 || strcmp(argv[1], "-i")==0){
		argvs->installArgv(argc, argv);
	}

	if(argc >= 3 && strcmp(argv[1], "--remove")==0 || strcmp(argv[1], "remove")==0 || strcmp(argv[1], "-r")==0){
		argvs->removeArgv(argc, argv);
	}

	if(argc >= 3 && strcmp(argv[1], "--search")==0 || strcmp(argv[1], "search")==0 || strcmp(argv[1], "-s")==0){
		argvs->searchArgv(argc, argv);
	}

	if(argc >= 3 && strcmp(argv[1], "--just-get")==0 || strcmp(argv[1], "just-get")==0 || strcmp(argv[1], "-JG")==0){
		argvs->justgetArgv(argc, argv);
	}

	if(argc == 2 && strcmp(argv[1], "--list")==0 || strcmp(argv[1], "list")==0 || strcmp(argv[1], "-l")==0){
		argvs->listArgv(argc, argv);
	}

	return 0;
}