#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	FILE *file =
fopen("input.txt", "r");
	if(!file) {
		printf("oshibka otkr \n");
		return 1;	
	}
	
	int year, month, day;
	if (fscanf(file, "%d-%d-%d", &year, &month, &day)!=3){
		printf("oshibka cht\n");
		fclose(file);
		return 1;
	}
	fclose(file);
	
	time_t t = time(NULL);
	struct tm today = *localtime(&t);
	
	struct tm target = {0};
	target.tm_year=year - 1900;
	target.tm_mon = month - 1;
	target.tm_mday = day;
	
	time_t t_today = mktie(&today);
	time_t t_target = mktime(&target);
	
	int days = (int)((t_target - t_today) / (60*60*24));
	printf("ostaloc: %d days\n", days);
	
	return 0;
}
