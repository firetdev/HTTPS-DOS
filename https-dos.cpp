#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <filesystem>
#include "httplib.h"

std::string randomString() {
	std::string charList = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890";
	std::srand(std::time(NULL));
	std::string str;
        for(int e = 0; e < 10; e++) {
		str += charList[rand() % 50 + 1];
	}
	return str;
}

int main() {
	std::string url, sub;
	int times, num;
	std::cout << "URL: ";
	std::cin >> url;
	std::cout << "Sub: ";
	std::cin >> sub;
	std::cout << "Times: ";
	std::cin >> times;
	if(!std::filesystem::exists("params.txt")) {
		std::cout << "Number of random params: ";
	        std::cin >> num;
	}
	double myTime = static_cast<double>(std::time(0));
	httplib::Client cli(url);
	cli.set_connection_timeout(1, 1);
	for(int i = 0; i < times; i++) {
		httplib::Params params;
		if(!std::filesystem::exists("params.txt")) {
        		std::srand(std::time(NULL));
        		for(int u = 0; u < num; u++) {
                		params.emplace(randomString(), randomString());
        		}
		} else {
			std::string line;
			std::ifstream file("params.txt");
			while(getline(file, line)) {
				std::string str1, str2;
				bool is = false;
				for(int f = 0; f < line.length(); f++) {
					if(line[f] == *"$") {
						line.erase(f, 1);
						line.insert(f, randomString());
						continue;
					}
					if(line[f] != *":") {
						if(!is) {
							str1 += line[f];
						} else {
							str2 += line[f];
						}
					} else {
						is = true;
					}
				}
				params.emplace(str1, str2);
			}
			file.close();
		}
		auto res = cli.Post(sub, params);
		std::cout << "Request number " << i + 1 << " sent, time: " << static_cast<double>(std::time(0)) - myTime << std::endl;
	}
	std::cout << times << " requests sent. Time: " << static_cast<double>(std::time(0)) - myTime << std::endl;
	return 0;
}
