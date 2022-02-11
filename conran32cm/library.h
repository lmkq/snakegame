#pragma once // tránh đụng độ thư viện khi gọi chồng file lên nhau
#include <stdio.h>
#include <conio.h>
#include<ctime> /* thư viện hỗ trợ về thời gian thực */
#include "windows.h" // thư viện này bá đạo lắm nhé - chứa nhiều đồ chơi nek - cứ tìm hiểu dần dần s
//======= lấy tọa độ x của con trỏ hiện tại =============
#define KEY_NONE	-1
int whereX();
//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY();
//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(int x, int y);
//============= đặt màu cho chữ =========
void SetColor(WORD color);
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility);
//======= trả về mã phím người dùng bấm =========
int inputKey();
//====== màu nền
void textcolor(int x);