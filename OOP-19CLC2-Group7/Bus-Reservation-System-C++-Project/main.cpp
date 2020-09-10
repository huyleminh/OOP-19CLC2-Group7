#include "Header.h"
#include "Menu.h"
#include "User.h"
#include "BusList.h"
#include "Admin.h"
#include "List.h"
#include "Passenger.h"
#include "Ticket.h"

int main() {
	/*Menu menu;
	menu.renderMainMenu();*/
	PlaysTicket a("Student", "08", "AAA", "huyle");
	a.render();
	return 0;
}
