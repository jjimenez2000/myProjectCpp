//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <iostream>
#include <algorithm>

#include <conio.h>
#include <string.h>

using namespace std;

#include "estructuras_control.h"
#include "conversiones.h"

// Se inncluye la libreria que permite reproducio el sonido de la alarma
#include <mmsystem.h>
// Variables de la alarma
String alarma, hora;
bool bandera_alarma = 0;
int segundo = 0;

UnicodeString Dias[] = { L"",
						"Domingo", "Lunes", "Martes", "Miercoles",
						"Jueves", "Viernes", "Sabado"
						};
UnicodeString Meses[] = { L"",
						  L"Enero", L"Febrero", L"Marzo", L"Abril",
						  L"Mayo", L"Junio", L"Julio", L"Agosto",
						  L"Septiembre", L"Octubre", L"Noviembre", L"Diciembre",
						};
 UnicodeString ArrayhexaDeciNum[] = {L"",
							L"0", L"1", L"2", L"3",L"4", L"5", L"6", L"7",
							L"8",L"9", L"A", L"B",L"C", L"D",L"E", L"F",
						};
bool bandera = 0;
bool bandera_style = 0;
bool editable = 0;
bool mostrarDetalles = 0;
int contador = 0;
int interval = 1;
int contadorPorcentaje = 0;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

//-------------  Estructura switch  -----------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int dia = StrToInt(Edit3->Text);

	// "("+str(a)+", "+str(b)+")"
	switch (dia) {
	case 1:
		Edit2->Text = "Doming";
		break;
	case 2:
		Edit2->Text = "Lunes";
		break;
	case 3:
		Edit2->Text = "Martes";
		break;
	case 4:
		Edit2->Text = "Miercoles";
		break;
	case 5:
		Edit2->Text = "Jueves";
		break;
	case 6:
		Edit2->Text = "Viernes";
		break;
	case 7:
		Edit2->Text = "Sabas";
		break;
	default:
		Edit2->Text = "Otro";
	}



	}

//------------------ While -----------------------------------------------------
void __fastcall TForm1::mostrarClick(TObject *Sender)
{
	int i = 1;

	while (i<=10){
		ListBox1->Items->Add(i);
		i++;
	}
}

//------------------ Do while---------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
   	int i = 1;

	do  {
	ListBox1->Items->Add(i);
		i++;
	}
	while (i<=10);
}

//-----------------for----------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	// ASCENDENTE
	for(int i=1; i<=10; i++){
		//ListBox1->Items->Add(i);
	}
	// DESCENDENTE
	for(int i=10; i>=1; i--){
		ListBox1->Items->Add(i);
	}

}

//---------------For------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
		int tabla = StrToInt(Edit3->Text);
		for(int i=1; i<=10; i++){
		ListBox1->Items-> Add(IntToStr(tabla)+ " * "+i+ " = "+  IntToStr(i*tabla));
	}
}

//---------------- Clear List --------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
			ListBox1->Items->Clear();
}
//---------------- Factorial----------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
		int factorial = 1;
		int numero = StrToInt(Edit3->Text);

		int total = 0;
		for(int i= 1 ; i<=numero; i++){
			factorial = factorial * i;
			ListBox1->Items->Add(factorial);
		}
		Edit2->Text = "El Factorial es = " + IntToStr(factorial);
}

