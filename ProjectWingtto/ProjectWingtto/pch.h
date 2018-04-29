#pragma once

#include <Windows.h>
#include <tchar.h>
#include <memory>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_map>
#include <string>
#include "./Include/Singleton.hpp"
#include "./Include/Types.h"


#define KEY_DOWN(vk_code)	((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define SAFE_DELETE(ptr) if(ptr != nullptr) {delete ptr; ptr = nullptr;}