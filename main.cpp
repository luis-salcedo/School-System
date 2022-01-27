#include <iostream>
#include <vector>
#include <Windows.h>


void typewriter(std::string message, int time) {
	int counter{ 0 };
	while (message[counter] != NULL) {
		std::cout << message[counter];
		Sleep(time);
		counter++;
	}
}

auto userInterface() -> void;
auto main() -> int {

	userInterface();
	return 0;
}

auto userInterface() -> void{
	int pointer{ 0 };
	std::vector<std::string> mainMenu{
		"Student Lookup",
		"Administrative Tools",
	};
	while (true) {
		system("cls");
		for (int i{ 0 }; i < mainMenu.size(); i++) {
			// pointer is on the item 
			if (i == pointer) {
				//Do Something
				std::cout << "-> "; typewriter(mainMenu[i], 20); std::cout << " <-" << std::endl;
			}
			else {
				//Display other items in vector
				typewriter(mainMenu[i], 15); std::cout << std::endl;
			}
		}

		while (true) {
			if (GetAsyncKeyState(VK_UP) != NULL) {
				pointer -= 1;
				if (pointer == -1)
					pointer = mainMenu.size();
				break;
			}
			if (GetAsyncKeyState(VK_DOWN) != NULL) {
				pointer += 1;
				if (pointer == mainMenu.size())
					pointer = 0;
				break;
			}
			if (GetAsyncKeyState(VK_ESCAPE) != NULL) {
				// Exit Application 
				exit(EXIT_SUCCESS);
			}
			if(GetAsyncKeyState(VK_SPACE)){
				// User Clicked on selected item
				switch (pointer) {
					// Student Search
				case 0:{
					system("cls");
					std::cout << "Student Search";
					exit(EXIT_SUCCESS);
				}
					// Administrator tools
				case 1: {
					break;
				}
				default:
					break;
				}
			}
		}
	} //end main while loop
}

