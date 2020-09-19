#include "Header.h"
#include "./Menu/Menu.h"



int main() {

	Graphic::font(20, 20);
	Menu menu;
	menu.renderMainMenu();
	return 0;
}
