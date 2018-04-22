#ifndef DIRECTINPUT_H
#define DIRECTINPUTH

#include<dinput.h>
#include<d3dx9.h>

enum KEY_KIND
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,
	KEY_0,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	SPACE,
	LSHIFT,
	RSHIFT,
	LCONTROL,
	RCONTROL,
	ESC,
	ENTER,
	MAX
};

enum struct BUTTON_STATE {
	OFF,	//!< �O�t���[�����痣����Ă�����
	ON,		//!< �O�t���[�����牟����Ă�����
	PUSH,	//!< ���t���[�����牟���ꂽ���
	RELEASE	//!< ���t���[�����痣���ꂽ���
};

struct MouseData {
	D3DXVECTOR3 Movement;
	BUTTON_STATE LeftMouse;		//!< �}�E�X�̍��N���b�N�̏��
	BUTTON_STATE RightMouse;	//!< �}�E�X�̉E�N���b�N�̏��
};

class DirectInput {
public:
	~DirectInput();

	//�L�[�{�[�h�̃A�b�v�f�[�g
	void UpdateKey();

	//�}�E�X�̃A�b�v�f�[�g
	void UpdateMouse();

	static void CreateDirectInput(HWND hWnd);

	int DikCheck(KEY_KIND keyKind);
	void KeyCheck(KEY_KIND keyKind, BYTE* pDiks);
	void MouseCheck(const DIMOUSESTATE& dims);

	static DirectInput* GetpInstance() { return pInstance; }
private:
	static DirectInput* pInstance;
	DirectInput(HWND hWnd);

	BUTTON_STATE m_CurrentKey[static_cast<int>(KEY_KIND::MAX)];
	LPDIRECTINPUT8 m_pDInput;
	LPDIRECTINPUTDEVICE8 m_pKeyDevice;
	LPDIRECTINPUTDEVICE8 m_pMouseDevise;
	MouseData m_Mouse;

};

#endif
