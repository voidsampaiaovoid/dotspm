/*
*
* Author: Nicolas Sampaio
*
* Github: http://github.com/voidsampaiaovoid
*
*/
#ifndef ARGS_HH
#define ARGS_HH

#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "pugixml.hpp"
#include "loading.h"
#include "table.hh"

class Args{
public:
	void helpArgv();
	void installArgv(int aargc, char* aargv[]);
	void removeArgv(int aargc, char* aargv[]);
	void searchArgv(int aargc, char* aargv[]);
	void justgetArgv(int aargc, char* aargv[]);
	void listArgv(int aargc, char* aargv[]);
};

void Args::helpArgv(){
	std::cout << "dotspm: A package-manager like for Dotfiles" << std::endl;
	std::cout << "Usage:" << std::endl;
	std::cout << "	dotspm [ parameter ] [ name ]" << std::endl;
	std::cout << "Parameters:" << std::endl;
	std::cout << "	[ --help ]  [ --install ]" << std::endl;
	std::cout << "	[ --remove ]  [ --search ]" << std::endl;
	std::cout << "	[ --list ]  [ --just-get ]" << std::endl;
}

void Args::installArgv(int aargc, char* aargv[]){
	std::string pkgurl;
	std::string pkgdir;
	std::string pkgcommand;
	std::string pkgremove;
	std::string pkgcomment;
	pugi::xml_document doc;
    std::string namePanel;

    if(!doc.load_file("repo.xml")){
    	std::cout << "Error file \"repo.xml\" not found" << std::endl;
    	return;
    }

    for(int i = 2; i <= aargc-1; i++){
    	pugi::xml_node panels = doc.child("repo");

       	bool notfound[aargc-1];
    	bool found[aargc-1];

    	for(pugi::xml_node panel = panels.first_child(); panel; panel = panel.next_sibling()){
        	for(pugi::xml_attribute attr = panel.first_attribute(); attr; attr = attr.next_attribute()){
            	if(strcmp(attr.name(), "name") && strcmp(attr.value(), aargv[i])){
            		notfound[i] = true;
            	}else if(strcmp(attr.name(), "name")==0 && strcmp(attr.value(), aargv[i])==0){
            		found[i] = true;
            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "url")==0){
            			pkgurl = attr.value();
            		}

            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "dir")==0){
            			pkgdir = attr.value();
            		}

            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "command")==0){
            			pkgcommand = attr.value();
            		}

            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "remove")==0){
            			pkgremove = attr.value();
            		}

            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "comment")==0){
            			pkgcomment = attr.value();
            		}
            	}

            	std::string attrName = attr.name();
            	if(!attrName.compare("name")){
                	namePanel = attr.value();
            	}
        	}
    	}

    	for(int j = 2; j <= aargc-1; j++){	
    		if(found[j] == true){
    			std::cout << "Checking if the \"" << aargv[j] << "\" dotfiles is available in the repository ";
    			loading();
    			loading();
    			std::cout << " Done!\n";
    			std::cout << "\"" << aargv[j] << "\" Has been found in repo!" << std::endl; 
    			std::cout << "Getting from \"" << pkgurl << "\"\n";
    			system(("sh install.sh "+pkgurl+" "+pkgdir+" "+pkgcommand+" ").c_str());
    		}

    		if(notfound[j] == true && found[j] != 1){
    			std::cout << "Checking if the \"" << aargv[j] << "\" dotfiles is available in the repository ";
    			loading();
    			loading();
    			std::cout << "\n";
    			std::cout << "Dotfiles \"" << aargv[i] << "\" has not found in repo" << std::endl;	
    		}
    	}
	}
}

