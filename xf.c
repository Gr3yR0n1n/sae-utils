/* Tiny hex editor, minus the unix specific 'read' call.
 */
#include <stdio.h>

int
main()
{
	unsigned long flen = 0;
	unsigned char buf[16] = {0};
	int rdlen = 0, iter = 0;
	while((rdlen = fread(buf,sizeof(unsigned char),16,stdin)) > 0)
	{
		flen += 16;
		printf("%8.8lX: ",flen);
		for(iter = 0;iter < rdlen;iter++)
		{
			printf("%2.2X ",buf[iter]);
			if(buf[iter] < 33 || buf[iter] > 126)
				buf[iter] = '.';
		}	
		for(iter = 0;iter < rdlen;iter++)
			printf("%c",buf[iter]);
		printf("\n");	
	}
}
