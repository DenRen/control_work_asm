#include <cstdio>
#include <memory>

void _P1_mirror (char* str) {
	char* begin = str;

	if (begin == nullptr) return;
	if (*begin == '\0') return;

	while (*(++str) != '\0')
		;

	str--;

	char temp;
	while (begin < str) {
		temp = *str;
		*str = *begin;
		*begin = temp;
		begin++;
		str--;
	}
}

void _P2_strcat (char* str, const char* src) {	// si = a;
	if (str == nullptr)	// di = b;
		return;
	if (src == nullptr)
		return;		// Так будет удобнее

	while (*str != 0)
		str++;
	str--;

	while (*src != 0)
		*(str++) = *(src++);
	*str = '\0';
}

int _P3_sum (char* str) {		// si = str;
	if (str != nullptr) {
		int sum = 0;

		while (*str != 0)
			sum += *(str++);

		return sum;

	}

	return 0;
}

int _P4_min (int* str, int size) {	//si = a, di = size

	if (str == nullptr)
		return 0;

	int* c = str + 2 * size;

	int* min = str;

	while (str < c) {
		if (*str < size) min = str;
		str += 2;
	}

	return *min;
}

char arr[80] = { "abcde" };
int numbers[5] = { 1, 5, -8, 9, 1 };

int main () {
	char str[80];
	int num[5];

	printf ("\n");
	std::memcpy (str, arr, 80);	// Правда функция явно другая, ибо аргументы
								          // наоборот подаются
	_P1_mirror (str);
	printf ("<%s>\n", str);

	_P2_strcat (str, "12345");
	printf ("<%s>\n", str);

	printf ("<%s>\n", _P3_sum (str));

	std::memcpy (num, numbers, 10);

	printf ("<%d>\n", _P4_min (num, 5));

	return 0;
}
