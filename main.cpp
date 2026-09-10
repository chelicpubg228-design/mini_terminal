#include <iostream>
#include <string>
#include <fstream>
#include "class.h"

//переменные================================================================================
std::string text_hi = R"(
Hello! This terminal was created for automation and convenience.
For help, type help
There you will find instructions for the terminal.
Creator's Telegram: @GGCHELIC
GitHub: 
Some commands are still under development.
Good luck!


)";
float result;
std::string requirements_text = R"(
================================================================
   SYSTEM REQUIREMENTS
================================================================

  OS: Windows 11

  NATIVE (Windows side)
  -- WSL2                subsystem for Linux
  -- MSYS2               provides g++ compiler
  -- dotnet SDK           for "dotnet" command
  -- fastfetch            system info tool

  INSIDE WSL2
  -- cacafire             ASCII fire animation
  -- cmatrix              Matrix digital rain
  -- sl                   steam locomotive animation
  -- vitetris             terminal Tetris
  -- tty-clock            animated clock ("time")
  -- cbonsai              growing tree animation ("tree")
  -- ninvaders            space shooter ("astro_play")
  -- telnet               ASCII world map ("map")
  -- maigret (venv)       OSINT username search
  -- sherlock (venv)      OSINT username search
  -- phoneosint (venv)    OSINT phone number search

  OPTIONAL INTERPRETERS
  -- python
  -- node.js
  -- lua

----------------------------------------------------------------
NOTE:
  Commands marked [needs: ...] in "help" will fail
  if the corresponding requirement above is missing.
  venv-based OSINT tools expect the path:
  /home/CHELIC/phoneosint/venv/bin/

----------------------------------------------------------------
			SYSTEM REQUIREMENTS
----------------------------------------------------------------
)";
std::string help_text = R"(
================================================================
					help
================================================================

[ BASIC ]
  help          show this manual                    [native]
  clear         clear the screen                     [native]
  pwd           show current directory path          [native]
  req           show requirements & dependencies      [native]
  exit          quit the terminal                    [native]
  start         start program (need name)			 [native]
  echo          repeating a written word			 [native]

[ FILESYSTEM ]
  ls            scan a folder (full path required)   [native]
  read          read a file (full path required)     [native]
  creat         create a file, type "end" to finish  [native]
  vim           open vim editor (F2: tree, F4: term) [needs: wsl]
  vim_new       create/open a new file in vim         [needs: wsl]

[ OSINT ]
  m             Maigret - search username (soc. nets) [needs: wsl+venv]
  sh            Sherlock - search username (300+ sites)[needs: wsl+venv]
  p             PhoneOSINT - search by phone number    [needs: wsl+venv]

[ FUN ]
  fastfetch     show system info                      [needs: wsl]
  cacafire      ASCII fire animation                   [needs: wsl]
  cmatrix       Matrix digital rain                     [needs: wsl]
  sl            steam locomotive animation             [needs: wsl]
  tetris        Tetris in terminal                      [needs: wsl]
  time          animated clock                          [needs: wsl]
  tree          growing bonsai tree animation           [needs: wsl]
  astro_play    mini space shooter (ninvaders)          [needs: wsl]
  map           ASCII world map (telnet mapscii.me)     [needs: wsl]
  date          show current date & time                [needs: wsl]

[ DEV ]
  g++           compile with MSYS2 (enter flags/file)  [needs: msys2]
  dotnet        run/build with dotnet (enter flags)     [needs: dotnet]
  python        launch Python interpreter               [needs: python]
  nod           launch Node.js shell                     [needs: node]
  lua           launch Lua interpreter                   [needs: lua]
  calc          simple calculator (+ - * /)              [native]

[ TRAINING GROUND ]
  trn           OOP practice: choose class (Ork / Car)  [native]

----------------------------------------------------------------
USAGE EXAMPLES:
  $ help              show this guide
  $ m                 -> enter username -> run Maigret
  $ g++               -> enter "main.cpp -o main"
  $ cmatrix           run Matrix effect (Ctrl+C to exit)

