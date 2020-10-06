#include <stdio.h>
#include <string.h>

#define DEBUG(X,...) 
//printf(X, ##__VA_ARGS__)

int T;
int bases[9];
char visited[2048];

int happy_number_in_base(int number, const int base) {
	int result = 0;
	
	while (number) {
		result += (number % base) * (number % base);
		number /= base;
	}
	
	if (result == 1)
		return 1;
	if (visited[result])
		return 0;
	visited[result] = 1;
	return happy_number_in_base(result, base);
}

int main (int argc, const char * argv[]) {
	if (argc < 2) {
		printf("\nUsage: multi input_file_name\n\n");
		return 0;
	}
	
	FILE* input_file = fopen(argv[1],"r");
	
	fscanf(input_file, "%d\n", &T);
	DEBUG("T: %d\n",T);
	
	for (int t = 0; t < T; t++) {
		memset(bases, -1, sizeof(bases));
		char line[1024];
		bzero(line, sizeof(line));
		
		fgets(line, 1024, input_file);
		int base_count = sscanf(line, "%d %d %d %d %d %d %d %d %d ", &bases[0], &bases[1], &bases[2], &bases[3], &bases[4],
			   &bases[5], &bases[6], &bases[7], &bases[8], &bases[9]);
		
		int happy_bases = 0;
		int happy_number = 1;
		while (happy_bases != base_count) {
			happy_number++;
			happy_bases = 0;
			for (int i = 0; i < base_count; i++) {
				bzero(visited, sizeof(visited));
				happy_bases += happy_number_in_base(happy_number, bases[i]);
			}
		}
		
		
		printf("Case #%d: %d\n", t+1, happy_number);
	}
	
	fclose(input_file);
	
    return 0;
}
