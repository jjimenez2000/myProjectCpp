//---------------------------------------------------------------------------


UnicodeString ArrayhexaDeciNum2[] = {L"",
							L"0", L"1", L"2", L"3",L"4", L"5", L"6", L"7",
							L"8",L"9", L"A", L"B",L"C", L"D",L"E", L"F",
						};

struct Automovil{
	char marca[];
	int modelo;
}automovil1;

 #include "iostream"
 #include <algorithm>
using namespace std;

String Estructuras(String texto){

return texto;
}
// Funcion para convertir decimal a binario
String Decimal_Binario(int num){
	String binario = "";
	String aux = "";
	// metodo de escalera
	while (num > 0){
		if(num%2 == 1){
			binario = binario + "1";
		}else {
			binario = binario + "0";
		}
		num = num / 2;
	}
	aux = binario;
	binario = "";
	for (int i = aux.Length(); i >= 1; i--) {
		binario= binario + aux[i];
	}

	return 	binario;
}

//---------------------------------------------------------------------------
int binario_Decimal(String binario){
	int n = 0;
	int decimal = 0;

	for (int i = binario.Length(); i >= 1; i--) {
		if(binario[i] == '1'){
			decimal = decimal + pow(2.00,n);
			 n = n + 1;
		}else{
			n = n + 1;
        }
	}


	return 	decimal;

}

// Funcion para convertir decimal a hexadecimal
String decimal_Hexadecimal(int n){

	char hexaDeciNum[100];
	String hexa = "";
	// counter for hexadecimal number array
	int i = 0;
	while (n != 0) {
		// temporary variable to store remainder
		int temp = 0;
		// storing remainder in temp variable.
		temp = n % 16;
		// check if temp < 10
		if (temp < 10) {
			hexaDeciNum[i] = temp +48;
			i++;
		}
		else {
			hexaDeciNum[i] = temp +55;
			i++;
		}
		n = n / 16;
	}

	String res="";
	for (int j = i - 1; j >= 0; j--){
	  res =  hexaDeciNum [ j ] ;
	}

	return 	hexaDeciNum;

}
//---------------------------------------------------------------------------

// Funcion para convertir decimal a hexadecimal
String my_decimal_Hexadecimal(int n){
		  int decimal, remainder;
		  String hex_dec = "", aux="";
		  decimal= n;
		  while (decimal != 0) {
			remainder = decimal % 16;
			char ch;
			if (remainder >= 10)
			  ch = remainder + 55;
			else
			  ch = remainder + 48;
			hex_dec += ch;
			decimal = decimal / 16;
		  }
		 //reverse(hex_dec.begin(), hex_dec.end());

			aux = hex_dec;
			hex_dec = "";
			for (int i = aux.Length(); i >= 1; i--) {
				hex_dec +=  aux[i];
			}


		 return hex_dec;
}
//------------------------------