void Args::removeArgv(int aargc, char* aargv[]){
	std::string pkgurl;
	std::string pkgdir;
	std::string pkgcommand;
	std::string pkgremove;
	std::string pkgcomment;
	pugi::xml_document doc;
    std::string namePanel;

    if(!doc.load_file("repo.xml")){
    	std::cout << "Error file \"repo.xml\" not found" << std::endl;
    	return;
    }

    for(int i = 2; i <= aargc-1; i++){
    	pugi::xml_node panels = doc.child("repo");

       	bool notfound[aargc-1];
    	bool found[aargc-1];

    	for(pugi::xml_node panel = panels.first_child(); panel; panel = panel.next_sibling()){
        	for(pugi::xml_attribute attr = panel.first_attribute(); attr; attr = attr.next_attribute()){
            	if(strcmp(attr.name(), "name") && strcmp(attr.value(), aargv[i])){
            		notfound[i] = true;
            	}else if(strcmp(attr.name(), "name")==0 && strcmp(attr.value(), aargv[i])==0){
            		found[i] = true;
            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "url")==0){
            			pkgurl = attr.value();
            		}

            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "dir")==0){
            			pkgdir = attr.value();
            		}

            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "command")==0){
            			pkgcommand = attr.value();
            		}

            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "remove")==0){
            			pkgremove = attr.value();
            		}

            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "comment")==0){
            			pkgcomment = attr.value();
            		}
            	}

            	std::string attrName = attr.name();
            	if(!attrName.compare("name")){
                	namePanel = attr.value();
            	}
        	}
    	}

    	for(int j = 2; j <= aargc-1; j++){	
    		if(found[j] == true){
    			std::cout << "Checking if the \"" << aargv[j] << "\" package is available in the repository ";
    			loading();
    			loading();
    			std::cout << " Done!\n";
    			std::cout << "\"" << aargv[j] << "\" Has been found in repo!" << std::endl; 
    			std::cout << "Preparing to remove \"" << aargv[j] << "\" package\n";
    			system(("sh remove.sh "+pkgurl+" "+pkgdir+" "+pkgremove+" ").c_str());
    		}

    		if(notfound[j] == true && found[j] != 1){
    			std::cout << "Checking if the \"" << aargv[j] << "\" package is available in the repository ";
    			loading();
    			loading();
    			std::cout << "\n";
    			std::cout << "Package \"" << aargv[i] << "\" has not found in repo" << std::endl;	
    		}
    	}
	}	
}

void Args::searchArgv(int aargc, char* aargv[]){
	std::string pkgname;
	std::string pkgurl;
	std::string pkgdir;
	std::string pkgcommand;
	std::string pkgremove;
	std::string pkgcomment;
	std::string pkgversion;
	pugi::xml_document doc;
    std::string namePanel;

    if(!doc.load_file("repo.xml")){
    	std::cout << "Error file \"repo.xml\" not found" << std::endl;
    	return;
    }

    for(int i = 2; i <= aargc-1; i++){
    	pugi::xml_node panels = doc.child("repo");

       	bool notfound[aargc-1];
    	bool found[aargc-1];

    	for(pugi::xml_node panel = panels.first_child(); panel; panel = panel.next_sibling()){
        	for(pugi::xml_attribute attr = panel.first_attribute(); attr; attr = attr.next_attribute()){
            	if(strcmp(attr.name(), "name") && strcmp(attr.value(), aargv[i])){
            		notfound[i] = true;
            	}else if(strcmp(attr.name(), "name")==0 && strcmp(attr.value(), aargv[i])==0){
            		found[i] = true;
            		pkgname = attr.value();
            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "url")==0){
            			pkgurl = attr.value();
            		}

            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "dir")==0){
            			pkgdir = attr.value();
            		}

            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "command")==0){
            			pkgcommand = attr.value();
            		}

            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "remove")==0){
            			pkgremove = attr.value();
            		}

            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "comment")==0){
            			pkgcomment = attr.value();
            		}

            		attr = attr.next_attribute();
           			if(strcmp(attr.name(), "version")==0){
           				pkgversion = attr.value();
           			}
            	}

            	std::string attrName = attr.name();
            	if(!attrName.compare("name")){
                	namePanel = attr.value();
            	}
        	}
    	}

    	for(int j = 2; j <= aargc-1; j++){	
    		if(found[j] == true){
    			std::cout << "Checking if the \"" << aargv[j] << "\" package is available in the repository ";
    			loading();
    			loading();
    			std::cout << " Done!\n";
    			table(pkgname, pkgcomment, pkgversion);
    		}

    		if(notfound[j] == true && found[j] != 1){
    			std::cout << "Checking if the \"" << aargv[j] << "\" package is available in the repository ";
    			loading();
    			loading();
    			std::cout << "\n";
    			std::cout << "Package \"" << aargv[i] << "\" has not found in repo" << std::endl;	
    		}
    	}
	}
}

