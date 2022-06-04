// Exercise 4.37: Rewrite each of the following old-style casts to use a named cast:

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(){
	int 			i;
	int 			i_a;
	double 			d;
	string 			s 		= "some_string";
	const string 	*ps 	= &s;
	char 			c 		= 'a';
	char 			*pc		= &c;
	char			*pc_a 	= pc;
	void			*pv;
	void 			*pv_a;

	pv_a 	= (void*)									ps;
	pv 		= const_cast<void*>(static_cast<const void*>(ps));
	if(pv_a == pv) 	cout << "[PV\tMATCH]" 	<< endl;
	else 			cout << "[PV\tNO_MATCH]" << endl;

	i_a 	= int 				(*pc);
	i 		= static_cast<int>	(*pc);
	if(i_a == i) cout 	<< "[I\tMATCH]" 	<< endl;
	else cout 			<< "[I\tNO_MATCH]" 	<< endl;
	
	pv 		= &d;
	pc_a 	= (char*) 				pv;
	pc 		= static_cast<char*>	(pv);
	if(pc_a == pc) cout << "[PC\tMATCH]" 	<< endl;
	else cout 			<< "[PC\tNO_MATCH]" << endl;

	return 0;
}