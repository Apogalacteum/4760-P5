#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>

struct processControlBlock
{
	pid_t pid;
	long state;
	unsigned int totalCPUTime;
	unsigned int totalSysTime;
	unsigned int lastBurstTime;
	int pPriority;
};



int main()
{
	struct processControlBlock p;
	p.state = 0;
	p.totalCPUTime = 0;
	p.totalSysTime = 0;
	p.lastBurstTime = 0;
	p.pPriority = 0;

	

	return 0;
}
