//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DS_12360740.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
#define SWAP(a,b,t) t=a,a=b,b=t

int count, move;
int topA, topB, topC;
int MAX_DISKS = 10; // 最大盘子数量
TColor diskColors[] = {
	clRed,
	clGreen,
	clBlue,
	clYellow,
	clFuchsia,
	clLime,
	clAqua,
	TColor(RGB(255, 165, 0)), // 橙色
	clPurple,
	clTeal
};

void perm(String str, int k, int n) {
	wchar_t tmp;
	if (k == n) { // 输出排列结果
		Form1->Memo2->Lines->Add(str + "  [" + IntToStr(count++) + "]");\
		if (Form1->CheckBox1->Checked) {
			Form1->Memo1->Lines->Add(str + "  [" + IntToStr(count) + "]");
		}
	} else {
		for (int i = k; i <= n; i++) {
			SWAP(str[k], str[i],tmp);
			Form1->Memo2->Lines->
				Add("i=" + IntToStr(i) + ", k=" + IntToStr(k) +
					", swap: str[" + IntToStr(k) + "]= " + str[k] +
					", str[" + IntToStr(i) + "]= " + str[i] +
					", list[]=" + str);
			perm(str, k + 1, n);
			SWAP(str[k], str[i],tmp);
		}
	}
}

void DrawDisks(TCanvas *canvas, int tower[], int diskOffset, int towerHeight, int i) {
	if (tower[i] > 0) {
		int diskWidth = tower[i] * 20; // 盘子宽度
		int diskY = towerHeight - (i + 1) * 10; // 调整Y坐标
		int diskX = diskOffset - tower[i] * 10; // 柱子X坐标
		canvas->Brush->Color = diskColors[tower[i] % 10 - 1]; // 设置颜色
		canvas->FillRect(Rect(diskX, diskY, diskX + diskWidth, diskY + 10)); // 绘制盘子
	}
}
void DrawTower(int n, int towerA[], int towerB[], int towerC[]) {
	TCanvas *canvas = Form1->PaintBox1->Canvas;
	canvas->Brush->Color = clWhite;
	canvas->FillRect(Rect(0, 0, Form1->PaintBox1->Width, Form1->PaintBox1->Height));

	int towerHeight = Form1->PaintBox1->Height;
	int baseOffset = Form1->PaintBox1->Width / 4; // 调整柱子的基础偏移量，增加间距

	// 绘制柱子
	for (int i = 0; i < 3; i++) {
		canvas->Brush->Color = clBlack;
		canvas->FillRect(Rect((i + 1) * baseOffset - 5, towerHeight - 150, (i + 1) * baseOffset + 5, towerHeight)); // 调整柱子的高度
	}
	for (int i = 0; i < MAX_DISKS; i++) {
		DrawDisks(canvas, towerA, baseOffset * 1, towerHeight, i); // A柱
		DrawDisks(canvas, towerB, baseOffset * 2, towerHeight, i); // B柱
		DrawDisks(canvas, towerC, baseOffset * 3, towerHeight, i); // C柱
	}
}


// 汉诺塔移动函数
void Hanoi(int n, String a, String b, String c, int towerA[], int towerB[], int towerC[]) {
	if (n == 1) {
        Form1->Memo3->Lines->Add("步驟：" + IntToStr(move++) + " 從 " + a + " 移到 " + c);
        if (Form1->CheckBox2->Checked) {
            int disk;
            // 将顶部盘子存入disk
				 if (a == "A") { disk = towerA[--topA]; towerA[topA] = 0; }
			else if (a == "B") { disk = towerB[--topB]; towerB[topB] = 0; }
			else if (a == "C") { disk = towerC[--topC]; towerC[topC] = 0; }
            // 将盘子放到目标柱子上
				 if (c == "A") { towerA[topA++] = disk; }
			else if (c == "B") { towerB[topB++] = disk; }
			else if (c == "C") { towerC[topC++] = disk; }
			// 更新图案
			DrawTower(n, towerA, towerB, towerC);
			Sleep(500); // 暂停以便观看
        }
		return;
	}
	// 递归移动
    Hanoi(n - 1, a, c, b, towerA, towerB, towerC); // 将 n-1 个盘子从 A 移到 B
	Hanoi(    1, a, b, c, towerA, towerB, towerC); // 将第 n 个盘子从 A 移到 C
    Hanoi(n - 1, b, a, c, towerA, towerB, towerC); // 将 n-1 个盘子从 B 移到 C
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PageControl1Change(TObject *Sender)
{
	if(PageControl1->ActivePage == TabSheet1)
    {
		PageControl3->Visible = false;
	}
	else if(PageControl1->ActivePage == TabSheet2)
    {
		PageControl3->Visible = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//	char list[9] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' };
	String list = "ABCDEFGHI";
	int n = StrToInt(Edit1->Text); // 長度
	int k = StrToInt(Edit2->Text); // 固定
	count = 0;                     // 計數
	Form1->Memo1->Lines->Add("開始------------");
	perm(list.SubString(1, n), k + 1, n);
	Form1->Memo1->Lines->Add("結束------------");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	String inputString = Edit3->Text;
	int n = inputString.Length();  // 長度
	int k = StrToInt(Edit2->Text); // 固定
	count = 0; 					   // 計數
	Form1->Memo1->Lines->Add("開始------------");
	perm(inputString, k + 1, n);
	Form1->Memo1->Lines->Add("結束------------");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	MAX_DISKS = StrToInt(Edit4->Text);
	topA = MAX_DISKS; // 初始化 A 柱的顶部盘子数量
    topB = 0; // 初始化 B 柱的顶部盘子数量
    topC = 0; // 初始化 C 柱的顶部盘子数量
    move = 0;
	// 动态分配内存来存储三根柱子的盘子
	int** towers = new int*[3]; // 创建指向3个柱子的指针数组
    for (int i = 0; i < 3; i++) {
		towers[i] = new int[MAX_DISKS]; // 为每根柱子分配n个盘子的空间
        memset(towers[i], 0, MAX_DISKS * sizeof(int)); // 初始化为0
    }

	// 初始化 A 柱子上的盘子
	for (int i = 0; i < MAX_DISKS; i++) towers[0][i] = MAX_DISKS - i;

    Form1->Memo3->Lines->Add("開始------------");
	Hanoi(MAX_DISKS, "A", "B", "C", towers[0], towers[1], towers[2]); // 传递柱子数组
    Form1->Memo3->Lines->Add("結束------------");

	// 释放动态分配的内存
	for (int i = 0; i < 3; i++) {
        delete[] towers[i]; // 释放每根柱子的盘子空间
    }
	delete[] towers; // 释放指针数组
}

//---------------------------------------------------------------------------

