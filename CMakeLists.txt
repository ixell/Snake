cmake_minimum_required (VERSION 3.13)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Snake")

add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)

add_executable (Snake WIN32
	"SnakeWnd.cpp"
	"SnakeWnd.h"
	"Window/framework.h"
	"Window/resource.h"
	"Window/SnakeApp.cpp"
	"Window/SnakeApp.h"
	"Window/pch.h"
	"Window/framework.h"
	"Window/targetver.h"
)

target_precompile_headers (
	Snake 
	PUBLIC
		"Window/pch.h"
		"Window/framework.h"
		"Window/targetver.h"
)

target_include_directories (Snake PUBLIC Window .)

add_subdirectory (Game)

set_property(GLOBAL PROPERTY CXX_STANDARD 20)
