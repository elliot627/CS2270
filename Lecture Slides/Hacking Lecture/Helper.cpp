#include <fstream>

// Link to system() call and get address for demo.
void* System = &system;

// Make stack available to the functions implemented here.
extern char* sp;
extern char Stack[1000];

// Initialize stack for demo purposes.
char* InitStack()
{
	// Seed stack with 0xCC.
	memset(Stack, 0xCC, 1000);
	// Return 256 byte aligned stack address.
	return (char*)((int)(Stack + 1000) & 0xFFFFFF00);
}

// Stack version of Print() function.
void Print(/*const char* format, char* content*/)
{
	// Get function parameters from stack (this is a shortcut).
	char* format = *(char**)(sp + 4);
	va_list va = (char*)(sp + 8);
	
	vprintf(format, va);

	// Adjust stack pointer/pop 2 parameters & return address off stack.
	sp += 12;
}

// Standard Print() function.
void Print(const char* format, char* content)
{
	printf(format, content);
}

// Stack version of LoadFile() function.
void LoadFile(/*const char* fileName, char* content*/)
{
	// Get function parameters from stack (this is a shortcut).
	char* fileName = *(char**)(sp + 4);
	char* content = *(char**)(sp + 8);

	std::ifstream file(fileName);
	file.read(content, 256);

	// Adjust stack pointer/pop 2 parameters & return address off stack.
	sp += 12;
}

// Standard LoadFile() function.
void LoadFile(const char* fileName, char* content)
{
	std::ifstream file(fileName);
	file.read(content, 256);
}
