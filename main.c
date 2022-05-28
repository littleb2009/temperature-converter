#include<stdio.h>
#include<stdlib.h>

#define ftoc(x) ((x-32l)/1.8l)
#define ctof(x) ((x*1.8l)+32l)

const long double CTOK = 273.15l;

long double celsius, kelvin, fahrenheit;

signed main(signed argc, char **argv) {
	if(argc!=3) return 1;

	char *endptr = (char *)malloc(4096*sizeof(char));
	switch(argv[1][0]) {
		case 'f':
			fahrenheit = strtold(argv[2], &endptr);
			celsius = ftoc(fahrenheit);
			kelvin = celsius + CTOK;

		break;case 'c':
			celsius = strtold(argv[2], &endptr);
			fahrenheit = ctof(celsius);
			kelvin = celsius + CTOK;

		break;case 'k':
			kelvin = strtold(argv[2], &endptr);
			celsius = kelvin - CTOK;
			fahrenheit = ctof(celsius);

		break;case 'r':
			return 1;

		break;default:
			return 1;
	}
	printf(
		"K: %.15Lf\nC: %.15Lf\nF: %.15Lf\n",
		kelvin, celsius, fahrenheit
	);
	return 0;
}
