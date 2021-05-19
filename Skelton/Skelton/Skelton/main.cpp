#include<DxLib.h>

#include<cassert>
#include<string>
#include<sstream>
#include<iomanip>
#include"Debug.h"


struct Vector2
{
	float x, y;
};

using Position2 = Vector2;


struct Rect
{
	Position2 center;
	float w, h;
struct Rect {

	float Left()const {
		return center.x - w;
	}
	float RIGHT()const {
		return center.x + w;
	}
	float TOP()const {
		return center.y - h;
	}

	float DOWN()const {
		return center.y + h;
	}
	float Width()const {
		return w * 2.0f;
	}
	float Height()const {
		return h * 2.0f;
	}

};
	

}; 


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetWindowText(L"2016003_ˆî–Ø’q‘å");
	DxLib::ChangeWindowMode(true);
	DxLib_Init();
	DxLib::SetDrawScreen(DX_SCREEN_BACK);
	Rect rcA = { 200,200,50,50 };

	//DxLib::SetWindowText(L"Ninja Sprit");
	int graphH[6] = {};
	//wchar_t path[100];
	
	for (int i = 0; i < 6; ++i) {
		std::wostringstream pathOss;
		

		pathOss << L"../../../Asset/run3/adventurer-run3-";
		pathOss << std::setw(2) << std::setfill(L'0');
		pathOss << i << L".png";
		//wsprintf(path, L"../../../Asset/run3/adventurer-run3-%02d.png",i);
		graphH[i] = DxLib::LoadGraph(pathOss.str().c_str());
		assert(graphH[i]!= -1);

	}
	
	
	
	char keystate[256];
	unsigned int frame = 0;

	while (DxLib::ProcessMessage() == 0) {
		ClearDrawScreen();
		DrawString(100, 100, L"hello wold",0xffffff);

		GetHitKeyStateAll(keystate);
		constexpr float speed = 4.0f;
		if (keystate[KEY_INPUT_LEFT])
		{
			rcA.center.x -= speed;
		}
		if (keystate[KEY_INPUT_RIGHT])
		{
			rcA.center.x += speed;
		}
		if (keystate[KEY_INPUT_UP])
		{
			rcA.center.y -= speed;
		}
		if (keystate[KEY_INPUT_DOWN])
		{
			rcA.center.y += speed;
		}
		DrawBox(rcA.Left(), rcA.TOP(), rcA.RIGHT(), rcA.DOWN(), 0xffffff, true);
		DrawFormatString(10, 10, 0xffffaa, L"x=%d , y =%d", (int)rcA.center.x, (int)rcA.center.y);

		int srcX = 49 * (frame/10);
		int srcY = 0;

		DrawRotaGraph(rcA.RIGHT() + 50, rcA.DOWN() + 50,3.0f,0.0f,graphH[frame/10], true);

	

		ScreenFlip();
		frame = (frame + 1) % 60;

		std::ostringstream oss;
		//wchar_t out[32];
		//wsprintf(out, sizeof(out), "x=%d,y=%d\n");
		oss << "x=" << rcA.center.x << ",y="<<rcA.center.y<< std::endl;
		OutputDebugStringA(oss.str().c_str());

	

	
	
	Debug::Output("Main Loop is end");
	DxLib_End();

	return 0;
}