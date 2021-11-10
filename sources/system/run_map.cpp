#include "engine.ipp"

int main(int argc, char* argv[], char* env[]) {
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "|                                           MAP                                            |" << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
	printElement("FUNCTION"); printElement(WHITE + "RESULT" + RESET); printElement(WHITE + "FT TIME" + RESET); printElement(WHITE + "STD TIME" + RESET);
	printElement(WHITE + "LEAKS" + RESET); cout << endl;

	// runNonCompilable("../map_tests/key_redefinition.cpp", argv, env);		//1
	// runFunctionTest("../map_tests/constructor.cpp", argv, env);
	// runFunctionTest("../map_tests/assign overload.cpp", argv, env);
	// runFunctionTest("../map_tests/iterators.cpp", argv, env);				//2
	// runFunctionTest("../map_tests/reverse iterators.cpp", argv, env);
	// runFunctionTest("../map_tests/insert(value).cpp", argv, env);
	// runFunctionTest("../map_tests/insert(InputIt).cpp", argv, env);
	// runFunctionTest("../map_tests/insert(hint).cpp", argv, env);
	// runFunctionTest("../map_tests/at().cpp", argv, env);					//4 (СТАНДАРТ 11+ )
	// runFunctionTest("../map_tests/operator[].cpp", argv, env);
	// runFunctionTest("../map_tests/empty().cpp", argv, env);
	// runFunctionTest("../map_tests/size().cpp", argv, env);
	// runFunctionTest("../map_tests/max_size().cpp", argv, env);
	// runFunctionTest("../map_tests/clear().cpp", argv, env);
	// runFunctionTest("../map_tests/erase(key).cpp", argv, env);
	// runFunctionTest("../map_tests/erase(pos).cpp", argv, env);				//5
	// runFunctionTest("../map_tests/erase(InputIt).cpp", argv, env);
	// runFunctionTest("../map_tests/swap().cpp", argv, env);
	// runFunctionTest("../map_tests/count().cpp", argv, env);
	// runFunctionTest("../map_tests/find().cpp", argv, env);
	// runFunctionTest("../map_tests/key_comp().cpp", argv, env);
	// runFunctionTest("../map_tests/using allocator.cpp", argv, env);
	// runFunctionTest("../map_tests/operator ==.cpp", argv, env);
	// runFunctionTest("../map_tests/operator !=.cpp", argv, env);
	// runFunctionTest("../map_tests/operator <.cpp", argv, env);
	// runFunctionTest("../map_tests/operator >.cpp", argv, env);
	// runFunctionTest("../map_tests/operator <=.cpp", argv, env);
	// runFunctionTest("../map_tests/operator >=.cpp", argv, env);



	runFunctionTest("../map_tests/lower_bound().cpp", argv, env);			//7 (не компилит)
	runFunctionTest("../map_tests/upper_bound().cpp", argv, env);			//8 (не компилит)
	runFunctionTest("../map_tests/equal_range().cpp", argv, env);			//9 
	runFunctionTest("../map_tests/compare class.cpp", argv, env);			//3 (сделан опо другому)



    saveResult("map_res");
	outputCurrentResult("MAP", _MAP_TEST_NUM);

	return (0);
}