NOTES:
  * [native]      - works without extra setup
  * [needs: wsl]  - requires WSL2 installed
  * [needs: X]    - requires X installed (see "req")
  * OSINT tools use full venv paths automatically
  * Interactive programs: exit with Ctrl+C

----------------------------------------------------------------
					help
----------------------------------------------------------------
)";
std::string glav_cin, g_compiller, clo, dotnet_texr, dotnet_texr_h, maigret_name, maigret_name_plus, sherlock_name, sherlock_name_i, pho, pho_p, ls_pit, ls_pit_p;
float cin_num1, cim_num2;
char znak_for_calc;
std::string print(std::string word);
int print(int word);
std::string i(std::string syu);

std::string i_wsl(std::string syu, std::string sui);
int kom2;
std::string start_pr;
std::string eho_cin;
std::string sim_g;
//переменные================================================================================

//это уже основная функция
int main() {
	

	std::cout << text_hi << std::endl;

	//сообщение - приветсвие
	user uuser;
	uuser.load_json();
	
	sim_g = uuser.name + "~$";

	while (true) {
		//это основной цииикл
		std::cout << sim_g;
		//команда exit для выхода из программы
		std::getline(std::cin, glav_cin);
		if (glav_cin == "exit") {
			break;
		}
		//требования  программы
		else if (glav_cin == "req") {
			std::cout << requirements_text << std::endl;
		}
		//фаст фетч 
		else if (glav_cin == "fastfetch") {
			system("fastfetch");
		}
		//echo
		else if (glav_cin == "echo") {
			std::getline(std::cin, eho_cin);
			std::cout << eho_cin << std::endl;
		}
		//очистка терминала
		else if (glav_cin == "clear") {
			system("clear");
		}
		//дата и время
		else if (glav_cin == "date") {
			system("wsl date");
		}
		//защита от пустых строк и  пробелов
		else if (glav_cin.find_first_not_of(" \t") == std::string::npos) {
			continue;
		}
		//костер 
		else if (glav_cin == "cacafire") {
			system("wsl cacafire");
		}
		//python
		else if (glav_cin == "python") {
			system("python");
		}
		//node.js
		else if (glav_cin == "nod") {
			system("node");
		}
		//lua
		else if (glav_cin == "lua") {
			system("lua");
		}
		// условие калькулятора
		else if (glav_cin == "calc") {
			try {
				class_calc NEW_KLASS;
				NEW_KLASS.calculator(cin_num1, cim_num2, znak_for_calc);
			}
			catch (int err){
				if (err == 67) std::cout << "Error x / 0" << std::endl;
			}
			std::cin.ignore();
		}
		//помощь
		else if (glav_cin == "help") {
			std::cout << help_text << std::endl;
		}
		//матрица
		else if (glav_cin == "cmatrix") {
			system("wsl cmatrix");
		}
		//скан папки
		else if (glav_cin == "ls") {
			std::cout << "Enter the path to scan: " << std::endl;
			std::getline(std::cin, ls_pit);
			ls_pit_p = "ls " + ls_pit;
			system(ls_pit_p.c_str());


		}
		//паравозик
		else if (glav_cin == "sl") {
			system("wsl sl");
		}
		//дерево
		else if (glav_cin == "tree") {
			system("wsl cbonsai --live");
		}
		//маигрет, пробив по нику
		else if (glav_cin == "m") {
			std::cout << "Enter username to search: " << std::endl;
			std::getline(std::cin, maigret_name);
			maigret_name_plus = "wsl maigret " + maigret_name;
			system(maigret_name_plus.c_str());
		}
		//тоже пробив по нику, шерлок

		else if (glav_cin == "sh") {
			std::cout << "Enter username to search: " << std::endl;
			std::getline(std::cin, sherlock_name);
			sherlock_name_i = "wsl sherlock " + sherlock_name;
			system(sherlock_name_i.c_str());

		}
		//пробив по телефону
		else if (glav_cin == "p") {
			std::cout << "Enter phone number to search: " << std::endl;
			std::getline(std::cin, pho);
			pho_p = "wsl phoneosint " + pho;
			system(pho_p.c_str());

		}
		//игра про карабли и космос
		else if (glav_cin == "astro_play") {
			system("wsl ninvaders");
		}
		//компиляция NSYS2
		else if (glav_cin == "g++") {
			std::cout << "Enter flags or file name for MSYS2 compilation: " << std::endl;
			std::getline(std::cin, g_compiller);
			clo = "g++ " + g_compiller;
			system(clo.c_str());

		}
		//dotnet компиляция
		else if (glav_cin == "dotnet") {
			std::cout << "Enter flags or file name for dotnet compilation: " << std::endl;
			std::getline(std::cin, dotnet_texr);
			dotnet_texr_h = "dotnet " + dotnet_texr;
			system(dotnet_texr_h.c_str());
		}
		//запуск программы
		else if (glav_cin == "start") {
			std::cout << "name program: ";
			std::string start_start{ "start " };
			std::cin >> start_pr;
			std::string plus_start{ start_start + start_pr };
			system(plus_start.c_str());
			std::cin.ignore();
		}
		//путь  по котой находится программа
		else if (glav_cin == "pwd") {
			system("pwd");
		}
		// vim редактор
		else if (glav_cin == "vim") {
			system("wsl vim");
		}
		//карта мира
		else if (glav_cin == "map") {
			wsl_kommand THE_MAP;
			THE_MAP.print_cin("wsl telnet mapscii.me");
		}
		//тренеровочный полигон
		else if (glav_cin == "trn") {
			std::cout << "this is a training ground. here I'll show you what I'm learning" << std::endl;
			std::cout << "Chapter 1, let's start with OOP" << std::endl;
			std::cout << "1 for class ork, 2 for car: ";
			std::cin >> kom2;
			if (kom2 == 1) {
				Ork new_user;
				new_user.legend();

			}
			else if (kom2 == 2) {
				Car BMV;
				BMV.legend_function();

			}
			else {
				std::cout << "error";
			}
			
		}
		//чтениче файлов через fstream
		else if (glav_cin == "read") {
			std::string line, cin_file_user;
			std::cout << "Enter file" << std::endl;
			std::getline(std::cin, cin_file_user);
			std::ifstream file_read(cin_file_user);
			while (getline(file_read, line)) {
				std::cout << line << std::endl;
			}
			file_read.close();
		}
		//теперь уже создание фалов через fstream
		else if ((glav_cin == "creat")) {
			std::cout << "Enter file name: " << std::endl;
			std::string file_nasme, line;
			std::getline(std::cin, file_nasme);
			std::cout << "Enter content: " << std::endl;
			std::ofstream file_creat(file_nasme);
			while (std::getline(std::cin, line)) {
				if (line == "end") {
					break;
				}
				file_creat << line << std::endl;
			}
			file_creat.close();
			std::cout << "Great! File written! Named: " << file_nasme;
		}
		// новый vim  файл
		else if (glav_cin == "vim_new") {
			std::cout << "Enter file name: " << std::endl;
			std::string new_vim_file, new_vinm;
			std::getline(std::cin, new_vim_file);
			new_vinm = "wsl vim " + new_vim_file;
			system(new_vinm.c_str());
		}
		// wsl (подсистема linux  для windows)
		else if (glav_cin == "wsl") {
			system("wsl");
		}
		//тетрис игра
		else if (glav_cin == "tetris") {
			system("wsl vitetris");
		}
		//анимированые часы
		else if (glav_cin == "time") {
			system("wsl tty-clock -s -C 1");
		}
		//исколючение 
		else {
			std::cout << "$ " << glav_cin << ": " << "command not found" << std::endl;
		}

	}
	return 0;
}
//функции
//эта функция делает cout только через print
std::string print(std::string word) {
	std::cout << word << std::endl;
	return word;
}
//эта функция делает cout только через print только уже для int

int print(int word) {
	std::cout << word << std::endl;
		return word;
}
//эта функция позволяет чтото ввести в терминал

std::string i(std::string syu) {
	system(syu.c_str());
	return syu;
}



//эта функция позволяет что то ввести в терминал wsl
//
std::string i_wsl(std::string syu, std::string sui) {
	sui = "wsl " + syu;
	system(sui.c_str());
	return sui;
}




