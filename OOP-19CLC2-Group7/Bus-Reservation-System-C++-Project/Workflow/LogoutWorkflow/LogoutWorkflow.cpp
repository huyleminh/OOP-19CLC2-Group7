#include "LogoutWorkflow.h"
#include "../../../Library/LocalStorage.h"

void LogoutWorkflow::logout() {
    LocalStorage local;
    local.clear("../../../Data/LocalStorage.txt");

}