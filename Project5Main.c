#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>

struct Semaphore {
	int value;
	Queue<process> q;
};
P(struct Semaphore s)
{
	s.value = s.value - 1;
	if (s.value < 0)
	{
		q.push(p);
		block();
	}
	else
		return;
};
V(struct Semaphore s)
{
	s.value = s.value + 1;
	if (s.value <= 0)
	{
		q.pop();
		wakeup(p);
	}
};

struct Clock
{
	int sec;
	int nan;
	//incSec(){sec++;}
	//incNan(){nan++;}
};


int main(){	
	const unsigned int maxTimeBetweenNewProcsNS = 1000000;
	const unsigned int maxTimeBetweenNewProcsSecs = 1;
	int procCount = 0;
	int lastProcNan = 0;
	int lastProcSec = 0;
	
	shmid = shmget(key, sizeof(int*), 0666 | IPC_CREAT);
	struct Clock *freshClock = (struct Clock *)shmat(shmid, (void*)0,0);
	freshClock.sec = 0;
	freshClock.nan = 0;

	while(procCount < 100)
	{
		if(freshClock.nan - lastProcNan >= maxTimeBetweenNewProcsNS && freshClock.sec - lastProcSec >= maxTimeBetweenNewProcsSecs)
		{
			if(cpid = fork())
				break;
			lastProcNan = freshClock.nan;
			lastProcSec = freshClock.sec;
			procCount++;
		} 
	}

	if(cpid != 0)
		execl userP;

	return 0;
}
