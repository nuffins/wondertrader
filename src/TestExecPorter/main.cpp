#define _CRT_SECURE_NO_WARNINGS
#include "../WtExecMon/WtExecPorter.h"
#include "../Share/DLLHelper.hpp"

void test_exec()
{
#ifdef _WIN32
	DLLHelper::load_library("WtExecMon.dll");
#else
	DLLHelper::load_library("libWtExecMon.so");
#endif

	init_exec("logcfgexec.json");

	config_exec("config_exec.json");

	run_exec();

	set_position("CFFEX.IF.2007", 1);

	printf("press enter key to exit\n");
	getchar();

	release_exec();
}

int main()
{
	test_exec();
	getchar();
	return 0;
}
