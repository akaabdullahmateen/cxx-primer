#include <iostream>

int main(){
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::cout << "Type\t\t"			<< "Implementation width\t"			   	   << "Minimum width" 	<< std::endl;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::cout << "bool:\t\t" 		<< sizeof(bool) * 8 		<< " bits\t\t\t" << "NA" 			<< std::endl;
	std::cout << "char:\t\t" 		<< sizeof(char) * 8 		<< " bits\t\t\t" << "8 bits"  		<< std::endl;
	std::cout << "wchar_t:\t" 		<< sizeof(wchar_t) * 8 		<< " bits\t\t\t" << "16 bits" 		<< std::endl;
	std::cout << "char16_t:\t" 		<< sizeof(char16_t) * 8 	<< " bits\t\t\t" << "16 bits" 		<< std::endl;
	std::cout << "char32_t:\t" 		<< sizeof(char32_t) * 8 	<< " bits\t\t\t" << "32 bits" 		<< std::endl;
	std::cout << "short:\t\t" 		<< sizeof(short) * 8 		<< " bits\t\t\t" << "16 bits" 		<< std::endl;
	std::cout << "int:\t\t" 		<< sizeof(int) * 8 			<< " bits\t\t\t" << "16 bits" 		<< std::endl;
	std::cout << "long:\t\t" 		<< sizeof(long) * 8 		<< " bits\t\t\t" << "32 bits" 		<< std::endl;
	std::cout << "long long:\t" 	<< sizeof(long long) * 8 	<< " bits\t\t\t" << "64 bits" 		<< std::endl;
	std::cout << "float:\t\t" 		<< sizeof(float) * 8 		<< " bits\t\t\t" << "6 sig. dig." 	<< std::endl;
	std::cout << "double:\t\t" 		<< sizeof(double) * 8 		<< " bits\t\t\t" << "10 sig. dig." 	<< std::endl;
	std::cout << "long double:\t" 	<< sizeof(long double) * 8 	<< " bits\t\t"   << "10 sig. dig." 	<< std::endl;
	std::cout << "--------------------------------------------------------------------------------" << std::endl;

	return 0;
}