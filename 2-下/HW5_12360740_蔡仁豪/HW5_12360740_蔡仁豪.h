//---------------------------------------------------------------------------

#ifndef HW5_12360740_½²¤¯»¨H
#define HW5_12360740_½²¤¯»¨H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <VCLTee.Chart.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *Edit1;
	TLabel *Label2;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label3;
	TEdit *Edit4;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *Edit5;
	TButton *Button1;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TStringGrid *StringGrid1;
	TStringGrid *StringGrid2;
	TTabSheet *TabSheet3;
	TMemo *Memo1;
	TButton *Button2;
	TButton *Button3;
	TTabSheet *TabSheet2;
	TChart *Chart1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TTabSheet *TabSheet4;
	TMemo *Memo2;
	TLabel *Label6;
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
