#include <string.h>

// Functions for loading and printing the content of a file as
// you might do it in C++ using parameters (see Helper.cpp).
extern void LoadFile(const char* fileName, char* content);
extern void Print(const char* format, char* content);

// Functions for loading and printing the content of a file as
// the compiled code might do it using a stack (see Helper.cpp).
extern void LoadFile(/*const char* fileName, char* content*/);
extern void Print(/*const char* format, char* content*/);

// Global stack with stack & frame pointers <sp> & <fp> as
// the compiled code might have and make use of.
char Stack[1000];
extern char* InitStack();
char* sp = InitStack();  // Stack pointer.
char* fp = &Stack[1000];  // Frame pointer.

// Forward declarations for the individual sample functions.
void SampleMain(int argc, char *argv[]);
void MacroMain(int argc, char *argv[]);

// Sample program's main entry point.
void main(int argc, char *argv[])
{
	// C++ code as it may be found in the wild (with vulnerability we can exploit).
	SampleMain(argc, argv);

	// Macro sample code to demo what's going on under the hood (on the stack).
	MacroMain(argc, argv);
}


// ************************************************************************************************
// ********** Standard C++ example code ***********************************************************
// ************************************************************************************************

void SampleDisplayFileContent(const char* fileName)
{
	char content[16] = { 0 };
	LoadFile(fileName, content);
	Print("Content: '%s'\n", content);
}

void SampleMain(int argc, char *argv[])
{
	SampleDisplayFileContent(argv[1]);
}


// ************************************************************************************************
// ********** Example with stack and virtual assembler instructions (macros) **********************
// ************************************************************************************************

#pragma region Macros (virtual assembler instructions)
#define var(localVarOffset)			/* All variables are 'above' the frame pointer. */ \
	(int*)(fp - localVarOffset)		/* 'Above' means negative relative to the fp. */

#define param(x)					/* All parameters are 'below' the frame pointer. */ \
	*(int*)(fp + 4 + 4 + x*4)		/* fp + old fp slot + return address slot + x*4 bytes. */

#define push(value)					/* Push value onto stack (next slot). */ \
	sp -= 4;						/* Decrement stack pointer. */ \
	*(int*)sp = (int)(value);		/* Copy value onto stack. */

#define call(function)				/* Call a function. */ \
	push(__LINE__ + 2);				/* Push return address (line #). */ \
	function;						/* Call function. */

#define prolog(localVariablesSize)	/* Set up new stack frame. */ \
	push(fp);						/* Store off previous frame pointer. */ \
	fp = sp;						/* Update frame pointer. */ \
	sp -= localVariablesSize;		/* Make room for local variables. */

#define epilog(numBytesToPopOff)	/* Restore previous stack frame. */ \
	sp = fp;						/* Restore stack pointer. */ \
	fp = *(char**)sp; sp += 4;		/* Restore frame pointer. */ \
	sp += 4;						/* Fake 'return to line #' */ \
	sp += numBytesToPopOff;			/* Pop off parameters. */
#pragma endregion

void MacroDisplayFileContent(/*const char* fileName*/)
{
	prolog(16);						// 16 bytes in local variables.

	memset(var(16), 0, 16);			// char content[16] = { 0 };

	push(var(16));					// Push <content>.
	push(param(0));					// Push <fileName>.
	call(LoadFile());				// Call <LoadFile()>.

	push(var(16));					// Push <content>.
	push("Content: '%s'\n");		// Push <format>.
	call(Print());					// Call <Print()>.

	epilog(4);						// Pop <fileName> parameter (4 bytes).
}

void MacroMain(int argc, char *argv[])
{
	prolog(0);						// No local variables.

	push(argv[1]);					// Push <fileName>.
	call(MacroDisplayFileContent());// Call <MacroDisplayFileContent()>.

	epilog(8);						// Pop <argc> & <argv> parameters (8 bytes).
}
