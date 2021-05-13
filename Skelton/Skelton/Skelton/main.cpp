#include<DxLib.h>

struct Vector2
{
	float x, y;
};

using Position2 = Vector2;

struct Rect {
	Position2 center;
	float w, h;//w/hÇªÇÍÇºÇÍïùçÇÇ≥ÇÃîºï™

	float Left()const {
		return center.x - w;
	}
	float RIGHT()const {
		return center.x + w;
	}
	float TOP()const {
		return center.y - h;
	}
	float BOTTOM()const {
		return center.y - h;
	}



}; 

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	DxLib::SetGraphMode(1280, 720, 32);
	DxLib::ChangeWindowMode(true);
	DxLib::SetWindowText(L"Ninja Sprit");
	if (DxLib_Init()) {
		return -1;
	}
	DxLib::SetDrawScreen(DX_SCREEN_BACK);
	Rect rcA = { 200,200,50,50 };
	char keyState[256];
	while (DxLib::ProcessMessage() == 0) {
		DxLib::ScreenFlip();
		DrawString(100, 100, L"hello wold",0xffffff);
		DrawBox(rcA.Left(), rcA.RIGHT(), rcA.TOP(), rcA.BOTTOM(), 0xffffff, true);

		GetHitKeyStateAll(keyState);
		constexpr float speed = 4.0f;
		if (keyState[KEY_INPUT_LEFT])
		{
			rcA.center.x -= speed;
		}
		if (keyState[KEY_INPUT_RIGHT])
		{
			rcA.center.x += speed;
		}
		if (keyState[KEY_INPUT_UP])
		{
			rcA.center.x -= speed;
		}
		if (keyState[KEY_INPUT_DOWN])
		{
			rcA.center.x -= speed;
		}

	}
	return 0;
}