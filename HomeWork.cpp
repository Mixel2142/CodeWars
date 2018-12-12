#include <iostream>

using namespace std;

typedef bool ( *Vd_funPtr_chPtr )( char* );

bool ToLower( char* ch)
{
	if((int)*ch >= 65 && (int)*ch <= 90)(*ch)+=32;
	//if((int)ch >= 192 && (int)ch <= 223)ch+=31;
	return *ch != '\0';
}

bool ToUpper( char* ch)
{
	if((int)*ch >= 97 && (int)*ch <= 122)(*ch)-=32;
	//if((int)ch >= 223 && (int)ch <= 254)ch-=31;
	return *ch != '\0';
}

char* ChangeStr( char* str, Vd_funPtr_chPtr fun1, Vd_funPtr_chPtr fun2 )
{
	while ( fun1(str++) && fun2(str++) );
	return str;
}

int main(int argc, char* argv[])
{ 
	if(argc>1)
	{
		cout << ChangeStr( argv[1], ToLower, ToUpper ) << endl;
		cout << argv[1];
	}
	return 0;
}