//---------------- Verificar que vocales tiene el textp-------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	//bandera = 0;
	String letra = (Edit3->Text);
	ListBox1->Items->Clear();

	if( letra == ""){
		Edit1->Visible=true;
		Edit1->Text = "INGRESA MINIMO UN CARACTER";
		return;
	}

	char c = letra[1];
	int total = letra.Length();

	int vector1 = 0;
	int vector2 = 0;
	int vector3 = 0;
	int vector4 = 0;
	int vector5 = 0;

	String resp;
	int vocalestotal = 0;
	for(int i = 1 ; i<=total; i++){
		 char c1 =  tolower(letra[i]);
		 char a = toupper(letra[i]);
	switch (c1) {
		case 'a':
			resp = "A";
			vector1 += 1;
			break;
		case 'e':
			resp = "E";
			vector2 += 1;
			break;
		case 'i':
			resp = "I";
			vector3 += 1;
			break;
		case 'o':
			resp = "O";
			vector4 += 1;
			break;
		case 'u':
			resp = "U";
			vector5 += 1;
			break;
		default:
			resp = "Otro";
	}
		Edit2->Text = "Vocal: "+resp;
	}

	int vocal = 0;
	vocalestotal =  ( vector1 + vector2 +vector3 +vector4 +vector5 );

	vector1>0?ListBox1->Items->Add("A.-"+IntToStr(vector1)):vocal =1;
	vector2>0?ListBox1->Items->Add("E.-"+IntToStr(vector2)):vocal =1;
	vector3>0?ListBox1->Items->Add("I.-"+IntToStr(vector3)):vocal =1;
	vector4>0?ListBox1->Items->Add("O.-"+IntToStr(vector4)):vocal =1;
	vector5>0?ListBox1->Items->Add("U.-"+IntToStr(vector5)):vocal =1;

	if(vocalestotal == 0) {
		ListBox1->Items->Clear();
		ListBox1->Items->Add("No hay ninguna Vocal!");
	}

}

//---------------- aEvento al escribir en un campo de texto---------------------
void __fastcall TForm1::Edit3KeyPress(TObject *Sender, System::WideChar &Key)
{
Edit1->Visible=false;
if( bandera == 1){
	// No permite escribir más caracteres
	//Key = 0;
}
bandera = 1;
}


//---------------- En este se saca si el numero es par o impar------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	String numero1 = Edit3->Text;
	ListBox1->Items->Clear();

	if( numero1 == ""){
		Edit1->Visible=true;
		Edit1->Text = "INGRESA MINIMO UN NÚMERO";
		return;
	}

	int numero = StrToInt(Edit3->Text);
	if(numero % 2 == 0 ) {
		Edit2->Text = "El numero "+ IntToStr(numero) + " es par";
	}else{
		Edit2->Text = "El numero "+ IntToStr(numero) + " es Impar";
	}

}

//--------------- Fibonachi ciclo While ----------------------------
void __fastcall TForm1::FibonacciWhileClick(TObject *Sender)
{

	String numero1 = Edit3->Text;
	ListBox1->Items->Clear();

	if( numero1 == ""){
		Edit1->Visible=true;
		Edit1->Text = "INGRESA MINIMO UN NÚMERO";
		return;
	}



	int anterior = 0, ultimo = 1, suma;
	int elements = StrToInt(Edit3->Text);

	Edit2->Text = IntToStr(anterior) + ", "+IntToStr(ultimo);

	while (elements > 2) {
	   suma = ultimo + anterior;
	   Edit2->Text = Edit2->Text+", "+IntToStr(suma);
	   ListBox1->Items->Add(IntToStr(suma));
	   anterior = ultimo;
	   ultimo = suma;
	   elements = elements-1;
	}
	}

//-------------------- Exit -------------------------------------------------
void __fastcall TForm1::ExitClick(TObject *Sender)
{
  exit(0);
}

//------------------ Fibonachi For --------------------------------------
void __fastcall TForm1::FibonacciForClick(TObject *Sender)
{
	String numero1 = Edit3->Text;
	ListBox1->Items->Clear();

	if( numero1 == ""){
		Edit1->Visible=true;
		Edit1->Text = "INGRESA MINIMO UN NÚMERO";
		return;
	}

	int anterior = 0, ultimo = 1, suma;
	int elements = StrToInt(Edit3->Text);

	Edit2->Text = IntToStr(anterior) + ", "+IntToStr(ultimo);
	ListBox1->Items->Add(anterior);
	ListBox1->Items->Add(ultimo);
	if(elements>=2){
		for (int i = 2; i < elements; i++) {
		suma = ultimo + anterior;
		Edit2->Text = Edit2->Text+", "+IntToStr(suma);
		ListBox1->Items->Add(IntToStr(suma));
		anterior = ultimo;
		ultimo = suma;
	}

	}


}
//---------------------------------------------------------------------------

//------------------- Agregar un Mensaje --------------------------------------
void __fastcall TForm1::MessageClick(TObject *Sender)
{
	String mensaje = Edit3->Text;
	if( mensaje == ""){
		Edit1->Visible=true;
		Edit1->Text = "INGRESA Tu mensaje";
		// ShowMessage("Tienes que escribir un mensjae :#")     ;
		Edit3->SetFocus();
		return;
	}
	int elements = ListBox1->Items->Count;


	ListBox1->Items->Add(IntToStr(elements+1)+ ". "+mensaje);
	Edit3->Text = "";
	Edit3->SetFocus();
}

