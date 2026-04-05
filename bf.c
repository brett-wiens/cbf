#include <stdio.h>

int main(int argc, char* argv[]) {
	if( argc < 2 ) return(1);
	unsigned char tape[256];
	for( int i=0; i<256; i++ ) { tape[i]=0; }
	unsigned char tptr = 0;
	unsigned char istack[256];
	unsigned char sptr = 0;

	char* bf = argv[1];
	// I need one bit per bf...

	unsigned char iptr = 0;
	while( bf[iptr] != '\0' ) {
	switch(bf[iptr]) {
		// Hmmm... what we can actually do here is build a clock mask
		case '+': tape[tptr]++; tape[tptr]&=0xff; break;
		case '-': tape[tptr]--; tape[tptr]&=0xff; break;
		case '>': tptr++; tptr&=0xff; break;
		case '<': tptr--; tptr&=0xff; break;
		case '.': putchar(tape[tptr]); break;
		case '[': istack[sptr++]=iptr; break;
		case ']': if( tape[tptr]!='\0' ) { iptr=istack[sptr-1]; }
		          else { sptr--; }
		          break;
	} iptr++;}

}
