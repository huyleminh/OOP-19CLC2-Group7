#include "Header.h"
#include "./Menu/Menu.h"
#include "Feedback/Feedback.h"

int main() {
	/*Menu menu;
	menu.renderMainMenu();*/

	Feedback list;
	list.addFeedback(new NodeFeedback);
	list.addFeedback(new NodeFeedback);
	list.viewFeedback();
	list.updateFeedback();
	list.viewFeedback();

	system("pause");
	

	return 0;

}
