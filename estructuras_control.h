//---------------------------------------------------------------------------

#ifndef estructuras_controlH
#define estructuras_controlH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <Vcl.AppEvnts.hpp>
#include <Vcl.WinXCalendars.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <IdTime.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TImage *Image1;
	TLabel *LabelNombreCliente;
	TButton *Button1;
	TEdit *Edit2;
	TListBox *ListBox1;
	TButton *mostrar;
	TButton *Button2;
	TButton *Button3;
	TEdit *Edit3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TEdit *Edit1;
	TButton *Button8;
	TButton *FibonacciWhile;
	TButton *Exit;
	TButton *FibonacciFor;
	TButton *Message;
	TEdit *Edit4;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TEdit *Edit5;
	TGroupBox *GroupBox1;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TGroupBox *GroupBox2;
	TRadioButton *rdb_sumar;
	TRadioButton *rdb_restar;
	TRadioButton *rdb_multiplicacion;
	TRadioButton *rdb_dividir;
	TButton *Button12;
	TGroupBox *GroupBox3;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TButton *Button13;
	TListBox *ListBox2;
	TComboBox *ComboBox1;
	TLabel *Label7;
	TLabel *Label3;
	TLabel *Label4;
	TGroupBox *GroupBox4;
	TButton *Button14;
	TButton *Button15;
	TButton *Button16;
	TEdit *Edit9;
	TTimer *Timer1;
	TLabel *Label5;
	TEdit *Edit10;
	TLabel *Label6;
	TLabel *Label8;
	TButton *Button17;
	TProgressBar *ProgressBar1;
	TProgressBar *ProgressBar2;
	TProgressBar *ProgressBar3;
	TButton *Button18;
	TLabel *Label9;
	TTimer *Timer2;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TComboBox *ComboBox2;
	TLabel *Label13;
	TGroupBox *GroupBox5;
	TButton *Button19;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TTimer *Timer3;
	TToggleSwitch *ToggleSwitch1;
	TEdit *Edit11;
	TEdit *Edit12;
	TEdit *Edit13;
	TLabel *Label17;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TImage *Image2;
	TLabel *Label21;
	TLabel *Label22;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TLabel *Label24;
	TTabSheet *TabSheet2;
	TEdit *Edit14;
	TLabel *Label23;
	TEdit *Edit15;
	TLabel *Label25;
	TLabel *Label26;
	TLabel *Label27;
	TEdit *Edit18;
	TLabel *Label28;
	TEdit *Edit19;
	TTabSheet *TabSheet3;
	TButton *Button23;
	TLabel *Label29;
	TEdit *Edit20;
	TLabel *Label30;
	TEdit *Edit21;
	TButton *Button20;
	TListBox *ListBox3;
	TEdit *Edit16;
	TButton *Button21;
	TEdit *Edit17;
	TLabel *Label31;


	void __fastcall mostrarClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Edit3KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall ExitClick(TObject *Sender);
	void __fastcall FibonacciWhileClick(TObject *Sender);
	void __fastcall MessageClick(TObject *Sender);
	void __fastcall FibonacciForClick(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
	void __fastcall Edit4KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Button15Click(TObject *Sender);
	void __fastcall Button16Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Edit9Change(TObject *Sender);
	void __fastcall Edit10Change(TObject *Sender);
	void __fastcall Button17Click(TObject *Sender);
	void __fastcall Label8Click(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Button18Click(TObject *Sender);
	void __fastcall ComboBox2Change(TObject *Sender);
	void __fastcall Button19Click(TObject *Sender);
	void __fastcall Timer3Timer(TObject *Sender);
	void __fastcall ToggleSwitch1Click(TObject *Sender);
	void __fastcall Button23Click(TObject *Sender);
	void __fastcall Edit14KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit18KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button21Click(TObject *Sender);





private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
