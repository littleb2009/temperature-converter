#include <stdio.h>
#include <stdlib.h>

#define ftoc(x) ((x - 32l) / 1.8l)
#define ctof(x) ((x * 1.8l) + 32l)

const long double CTOK = 273.15l;

long double celsius, kelvin, fahrenheit;

const char usage[] =
  "Usage: tempconvert scale value\n"
  "\n"
  "scale: The temperature scale the value is provided in:\n"
  "  f, F - Fahrenheit\n"
  "  c, C - Celsius\n"
  "  k, K - Kelvin\n"
  "  r, R - Rankine (under development)\n"
  "\n"
  "value: The numeric value.\n";


int main(int argc, char **argv) {
  if(argc<2) {
    fprintf(stderr, "Bad argument count.\n");
    printf("%s", usage);
    return 1;
  }

  if(argv[1][0]=='h') {
    printf("%s", usage);
    return 0;
  }

  if (argc != 3) {
    fprintf(stderr, "Bad argument count.\n");
    printf("%s", usage);
    return 1;
  }

  char *endptr = (char *)malloc(4096 * sizeof(char));
  switch (argv[1][0]) {
    case 'f':
    case 'F':
      fahrenheit = strtold(argv[2], &endptr);
      celsius = ftoc(fahrenheit);
      kelvin = celsius + CTOK;

      break;
    case 'c':
    case 'C':
      celsius = strtold(argv[2], &endptr);
      fahrenheit = ctof(celsius);
      kelvin = celsius + CTOK;

      break;
    case 'k':
    case 'K':
      kelvin = strtold(argv[2], &endptr);
      celsius = kelvin - CTOK;
      fahrenheit = ctof(celsius);

      break;
    case 'r':
    case 'R':
      return 1;

      break;
    default:
      fprintf(stderr, "Unrecognized temperature scale %c\n", argv[1][0]);
      printf("%s", usage);
      return 1;
  }
  printf("K: %.15Lf\nC: %.15Lf\nF: %.15Lf\n", kelvin, celsius, fahrenheit);
  return 0;
}