//---------------Funcion al seleccionar uno de los elementos de la lista--------
void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
   //	Button9->Visible=true;

	int cnt =  ListBox1->ItemIndex;

	if(cnt==-1){

	} else {
	Button9->Visible=true;
	Button10->Visible=true;
	Button11->Visible=true;
	Edit4->Visible=true;
	Edit5->Text = ListBox1->ItemIndex;
	Edit4->Text =  ListBox1 ->Items->operator [](cnt);
	}
}

//---------- Eliminar un elemento de la lista-----------------------------------
 void __fastcall TForm1::Button10Click(TObject *Sender)
{
	int cnt =  ListBox1->ItemIndex;
	ListBox1 ->Items->Delete(cnt);
}

//------------------ Boton cancelar para ocultar los botones-------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
	Button9->Visible=false;
	Button10->Visible=false;
	Button11->Visible=false;
	Edit4->Visible=false;
}

//------------- Boton Update para  Editar un elemento de la lista --------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
String mensaje = Edit4->Text;
	if( editable == 0){
		ShowMessage("No hiciste cambios en el texto")     ;
		Edit4->SetFocus();
		return;
	}

	if( mensaje == ""){
		ShowMessage("Tienes que escribir un mensjae :#")     ;
		Edit4->SetFocus();
		return;
	}

	int cnt =  ListBox1->ItemIndex;
	ListBox1 ->Items->Delete(cnt);
	ListBox1->Items->Insert(cnt, Edit4->Text);
	Button9->Visible=false;
	editable = 0;
}


//---------------- Al hacer cambios en el texto editable------------------------
void __fastcall TForm1::Edit4KeyPress(TObject *Sender, System::WideChar &Key)
{

	int cnt =  ListBox1->ItemIndex;
	if(cnt==-1){
//ShowMessage("Tienes que escribir un mensjae :#");
		Button9->Visible=false;
		Button10->Visible=false;
		Button11->Visible=false;
		Edit4->Visible=false;
	return;
	}

   editable = 1;
}

//----------------- Operaciones Básicas de -------------------------------------
void __fastcall TForm1::Button12Click(TObject *Sender)
{
	float num1, num2, res;
	 num1 = StrToFloat(Edit6->Text);
	 num2 = StrToFloat(Edit7->Text);

	 int elements = ListBox1->Items->Count;
	 ListBox1->Items->Add(IntToStr(elements+1)+ ". "+FloatToStr(num2));

	 if(rdb_sumar->Checked){
		res = num1+num2;
	 }
	 if(rdb_restar->Checked){
		 res = num1-num2;
	 }
	 if(rdb_multiplicacion->Checked){
		res = num1*num2;
	 }
	 if(rdb_dividir->Checked){
        res = num1/num2;
	 }
//	 Edit7->Text = res;
	 Edit8->Text=res;
}

//----------- Formulario para agregar los checkbox a una lista -----------------
void __fastcall TForm1::Button13Click(TObject *Sender)
{
	String name = Edit5->Text;
	if( name.Trim() == ""){
		ShowMessage("No hiciste cambios en el texto")     ;
		return;
	}

	ListBox2->Clear();

	ListBox2->Items->Add( " Hola "+name+" ");
	ListBox2->Items->Add("Tus pasatiempos son: ");
	bool tiene_pasatiempos = false;

	if(CheckBox1->Checked){
		ListBox2->Items->Add(CheckBox1->Caption);
		tiene_pasatiempos = true;
	}
	if(CheckBox2->Checked){
		ListBox2->Items->Add(CheckBox2->Caption);
		tiene_pasatiempos = true;
	}
	if(CheckBox3->Checked){
		ListBox2->Items->Add(CheckBox3->Caption);
		tiene_pasatiempos = true;
	}
	if(CheckBox4->Checked){
		ListBox2->Items->Add(CheckBox4->Caption);
		tiene_pasatiempos = true;
	}

	if( !tiene_pasatiempos ){
	 ListBox2 ->Items->Delete(1);
	 ListBox2->Items->Add("No tienes Pasatiempos");
	}




	ListBox2->Visible = true;

}


