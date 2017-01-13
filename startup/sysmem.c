/**
*****************************************************************************
**
**  File        : sysmem.c
**
**  Author	    : Ac6
**
**  Abstract    : System Workbench Minimal System Memory calls file
**
** 		          For more information about which c-functions
**                need which of these lowlevel functions
**                please consult the Newlib libc-manual
**
**  Environment : System Workbench for MCU
**
**  Distribution: The file is distributed �as is,� without any warranty
**                of any kind.
**
*****************************************************************************
**
** <h2><center>&copy; COPYRIGHT(c) 2014 Ac6</center></h2>
**
** Redistribution and use in source and binary forms, with or without modification,
** are permitted provided that the following conditions are met:
**   1. Redistributions of source code must retain the above copyright notice,
**      this list of conditions and the following disclaimer.
**   2. Redistributions in binary form must reproduce the above copyright notice,
**      this list of conditions and the following disclaimer in the documentation
**      and/or other materials provided with the distribution.
**   3. Neither the name of Ac6 nor the names of its contributors
**      may be used to endorse or promote products derived from this software
**      without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
** FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
** DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
** SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
** CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
** OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
*****************************************************************************
*/

/* Includes */
#include <errno.h>
#include <stdio.h>

/* Variables */
extern int errno;
register char * stack_ptr __asm("sp");

/* Functions */

/**
 _exit
 Block system in an eternal loop. exit function depend on this
**//*
void _exit(int status)
{
	while (1)
	{
		__asm("NOP");
	}
}*/

/**
 _sbrk
 Increase program data space. Malloc and related functions depend on this
**/
/*
caddr_t _sbrk(int incr)
{
	extern char end __asm("end");
	static char *heap_end;
	char *prev_heap_end;

	if (heap_end == 0)
		heap_end = &end;

	prev_heap_end = heap_end;
	if (heap_end + incr > stack_ptr)
	{
		errno = ENOMEM;
		return (caddr_t) -1;
	}

	heap_end += incr;

	return (caddr_t) prev_heap_end;
}*/

/**
 _kill
 Kill current process.
**/
/*
long _kill(pid_t pid, int sig)
{
	(void)pid;
	(void)sig;
	return 0;
}

long _getpid(pid_t pid)
{
	(void)pid;
	return 0;
}*/

// For more system call function :
//		https://github.com/bjornfor/stm32-test/blob/master/STM32L1xx_StdPeriph_Lib_V1.1.1/syscalls.c

