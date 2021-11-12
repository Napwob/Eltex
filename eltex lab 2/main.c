#include <stdio.h>
#include <math.h>

struct align_three_char
{
	long long b;
	int d;
	short f;
	char h;
	char o;
	char u;
};

struct packed_three_char
{
	long long b;
	int d;
	short f;
	char h;
	char o;
	char u;
}__attribute__((packed));

struct align_two_char
{
	long long b;
	int d;
	short f;
	char h;
	char u;
};

struct packed_two_char
{
	long long b;
	int d;
	short f;
	char h;
	char u;
}__attribute__((packed));

int main() {
	int a = 270533154;
	char *p = &a;
	printf("Original bytes of %d:\n", a);
	printf("First byte = %d\n",*p);
	printf("Second byte = %d\n",*(p+1));
	printf("Third byte = %d\n",*(p+2));
	printf("Forth byte = %d\n\n",*(p+3));
	
	printf("Manipulations: lets change third byte\n");
	printf("First byte = %d\n",*p);
	printf("Second byte = %d\n",*(p+1));
	printf("Third byte = %d\n",*(p+2)+5);
	printf("Forth byte = %d\n",*(p+3));
	*p = *(p+2)+5;
	printf("After manipulations our number is equal %d\n\n", a);
	
	printf("Struct padding test:\n");
	struct align_three_char tna;
	struct packed_three_char tpa;
	struct align_two_char twna;
	struct packed_two_char twpa;
	printf("Bytes padded struct with three chars = %ld\n",sizeof(tna));
	printf("Bytes packed struct with three chars= %ld\n",sizeof(tpa));
	printf("We loose over %ld bytes\n",sizeof(tna)-sizeof(tpa));
	printf("Bytes padded struct with two char = %ld\n",sizeof(twna));
	printf("Bytes packed struct with two char= %ld\n",sizeof(twpa));
	printf("We loose over %ld bytes\n",sizeof(twna)-sizeof(twpa));
	return 0;
}
