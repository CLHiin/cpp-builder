//---------------------------------------------------------------------------

#ifndef DS_12360740H
#define DS_12360740H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TTabSheet *TabSheet2;
	TPageControl *PageControl2;
	TTabSheet *TabSheet3;
	TTabSheet *TabSheet4;
	TLabel *Label1;
	TEdit *Edit1;
	TEdit *Edit2;
	TLabel *Label2;
	TButton *Button1;
	TCheckBox *CheckBox1;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit3;
	TButton *Button2;
	TMemo *Memo2;
	TLabel *Label5;
	TEdit *Edit4;
	TButton *Button3;
	TMemo *Memo1;
	TPageControl *PageControl3;
	TTabSheet *TabSheet5;
	TPaintBox *PaintBox1;
	TMemo *Memo3;
	TCheckBox *CheckBox2;
	void __fastcall PageControl1Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
