#include <stdio.h>

static int remove_extremum(unsigned short *data_buffer, unsigned char size);

int main(void)
{
        int size;
        printf("please input a size:");
        scanf("%d", &size);

        unsigned short buffer[size];
        printf("please input %d numbers!\n", size);
        for (int i = 0; i < size; i++)
        {
                scanf("%d", &buffer[i]);
        }

        remove_extremum(buffer, size);

        for (int i = 0; i < size; i++)
        {
                printf("%d ", buffer[i]);
        }

        return 0;
}


static int remove_extremum(unsigned short *data_buffer, unsigned char size)
{
	int max_tmp = *data_buffer;
	int min_tmp = *data_buffer;
	unsigned char max_cursor = 0;
	unsigned char min_cursor = 0;
	
	for (int i = 1; i < size; i++)
	{
		if (data_buffer[i] > max_tmp)
		{
			max_tmp = data_buffer[i];
			max_cursor = i;
		}
		
		if (data_buffer[i] < min_tmp)
		{
			min_tmp = data_buffer[i];
			min_cursor = i;
		}
	}
	
        printf("%d %d\n",max_cursor ,min_cursor);

	data_buffer[max_cursor] = 0;
	data_buffer[min_cursor] = 0;
	
	return 0;
}