//----------- Al hacer un cambio en el comboBox cambiamos la imagen ------------
 void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
	String ruta="C:\\Users\\desarrollo6\\Pictures\\Saved Pictures\\";

	bool ok = false;
	if(ComboBox1->Text == "Leon"){
		ruta += "img2";
		ok = true;
	}
	if(ComboBox1->Text == "Perro"){
		ruta += "animales-en-su-habitat-natural-animal-photography-13";
		ok = true;

	}
	if(ComboBox1->Text == "Aguila"){
		ruta += "img3";
		ok = true;
	}
	if(ComboBox1->Text == "Icono"){
		ruta += "img4";
		ok = true;
	}
	if(ComboBox1->Text == "Otro"){
		ruta += "img5";
		ok = true;
	}
	ruta += ".bmp";

if(	ok ){
	LabelNombreCliente ->Visible = false;
	Image1->Picture->LoadFromFile(ruta);
}else{
	LabelNombreCliente ->Visible = true;
	LabelNombreCliente->Caption="Selecciona un elemento";
}

}

//-----------  Asignar propiedades al Timer Time ------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	contador += interval;
//	if(contador > 9){
	//	contador = 0;
  //	}
	Label3->Caption = contador;
}

//-----------  Boton Iniciar - continuar y pausar el contador ------------
void __fastcall TForm1::Button14Click(TObject *Sender)
{
	int velocidad = StrToInt(Edit9
	->Text);
	Timer1->Interval =  velocidad;

	if(Timer1->Enabled){
		Timer1->Enabled = false;
		Button14->Caption = "Continuar...";
	}else{
	  Timer1->Enabled = true;
	  Button14->Caption = "Pausar";
	}
}
//----------------- Boton para detener el contador y reiniciar todo ------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
		Timer1->Enabled = false;
		Label3->Caption = 0;
		contador = 0;
		Button14->Caption = "Iniciar";
}
//------------ Reinicar el contador a 0---------------------------------
void __fastcall TForm1::Button16Click(TObject *Sender)
{
	Label3->Caption = 0;
	contador = -interval;
}

//----------------------- Hacer cambios en la velocidadd -----------------------
void __fastcall TForm1::Edit9Change(TObject *Sender)
{
	int velocidad = StrToInt(Edit9->Text);
	Timer1->Interval =  velocidad;
	Timer2->Interval =  velocidad;
}

//---- Hacer cambios en el numero que se incrementa cada segundo----------------

