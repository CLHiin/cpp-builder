//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HW3_12360740_蔡仁豪.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
const int MaxN = 21;
int magicSquare[MaxN][MaxN];

const int directions[4][2] = {
	{-1,-1}, // 左上
	{-1, 1}, // 右上
	{ 1,-1}, // 左下
	{ 1, 1}, // 右下
};
// 每種起點的的占用移動量
const int moveOffsets[4][2] = {
	{ 1, 0}, // 上中，向下移动
	{-1, 0}, // 下中，向上移动
	{ 0, 1}, // 左中，向右移动
	{ 0,-1}, // 右中，向左移动
};
//---------------------------------------------------------------------------
void GenerateMagicSquareOdd(int n,int startPoint,int dir) {
	memset(magicSquare, 0, sizeof(magicSquare)); // 初始化魔術方陣為0

//	int row , col;
//	if (startPoint == 0) { // 上中
//		row = 0;
//		col = n / 2;
//	} else if (startPoint == 1) { // 下中
//		row = n - 1;
//		col = n / 2;
//	} else if (startPoint == 2) { // 左中
//		row = n / 2;
//		col = 0;
//	} else { // 右中
//		row = n / 2;
//		col = n - 1;
//	}

	int row = (startPoint == 0) ? 0 : (startPoint == 1) ? n - 1 : n / 2;
	int col = (startPoint == 0 || startPoint == 1) ? n / 2 : (startPoint == 2) ? 0 : n - 1;

	for (int num = 1; num <= n * n; ++num) {
		magicSquare[row][col] = num;

		int nextRow = (row + directions[dir][0] + n) % n; // 确保 nextRow 为非负
        int nextCol = (col + directions[dir][1] + n) % n; // 确保 nextCol 为非负

        // 检查下一个位置是否已被占用
		if (magicSquare[nextRow][nextCol] != 0) {
            row = (row + moveOffsets[startPoint][0] + n) % n; // 根据起点移动
			col = (col + moveOffsets[startPoint][1] + n) % n; // 根据起点移动
        } else {
            row = nextRow; // 否则，移动到下一个位置
            col = nextCol; // 更新列
		}
	}
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int n = StrToInt(Edit1->Text), dir = -1, outset = -1;
	if (n % 2 == 0 || n < 3 || n > MaxN){
		Memo1->Lines->Add("請輸入3~21的奇數！");
		return;
	}

	TRadioButton* radioButtons1_4[] = { RadioButton1, RadioButton2, RadioButton3, RadioButton4 };
	TRadioButton* radioButtons5_8[] = { RadioButton5, RadioButton6, RadioButton7, RadioButton8 };

	for (int i = 0; i < 4; ++i) if (radioButtons1_4[i]->Checked) {   dir = i;break;}
	for (int i = 0; i < 4; ++i) if (radioButtons5_8[i]->Checked) {outset = i;break;}

	if (   dir == -1) {Memo1->Lines->Add("請選擇一個方向！");return;}
	if (outset == -1) {Memo1->Lines->Add("請選擇一個起點！");return;}

	GenerateMagicSquareOdd(n,outset,dir);
	int maxWidthPerCell = 6;  // 假設每個數字占用4個字符的寬度
	int totalWidth = n * maxWidthPerCell;
	AnsiString separator = AnsiString('-').StringOfChar('-', totalWidth - 6)
							+ "   " + n + " * " + n + "   " +
						   AnsiString('-').StringOfChar('-', totalWidth - 6);
	// 计算行、列和对角线的和，并打印到 Memo2
	Memo1->Lines->Add(separator);
	for (int i = 0; i < n; ++i) {
		AnsiString rowText;
		int rowSum = 0;
		for (int j = 0; j < n; ++j) {
			rowText += IntToStr(magicSquare[i][j]) + "\t";
			rowSum  += magicSquare[i][j];
		}
		Memo1->Lines->Add(rowText + "-" + IntToStr(rowSum));
	}
	// 打印每列和
	AnsiString colSumsLine = "|";
	for (int j = 0; j < n; ++j) {
		int colSum = 0;
		for (int i = 0; i < n; ++i) {
			colSum += magicSquare[i][j]; // 累加每列的和
		}
		colSumsLine += IntToStr(colSum) + "\t"; // 添加列和
		if (j < n - 1) {
			colSumsLine += "|"; // 在每个列和之间添加分隔符
		}
	}
	// 计算对角线的和
	int diag1Sum = 0, diag2Sum = 0;
	for (int i = 0; i < n; ++i) {
		diag1Sum += magicSquare[i][i]; // 主对角线
		diag2Sum += magicSquare[i][n - 1 - i]; // 副对角线
	}
	Memo1->Lines->Add(colSumsLine +       // 输出列和
						"\\ " + IntToStr(diag1Sum)+
						"/"   + IntToStr(diag2Sum));


	// 设置 TStringGrid 的行数和列数
	StringGrid1->RowCount = n + 1;
	StringGrid1->ColCount = n + 1;
	// 添加列标题
	for (int j = 1; j <= n; ++j) StringGrid1->Cells[j][0] = IntToStr(j); // 列标题

	// 填充魔術方陣到 TStringGrid
    for (int i = 0; i < n; ++i) {
        StringGrid1->Cells[0][i + 1] = IntToStr(i + 1); // 行标题
        for (int j = 0; j < n; ++j) {
            StringGrid1->Cells[j + 1][i + 1] = IntToStr(magicSquare[i][j]); // 填充方阵数据
        }
    }
}
//---------------------------------------------------------------------------
