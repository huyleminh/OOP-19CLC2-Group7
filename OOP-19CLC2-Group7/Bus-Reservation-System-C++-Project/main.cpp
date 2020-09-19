#include "Header.h"
#include "./Menu/Menu.h"



int main() {

	Graphic::font(16, 16);
	Menu menu;
	menu.renderMainMenu();
	return 0;
}
