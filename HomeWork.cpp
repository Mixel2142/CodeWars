#include <iostream>

using namespace std;

typedef void ( *VoidFunPtr )( char* );

void ToLower( char* ch)
{
	if((int)*ch >= 65 && (int)*ch <= 90)(*ch)+=32;
	//if((int)ch >= 192 && (int)ch <= 223)ch+=31;
	//return *ch != '\0';
}

void ToUpper( char* ch)
{
	if((int)*ch >= 97 && (int)*ch <= 122)(*ch)-=32;
	//if((int)ch >= 223 && (int)ch <= 254)ch-=31;
	//return *ch != '\0';
}

char* ChangeStr( char* str, VoidFunPtr fun1, VoidFunPtr fun2 )
{
	
	while ( *str != '\0')
	{
		fun1(str++);
		fun2(str++);
	}
	return str;
}

int main(int argc, char* argv[])
{ 
	if( argc > 1 )
	{
		cout << ChangeStr( argv[1], ToLower, ToUpper ) << endl;
		cout << argv[1];
	}
	return 0;
}


