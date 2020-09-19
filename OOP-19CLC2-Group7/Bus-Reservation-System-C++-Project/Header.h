/*
    *This file include all libraries that used in this project.
    *Only libraries and namespaces define in thi file.
    *If any file that wants to use lib, include this file only.
*/
#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <algorithm>
#include <iomanip>
#include <ctime> // get time now
#include <conio.h>
#include "Graphic.h"
#include "../Library/LocalStorage.h"
#include "../Library/Tokenizer.h"
#include "../Library/StdFormat.h"
#include "../Library/Date.h"
using namespace std;
#pragma warning(disable : 4996)
#define FORBIDDEN 403
#define NULL_USER 404
#define ADMIN_USER 405
#define DRIVER_USER 406
#define PASSENGER_USER 407

#endif