void __fastcall TForm1::Edit10Change(TObject *Sender)
{
	int interva = StrToInt(Edit10->Text);
	interval =  interva;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
	if(mostrarDetalles){
		mostrarDetalles = 0;
		Label8->Caption = "Detalles";
	}else{
		String propsProgress="Propiedades de ProgressBar\n";
		propsProgress+="Max: Valor Máximo 100\nMin: valor minimo\nPosition: Valor actual\n";
		propsProgress+="State: -psbNormal, pbsError, pbsPused";
		Label8->Caption = propsProgress;
		mostrarDetalles = 1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label8Click(TObject *Sender)
{
  	if(mostrarDetalles){
		mostrarDetalles = 0;
		Label8->Caption = "Detalles";
	}else{
		String propsProgress="Propiedades de ProgressBar\n";
		propsProgress+="Max: Valor Máximo 100\nMin: valor minimo\nPosition: Valor actual\n";
		propsProgress+="State: -psbNormal, pbsError, pbsPused";
		Label8->Caption = propsProgress;
		mostrarDetalles = 1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
	 contadorPorcentaje+=1;
	 ProgressBar1->Position = contadorPorcentaje;
	 ProgressBar2->Position = contadorPorcentaje;
	 ProgressBar3->Position = contadorPorcentaje;
	 Label9->Caption=
		IntToStr((ProgressBar1->Position * 100) / ProgressBar1->Max )+"%";

	 Label10->Caption= ProgressBar1->Position;
	 Label11->Caption= ProgressBar2->Position;
	 Label12->Caption= ProgressBar3->Position;

	 if(contadorPorcentaje > 100){
		contadorPorcentaje = 0;
		 ProgressBar1->Position = contadorPorcentaje;
		 ProgressBar2->Position = contadorPorcentaje;
		 ProgressBar3->Position = contadorPorcentaje;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
	Timer2->Enabled = true;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox2Change(TObject *Sender)
{
	TStyleManager::SetStyle(ComboBox2->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
  String ruta="C:\\Users\\desarrollo6\\Pictures\\Saved Pictures\\";
  TStyleInfo LStyleInfo;
  TStyleManager::IsValidStyle(ruta, LStyleInfo);

	if (bandera_style == 0) {
		TStyleManager::LoadFromFile(ruta);
		TStyleManager::SetStyle(LStyleInfo.Name);
		bandera_style = true;
	} else {
		TStyleManager::SetStyle(LStyleInfo.Name);

	}

}

 // Esto se cargara al crear el formulario---------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
//    class PASCALIMPLEMENTATION TTreeView : public TCustomTreeView;
	 //eList1->FullExpand();
	//-- Permie que se agregue la barra para desplazarse en la lista ----
	SendMessage(ListBox2->Handle, LB_SETHORIZONTALEXTENT, 300, 0);

	for (int i = 0; i < TStyleManager::StyleNames.Length; i++) {
		String style =  TStyleManager::StyleNames[i];
		  ComboBox2 ->Items->Add(style);
	}
	ComboBox2->ItemIndex = ComboBox2->Items->IndexOf(TStyleManager::ActiveStyle->Name);
	// Agregar elementos al comboBox
	ComboBox1->Items->Add("Perro");
	ComboBox1->Items->Add("Leon");
	ComboBox1->Items->Add("Aguila");
	ComboBox1->Items->Add("Icono");
	ComboBox1->Items->Add("Otro");

   	// Label14->Caption = Time().FormatString("h:mm:ss AMPM");
	// Label14->Caption = Time().FormatString("h:mm:ss");
// 	Label15->Caption = Time().FormatString("AMPM");
//	Label16->Caption = Date();

	int numeros[] = {1,2,3,4,5};
	char letras[] = {'a','b','c','d'};
//	ListBox3->Items->Add(numeros[2]);

	// Matriz, fila y columna
	int Matriznumeros[2][3] = {{1,2,3},{1,2,3}};
	int suma = 0;

	for (int i = 0; i < 5; i++) {
	  ListBox3->Items->Add(numeros[i]);
	  suma += numeros[i];
	}

	ListBox3->Items->Add(suma);

	char palabra[]="Jesus";
	char nombre2[20]="Jesus";

	if(strcmp(palabra,nombre2)!=0){
	  ListBox3->Items->Add("No son Iguales");
	  }


	if(strcmp(palabra,nombre2)<0) {
	  ListBox3->Items->Add("La primera esta primero");
	}else if(strcmp(palabra,nombre2)>0) {
	  ListBox3->Items->Add("La segunda esta primero");
	}else {
	   ListBox3->Items->Add("Estan iguales");
	}

	// Copiar una cadena a otra
	ListBox3->Items->Add("Copiar palabra");
	strcpy(nombre2,palabra);

	int longitud = strlen(palabra);
	  ListBox3->Items->Add(palabra);
		ListBox3->Items->Add(IntToStr(longitud));
		ListBox3->Items->Add(nombre2);

	  if(strcmp(palabra,nombre2)==0){
	  ListBox3->Items->Add("Son Iguales");
	  }

	  ListBox3->Items->Add(IntToStr(strcmp(palabra,nombre2)));

	   char cadena3[]="";
	   strcat(cadena3,nombre2);

		ListBox3->Items->Add("Concatenacion");
		ListBox3->Items->Add(cadena3);

		ListBox3->Items->Add("Invertir cadena");
		ListBox3->Items->Add(strrev(cadena3));


		ListBox3->Items->Add("Pasar a Mayuscula ");
		String mayucula = strupr(cadena3);
		ListBox3->Items->Add(mayucula);
		ListBox3->Items->Add("Pasar a Minuscula ");
		  mayucula = strrev(strlwr(cadena3));
		ListBox3->Items->Add(mayucula);

		 char numbersStr[]="1234";
		 char numbers2Str[]="1.25";


		int numeroEnterp;
		int *dir_num;

		float numeroEnterp2;
		// Entero
		numeroEnterp = atoi(numbersStr);
		// Flotante
		numeroEnterp2 = atof(numbers2Str);

		ListBox3->Items->Add("Pasar a STRING A number ");
		ListBox3->Items->Add(numeroEnterp);
		ListBox3->Items->Add("Pasar a STRING A flotante ");
		ListBox3->Items->Add(numeroEnterp2);

		dir_num = &numeroEnterp;
		ListBox3->Items->Add("Direccion de memoria ");
		//ListBox3->Items->Add(IntToStr(dir_num));

		ListBox3->Items->Add(*dir_num);

	// longitud = intlen(numeros);
// 	ListBox3->Items->Add(numeros);

   //	ListBox3->Items->Add(IntToStr(longitud));


	Edit16->Text = IntToStr(suma);




}

//---------------------------------------------------------------------------
void repetir(){
	PlaySound(TEXT("C:\\Users\\desarrollo6\\Pictures\\Saved Pictures\\videoplayback.wav"), NULL, SND_ASYNC);
}

void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
	// Label14->Caption = Time().FormatString("h:mm:ss");
	Label14->Caption = Time().TimeString().SetLength(8);
	Label15->Caption = Time().FormatString("AMPM");
	Label16->Caption = Date();
	TDateTime valor = Date();
	int dia = DayOfWeek(valor);
	Label17 -> Caption = "Dia:  "+Dias[dia];

	Word Year, Month, Day;
	   DecodeDate (valor, Year, Month, Day);
	Label18 -> Caption = "Mes:  "+Meses[Month];

	hora = Time().TimeString().SetLength(8);

	if(hora == alarma){
		Label20 ->Visible = true;
		String ruta = "C:\\Users\\desarrollo6\\Pictures\\Saved Pictures\\videoplayback.wav";
		// PlaySound(lpszName, hModule, dvFlags)
		// PlaySound(TEXT(""), NULL, SND_ASYNC)
		repetir();
		bandera_alarma = true;
	}else {
	   Label21->Caption = hora  ;
	}

}


//---------------------------------------------------------------------------

void __fastcall TForm1::ToggleSwitch1Click(TObject *Sender)
{

	if(ToggleSwitch1->State == tssOn){
	// Realiza un sonido
	MessageBeep(-1);
	alarma = Edit11->Text+ ":" + Edit12->Text+":"+ Edit13->Text;
	Image2->Visible = true;
	Label19->Visible = true;
	Label19->Caption = ">> "+alarma;
	}else {
		Image2->Visible = false;
		PlaySound(NULL, NULL, SND_ASYNC); // Detenemos la alarma
		Label19->Visible = false;
		Label20->Visible = false;
			Label19->Caption = ">>";
			bandera_alarma = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button23Click(TObject *Sender)
{
	ListBox1->Items->Clear();
	int idPage = PageControl1->ActivePageIndex;

	// Decimal a binario
	 if(idPage == 0){
		int numero = StrToInt(Edit14->Text);
		// LLamar a la funcion que incluimos
		Edit15->Text = Decimal_Binario(numero);
	}
	else if(idPage == 1){
		String num = Edit18->Text;
		for (int i = 1; i <= num.Length() ; i++) {
		   if(num[i]=='1' || num[i]=='0'){
		   }else {
			   ShowMessage("Ingresa un numero Binario Válido");
			   break;
		   }
		}
		// LLamar a la funcion que incluimos
		Edit19->Text = binario_Decimal(num);
	}
		else if(idPage == 2){
		int n = StrToInt(Edit20->Text);
		// LLamar a la funcion que incluimos

		Edit21->Text = my_decimal_Hexadecimal(n);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit14KeyPress(TObject *Sender, System::WideChar &Key)
{
	 // Revisar que la tecla pulsada sea un numero o borrar
	 if(!(Key>='0' && Key <= '9' || Key == '\b')){
		Key =0;
	 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit18KeyPress(TObject *Sender, System::WideChar &Key)
{
	 // Revisar que la tecla pulsada sea un 0 || 1 || borrar
	 if(!(Key=='0' || Key == '1' || Key == '\b')){
		Key =0;
	 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
	Button21->Caption=(Estructuras(Edit17->Text));


	 Edit17->Text = IntToStr(automovil1.modelo)+" "+automovil1.marca;


}
//---------------------------------------------------------------------------

