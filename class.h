#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <nlohmann/json.hpp>
#include <ctime>
class class_calc {
public:
	//функция калькулятора
	void calculator(float a, float b, char c) {

		std::cout << "number 1: ";
		std::cin >> a;

		while (true) {
			std::cout << "sign: ";
			std::cin >> c;
			if (c == '=') {
				break;
			}



			std::cout << "number 2: ";
			std::cin >> b;

			if (c == '-') {
				a -= b;

			}
			else if (b == 0 and c == '/') {
				throw 67;

			}
			else if (c == '+') {
				a += b;

			}
			else if (c == '*') {
				a *= b;



			}
			else if (c == '/') {
				a /= b;
			}
	

			else {
				std::cout << "error operation!";
			}


		}
		std::cout << a << std::endl;
	}
};


class wsl_kommand {
public:
	void print_cin(std::string a) {
		system(a.c_str());
	}

};
class Car {
public:
	float speed{ 0.0f };
	std::string color{ "0" };
	int places{ 0 };
	void input_info() {
		std::cout << "I need info for you (1 - speed, 2 - places, 3 color): ";
		std::cin >> speed >> places >> color;
		if (color == "0") {
			std::cout << "you lose!" << std::endl;
		}
		else if (speed == 0) {
			std::cout << "you lose!" << std::endl;
		}
		else if (places == 0) {
			std::cout << "you lose!" << std::endl;
		}
		else {
			std::cout << "Good! you are registen!" << std::endl;
		}
	}
	void print_info() {
		if (color == "0" or speed == 0 or places == 0) {
			std::cout << "Error output!" << std::endl;
		}
		else {
			std::cout << "speed: " << speed << std::endl << "places: " << places << std::endl << "color: " << color << std::endl;
		}
	}
	void legend_function() {
		int per_1;
		while (true) {
			std::cout << "enter 1 for registration, 2 for results output, 3 for exit:  ";
			std::cin >> per_1;
			if (per_1 == 1) {
				input_info();
			}
			else if (per_1 == 2) {
				print_info();
			}
			else if (per_1 == 3) {
				std::cout << "exiting.........." << std::endl;
				std::cin.ignore();
				break;
			}
		}

	}
};

class Ork {
public:
	float hp{ 0 };
	float attack{ 0 };
	bool is_reg{ false };
	std::string classes{ "None" };
	int cin_v{ 0 };
	int  cin_1s{ 0 };
	void info_cin() {
		std::cout << "Enter hp: ";
		std::cin >> hp;

		std::cout << "Enter attack: ";
		std::cin >> attack;
		std::cout << "Enter classes: ";
		std::cin >> classes;
		if (hp == 0 or attack == 0 or classes == "None") {
			std::cout << "error reg" << std::endl;
			is_reg = false;
		}

		else if (hp > 100) {
			std::cout << "error reg";
			is_reg = false;

		}
		else {
			is_reg = true;
			std::cout << "good!" << std::endl;
		}
	}
	void print_info() {
		if (is_reg == false) {
			std::cout << "error" << std::endl;
			legend();

		}
		while (true) {
			std::cout << "1 for exit 2 for hp 3 for attack 4 for classes 5 for all: ";
			std::cin >> cin_v;
			if (cin_v == 1) {
				std::cout << "exit.............." << std::endl;
				break;
			}
			else if (cin_v == 2) {
				std::cout << hp << std::endl;

			}

			else if (cin_v == 3) {
				std::cout << attack << std::endl;

			}
			else if (cin_v == 4) {
				std::cout << classes << std::endl;

			}
			else if (cin_v == 5) {
				std::cout << hp << std::endl;
				std::cout << attack << std::endl;
				std::cout << classes << std::endl;
			}

		}

	}


	void legend() {
		while (true)
		{
			std::cout << "available functions: 1 - information output, 2 - registration (without it it is impossible to output information), 3 for exit: ";
			std::cin >> cin_1s;
			if (cin_1s == 1) {
				print_info();
			}
			else if (cin_1s == 2) {
				info_cin();

			}
			else if (cin_1s == 3) {
				break;
			}
		} 
	}

};





class minirast {
	// Инициализация генератора случайных чисел
	

	// Переменная с случайным числом от 1 до 3
	int rand = std::rand() % 3 + 1;

	int hp{0};
	std::string name;

	void prov() {
		if (hp == 0) {
			std::cout << "you lose!";
		}

	}


};


class user {
public:
	std::string name;
	std::string Repeat_password;
	std::string passwd;
	bool reg = false;
	void load_json() {
		std::ifstream user_info("user_info.json");
		if (user_info.is_open()) {
			nlohmann::json data = nlohmann::json::parse(user_info);
			std::string nam, pas;
			name = data["name"];
			passwd = data["passwd"];
			reg = true;

			
		}

		else if (reg == false) {

			registr();
		}
	

	}
	void registr() {
		std::cout << "Enter you name: ";
		std::cin >> name;
		std::cout << "Enter passwd: ";
		std::cin >> passwd;
		nlohmann::json user_json {
			{"passwd", passwd},
			{"name", name},
		
		
		};
		reg = true;
		std::ofstream outn("user_info.json");
		outn << user_json;
		
		outn.close();
		std::cin.ignore();

	}

	

};
