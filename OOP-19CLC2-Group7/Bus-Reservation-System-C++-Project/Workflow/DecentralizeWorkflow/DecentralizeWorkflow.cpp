#include "DecentralizeWorkflow.h"
#include "../../../Library/LocalStorage.h"
#include "../../../Library/Tokenizer.h"

string DecentralizeWorkflow::onDecentralizeUser() {
	LocalStorage local;
    vector<string> items = local.getItem("../Data/LocalStorage.txt");

    if (items[1] == "Admin")
        return "Admin";
    else if (items[1] == "Driver")
        return "Driver";
    else if (items[1] == "Passenger")
        return "Passenger";
    else 
        return "Undefined";            
}
