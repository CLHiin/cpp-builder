//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "HW4_12360740_蔡仁豪.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
#include <algorithm>
enum TMode { WALL, ROAD, START, END };  // 定義操作模式
TMode currentMode = ROAD;  // 預設為放置道路

struct CellColor {int value;TColor color;};
CellColor cellColors[] = {  // 創建一個對照表陣列
	{  0, clWhite  }, // 道路
	{ -1, clGray   }, // 牆壁
	{-10, clGreen  }, // 起點
	{-11, clRed    }, // 終點
	{ -2, clPurple }, // 走過的道路
	{ -3, clBlue   }, // 老鼠的位置
	{ -4, clYellow }, // 放棄的道路
};

// 定義四個方向：上、下、左、右
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool visited[100][100];  // 標記每個格子是否被訪問過
int stack[100][2];

int startX, startY, endX, endY, stackTop;
bool foundEnd;

bool IsMove(int x, int y, int rows, int cols, TStringGrid* grid) {
	// 確保座標在迷宮範圍內，且該位置不是牆壁（-1）
	return (x > 0 && x < rows && y > 0 && y < cols && grid->Cells[y][x] != -1 && !visited[x][y]);
}

bool TForm1::FindPath(int x,int y) {
	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];

		if (IsMove(newX, newY, StringGrid1->RowCount, StringGrid1->ColCount, StringGrid1)) {

			visited[newX][newY] = true;
			stack[++stackTop][0] = newX;
			stack[  stackTop][1] = newY;
			//parent[newX][newY][0] = x;
			//parent[newX][newY][1] = y;

			// 當老鼠移動時，把老鼠走到的格子設為 -3，前一格設為 -2
			StringGrid1->Cells[newY][newX] = -3;  // 下一個位置標記為 -3 (老鼠的位置)
			StringGrid1->Cells[y][x] = -2;  	   // 上一個位置標記為 -2 (走過的路徑)

			if (CheckBox1->Checked) {
				Sleep(50);  // 讓畫面更新的速度變慢
				StringGrid1->Invalidate();  // 強制重繪格子，調用 StringGrid1DrawCell
				Application->ProcessMessages();  // 允許界面更新
			}
			if (newX == endX && newY == endY) {
                ShowMessage("找到終點了!");
				return foundEnd = true;
			}
			FindPath(newX,newY); // 在該位置繼續尋找道路
			if (foundEnd) return true;

			// 沒找到，老鼠走回去
			StringGrid1->Cells[newY][newX] = -4;  // 放棄的道路
			StringGrid1->Cells[y][x] = -3;  	  // 回去的路徑

			if (CheckBox1->Checked) {
				Sleep(50);
				StringGrid1->Invalidate();
				Application->ProcessMessages();
			}


		}
	}
	return false; // 沒找到
}
bool TForm1::IsPointPresent(int n)
{
	// 遍歷陣列，檢查是否已經存在起點/終點
	for (int i = 0; i < StringGrid1->RowCount; i++) {
		for (int j = 0; j < StringGrid1->ColCount; j++) {
			if (StringGrid1->Cells[j][i] == n) {
				return true;  // 已經有
			}
		}
	}
	return false;  // 沒有
}

void AdjustGridSize(TStringGrid* StringGrid)
{
	// 获取StringGrid1的宽高
	int gridWidth = StringGrid->Width;
	int gridHeight = StringGrid->Height;
	// 根据当前列数和行数计算每个格子的新宽度和高度
	int newColWidth = gridWidth / (StringGrid->ColCount + 1);
	int newRowHeight = gridHeight / (StringGrid->RowCount + 1);
	// 设置最小格子尺寸，避免格子过小
	StringGrid->DefaultColWidth = std::min(newColWidth, 32);  // 最小宽度32
	StringGrid->DefaultRowHeight = std::min(newRowHeight, 32); // 最小高度32
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int cols = StrToInt(Edit1->Text) + 1; // 从Edit1获取列数
	int rows = StrToInt(Edit2->Text) + 1; // 从Edit2获取行数

	if (cols > 0 && rows > 0) {
		StringGrid1->ColCount = cols;
		StringGrid1->RowCount = rows;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				StringGrid1->Cells[j][i] = -1;
				if(i == 0) StringGrid1->Cells[j][i] = j;
				if(j == 0) StringGrid1->Cells[j][i] = i;
			}
		}
		AdjustGridSize(StringGrid1);  // 调整格子大小
		ShowMessage("迷宮大小已更新!");
	}
	else ShowMessage("請輸入有效的長和寬!");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1DrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{

	int cellValue = StrToIntDef(StringGrid1->Cells[ACol][ARow], 0);
    TColor colorToUse = clWhite; // 預設顏色

	if (ACol == 0 || ARow == 0) colorToUse = TColor(RGB(169, 169, 169)); // 灰色邊框
	else {
		for (const auto& cellColor : cellColors) {
			if (cellColor.value == cellValue) {
				colorToUse = cellColor.color;
				break;
			}
		}
	}

	StringGrid1->Canvas->Brush->Color = colorToUse;
	StringGrid1->Canvas->FillRect(Rect);

	// 顯示格子的內容（"1" 或 "0"）
	StringGrid1->Canvas->TextOut(Rect.Left + 2, Rect.Top + 2, StringGrid1->Cells[ACol][ARow]);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StringGrid1Click(TObject *Sender)
{
	int col = StringGrid1->Col;
	int row = StringGrid1->Row;

	// 根據當前的模式更新格子內容
	switch (currentMode) {
        case WALL:
			StringGrid1->Cells[col][row] = -1;  // 設置牆壁
			break;
        case ROAD:
			StringGrid1->Cells[col][row] =  0;  // 設置道路
			break;
		case START:
			if (IsPointPresent(-10)) {
				ShowMessage("起点已經存在，不能放置第二個起點!");break;
			}
			StringGrid1->Cells[col][row] = -10;  // 设置起点
			break;
		case END:
			if (IsPointPresent(-11)) {
				ShowMessage("終點已經存在，不能放置第二個終點!");break;
			}
			StringGrid1->Cells[col][row] = -11;  // 設置終點
			break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
	currentMode = WALL;  // 設定為放置牆壁模式
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
	currentMode = ROAD;  // 設定為放置道路模式
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
	currentMode = START;  // 設定為放置起點模式
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton4Click(TObject *Sender)
{
	currentMode = END;  // 設定為放置終點模式
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	for (int i = 0; i < StringGrid1->RowCount; i++) {
		for (int j = 0; j < StringGrid1->ColCount; j++) {
			int cellValue = StrToIntDef(StringGrid1->Cells[j][i], 0);
			if (cellValue < -1 && cellValue > -9) {
				StringGrid1->Cells[j][i] = 0 ;
			}
		}
	}


	foundEnd = false;
	stackTop = startX = startY = endX = endY = -1;
	memset(visited, false, sizeof(visited));

	// 找到起點和終點的位置
	for (int i = 0; i < StringGrid1->RowCount; i++) {
		for (int j = 0; j < StringGrid1->ColCount; j++) {
			if (StringGrid1->Cells[j][i] == -10) {
				startX = i;
				startY = j;
			}
			if (StringGrid1->Cells[j][i] == -11) {
				endX = i;
				endY = j;
			}
		}
	}

	if (startX == -1 || endX == -1) {
		ShowMessage("請確保起點和終點已經設置!");
		return;
	}


	FindPath(startX,startY);
}
//---------------------------------------------------------------------------

