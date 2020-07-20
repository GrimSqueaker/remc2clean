//#include "stdafx.h"

#include "engine/engine_support.h"
#include "engine/sub_main.h"

using namespace std;

int main(int argc, char** argv)
{
	char *envp[] = { NULL };

	support_begin();
	int retval = sub_main(argc, argv, envp);
	support_end();

    return 0;
}

