#include<DxLib.h>
#include<cassert>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	DxLib::SetGraphMode(1280, 720, 32);
	DxLib::ChangeWindowMode(true);
	DxLib::SetWindowText(L"Ninja Sprit");
	auto graphH = DxLib::LoadGraph(L"../../../Asset/run3/adventurer-run3-sword-Sheet.png");
	assert(graphH != -1);
	if (DxLib_Init()) {
		return -1;
	}
	DxLib::SetDrawScreen(DX_SCREEN_BACK);
	while (DxLib::ProcessMessage() == 0) {
		DxLib::ScreenFlip();
		DrawString(100, 100, L"hello wold",0xffffff);
		DrawGraph(10, 10, graphH, true);
		//drii
	}
	return 0;
}