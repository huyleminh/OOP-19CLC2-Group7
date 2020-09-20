#include "Header.h"
#include "./Menu/Menu.h"



int main() {

	Graphic::font(18, 18);
	Menu menu;
	menu.renderMainMenu();
	return 0;
}
