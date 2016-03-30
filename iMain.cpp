#include "Includes.h"
#define c_p (1<<0)

void BunnyHop()
{
	while (true)
	{
		if (LocalPlayer::GetHealth() > 0 && GetAsyncKeyState(VK_SPACE) & 0x8000 && LocalPlayer::GetFlags() & c_p)
		{
			cout << "Client should be jumping" << endl;
			Client::SetJump(1);
			Sleep(15);
			Client::SetJump(0);
		}

		Sleep(15);

	}
}

int main()
{
	if (Memory::AttachProcess("csgo.exe"))
	{
		Resources::ClientDLL = Memory::GetModuleInformation("client.dll");
		Offsets::GetOffsetsByFile(".//Offsets.ini");

		BunnyHop();
	}
	Sleep(1500);

	return 0;
}