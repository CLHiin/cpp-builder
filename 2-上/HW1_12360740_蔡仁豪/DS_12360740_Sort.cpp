//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DS_12360740_Sort.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define SWAP(x,y,t) t=x,x=y,y=t
TForm1 *Form1;
int i, j, n, range, target;
int 		 data[10000000];
int original_data[10000000];
clock_t t0, tx;
void put_Data(TMemo *Memo){
	Memo->Lines->Add("資料 :");
	for (i = 0; i < n; i++) {
		Memo->Lines->Add("Data[" + IntToStr(i) + "]=" + IntToStr(data[i]));
	}
}
void check_Data(TMemo *Memo){
	for (i = 0; i < n - 1; i++) {
		if(data[i] > data[i+1]){
			Memo->Lines->Add("資料未正常排序。");
			return ;
		}
	}
	Memo->Lines->Add("資料有正常排序。");
}
void creat_Data(){
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		original_data[i] = rand() % range;
	}
}
int binary_Search(){
	for (i = 0; i < n; i++){
		if (target == data[i]) return i;
	}
	return -1;
}
void get_Data(int data[],int original_data[],int n){
	for (i = 0; i < n; i++) {
		data[i] = original_data[i];
	}
}
void selection_Sort(int data[],int n){
	int temp, min = 0;
	for (i = 0; i < n; min = ++i) {
		for (j = i + 1; j < n; j++){
			if (data[j] < data[min])
				min = j;
		}
		SWAP(data[i], data[min], temp);
	}
}
void bubble_Sort(int data[],int n){
	int temp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++)
			if (data[j] > data[j+1])
				SWAP(data[j], data[j+1], temp);
	}
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("排序時間比較");
	Chart1->BottomAxis->Title->Caption = "排序算法";
	Chart1->LeftAxis->Title->Caption = "CPU 時間 (秒)";

	TBarSeries *selSortSeries = new TBarSeries(this);
	Chart1->AddSeries(selSortSeries);
	Chart1->Series[0]->Title = "選擇排序";

	TBarSeries *bubSortSeries = new TBarSeries(this);
	Chart1->AddSeries(bubSortSeries);
	Chart1->Series[1]->Title = "氣泡排序";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	t0 = clock();
	n = StrToInt(Edit1->Text);
	range = StrToInt(Edit2->Text);
	creat_Data();
	tx = clock();
	if (CheckBox1->Checked) put_Data(Memo1);
	Memo1->Lines->Add("CPU時間 :" + FloatToStr(float(tx-t0)/CLOCKS_PER_SEC));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	t0 = clock();
	get_Data(data,original_data,n);
	selection_Sort(data,n);
	tx = clock();
	if (CheckBox1->Checked)   put_Data(Memo2);
	if (CheckBox2->Checked) check_Data(Memo2);
	double sortTime = float(tx-t0)/CLOCKS_PER_SEC;
	Memo2->Lines->Add("CPU時間 :" + FloatToStr(sortTime));
	Chart1->Series[0]->AddXY(n, sortTime, "選擇排序 (" + IntToStr(n) + ")", clRed);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	t0 = clock();
	get_Data(data,original_data,n);
	bubble_Sort(data,n);
	tx = clock();
	if (CheckBox1->Checked)   put_Data(Memo3);
	if (CheckBox2->Checked) check_Data(Memo3);
	double sortTime = float(tx-t0)/CLOCKS_PER_SEC;
	Memo3->Lines->Add("CPU時間 :" + FloatToStr(sortTime));
	Chart1->Series[1]->AddXY(n, sortTime, "氣泡排序 (" + IntToStr(n) + ")", clBlue);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	target = StrToInt(Edit3->Text);
	int success = binary_Search();
	if (success == -1)
		Memo4->Lines->Add("目標[" + IntToStr(target) + "]無法找到");
	else
		Memo4->Lines->Add("目標[" + IntToStr(target) + "]在位置：" + IntToStr(success));
}
//---------------------------------------------------------------------------

