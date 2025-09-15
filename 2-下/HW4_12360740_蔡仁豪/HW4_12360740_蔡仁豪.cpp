//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW4_12360740_蔡仁豪.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;  // ✅ 這裡只在主表單 .cpp 中定義一次即可

int size;
int randRange;
int maxDistance;
int noConnValue;
bool directed;
int start;
int dist[9999999];
bool found[9999999];
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	PageControl1->ActivePage = TabSheet1;
	size = StrToInt(Edit1->Text);
	randRange = StrToInt(Edit2->Text);
	maxDistance = StrToInt(Edit3->Text);
	noConnValue = StrToInt(Edit4->Text);
	directed = CheckBox1->Checked;

	StringGrid1->RowCount = size + 1;
	StringGrid1->ColCount = size + 1;

	// 設定標題列與標題欄
	for (int i = 1; i <= size; ++i) {
		StringGrid1->Cells[i][0] = IntToStr(i - 1); // 上排標籤
		StringGrid1->Cells[0][i] = IntToStr(i - 1); // 左側標籤
	}
	StringGrid1->Cells[0][0] = "距離\\當前點";

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int value = Random(randRange) + 1;
			if (value > maxDistance) value = noConnValue;

			if (i == j) StringGrid1->Cells[i + 1][j + 1] = noConnValue;
			else {
				StringGrid1->Cells[i + 1][j + 1] = IntToStr(value);
				if (!directed) {
					StringGrid1->Cells[j + 1][i + 1] = IntToStr(value);
				}
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::But(TObject *Sender)
{
	PageControl1->ActivePage = TabSheet2;
	start = StrToInt(Edit5->Text);

	StringGrid2->RowCount = size + 1;
	StringGrid2->ColCount = size + 2;
	StringGrid2->Cells[0][0] = "座標\\次數";
	StringGrid2->Cells[size+1][0] = "相連座標";
	for (int i = 1; i <= size; i++) {
		StringGrid2->Cells[i][0] = IntToStr(i - 1);
		StringGrid2->Cells[0][i] = IntToStr(i - 1);

		StringGrid2->Cells[1][i] = StringGrid1->Cells[1][i];
		dist[i-1] = StrToInt(StringGrid1->Cells[start+1][i]); // 點與起點的距離

		if (dist[i-1] < noConnValue) {  // 有連結
			StringGrid2->Cells[size+1][i] = IntToStr(start);  // 與起點相連
		}
		found[i-1] = false;
	}
	StringGrid2->Cells[1][start+1] = "---";
	found[start] = true;
	int count;

	for (count = 2; count <= size ; count++) {
		int u = -1, minDist = noConnValue;
		// 尋找最短距離
		for (int j = 0; j < size; j++){
			if (!found[j] && dist[j] < minDist) {
				minDist = dist[j];
				u = j;
			}
		}
		if (u == -1) break; // 所有能達的點都訪問完了
		found[u] = true;

		for (int v = 0; v < size; ++v) {  // 更新從 u 到其他點的距離
			int w = StrToInt(StringGrid1->Cells[u + 1][v + 1]);
			if (!found[v] &&  dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				StringGrid2->Cells[size+1][v+1] = IntToStr(u);  // 上一個相連的點
				StringGrid2->Cells[count][v+1] = "<" + IntToStr(dist[v]) + ">"; //更近的距離
			}
			else
				StringGrid2->Cells[count][v+1] = IntToStr(dist[v]); // 沒找到就用上一次的值
		}
		StringGrid2->Cells[count][start+1] = "---";
		StringGrid2->Cells[count][u+1] = "[" + StringGrid2->Cells[count][u+1] + "]";  //本次走的距離
	}


	for (;count <=size;count++) { // 代表n次內就跑完了(有空格)
		for (int i = 1; i <= size; i++) {
			StringGrid2->Cells[count][i+1] = "";
		}
	}
	for (int i = 0; i < size; i++) { // 不存在的相連去除掉
		if (!found[i] || i == start) {
			StringGrid2->Cells[size+1][i+1] = noConnValue;
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	PageControl1->ActivePage = TabSheet3;
	Memo1->Lines->Add("---------------------------------------------------------------------------");
	for (int i = 0; i < size; i++) {
		int prev, curr = i, steps = 0;
		String cell, distText, details[size], route = IntToStr(i);
		// cell-下個連結點 / distText-2點距離 / details-紀錄路徑與距離 / route-完整路徑
		while( (cell=StringGrid2->Cells[size+1][curr+1] )!= noConnValue) {
			// 每次判斷時將 cell=當前點的連結點，並判斷是否為空
			prev = StrToInt(cell); // 上一個接連座標
			distText = StringGrid1->Cells[prev + 1][curr + 1]; // 計算 rev, curr兩點距離
			details[steps++] = "[" + IntToStr(prev) + "->" + IntToStr(curr) + "](距離: " + distText + ")";
			route = IntToStr(prev) + "->" + route; // 簡易的紀錄---
			curr=prev; //迴圈最後將 curr=prev
		}
		Memo1->Lines->Add("從 " + IntToStr(start) + " 到 " + IntToStr(i) + " 的距離是 " + IntToStr(dist[i]));
		Memo1->Lines->Add("移動方法為: " + route);
		for (int j = 0; j < steps ; j++) Memo1->Lines->Add(details[j]);
	}
	// 我寫得真好0u0
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	PageControl1->ActivePage = TabSheet4;
	StringGrid3->RowCount = size + 1;
	StringGrid3->ColCount = size + 1;
	StringGrid4->RowCount = size + 1;
	StringGrid4->ColCount = size + 1;
	for (int i = 0; i <= size; i++) for (int j = 0; j <= size; j++){
		StringGrid3->Cells[i][j] = StringGrid1->Cells[i][j];
		StringGrid4->Cells[i][j] = noConnValue;
	}
	for (int i = 1; i <= size; i++) {
		StringGrid4->Cells[i][0] = i-1;
		StringGrid4->Cells[0][i] = i-1;
	}
	StringGrid4->Cells[0][0] = "經過點";
	for (int k = 1; k <= size; k++)
	for (int i = 1; i <= size; i++)
	for (int j = 1; j <= size; j++){
		int A = StrToInt(StringGrid3->Cells[i][k]),
			B = StrToInt(StringGrid3->Cells[k][j]),
			C = StrToInt(StringGrid3->Cells[i][j]);
		if (i == j) {
			StringGrid3->Cells[i][j] = 0;
		}
		else if (A+B<C) {
			StringGrid3->Cells[i][j] = IntToStr(A+B);
			StringGrid4->Cells[i][j] = k-1;
		}
		else StringGrid4->Cells[i][j] = i-1;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	PageControl1->ActivePage = TabSheet3;

	for (int i = 0; i < size; i++) {
		Memo1->Lines->Add("---------------------------------------------------------------------------");
		for (int j = 0; j < size; j++){ // i 到 j

			int prev = i, curr = j, steps = 0;
			String cell, distText, details[size], route = IntToStr(j);

			if (StringGrid3->Cells[i+1][j+1] != noConnValue && StringGrid3->Cells[i+1][j+1] != "0") {
				while( (cell=StringGrid4->Cells[prev+1][curr+1] )!= noConnValue) {  // 上一個到當前
					prev = StrToInt(cell); // 上一個中間的接連座標
					distText = StringGrid1->Cells[prev+1][curr+1]; // 計算 rev, curr兩點距離
					details[steps++] = "[" + IntToStr(prev) + "->" + IntToStr(curr) + "](距離: " + distText + ")";
					route = IntToStr(prev) + "->" + route; // 簡易的紀錄---
					curr=prev;prev=i; //迴圈最後目標curr=prev;出發點prev=i;
				}
			}
			Memo1->Lines->Add("從 " + IntToStr(i) + " 到 " + IntToStr(j) + " 的距離是 " + StringGrid3->Cells[i+1][j+1] );
			Memo1->Lines->Add("移動方法為: " + route);
			for (int k = 0; k < steps ; k++) Memo1->Lines->Add(details[k]);
		}
	}
}
//---------------------------------------------------------------------------