void Args::justgetArgv(int aargc, char* aargv[]){
	std::string pkgurl;
	std::string pkgdir;
	std::string pkgcommand;
	std::string pkgremove;
	std::string pkgcomment;
	pugi::xml_document doc;
    std::string namePanel;

    if(!doc.load_file("repo.xml")){
    	std::cout << "Error file \"repo.xml\" not found" << std::endl;
    	return;
    }

    for(int i = 2; i <= aargc-1; i++){
    	pugi::xml_node panels = doc.child("repo");

       	bool notfound[aargc-1];
    	bool found[aargc-1];

    	for(pugi::xml_node panel = panels.first_child(); panel; panel = panel.next_sibling()){
        	for(pugi::xml_attribute attr = panel.first_attribute(); attr; attr = attr.next_attribute()){
            	if(strcmp(attr.name(), "name") && strcmp(attr.value(), aargv[i])){
            		notfound[i] = true;
            	}else if(strcmp(attr.name(), "name")==0 && strcmp(attr.value(), aargv[i])==0){
            		found[i] = true;
            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "url")==0){
            			pkgurl = attr.value();
            		}

            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "dir")==0){
            			pkgdir = attr.value();
            		}

            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "command")==0){
            			pkgcommand = attr.value();
            		}

            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "remove")==0){
            			pkgremove = attr.value();
            		}

            		attr = attr.next_attribute();
            		if(strcmp(attr.name(), "comment")==0){
            			pkgcomment = attr.value();
            		}
            	}

            	std::string attrName = attr.name();
            	if(!attrName.compare("name")){
                	namePanel = attr.value();
            	}
        	}
    	}

    	for(int j = 2; j <= aargc-1; j++){
    		if(found[j] == true){
    			std::cout << "Checking if the \"" << aargv[j] << "\" package is available in the repository ";
    			loading();
    			loading();
    			std::cout << " Done!\n";
    			std::cout << "\"" << aargv[j] << "\" Has been found in repo!" << std::endl; 
    			std::cout << "Getting from \"" << pkgurl << "\"\n";
    			system(("sh justget.sh "+pkgurl+" "+pkgdir+" ").c_str());
    		}

    		if(notfound[j] == true && found[j] != 1){
    			std::cout << "Checking if the \"" << aargv[j] << "\" dotfiles is available in the repository ";
    			loading();
    			loading();
    			std::cout << "\n";
    			std::cout << "Dotfiles \"" << aargv[i] << "\" has not found in repo" << std::endl;	
    		}
    	}
	}
}

void Args::listArgv(int aargc, char* aargv[]){
	std::string pkgname;
	std::string pkgurl;
	std::string pkgdir;
	std::string pkgcommand;
	std::string pkgremove;
	std::string pkgcomment;
	std::string pkgversion;
	pugi::xml_document doc;
    std::string namePanel;

    if(!doc.load_file("repo.xml")){
    	std::cout << "Error file \"repo.xml\" not found" << std::endl;
    	return;
    }

   	pugi::xml_node panels = doc.child("repo");

    for(pugi::xml_node panel = panels.first_child(); panel; panel = panel.next_sibling()){
       	for(pugi::xml_attribute attr = panel.first_attribute(); attr; attr = attr.next_attribute()){
           	if(strcmp(attr.name(), "name")==0){
           		pkgname = attr.value();

           		attr = attr.next_attribute();
           		if(strcmp(attr.name(), "url")==0){
           			pkgurl = attr.value();
           		}

           		attr = attr.next_attribute();
           		if(strcmp(attr.name(), "dir")==0){
           			pkgdir = attr.value();
           		}

           		attr = attr.next_attribute();
           		if(strcmp(attr.name(), "command")==0){
           			pkgcommand = attr.value();
           		}

           		attr = attr.next_attribute();
           		if(strcmp(attr.name(), "remove")==0){
           			pkgremove = attr.value();
           		}

           		attr = attr.next_attribute();
           		if(strcmp(attr.name(), "comment")==0){
           			pkgcomment = attr.value();
           		}

           		attr = attr.next_attribute();
           		if(strcmp(attr.name(), "version")==0){
           			pkgversion = attr.value();
           		}

           		table(pkgname, pkgcomment, pkgversion);
           	}

           	std::string attrName = attr.name();
           	if(!attrName.compare("name")){
               	namePanel = attr.value();
           	}
       	}
	}
}

#endif
